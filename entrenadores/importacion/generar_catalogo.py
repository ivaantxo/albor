#!/usr/bin/env python3
"""Genera un catálogo HTML local: datos embebidos, sin servidor ni dependencias.

Ejecutar después de importar.py, o llamar generar() desde el importador.
Los gráficos se cargan mediante rutas relativas; abrir catalogo.html directamente.
"""
import argparse
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
FIELDS = (
    "id", "name", "game", "directory", "has_front", "has_ow",
    "front_frames", "ow_frames", "east_mirrored", "palette", "palette_rgb",
    "palette_origin", "missing", "ow_palette_conversion", "code", "originals",
    "extras", "animation",
)


def generar(catalogo=None, destino=None):
    """Lee catalogo.json y devuelve la ruta del HTML generado junto al catálogo."""
    source = Path(catalogo) if catalogo is not None else HERE / "catalogo.json"
    target = Path(destino) if destino is not None else source.with_suffix(".html")
    catalog = json.loads(source.read_text(encoding="utf-8"))
    data = {
        "counts": catalog.get("counts", {}),
        "entries": [{key: entry[key] for key in FIELDS if key in entry}
                    for entry in catalog["entries"]],
    }
    # Un nombre de la fuente nunca debe cerrar el bloque <script> del documento.
    payload = json.dumps(data, ensure_ascii=False, separators=(",", ":"))
    payload = payload.replace("&", "\\u0026").replace("<", "\\u003c").replace(">", "\\u003e")
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_text(HTML.replace("__CATALOGO_JSON__", payload), encoding="utf-8")
    return target


