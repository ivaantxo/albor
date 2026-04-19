import re
import os

# CONFIGURACIÓN DE RUTAS
SPECIES_INFO_PATH = "src/data/pokemon/species_info.h"
ABILITIES_PATH = "src/data/abilities.h"
OUTPUT_FILE = "pokedex_privada.html"

# Mapeo de tipos según tu lista de "types :="
TYPE_MAP = {
    "NORMAL": "normal", "LUCHA": "fight", "VOLADOR": "flying", "VENENO": "poison",
    "TIERRA": "ground", "ROCA": "rock", "BICHO": "bug", "FANTASMA": "ghost",
    "ACERO": "steel", "FUEGO": "fire", "AGUA": "water",
    "PLANTA": "grass", "ELECTRICO": "electric", "PSIQUICO": "psychic",
    "HIELO": "ice", "DRAGON": "dragon", "SINIESTRO": "dark", "HADA": "fairy"
}

def clean_val(pattern, body):
    """Busca un valor numérico ignorando espacios: MACRO ( 123 )"""
    match = re.search(pattern, body, re.IGNORECASE | re.VERBOSE)
    return int(match.group(1)) if match else 0

def parse_abilities():
    abilities = {}
    if not os.path.exists(ABILITIES_PATH): return abilities
    with open(ABILITIES_PATH, 'r', encoding='utf-8') as f:
        content = f.read()
        blocks = re.findall(r'\[(ABILITY_\w+)\]\s*=\s*\{(.*?)\},', content, re.DOTALL)
        for ab_id, body in blocks:
            name = re.search(r'\.name\s*=\s*_\("([^"]+)"\)', body)
            desc = re.search(r'\.description\s*=\s*COMPOUND_STRING\("([^"]+)"\)', body)
            abilities[ab_id] = {
                "name": name.group(1) if name else ab_id,
                "desc": desc.group(1) if desc else ""
            }
    return abilities

def parse_species(abilities_map):
    pokemon_list = []
    if not os.path.exists(SPECIES_INFO_PATH): 
        print(f"Error: No se encuentra {SPECIES_INFO_PATH}")
        return []

    with open(SPECIES_INFO_PATH, 'r', encoding='utf-8') as f:
        content = f.read()
        # Buscamos bloques [SPECIES_...] = { ... }
        # Usamos un regex que capture todo hasta el cierre de la llave principal
        species_blocks = re.findall(r'\[(SPECIES_\w+)\]\s*=\s*\{(.*?)\n\s*\},', content, re.DOTALL)

        for spec_id, body in species_blocks:
            if "NOMBRE(??????????)" in body or spec_id == "SPECIES_NONE":
                continue
            
            # EXTRAER STATS (Usando \s* para ignorar espacios/tabs)
            hp = clean_val(r'PS\s*\(\s*(\d+)\s*\)', body)
            atk = clean_val(r'ATAQUE\s*\(\s*(\d+)\s*\)', body)
            df = clean_val(r'DEFENSA\s*\(\s*(\d+)\s*\)', body)
            spa = clean_val(r'ATAQUE_ESPECIAL\s*\(\s*(\d+)\s*\)', body)
            spd = clean_val(r'DEFENSA_ESPECIAL\s*\(\s*(\d+)\s*\)', body)
            spe = clean_val(r'VELOCIDAD\s*\(\s*(\d+)\s*\)', body)
            
            bst = hp + atk + df + spa + spd + spe
            
            # NOMBRE
            n_match = re.search(r'NOMBRE\s*\(\s*(.*?)\s*\)', body)
            name = n_match.group(1) if n_match else spec_id

            # TIPOS
            types = []
            # Intentar TIPOS(A, B) o TIPO(A)
            t_match = re.search(r'TIPOS?\s*\(\s*(\w+)(?:\s*,\s*(\w+))?\s*\)', body)
            if t_match:
                for i in range(1, 3):
                    t_name = t_match.group(i)
                    if t_name:
                        img = TYPE_MAP.get(t_name, t_name.lower())
                        types.append(f"graphics/types/{img}.png")

            # HABILIDADES
            h_match = re.search(r'HABILIDADES\s*\(\s*(\w+)\s*,\s*(\w+)\s*,\s*(\w+)\s*\)', body)
            pkm_abs = []
            if h_match:
                for i in range(1, 4):
                    ab_name = h_match.group(i)
                    if ab_name != "NONE":
                        info = abilities_map.get("ABILITY_" + ab_name, {"name": ab_name, "desc": ""})
                        pkm_abs.append(info)

            # RUTA SPRITE
            folder = spec_id.replace("SPECIES_", "").lower()
            sprite_path = f"graphics/pokemon/{folder}/anim_front.png"

            pokemon_list.append({
                "name": name, "hp": hp, "atk": atk, "def": df, "spa": spa, "spd": spd, "spe": spe,
                "bst": bst, "types": types, "abilities": pkm_abs, "sprite": sprite_path
            })
            
    return pokemon_list

