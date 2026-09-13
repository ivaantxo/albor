#!/usr/bin/env python3
"""Inventario reproducible y sin cuantización de las tres hojas de fronts.

Ejecutar desde cualquier directorio con Python + Pillow. No modifica las fuentes.
Los rectángulos usan x,y,ancho,alto, excluyen marcos/títulos y conservan el anclaje.
"""
from pathlib import Path
from collections import Counter
import hashlib
import json
from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent
SOURCES = {v: Image.open(ROOT / f'entrenadores/{v}.png').convert('RGB')
           for v in ['18524', '28037', '47490']}
ENTRIES = []


def add(identity, game, source, cells, *, y=None, notes=None, extras=None,
        name=None, confidence='high', folder=None):
    frames = []
    colors = set()
    for r, c in cells:
        rect = [1 + 81*c, 18 + 98*r if y is None else y, 80, 80]
        frame = describe(source, rect)
        frames.append(frame)
        colors.update(tuple(rgb) for rgb in frame['opaque_colors_rgb'])
    entry = dict(id=f'{identity}_{game}', name=name or identity.replace('_', ' ').title(),
                 game=game, source=f'entrenadores/{source}.png', kind='front',
                 confidence=confidence, frames=frames,
                 frame_order=list(range(len(frames))),
                 animation_available=len(frames)>1,
                 animation_timing='unspecified_source_poses_only',
                 opaque_colors_rgb=[list(c) for c in sorted(colors)],
                 opaque_color_count=len(colors), palette_4bpp_compatible=len(colors)<=15,
                 notes=notes or [], extras=extras or [])
    if folder: entry['folder']=folder
    ENTRIES.append(entry)
    return entry


def describe(source, rect):
    x,y,w,h = rect
    crop = SOURCES[source].crop((x,y,x+w,y+h))
    background = crop.getpixel((0,0))
    counter = Counter(crop.get_flattened_data())
    colors = sorted(c for c in counter if c != background)
    normalized = bytes(channel for c in crop.get_flattened_data()
                       for channel in ((255,0,255) if c==background else c))
    return dict(rect=rect, background=list(background),
                opaque_color_count=len(colors), opaque_colors_rgb=[list(c) for c in colors],
                normalized_rgb_sha256=hashlib.sha256(normalized).hexdigest())


COMMON_ROWS = [
    # The sheet follows the game trainer-class order, except labeled insertions.
    ['hiker','battle_girl','fisher','cycler_m','cycler_f','black_belt','artist',
     'pokemon_breeder_m','pokemon_breeder_f','cowgirl','jogger','pokefan_m'],
    ['pokefan_f','poke_kid','young_couple','ace_trainer_m','ace_trainer_f',
     'waitress','veteran','ninja_boy','dragon_tamer','bird_keeper','double_team','rich_boy'],
    ['lady','gentleman','socialite','beauty','collector','policeman','pokemon_ranger_m',
     'pokemon_ranger_f','scientist','swimmer_m','swimmer_m_censored','swimmer_f'],
    ['tuber_m','tuber_f','sailor','ruin_maniac','psychic_m','psychic_f','pi','guitarist',
     'ace_trainer_snow_m','ace_trainer_snow_f','skier_m','skier_f'],
]