HTML = r'''<!doctype html>
<html lang="es">
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>Catálogo de entrenadores · Albor</title>
<style>
:root{color-scheme:light;--ink:#202c38;--muted:#596b7b;--line:#d7e0e7;--accent:#116353;--paper:#fff}
*{box-sizing:border-box}body{margin:0;background:#f2f5f7;color:var(--ink);font:15px/1.5 system-ui,sans-serif}
header{padding:24px 28px 20px;background:#142c35;color:#fff}header h1{font-size:25px;margin:0 0 5px}
header p{margin:0;color:#d3e2e7}.counts{display:flex;flex-wrap:wrap;gap:9px;margin-top:15px}
.count{border:1px solid #587078;border-radius:6px;padding:5px 10px;font-size:13px}
.layout{display:grid;grid-template-columns:290px minmax(0,1fr);gap:22px;max-width:1500px;margin:auto;padding:22px}
aside{align-self:start;position:sticky;top:16px}.panel{padding:18px;background:var(--paper);border:1px solid var(--line);border-radius:10px}
label{display:block;font-weight:600;margin-bottom:5px}input[type=search],select,button{font:inherit;border:1px solid #a7b8c5;border-radius:5px;background:#fff;color:var(--ink)}
input[type=search],select{width:100%;padding:8px}select[size]{margin-top:10px;padding:4px;height:350px}select[size] option{padding:6px}
button{padding:7px 12px;cursor:pointer}button:hover{border-color:var(--accent)}button:disabled{opacity:.45;cursor:default}
button[aria-pressed=true]{background:var(--accent);border-color:var(--accent);color:#fff}
input:focus-visible,select:focus-visible,button:focus-visible,a:focus-visible{outline:3px solid #dfb145;outline-offset:2px}
.field{margin-bottom:12px}.muted{color:var(--muted)}.small{font-size:13px}.nav{display:flex;gap:8px;margin-top:12px}.nav button{flex:1}
h2{font-size:24px;margin:0}h3{font-size:17px;margin:0 0 12px}h4{font-size:15px;margin:14px 0 5px}
.heading{display:flex;justify-content:space-between;gap:12px;align-items:flex-start;margin-bottom:16px}.slug{overflow-wrap:anywhere}
.tags{display:flex;flex-wrap:wrap;gap:6px;margin-top:8px}.tag{font-size:12px;padding:3px 8px;border-radius:4px;background:#e5f0ed;color:#205947}.tag.warning{background:#fff0ce;color:#755300}
.controls{display:flex;flex-wrap:wrap;align-items:center;gap:12px;margin:16px 0}.controls label{font-size:13px;font-weight:500;margin:0;display:flex;align-items:center;gap:6px}.controls select{width:auto;padding:6px}.directions{display:flex;flex-wrap:wrap;gap:5px}
.preview{display:grid;grid-template-columns:1.2fr 1fr 1fr;gap:14px}.preview article{min-width:0}.sprite-stage{min-height:200px;display:flex;align-items:center;justify-content:safe center;overflow:auto;padding:10px;background:#e9edf0;border-radius:6px}
canvas{image-rendering:pixelated;image-rendering:crisp-edges;flex:none;background-color:#fafafa;background-image:linear-gradient(45deg,#e1e5e8 25%,transparent 25%),linear-gradient(-45deg,#e1e5e8 25%,transparent 25%),linear-gradient(45deg,transparent 75%,#e1e5e8 75%),linear-gradient(-45deg,transparent 75%,#e1e5e8 75%);background-size:16px 16px;background-position:0 0,0 8px,8px -8px,-8px 0}
.preview article:first-child .sprite-stage{min-height:340px}.preview p{margin:7px 0}.sections{display:grid;gap:16px;margin-top:18px}.strip{display:flex;flex-wrap:wrap;gap:12px}.frame{margin:0;text-align:center;max-width:165px}.frame figcaption{font-size:12px;line-height:1.3;margin-top:4px}.frame.missing{outline:2px dashed #c18c21;outline-offset:3px}.palette{display:grid;grid-template-columns:repeat(8,minmax(35px,1fr));gap:8px;max-width:600px}.swatch{height:34px;border:1px solid #84909a;border-radius:3px}.color{text-align:center;font-size:12px}.color code{display:block;font-size:10px}.stats{display:flex;gap:18px;flex-wrap:wrap;margin:12px 0}.stats strong{display:block;font-size:19px}.stats span{font-size:12px;color:var(--muted)}
.links{display:flex;flex-wrap:wrap;gap:8px 16px}a{color:#075e73}pre{padding:12px;background:#f3f5f6;border-radius:6px;overflow:auto;font-size:12px}details{margin-top:12px}summary{cursor:pointer;font-weight:600}table{border-collapse:collapse;font-size:13px;width:100%;margin-top:10px}th,td{text-align:left;padding:7px;border-bottom:1px solid var(--line)}.table-scroll{overflow:auto}.chip{display:inline-block;width:15px;height:15px;border:1px solid #889;margin-right:5px;vertical-align:middle}ul{padding-left:22px}.notice{padding:12px;border-left:4px solid #bc8520;background:#fff5dc}.empty{padding:40px;text-align:center}.hidden,[hidden]{display:none!important}
@media(max-width:1100px){.preview{grid-template-columns:1fr 1fr}.preview article:first-child{grid-column:1/-1}.preview article:first-child .sprite-stage{min-height:200px}}
@media(max-width:700px){header{padding:20px}.layout{display:block;padding:12px}aside{position:static;margin-bottom:16px}select[size]{height:155px}.preview{grid-template-columns:1fr 1fr}.panel{padding:13px}.heading{display:block}h2{font-size:21px}.sprite-stage{min-height:150px;padding:4px}.palette{grid-template-columns:repeat(4,1fr)}}
</style>
<header><h1>Catálogo de entrenadores</h1><p>Fronts de 80×80 y overworlds de 32×32 · Albor</p><div class="counts" id="counts"></div></header>
<div class="layout">
<aside class="panel">
 <div class="field"><label for="search">Buscar entrenador o clase</label><input id="search" type="search" placeholder="Cynthia, pescador, hgss…" autocomplete="off"></div>
 <div class="field"><label for="filter">Mostrar</label><select id="filter"><option value="all">Todos</option><option value="pair">Front y OW identificados</option><option value="animated">Front con varias poses</option><option value="converted">OW con paleta adaptada</option><option value="missing">Con frames pendientes</option><option value="drawer">Cajón de sastre</option></select></div>
 <label for="entries">Entrenadores <span id="resultCount" class="muted small"></span></label><select id="entries" size="13" aria-label="Seleccionar entrenador"></select>
 <div class="nav"><button id="previous" type="button">← Anterior</button><button id="next" type="button">Siguiente →</button></div>
 <p class="small muted">Funciona sin conexión. Los archivos se leen directamente de sus carpetas; no necesita servidor.</p>
 <a href="INFORME.md">Informe de importación</a> · <a href="catalogo.json">Catálogo JSON</a>
</aside>
<main>
 <div id="empty" class="panel empty" hidden>No hay coincidencias con esta búsqueda.</div>
 <div id="detail">
 <section class="panel">
  <div class="heading"><div><h2 id="name"></h2><div id="identity" class="slug muted small"></div><div id="tags" class="tags"></div></div><a id="metadataTop" href="#">Metadatos ↗</a></div>
  <div class="controls"><button id="play" type="button" aria-pressed="true">Pausar animación</button><label for="zoom">Escala <select id="zoom"><option value="2">×2</option><option value="3">×3</option><option value="4" selected>×4</option><option value="6">×6</option></select></label><label><input id="walk" type="checkbox" checked> Caminar</label><div class="directions" aria-label="Dirección OW"><button data-direction="sur" aria-pressed="true">Sur</button><button data-direction="norte" aria-pressed="false">Norte</button><button data-direction="oeste" aria-pressed="false">Oeste</button><button data-direction="este" aria-pressed="false">Este</button></div></div>
  <div class="preview">
   <article><h3>Front</h3><div class="sprite-stage"><canvas id="frontCanvas" width="320" height="320" role="img" aria-label="Front del entrenador"></canvas></div><p id="frontCaption" class="small muted"></p><p id="frontStatus" class="small"></p></article>
   <article><h3>OW con paleta final</h3><div class="sprite-stage"><canvas id="owCanvas" width="128" height="128" role="img" aria-label="OW con paleta compartida"></canvas></div><p id="owCaption" class="small muted"></p><p id="owStatus" class="small"></p></article>
   <article><h3>OW original</h3><div class="sprite-stage"><canvas id="originalCanvas" width="128" height="128" role="img" aria-label="OW antes de adaptar la paleta"></canvas></div><p class="small muted">Misma pose y posición, antes de la conversión de paleta.</p><p id="originalStatus" class="small"></p></article>
  </div>
  <p class="small muted">Los fronts animados reproducen la secuencia propuesta de entrada y vuelven a la pose 0, con una pausa para comparar. Las hojas no contienen los tiempos originales. Los recuadros de cuadros grises representan transparencia.</p>
 </section>
 <div class="sections">
  <section class="panel"><h3>Todos los frames del front</h3><div id="frontStrip" class="strip"></div></section>
  <section class="panel"><h3>Todos los frames del OW</h3><p id="orderNote" class="small muted"></p><div id="owStrip" class="strip"></div></section>
  <section class="panel"><h3>Paleta compartida</h3><p id="paletteNote" class="small muted"></p><div id="palette" class="palette"></div><div id="conversionStats" class="stats"></div><details id="conversionDetails"><summary>Ver cambios de color del OW</summary><div class="table-scroll"><table><thead><tr><th>Original</th><th>Adaptado</th><th>Píxeles</th><th>ΔE76</th></tr></thead><tbody id="conversionRows"></tbody></table></div></details></section>
  <section class="panel"><h3>Frames pendientes</h3><div id="missing"></div></section>
  <section class="panel"><h3>Archivos e identificadores</h3><div id="files" class="links"></div><h4>Originales y extras conservados</h4><div id="originalFiles" class="links"></div><pre id="code"></pre></section>
 </div>
 </div>
</main>
</div>
<script id="catalog-data" type="application/json">__CATALOGO_JSON__</script>
<script>
'use strict';
const catalog = JSON.parse(document.getElementById('catalog-data').textContent);
const $ = id => document.getElementById(id);
const entries = [...catalog.entries].sort((a,b) => a.name.localeCompare(b.name,'es') || a.id.localeCompare(b.id));
const cache = new Map();
const state = {entry:null, images:{}, direction:'sur', playing:true, elapsed:0, previousTime:null, generation:0};
let filtered = [];
const labels = ['Sur · reposo','Sur · paso izquierda','Sur · paso derecha','Norte · reposo','Norte · paso izquierda','Norte · paso derecha','Oeste · reposo','Oeste · paso izquierda','Oeste · paso derecha','Este · reposo','Este · paso izquierda','Este · paso derecha'];
const number = value => Number(value || 0).toLocaleString('es-ES',{maximumFractionDigits:3});
const rgb = color => `rgb(${color.join(',')})`;
const hex = color => '#' + color.map(n => n.toString(16).padStart(2,'0')).join('');
const normalized = text => String(text || '').normalize('NFD').replace(/[\u0300-\u036f]/g,'').toLowerCase();
const path = (entry,file) => '../../' + entry.directory.split('/').map(encodeURIComponent).join('/') + '/' + file.split('/').map(encodeURIComponent).join('/');
function element(tag,text,className){const node=document.createElement(tag);if(text!==undefined)node.textContent=text;if(className)node.className=className;return node;}
function link(parent,label,url){const a=element('a',label);a.href=url;parent.append(a);}
function badge(text,warning=false){$('tags').append(element('span',text,'tag'+(warning?' warning':'')));}
function loadImage(url){
 if(!cache.has(url)) cache.set(url,new Promise(resolve=>{const img=new Image();img.onload=()=>resolve(img);img.onerror=()=>resolve(null);img.src=url;}));
 return cache.get(url);
}
function draw(canvas,img,size,frame,flip=false){
 const ctx=canvas.getContext('2d');ctx.clearRect(0,0,canvas.width,canvas.height);ctx.imageSmoothingEnabled=false;
 if(!img)return;
 const cols=Math.floor(img.naturalWidth/size);if(cols<1)return;
 const sx=(frame%cols)*size, sy=Math.floor(frame/cols)*size;
 if(sy+size>img.naturalHeight)return;
 ctx.save();if(flip){ctx.translate(canvas.width,0);ctx.scale(-1,1);}
 ctx.drawImage(img,sx,sy,size,size,0,0,canvas.width,canvas.height);ctx.restore();
}
function frontFrame(){
 const entry=state.entry;if(!entry || entry.front_frames<=1)return 0;
 const order=entry.animation?.order?.length?entry.animation.order:Array.from({length:entry.front_frames},(_,i)=>i);
 const ticks=entry.animation?.durations_ticks?.length===order.length?entry.animation.durations_ticks:order.map((_,i)=>i===order.length-1?24:12);
 const total=ticks.reduce((a,b)=>a+b,0)*1000/60;
 let time=state.elapsed%(total+1100);
 for(let i=0;i<order.length;i++){const duration=ticks[i]*1000/60;if(time<duration)return order[i];time-=duration;}
 return 0;
}
function owFrame(){
 const phase=$('walk').checked?[1,0,2,0][Math.floor(state.elapsed/(8*1000/60))%4]:0;
 const base={sur:0,norte:3,oeste:6,este:state.entry?.east_mirrored?6:9}[state.direction];
 return {frame:base+phase, flip:state.direction==='este' && Boolean(state.entry?.east_mirrored)};
}
function redraw(){
 if(!state.entry)return;
 const front=frontFrame(),ow=owFrame();
 draw($('frontCanvas'),state.images.front,80,front);
 draw($('owCanvas'),state.images.ow,32,ow.frame,ow.flip);
 draw($('originalCanvas'),state.images.original,32,ow.frame,ow.flip);
 $('frontCaption').textContent=`Frame ${front} · 80×80 · ${state.entry.front_frames} ${state.entry.front_frames===1?'pose':'poses'}`;
 $('owCaption').textContent=`Frame ${ow.frame} · ${state.direction}${ow.flip?' (oeste reflejado)':''} · 32×32`;
}
function resize(){const zoom=Number($('zoom').value);for(const [id,size] of [['frontCanvas',80],['owCanvas',32],['originalCanvas',32]]){$(id).width=size*zoom;$(id).height=size*zoom;}redraw();}
function buildStrip(id,img,size,count,type){
 const root=$(id);root.replaceChildren();
 for(let i=0;i<count;i++){
  const missing=state.entry.missing?.some(m=>m.grafico===type && m.frame===i);
  const figure=element('figure',undefined,'frame'+(missing?' missing':''));const canvas=element('canvas');canvas.width=canvas.height=size*2;
  canvas.setAttribute('role','img');canvas.setAttribute('aria-label',`${type} frame ${i}${missing?', transparente pendiente':''}`);draw(canvas,img,size,i);
  figure.append(canvas,element('figcaption',`${i} · ${type==='ow'?(labels[i]||'Pose adicional'):'Front'}${missing?' · pendiente':''}`));root.append(figure);
 }
}
function renderPalette(entry){
 $('palette').replaceChildren();(entry.palette_rgb||[]).forEach((c,i)=>{const box=element('div',undefined,'color'),swatch=element('div',undefined,'swatch');swatch.style.backgroundColor=rgb(c);box.append(swatch,element('span',i===0?'0 · transparente':String(i)),element('code',hex(c)));$('palette').append(box);});
 $('paletteNote').textContent=entry.has_front?'El front conserva sus colores. El OW usa los mismos índices; el índice 0 es magenta transparente.':'Paleta provisional del OW: todavía no hay un front identificado con el que compartirla.';
 const c=entry.ow_palette_conversion||{};$('conversionStats').replaceChildren();
 for(const [title,value] of [['Colores adaptados',c.colores_modificados],['Píxeles adaptados',c.pixeles_modificados],['ΔE76 medio',c.delta_e_medio],['ΔE76 máximo',c.delta_e_maximo]]){const box=element('div');box.append(element('strong',number(value)),element('span',title));$('conversionStats').append(box);}
 $('conversionDetails').hidden=!(c.conversiones?.length);$('conversionDetails').open=false;$('conversionRows').replaceChildren();
 for(const change of c.conversiones||[]){const row=element('tr');for(const key of ['original','adaptado']){const cell=element('td'),chip=element('span',undefined,'chip');chip.style.backgroundColor=rgb(change[key]);cell.append(chip,document.createTextNode(hex(change[key])));row.append(cell);}row.append(element('td',number(change.pixeles)),element('td',number(change.delta_e_76)));$('conversionRows').append(row);}
}
function renderMissing(entry){
 const root=$('missing');root.replaceChildren();
 if(!entry.missing?.length){root.append(element('p','No faltan frames en los gráficos importados.'));return;}
 root.append(element('p','Las celdas pendientes se conservan transparentes. No contienen dibujos de sustitución.','notice'));
 const list=element('ul');for(const m of entry.missing)list.append(element('li',`${m.grafico==='front'?'Front':'OW'} ${m.frame}${m.pose?' · '+m.pose.replaceAll('_',' '):''}: ${m.motivo}`));root.append(list);
}
function renderLinks(entry){
 const files=$('files');files.replaceChildren();for(const [label,file] of [['Front PNG','front.png'],['OW PNG','ow.png'],['Paleta',entry.palette||entry.id+'.pal'],['Metadatos','importacion.json']])link(files,label,path(entry,file));
 $('metadataTop').href=path(entry,'importacion.json');const originals=$('originalFiles');originals.replaceChildren();
 for(const file of entry.originals||[])link(originals,file,path(entry,file));
 for(const extra of entry.extras||[])link(originals,extra.archivo,path(entry,extra.archivo));
 if(!originals.childElementCount)originals.append(element('span','No hay extras para esta entrada.','muted small'));
 $('code').textContent=Object.entries(entry.code||{}).map(([key,value])=>`${key}: ${value||'pendiente de identificación'}`).join('\n');
}
function updateNavigation(){const index=filtered.findIndex(e=>e.id===state.entry?.id);$('previous').disabled=index<=0;$('next').disabled=index<0||index>=filtered.length-1;}
async function selectEntry(id){
 const entry=entries.find(e=>e.id===id);if(!entry)return;
 const generation=++state.generation;state.entry=entry;state.images={};state.elapsed=0;$('entries').value=id;
 $('name').textContent=entry.name;$('identity').textContent=`${entry.game} · ${entry.id}`;$('tags').replaceChildren();
 badge(entry.has_front?'Front identificado':'Front pendiente',!entry.has_front);badge(entry.has_ow?'OW identificado':'OW pendiente',!entry.has_ow);
 if(entry.front_frames>1)badge(`${entry.front_frames} poses de front`);if(entry.ow_palette_conversion?.colores_modificados)badge('OW con paleta adaptada');if(entry.missing?.length)badge(`${entry.missing.length} frames pendientes`,true);
 $('frontStatus').textContent='Cargando gráfico…';$('owStatus').textContent='Cargando gráfico…';$('originalStatus').textContent=entry.has_ow?'Cargando original…':'No se ha identificado un OW.';
 $('orderNote').textContent=entry.east_mirrored?'Orden físico: sur 0–2, norte 3–5, oeste 6–8. El este se obtiene reflejando el oeste.':'Orden físico: sur 0–2, norte 3–5, oeste 6–8, este 9–11. El este conserva sus propios dibujos.';
 renderPalette(entry);renderMissing(entry);renderLinks(entry);updateNavigation();redraw();
 buildStrip('frontStrip',null,80,entry.front_frames,'front');buildStrip('owStrip',null,32,entry.ow_frames,'ow');
 const [front,ow,original]=await Promise.all([loadImage(path(entry,'front.png')),loadImage(path(entry,'ow.png')),entry.has_ow?loadImage(path(entry,'originales/ow.png')):Promise.resolve(null)]);
 if(generation!==state.generation)return;
 state.images={front,ow,original};state.elapsed=0;
 $('frontStatus').textContent=!front?'No se pudo cargar front.png.':entry.has_front?'Colores originales conservados.':'Front transparente: no identificado.';
 $('owStatus').textContent=!ow?'No se pudo cargar ow.png.':entry.has_ow?(entry.has_front?'Paleta final compartida.':'Paleta provisional del OW.'):'OW transparente: no identificado.';
 $('originalStatus').textContent=entry.has_ow?(original?'Colores anteriores a la conversión.':'No se pudo cargar originales/ow.png.'):'No se ha identificado un OW.';
 buildStrip('frontStrip',front,80,entry.front_frames,'front');buildStrip('owStrip',ow,32,entry.ow_frames,'ow');redraw();
}
function applyFilter(){
 const query=normalized($('search').value),filter=$('filter').value;
 filtered=entries.filter(e=>normalized(`${e.name} ${e.id} ${e.game}`).includes(query)).filter(e=>filter==='pair'?e.has_front&&e.has_ow:filter==='animated'?e.front_frames>1:filter==='converted'?e.ow_palette_conversion?.colores_modificados:filter==='missing'?e.missing?.length:filter==='drawer'?!e.has_front:true);
 $('entries').replaceChildren();for(const e of filtered){const option=element('option',`${e.name} · ${e.game} · ${e.id}`);option.value=e.id;option.title=e.id;$('entries').append(option);}
 $('resultCount').textContent=`(${filtered.length}/${entries.length})`;$('empty').hidden=filtered.length!==0;$('detail').hidden=filtered.length===0;
 if(!filtered.length){state.generation++;state.entry=null;updateNavigation();return;}
 const id=filtered.some(e=>e.id===state.entry?.id)?state.entry.id:filtered[0].id;
 if(state.entry?.id===id){$('entries').value=id;updateNavigation();}else selectEntry(id);
}
for(const [label,key] of [['carpetas','carpetas'],['fronts','fronts'],['OW','ow'],['parejas','parejas'],['fronts animados','fronts_con_animacion']])if(catalog.counts[key]!==undefined)$('counts').append(element('span',`${number(catalog.counts[key])} ${label}`,'count'));
$('search').addEventListener('input',applyFilter);$('filter').addEventListener('change',applyFilter);$('entries').addEventListener('change',()=>selectEntry($('entries').value));
for(const [id,step] of [['previous',-1],['next',1]])$(id).addEventListener('click',()=>{const index=filtered.findIndex(e=>e.id===state.entry?.id);const entry=filtered[index+step];if(entry)selectEntry(entry.id);});
$('zoom').addEventListener('change',resize);$('walk').addEventListener('change',redraw);
$('play').addEventListener('click',()=>{state.playing=!state.playing;$('play').textContent=state.playing?'Pausar animación':'Reanudar animación';$('play').setAttribute('aria-pressed',String(state.playing));});
for(const button of document.querySelectorAll('[data-direction]'))button.addEventListener('click',()=>{state.direction=button.dataset.direction;for(const other of document.querySelectorAll('[data-direction]'))other.setAttribute('aria-pressed',String(other===button));redraw();});
function tick(now){if(state.previousTime!==null && state.playing && state.entry)state.elapsed+=Math.min(now-state.previousTime,100);state.previousTime=now;if(state.playing)redraw();requestAnimationFrame(tick);}
applyFilter();resize();requestAnimationFrame(tick);
</script>
</html>
'''


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--catalogo", type=Path, default=HERE / "catalogo.json")
    parser.add_argument("--destino", type=Path)
    args = parser.parse_args()
    print(generar(args.catalogo, args.destino))