def generate_html(pokemon_data):
    html_template = """
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <title>Pokedex Privada</title>
        <style>
            body { background: #1a1a1a; color: white; font-family: sans-serif; display: flex; flex-wrap: wrap; justify-content: center; padding: 20px; }
            .card { background: #252525; border: 1px solid #444; border-radius: 12px; width: 280px; margin: 10px; padding: 15px; box-shadow: 0 4px 10px rgba(0,0,0,0.3); }
            
            /* RECORTE DE SPRITE: Solo frame 1 (64x64 de arriba) */
            .sprite-box { 
                width: 64px; height: 64px; 
                overflow: hidden; 
                margin: 0 auto 10px; 
                background: #333; 
                border-radius: 6px;
                display: flex;
                align-items: flex-start;
            }
            .sprite-box img { 
                width: 64px; 
                height: auto; /* Debería ser 128px de alto */
                image-rendering: pixelated;
                display: block;
            }

            h2 { text-align: center; margin: 0; font-size: 1.4em; }
            .types-container { text-align: center; margin: 10px 0; height: 25px; }
            .type-icon { height: 22px; margin: 0 4px; }
            
            .stats-table { width: 100%; font-size: 13px; border-collapse: collapse; }
            .stats-table td { padding: 4px 0; }
            .bar-bg { background: #444; height: 8px; border-radius: 4px; width: 120px; }
            .bar-fill { height: 100%; border-radius: 4px; }
            
            .bst-row { font-weight: bold; color: #00e5ff; border-top: 2px solid #444; }
            .abilities { margin-top: 15px; padding-top: 10px; border-top: 1px dotted #555; }
            .ab-name { color: #ffcc00; font-weight: bold; font-size: 13px; display: block; }
            .ab-desc { color: #ccc; font-size: 11px; display: block; margin-bottom: 8px; }
        </style>
    </head>
    <body>
    """
    
    for p in pokemon_data:
        type_html = "".join([f'<img src="{t}" class="type-icon" onerror="this.style.display=\'none\'">' for t in p['types']])
        
        stats_data = [
            ("PS", p['hp'], "#ff5959"), ("ATK", p['atk'], "#f5ac78"), ("DEF", p['def'], "#fae078"),
            ("SPA", p['spa'], "#9db7f5"), ("SPD", p['spd'], "#a7db8d"), ("VEL", p['spe'], "#fa92b2")
        ]
        
        stats_rows = ""
        for label, val, color in stats_data:
            width = min(100, (val / 180) * 100)
            stats_rows += f"""
            <tr>
                <td>{label}</td>
                <td style="text-align:right; padding-right:8px;"><b>{val}</b></td>
                <td><div class="bar-bg"><div class="bar-fill" style="width:{width}%; background:{color}"></div></div></td>
            </tr>"""

        abs_html = "".join([f"<span class='ab-name'>{a['name']}</span><span class='ab-desc'>{a['desc']}</span>" for a in p['abilities']])

        html_template += f"""
        <div class="card">
            <div class="sprite-box">
                <img src="{p['sprite']}">
            </div>
            <h2>{p['name']}</h2>
            <div class="types-container">{type_html}</div>
            <table class="stats-table">
                {stats_rows}
                <tr class="bst-row">
                    <td>BST</td>
                    <td style="text-align:right; padding-right:8px;">{p['bst']}</td>
                    <td></td>
                </tr>
            </table>
            <div class="abilities">{abs_html}</div>
        </div>
        """

    html_template += "</body></html>"
    with open(OUTPUT_FILE, 'w', encoding='utf-8') as f:
        f.write(html_template)
    print(f"Completado. Se han procesado {len(pokemon_data)} Pokémon.")

if __name__ == "__main__":
    generate_html(parse_species(parse_abilities()))