for source, game, player_m, player_f, rival in [
        ('18524','platinum','lucas','dawn','barry'),
        ('28037','hgss','ethan','lyra','silver')]:
    add(player_m,game,source,[(0,0)])
    add(player_f,game,source,[(0,1)])
    add(rival,game,source,[(0,2),(0,3),(0,4)])
    for c, identity in enumerate(['youngster','lass','camper','picnicker',
                                  'bug_catcher','aroma_lady','twins'],5):
        add(identity,game,source,[(0,c)])
    for r, row in enumerate(COMMON_ROWS,1):
        for c, identity in enumerate(row):
            if game=='hgss' and r==4 and c==10: identity='boarder'
            notes=[]
            if identity=='swimmer_m': notes=['La hoja etiqueta esta variante como Original.']
            if identity=='swimmer_m_censored': notes=['La hoja etiqueta esta variante como Censored; es una variante, no un frame de animación.']
            add(identity,game,source,[(r,c)],notes=notes)
    if game=='platinum':
        rows={
            5:['roughneck','clown','worker','school_kid_m','school_kid_f','belle_and_pa',
               'rancher','parasol_lady','waiter'],
            6:['interviewers','cameraman','reporter','idol','maid','lucas_dp','dawn_dp'],
        }
    else:
        rows={
            5:['roughneck','clown','worker','school_kid_m','school_kid_f','juggler',
               'kimono_girl','burglar','firebreather','biker','poke_maniac','bird_keeper_johto'],
            6:['rancher','teacher','super_nerd','sage','sage_korean','parasol_lady',
               'waiter','medium','cameraman','reporter'],
            7:['idol','elder','scientist_johto','eusine','lucas_dp','dawn_dp','lucas_platinum','dawn_platinum'],
        }
    for r,row in rows.items():
        for c,identity in enumerate(row):
            notes=['Variante coreana indicada por la hoja; no es un frame de animación.'] if identity=='sage_korean' else []
            add(identity,game,source,[(r,c)],notes=notes)


def groups(source,game,row,names):
    for g,identity in enumerate(names):
        add(identity,game,source,[(row,g*3+i) for i in range(3)])


for row,names in [
    (7,['roark','gardenia','maylene','crasher_wake']),
    (8,['fantina','byron','candice','volkner']),
    (9,['aaron','bertha','flint','lucian']),
    (11,['cynthia','cheryl','riley','marley']),
    (12,['buck','mira']),
    (13,['palmer','argenta','thorton','dahlia']),
    (14,['caitlin','darach']),
]: groups('18524','platinum',row,names)
for c,identity in enumerate(['galactic_grunt_m','galactic_grunt_f','mars','jupiter','saturn']):
    add(identity,'platinum','18524',[(10,c)])
add('cyrus','platinum','18524',[(10,5),(10,6),(10,7)])
for c,identity in enumerate(['sis_and_bro_unused','sis_and_bro_unused_censored',
                             'lucas_dp_unused','dawn_dp_unused']):
    add(identity,'platinum','18524',[(0,c)],y=1504,
        notes=['La hoja lo clasifica como UNUSED; conservar como variante independiente.'])

for row,names in [
    (8,['falkner','bugsy','whitney','morty']),
    (9,['chuck','jasmine','pryce','clair']),
    (10,['will','koga','bruno','karen']),
    (11,['brock','misty','lt_surge','erika']),
    (12,['janine','sabrina','blaine','blue']),
    (13,['lance','red']),
    (15,['palmer','argenta','thorton','dahlia']),
    (16,['caitlin','darach']),
]: groups('28037','hgss',row,names)
for c,identity in enumerate(['rocket_grunt_m','rocket_grunt_f','ariana','archer','proton','petrel']):
    add(identity,'hgss','28037',[(14,c)])
add('giovanni','hgss','28037',[(14,6),(14,7),(14,8)])
for c,identity in enumerate(['aroma_lady_unused','rich_boy_unused','picnicker_unused',
                             'camper_unused','poke_kid_unused','lucas_dp_unused','dawn_dp_unused']):
    add(identity,'hgss','28037',[(0,c)],y=1700,
        notes=['La hoja lo clasifica como UNUSED; conservar como variante independiente.'])
add('silver_unused','hgss','28037',[(0,7),(0,8),(0,9)],y=1700,
    notes=['La hoja lo clasifica como UNUSED; tres poses de una variante independiente.'])

