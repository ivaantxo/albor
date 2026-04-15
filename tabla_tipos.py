import re

# --- CONFIGURACIÓN DE ARCHIVOS ---
INPUT_FILE = "tabla_tipos.txt"
OUTPUT_FILE = "ranking_tipos.html"

# --- CONFIGURACIÓN DE PUNTOS ---
# Ofensivo
PUNTOS_OFF_SUPER = 1
PUNTOS_OFF_POCO = -1
PUNTOS_OFF_INMUNE = -2

# Defensivo
PUNTOS_DEF_RESISTE = 1
PUNTOS_DEF_INMUNE = 2
PUNTOS_DEF_DEBIL = -1

TIPOS = [
    "Normal", "Lucha", "Volador", "Veneno", "Tierra", "Roca", "Bicho", 
    "Fantasma", "Acero", "Misterio", "Fuego", "Agua", "Planta", 
    "Eléctrico", "Psíquico", "Hielo", "Dragón", "Siniestro", "Hada"
]

def parse_table():
    matrix = []
    with open(INPUT_FILE, "r", encoding="utf-8") as f:
        content = f.read()
        
    # Buscamos las líneas que definen cada fila de la matriz [TIPO_...] = { ... }
    rows = re.findall(r"\[TIPO_[A-Z]+\]\s*=\s*\{(.*?)\}", content, re.DOTALL)
    
    for row in rows:
        # Limpiar y separar valores. Convertir ______ a 1.0 y X(2.0) a 2.0
        values = []
        raw_values = row.split(",")
        for val in raw_values:
            val = val.strip()
            if "______" in val:
                values.append(1.0)
            elif "X(" in val:
                num = re.search(r"X\((.*?)\)", val).group(1)
                values.append(float(num))
        if values:
            matrix.append(values)
    return matrix

def calculate_scores(matrix):
    rankings = []
    
    for i in range(len(TIPOS)):
        off_score = 0
        def_score = 0
        
        # Cálculo Ofensivo (Fila i)
        for j in range(len(matrix[i])):
            efectividad = matrix[i][j]
            if efectividad == 2.0: off_score += PUNTOS_OFF_SUPER
            elif efectividad == 0.5: off_score += PUNTOS_OFF_POCO
            elif efectividad == 0.0: off_score += PUNTOS_OFF_INMUNE
            
        # Cálculo Defensivo (Columna i)
        for j in range(len(matrix)):
            efectividad = matrix[j][i]
            if efectividad == 0.5: def_score += PUNTOS_DEF_RESISTE
            elif efectividad == 0.0: def_score += PUNTOS_DEF_INMUNE
            elif efectividad == 2.0: def_score += PUNTOS_DEF_DEBIL
            
        rankings.append({
            "tipo": TIPOS[i],
            "ofensivo": off_score,
            "defensivo": def_score,
            "total": off_score + def_score
        })
    
    # Ordenar por Total de mayor a menor
    return sorted(rankings, key=lambda x: x['total'], reverse=True)

def generate_html(rankings):
    html = f"""
    <!DOCTYPE html>
    <html lang="es">
    <head>
        <meta charset="UTF-8">
        <title>Ranking de Tipos - Albor</title>
        <style>
            body {{ font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background: #f4f4f9; padding: 20px; }}
            table {{ width: 100%; border-collapse: collapse; background: white; border-radius: 8px; overflow: hidden; box-shadow: 0 4px 6px rgba(0,0,0,0.1); }}
            th, td {{ padding: 12px 15px; text-align: left; border-bottom: 1px solid #ddd; }}
            th {{ background-color: #2c3e50; color: white; cursor: pointer; }}
            tr:hover {{ background-color: #f1f1f1; }}
            .tipo {{ font-weight: bold; text-transform: uppercase; }}
            .pos {{ color: green; font-weight: bold; }}
            .neg {{ color: red; font-weight: bold; }}
            .total {{ background: #eef2f3; font-weight: bold; }}
        </style>
    </head>
    <body>
        <h2>Ranking de Tipos (Basado en gTablaEfectividadTipos)</h2>
        <p>Valores: Ofensivo (X2: +1, X0.5: -1, X0: -2) | Defensivo (Res: +1, Inm: +2, Deb: -1)</p>
        <table>
            <thead>
                <tr>
                    <th>Tipo</th>
                    <th>Puntos Ofensivos</th>
                    <th>Puntos Defensivos</th>
                    <th>Puntaje TOTAL</th>
                </tr>
            </thead>
            <tbody>
    """
    
    for r in rankings:
        html += f"""
            <tr>
                <td class="tipo">{r['tipo']}</td>
                <td class="{'pos' if r['ofensivo'] >= 0 else 'neg'}">{r['ofensivo']}</td>
                <td class="{'pos' if r['defensivo'] >= 0 else 'neg'}">{r['defensivo']}</td>
                <td class="total">{r['total']}</td>
            </tr>
        """
        
    html += """
            </tbody>
        </table>
    </body>
    </html>
    """
    
    with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
        f.write(html)

# Ejecución
try:
    matriz_datos = parse_table()
    resultados = calculate_scores(matriz_datos)
    generate_html(resultados)
    print(f"Éxito: Se ha generado '{OUTPUT_FILE}' correctamente.")
except Exception as e:
    print(f"Error al procesar: {e}")
