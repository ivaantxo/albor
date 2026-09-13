----------------------------------------------------------------------------
-- Modo GBA: el color, en 0-31.
--
-- Aseprite no tiene un modo de color de 5 bits ni forma de cambiar el rango de
-- sus deslizadores, y una extension tampoco puede anadirlo: la barra de color
-- es codigo nativo. Esto es lo mas parecido: una ventana que se queda abierta y
-- ensena SIEMPRE el color con el que estas pintando ahora mismo, en los valores
-- que existen de verdad en la consola.
--
-- Mientras la ventana esta abierta, el modo esta activo. Cerrarla lo apaga.
--
-- Que hace segun el tipo de sprite:
--
--   INDEXADO -lo que usa albor-. El pincel es un indice, no un color: mover un
--   deslizador cambia el COLOR DE ESA ENTRADA de la paleta, y el dibujo entero
--   se actualiza al momento. Es editar la paleta en 5 bits, que es el unico
--   sitio por donde se puede colar un color que la consola no sabe ensenar.
--
--   RGB. Los deslizadores mandan el color de pincel. Y si eliges un color por
--   otro lado -rueda, cuentagotas- que no existe en la consola, se corrige solo
--   al escalon mas cercano por abajo, que es lo que haria gbagfx despues.
--
-- Instalar: copiar a ~/Library/Application Support/Aseprite/scripts/ y luego
-- File > Scripts > Rescan scripts folder.
----------------------------------------------------------------------------

-- Los 32 valores de 8 bits con los que Aseprite deletrea cada nivel del GBA.
-- Es la misma cuenta que hace gbagfx al deshacer la conversion, asi que un
-- color puesto desde aqui llega a la ROM sin moverse ni un punto.
local REJILLA = {}
for v5 = 0, 31 do REJILLA[v5] = math.floor(v5 * 255 / 31) end

local function a5bits(v)
    local q = math.floor(v / 8)
    if q > 31 then q = 31 end
    return q
end

local function de5bits(v5) return REJILLA[v5] end

-- Corregir o repintar dispara otra vez el aviso de cambio de color. Esta
-- bandera corta la vuelta; y aunque se escapara no habria bucle, porque ajustar
-- un color ya ajustado lo deja igual.
local ocupado = false
local aviso

local dlg = Dialog{
    title = "Color GBA (0-31)",
    onclose = function()
        if aviso then app.events:off(aviso) end
    end,
}

local function esIndexado()
    return app.sprite ~= nil and app.sprite.colorMode == ColorMode.INDEXED
end

local function colorDeSliders(alfa)
    return Color{
        r = de5bits(dlg.data.r),
        g = de5bits(dlg.data.g),
        b = de5bits(dlg.data.b),
        a = alfa or 255,
    }
end

-- Vuelca en los deslizadores el color con el que se esta pintando.
local function leeColorActivo()
    local c = app.fgColor
    dlg:modify{ id = "r", value = a5bits(c.red) }
    dlg:modify{ id = "g", value = a5bits(c.green) }
    dlg:modify{ id = "b", value = a5bits(c.blue) }
    dlg:modify{ id = "muestra", color = Color{
        r = de5bits(a5bits(c.red)),
        g = de5bits(a5bits(c.green)),
        b = de5bits(a5bits(c.blue)),
        a = 255 } }
end

-- El color de pincel ha cambiado: por la barra, por el cuentagotas, por otro
-- script. En RGB se corrige si no existe en la consola; en indexado no se toca,
-- que ahi el pincel es un indice y cambiarlo saltaria a otra entrada.
local function alCambiarColor()
    if ocupado then return end
    if not esIndexado() then
        local c = app.fgColor
        local r, g, b = de5bits(a5bits(c.red)), de5bits(a5bits(c.green)), de5bits(a5bits(c.blue))
        if r ~= c.red or g ~= c.green or b ~= c.blue then
            ocupado = true
            app.fgColor = Color{ r = r, g = g, b = b, a = c.alpha }
            ocupado = false
        end
    end
    leeColorActivo()
end

-- Se ha movido un deslizador.
local function alMover()
    ocupado = true

    if esIndexado() then
        -- Las entradas marcadas en la barra de paleta, o la del propio pincel.
        local destinos = app.range.colors
        if #destinos == 0 then destinos = { app.fgColor.index } end

        local pal = app.sprite.palettes[1]
        app.transaction(function()
            for _, i in ipairs(destinos) do
                local anterior = pal:getColor(i)
                pal:setColor(i, colorDeSliders(anterior.alpha))
            end
        end)
        app.refresh()
    else
        app.fgColor = colorDeSliders(app.fgColor.alpha)
    end

    dlg:modify{ id = "muestra", color = colorDeSliders() }
    ocupado = false
end

dlg:slider{ id = "r", label = "R", min = 0, max = 31, value = 31, onchange = alMover }
dlg:newrow()
dlg:slider{ id = "g", label = "G", min = 0, max = 31, value = 31, onchange = alMover }
dlg:newrow()
dlg:slider{ id = "b", label = "B", min = 0, max = 31, value = 31, onchange = alMover }
dlg:color{ id = "muestra", label = "", color = Color{ r = 255, g = 255, b = 255 } }

aviso = app.events:on("fgcolorchange", alCambiarColor)

leeColorActivo()
dlg:show{ wait = false }