# Barry's isolated sheet uses different 82-pixel front/back and 34-pixel OW grids.
barry_frames=[describe('47490',[2+82*c,220,80,80]) for c in range(3)]
barry_colors=sorted({tuple(c) for f in barry_frames for c in f['opaque_colors_rgb']})
ENTRIES.append(dict(
    id='barry_47490',name='Barry — hoja individual',game='platinum',source='entrenadores/47490.png',
    kind='front',confidence='high',frames=barry_frames,frame_order=[0,1,2],animation_available=True,
    animation_timing='unspecified_source_poses_only',opaque_colors_rgb=[list(c) for c in barry_colors],
    opaque_color_count=len(barry_colors),palette_4bpp_compatible=len(barry_colors)<=15,
    notes=['El atuendo es el de Platinum. Se conserva esta fuente individual además de la hoja general.',
           'El retrato alto no cabe en 80×80 sin pérdida; preservar a tamaño original.'],
    extras=[dict(kind='back',name='back',source='entrenadores/47490.png',
                 frames=[describe('47490',[2+82*c,138,80,80]) for c in range(5)]),
            dict(kind='portrait',name='retrato_original',source='entrenadores/47490.png',
                 frames=[describe('47490',[2,302,64,128])]),
            dict(kind='ow',name='ow_original',source='entrenadores/47490.png',
                 frames=[describe('47490',[2+34*c,2+34*r,32,32]) for r in range(4) for c in range(4)],
                 notes=['Filas sur,norte,oeste,este. Cuatro poses por fila; orden físico sin reinterpretar.'])]))


def main():
    ids=[e['id'] for e in ENTRIES]
    assert len(ids)==len(set(ids))
    # Catch unaccounted source cells and overlapping assignments.
    expected={'18524': [12]*5+[9,7]+[12]*3+[8,12,6,12,6],
              '28037': [12]*6+[10,8]+[12]*5+[6,9,12,6]}
    for source,counts in expected.items():
        actual=[tuple(f['rect']) for e in ENTRIES if e['source']==f'entrenadores/{source}.png'
                for f in e['frames']]
        normal=[(1+81*c,18+98*r,80,80) for r,n in enumerate(counts) for c in range(n)]
        unused=[(1+81*c,1504 if source=='18524' else 1700,80,80)
                for c in range(4 if source=='18524' else 10)]
        assert len(actual)==len(set(actual)), source
        assert set(actual)==set(normal+unused), (source,set(normal+unused)-set(actual))
    by_hash={}
    for entry in ENTRIES:
        key=tuple(f['normalized_rgb_sha256'] for f in entry['frames'])
        if key in by_hash: entry['exact_front_duplicate_of']=by_hash[key]
        else: by_hash[key]=entry['id']
    problematic=[e['id'] for e in ENTRIES if not e['palette_4bpp_compatible']]
    result=dict(schema_version=1,
        source_metadata=[
            dict(source='entrenadores/18524.png',game='platinum',dimensions=[973,1602],
                 credit_on_sheet='Ripped by MufasaKong. No credits needed.',
                 front_cell_size=[80,80],grid_origin=[1,18],grid_stride=[81,98],unused_row_y=1504),
            dict(source='entrenadores/28037.png',game='hgss',dimensions=[973,1798],
                 credit_on_sheet='Ripped by MufasaKong. No credits needed.',
                 front_cell_size=[80,80],grid_origin=[1,18],grid_stride=[81,98],unused_row_y=1700),
            dict(source='entrenadores/47490.png',game='platinum',dimensions=[412,432],
                 credit_on_sheet='Ripped by redblueyellow.',
                 front_cell_size=[80,80],front_origin=[2,220],front_stride=[82,0])],
        extraction='80×80 cells, exact foreground RGB retained; replace only the documented sheet-background color with magenta index 0.',
        frame_order='Left-to-right poses from source. Timings/order beyond this cannot be recovered from a static spritesheet.',
        naming_references=[
            'https://raw.githubusercontent.com/pret/pokeplatinum/main/generated/trainer_classes.txt',
            'https://raw.githubusercontent.com/pret/pokeheartgold/master/include/constants/trainer_class.h'],
        entries=ENTRIES,
        summary=dict(entries=len(ENTRIES),front_frames=sum(len(e['frames']) for e in ENTRIES),
                     animated_entries=sum(e['animation_available'] for e in ENTRIES),
                     palette_incompatible_entries=problematic))
    (OUT/'fronts.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result['summary'],ensure_ascii=False,indent=2))


if __name__=='__main__': main()
