----------------------------------------------------------------------------
-- Ajusta la paleta a los colores que el GBA ensena DE VERDAD.
--
-- La consola guarda cada canal en 5 bits: 32 niveles, no 256. gbagfx baja el
-- valor truncando -v/8- y lo vuelve a subir con (v*255)/31, asi que de los 256
-- valores que ofrece Aseprite solo 32 llegan intactos a la pantalla. Los demas
-- se caen al escalon de abajo, siempre hacia el lado oscuro y hasta 7 puntos.
--
-- Este script mueve cada color al escalon exacto. A partir de ahi lo que ves
-- aqui es lo que sale en la consola, y la conversion del repo ya no toca nada.
--
-- Tambien avisa de lo que no se ve venir: dos colores distintos que caen en el
-- MISMO escalon. La paleta sigue teniendo 16 entradas pero la consola solo
-- ensena 15 colores, y el degradado que dependia de esa diferencia se aplana.
--
-- El indice 0 se ajusta como los demas a proposito: en albor no es solo el
-- transparente, en las especies con .pla es un color real que el sistema de
-- brillo mezcla de noche.
--
-- Instalar: copiar a la carpeta de scripts de Aseprite
--   ~/Library/Application Support/Aseprite/scripts/
-- y luego File > Scripts > Rescan scripts folder.
----------------------------------------------------------------------------

-- Los 32 valores de 8 bits que sobreviven al viaje, que son los mismos que
-- gbagfx escribe en los PNG del repo al deshacer la conversion.
local REJILLA = {}
for v5 = 0, 31 do REJILLA[v5] = math.floor(v5 * 255 / 31) end

local function a5bits(v)
    local q = math.floor(v / 8)
    if q > 31 then q = 31 end
    return q
end

local function ajusta(v) return REJILLA[a5bits(v)] end

local function clave5(c)
    return a5bits(c.red) .. "," .. a5bits(c.green) .. "," .. a5bits(c.blue)
end

local spr = app.sprite or app.activeSprite
if not spr then
    if app.isUIAvailable then app.alert("No hay ningun sprite abierto.") end
    return
end

local pal = spr.palettes[1]
local numColores = #pal

-- Que cambia y que se funde con que.
local cambian = 0
local porEscalon = {}
for i = 0, numColores - 1 do
    local c = pal:getColor(i)
    if ajusta(c.red) ~= c.red or ajusta(c.green) ~= c.green or ajusta(c.blue) ~= c.blue then
        cambian = cambian + 1
    end
    local k = clave5(c)
    porEscalon[k] = porEscalon[k] or {}
    table.insert(porEscalon[k], i)
end

-- Colision solo si los colores de ORIGEN eran distintos: dos entradas que ya
-- eran iguales antes no pierden nada al convertirse.
local colisiones = {}
for _, indices in pairs(porEscalon) do
    if #indices > 1 then
        local distintos = {}
        for _, i in ipairs(indices) do
            local c = pal:getColor(i)
            distintos[c.red .. "," .. c.green .. "," .. c.blue] = true
        end
        local cuantos = 0
        for _ in pairs(distintos) do cuantos = cuantos + 1 end
        if cuantos > 1 then table.insert(colisiones, indices) end
    end
end

local informe = {
    "Paleta de " .. numColores .. " colores.",
    "Fuera de la rejilla del GBA: " .. cambian .. ".",
}
if #colisiones > 0 then
    table.insert(informe, "")
    table.insert(informe, "AVISO: " .. #colisiones .. " grupo(s) de colores distintos")
    table.insert(informe, "acaban siendo el MISMO color en la consola:")
    for _, indices in ipairs(colisiones) do
        table.insert(informe, "   indices " .. table.concat(indices, ", "))
    end
    table.insert(informe, "Separalos a mano si te importa esa diferencia.")
end

local function aplica()
    app.transaction(function()
        for i = 0, numColores - 1 do
            local c = pal:getColor(i)
            pal:setColor(i, Color{
                r = ajusta(c.red),
                g = ajusta(c.green),
                b = ajusta(c.blue),
                a = c.alpha,
            })
        end

        -- En modo RGB la paleta es solo la barra de colores: lo que se ve son
        -- los pixeles, y hay que ajustarlos uno a uno. En modo indexado NO se
        -- tocan: los indices ya apuntan a la paleta recien ajustada.
        if spr.colorMode == ColorMode.RGB then
            for _, cel in ipairs(spr.cels) do
                local img = cel.image
                for it in img:pixels() do
                    local px = it()
                    local a = app.pixelColor.rgbaA(px)
                    if a > 0 then
                        it(app.pixelColor.rgba(
                            ajusta(app.pixelColor.rgbaR(px)),
                            ajusta(app.pixelColor.rgbaG(px)),
                            ajusta(app.pixelColor.rgbaB(px)),
                            a))
                    end
                end
            end
        end
    end)
    app.refresh()
end

if app.isUIAvailable then
    local dlg = Dialog("Ajustar paleta al GBA")
    for _, linea in ipairs(informe) do
        dlg:label{ text = linea }
        dlg:newrow()
    end
    dlg:separator()
    dlg:button{ id = "ajustar", text = "Ajustar", focus = true }
    dlg:button{ id = "cancelar", text = "Dejarlo" }
    dlg:show()
    if dlg.data.ajustar then
        aplica()
        app.alert("Paleta ajustada. Un solo paso de deshacer.")
    end
else
    for _, linea in ipairs(informe) do print(linea) end
    aplica()
    print("Paleta ajustada.")
end
