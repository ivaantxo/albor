const struct Ability gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
        .cantBeTraced = TRUE,
    },

    [ABILITY_LLOVIZNA] =
    {
        .name = _("Llovizna"),
        .description = COMPOUND_STRING("Summons rain in battle."),
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Speed Boost"),
        .description = COMPOUND_STRING("Gradually boosts Speed."),
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Battle Armor"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Damp"),
        .description = COMPOUND_STRING("Prevents self-destruction."),
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Limber"),
        .description = COMPOUND_STRING("Prevents paralysis."),
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Velo arena"),
        .description = COMPOUND_STRING("Sube evasión en Arena."),
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Static"),
        .description = COMPOUND_STRING("Paralyzes on contact."),
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Volt Absorb"),
        .description = COMPOUND_STRING("Turns electricity into HP."),
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Water Absorb"),
        .description = COMPOUND_STRING("Changes water into HP."),
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Oblivious"),
        .description = COMPOUND_STRING("Prevents attraction."),
        .breakable = TRUE,
    },

    [ABILITY_SEPTIMO_CIELO] =
    {
        .name = _("Cloud Nine"),
        .description = COMPOUND_STRING("Negates weather effects."),
    },

    [ABILITY_OJO_COMPUESTO] =
    {
        .name = _("Ojo compuesto"),
        .description = COMPOUND_STRING("+25% precisión."),
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .breakable = TRUE,
    },

    [ABILITY_CAMUFLAJE] =
    {
        .name = _("Camuflaje"),
        .description = COMPOUND_STRING("Cambia tipo antes de defender."),
        .breakable = TRUE,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Immunity"),
        .description = COMPOUND_STRING("Prevents poisoning."),
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Flash Fire"),
        .description = COMPOUND_STRING("Powers up if hit by fire."),
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Polvo escudo"),
        .description = COMPOUND_STRING("Previene efectos secundarios."),
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Own Tempo"),
        .description = COMPOUND_STRING("Prevents confusion."),
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Suction Cups"),
        .description = COMPOUND_STRING("Firmly anchors the body."),
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidación"),
        .description = COMPOUND_STRING("Baja el ataque rival."),
    },

    [ABILITY_MAL_AURA] =
    {
        .name = _("Mal aura"),
        .description = COMPOUND_STRING("Baja ataque especial rival."),
    },

    [ABILITY_ASPECTO_ENGANIOSO] =
    {
        .name = _("Aspecto engañoso"),
        .description = COMPOUND_STRING("Baja la defensa rival."),
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Shadow Tag"),
        .description = COMPOUND_STRING("Prevents the foe's escape."),
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Piel tosca"),
        .description = COMPOUND_STRING("Daña 6,25% al contacto."),
    },

    [ABILITY_RENCOR] =
    {
        .name = _("Rencor"),
        .description = COMPOUND_STRING("Daña 6,25% al ser herido."),
    },

    [ABILITY_GUARDA] =
    {
        .name = _("Guarda"),
        .description = COMPOUND_STRING("Resiste golpes neutros."),
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Levitación"),
        .description = COMPOUND_STRING("Inmunidad a Tierra."),
        .breakable = TRUE,
    },

    [ABILITY_PSICODELICO] =
    {
        .name = _("Psicodélico"),
        .description = COMPOUND_STRING("50% de causar estado aleatorio."),
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchronize"),
        .description = COMPOUND_STRING("Passes on status problems."),
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Clear Body"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Natural Cure"),
        .description = COMPOUND_STRING("Heals upon switching out."),
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Lightning Rod"),
        .description = COMPOUND_STRING("Draws electrical moves."),
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Dicha"),
        .description = COMPOUND_STRING("x2% efectos secundarios."),
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Nado rápido"),
        .description = COMPOUND_STRING("+2 velocidad en lluvia."),
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Clorofila"),
        .description = COMPOUND_STRING("+2 velocidad en Sol."),
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Iluminación"),
        .description = COMPOUND_STRING("Resiste fantasma y siniestro."),
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Trace"),
        .description = COMPOUND_STRING("Copies special ability."),
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Punto tóxico"),
        .description = COMPOUND_STRING("50% de envenenar si contacto def."),
    },

    [ABILITY_FUERZA_MENTAL] =
    {
        .name = _("Fuerza mental"),
        .description = COMPOUND_STRING("Prevents flinching."),
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Magma Armor"),
        .description = COMPOUND_STRING("Prevents freezing."),
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Water Veil"),
        .description = COMPOUND_STRING("Prevents burns."),
        .breakable = TRUE,
    },

    [ABILITY_IMAN] =
    {
        .name = _("Imán"),
        .description = COMPOUND_STRING("Atrapa Pokémon de Acero."),
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Insonorizar"),
        .description = COMPOUND_STRING("Inmune a sonido."),
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Rain Dish"),
        .description = COMPOUND_STRING("Recupera 1/8 PS en lluvia."),
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sand Stream"),
        .description = COMPOUND_STRING("Summons a sandstorm."),
    },

    [ABILITY_SEBO] =
    {
        .name = _("Sebo"),
        .description = COMPOUND_STRING("Resiste hielo y fuego."),
        .breakable = TRUE,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Cuerpo llama"),
        .description = COMPOUND_STRING("50% de quemar si contacto."),
    },

    [ABILITY_HUIDIZO] =
    {
        .name = _("Huidizo"),
        .description = COMPOUND_STRING("+1 prioridad cambio."),
    },

    [ABILITY_VISTA_LINCE] =
    {
        .name = _("Vista lince"),
        .description = COMPOUND_STRING("+25% precisión."),
    },

    [ABILITY_ENTUSIASMO] =
    {
        .name = _("Entusiasmo"),
        .description = COMPOUND_STRING("-12,5% precisión, +50% potencia."),
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Gran encanto"),
        .description = COMPOUND_STRING("50% de enamorar si contacto."),
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING("Powers up with Minus."),
    },

    [ABILITY_MINUS] =
    {
        .name = _("Minus"),
        .description = COMPOUND_STRING("Powers up with Plus."),
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Forecast"), // Darle + 1 de prioridad a movimientos climáticos (Set weather y movimientos como Heat Wave, Hurricane, Weather ball)
        .description = COMPOUND_STRING("Changes with the weather."),
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Sticky Hold"),
        .description = COMPOUND_STRING("Prevents item theft."),
        .breakable = TRUE,
    },

    [ABILITY_MUDAR] =
    {
        .name = _("Mudar"),
        .description = COMPOUND_STRING("Heals the body by shedding."),
    },

    [ABILITY_AGALLAS] =
    {
        .name = _("Agallas"),
        .description = COMPOUND_STRING("Sube ataques 50% si estado."),
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Marvel Scale"),
        .description = COMPOUND_STRING("Ups Defense if suffering."),
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Liquid Ooze"),
        .description = COMPOUND_STRING("Draining causes injury."),
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Blaze"),
        .description = COMPOUND_STRING("Ups Fire moves in a pinch."),
    },

    [ABILITY_SWARM] =
    {
        .name = _("Swarm"),
        .description = COMPOUND_STRING("Ups Bug moves in a pinch."),
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Cabeza roca"),
        .description = COMPOUND_STRING("No daño de retroceso."),
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Drought"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Arena Trap"),
        .description = COMPOUND_STRING("Prevents fleeing."),
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Vital Spirit"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("White Smoke"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .breakable = TRUE,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Shell Armor"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .breakable = TRUE,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Tangled Feet"),
        .description = COMPOUND_STRING("Ups evasion if confused."),
        .breakable = TRUE,
    },

    [ABILITY_ESQUIVO] =
    {
        .name = _("Esquivo"),
        .description = COMPOUND_STRING("Ataques recibidos tienen -2 de precisión."),
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Electromotor"),
        .description = COMPOUND_STRING("Eléctrico sube +2 vel."),
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalidad"),
        .description = COMPOUND_STRING("Mismo género +25%."),
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Manto níveo"),
        .description = COMPOUND_STRING("+25% evasión en nieve."),
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gula"),
        .description = COMPOUND_STRING("Come bayas 50% PS."),
    },

    [ABILITY_SOBREMESA] =
    {
        .name = _("Sobremesa"),
        .description = COMPOUND_STRING("Sube ataque tras comer baya."),
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Irascible"),
        .description = COMPOUND_STRING("+6 At. si crítico."),
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Unburden"),
        .description = COMPOUND_STRING("Using a hold item ups Speed."),
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simple"),
        .description = COMPOUND_STRING("Prone to wild stat changes."),
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Download"),
        .description = COMPOUND_STRING("Adjusts power favorably."),
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Iron Fist"),
        .description = COMPOUND_STRING("Boosts punching moves."),
    },

    [ABILITY_PATADA_FEROZ] =
    {
        .name = _("Patada Feroz"),
        .description = COMPOUND_STRING("Patada +25%."),
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Poison Heal"),
        .description = COMPOUND_STRING("Restores HP if poisoned."),
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Encadenado"),
        .description = COMPOUND_STRING("Multigolpes siempre 5."),
    },

    [ABILITY_ENJAMBRE] =
    {
        .name = _("Enjambre"),
        .description = COMPOUND_STRING("Multigolpes siempre 5."),
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydration"),
        .description = COMPOUND_STRING("Cures status in rain."),
    },

    [ABILITY_PODER_SOLAR] =
    {
        .name = _("Poder solar"),
        .description = COMPOUND_STRING("+25% de potencia en sol."),
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Quick Feet"),
        .description = COMPOUND_STRING("Ups Speed if suffering."),
    },

    [ABILITY_NORMALIDAD] =
    {
        .name = _("Normalidad"),
        .description = COMPOUND_STRING("Normal +25%."),
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Francotirador"),
        .description = COMPOUND_STRING("Críticos +50% de daño."),
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Magic Guard"),
        .description = COMPOUND_STRING("Only damaged by attacks."),
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Technician"),
        .description = COMPOUND_STRING("Boosts weaker moves."),
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Rompemoldes"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Afortunado"),
        .description = COMPOUND_STRING("+2 índice crítico."),
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Resquicio"),
        .description = COMPOUND_STRING("Fainting damages the foe."),
    },

    [ABILITY_CROMOLENTE] =
    {
        .name = _("Cromolente"),
        .description = COMPOUND_STRING("Pega x1 en vez de poco efectivo."),
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Scrappy"),
        .description = COMPOUND_STRING("Hits Ghost-type Pokémon."),
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Storm Drain"),
        .description = COMPOUND_STRING("Draws in Water moves."),
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Gélido"),
        .description = COMPOUND_STRING("Recupera 1/8 PS en nieve."),
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Solid Rock"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .breakable = TRUE,
    },

    [ABILITY_NEVADA] =
    {
        .name = _("Nevada"),
        .description = COMPOUND_STRING("Summons snow in battle."),
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Honey Gather"),
        .description = COMPOUND_STRING("May gather Honey."),
    },

    [ABILITY_RUTA_AEREA] =
    {
        .name = _("Ruta aérea"),
        .description = COMPOUND_STRING("+25% volador."),
    },

    [ABILITY_DESPENSA] =
    {
        .name = _("Despensa"),
        .description = COMPOUND_STRING("Recupera 1/16 PS por turno."),
    },

    [ABILITY_AUDAZ] =
    {
        .name = _("Audaz"),
        .description = COMPOUND_STRING("Boosts moves with recoil."),
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Bad Dreams"),
        .description = COMPOUND_STRING("Damages sleeping Pokémon."),
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Pickpocket"),
        .description = COMPOUND_STRING("Steals the foe's held item."),
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Sheer Force"),
        .description = COMPOUND_STRING("Trades effects for power."),
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Unnerve"),
        .description = COMPOUND_STRING("Foes can't eat Berries."),
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Competitivo"),
        .description = COMPOUND_STRING("+2 At. si bajan estadísticas."),
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Cuerpo maldito"),
        .description = COMPOUND_STRING("50% de anular ataque recibido."),
    },

    [ABILITY_HEALER] =
    {
        .name = _("Healer"),
        .description = COMPOUND_STRING("Heals partner Pokémon."),
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Weak Armor"),
        .description = COMPOUND_STRING("Its stats change when hit."),
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiscale"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Toxic Boost"),
        .description = COMPOUND_STRING("Ups Attack if poisoned."),
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Flare Boost"),
        .description = COMPOUND_STRING("Ups Sp. Atk if burned."),
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Harvest"),
        .description = COMPOUND_STRING("May recycle a used Berry."),
    },

    [ABILITY_TELEPATA] =
    {
        .name = _("Telépata"),
        .description = COMPOUND_STRING("Evita daño de aliado."),
        .breakable = TRUE,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Overcoat"),
        .description = COMPOUND_STRING("Blocks weather and powder."),
        .breakable = TRUE,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Regeneración"),
        .description = COMPOUND_STRING("Cura 1/3 al cambiar."),
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Sand Rush"),
        .description = COMPOUND_STRING("Ups Speed in a sandstorm."),
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analítico"),
        .description = COMPOUND_STRING("Potencia 50% si ataca después."),
    },

    [ABILITY_AGRESIVIDAD] =
    {
        .name = _("Agresividad"),
        .description = COMPOUND_STRING("Potencia 50% si ataca después."),
    },

    [ABILITY_PACIENTE] =
    {
        .name = _("Paciente"),
        .description = COMPOUND_STRING("Potencia 50% si ataca después."),
    },

    [ABILITY_SIGILOSO] =
    {
        .name = _("Sigiloso"),
        .description = COMPOUND_STRING("Golpea a través de barreras y ."),
    },

    [ABILITY_AUTOESTIMA] =
    {
        .name = _("Autoestima"),
        .description = COMPOUND_STRING("KOs suben ataque."),
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Justiciero"),
        .description = COMPOUND_STRING("Dragón/Sin./Fant. suben ataque."),
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Cobardía"),
        .description = COMPOUND_STRING("Bicho/Sin./Fant. +1 vel."),
    },

    [ABILITY_ESPEJO_MAGICO] =
    {
        .name = _("Espejo mágico"),
        .description = COMPOUND_STRING("Reflects status moves."),
        .breakable = TRUE,
    },

    [ABILITY_CAZATESOROS] =
    {
        .name = _("Cazatesoros"),
        .description = COMPOUND_STRING("Cambia objetos al entrar."),
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Sap Sipper"),
        .description = COMPOUND_STRING("Grass increases Attack."),
        .breakable = TRUE,
    },

    [ABILITY_BROMISTA] =
    {
        .name = _("Bromista"),
        .description = COMPOUND_STRING("Status moves go first."),
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Sand Force"),
        .description = COMPOUND_STRING("Powers up in a sandstorm."),
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Puntiagudo"),
        .description = COMPOUND_STRING("Daña 6,25% al contacto."),
    },

    [ABILITY_MUTATIPO] =
    {
        .name = _("Mutatipo"),
        .description = COMPOUND_STRING("Changes type to used move."),
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Bulletproof"),
        .description = COMPOUND_STRING("Avoids some projectiles."),
    },

    [ABILITY_RESPONDON] =
    {
        .name = _("Respondón"),
        .description = COMPOUND_STRING("Inverts stat changes."),
        .breakable = TRUE,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitive"),
        .description = COMPOUND_STRING("Lowered stats up Sp. Atk."),
    },

    [ABILITY_MANDIBULA_FUERTE] =
    {
        .name = _("Mandíbula fuerte"),
        .description = COMPOUND_STRING("+25% mordiscos."),
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Refrigerate"),
        .description = COMPOUND_STRING("Normal moves become Ice."),
    },

    [ABILITY_ALAS_VENDAVAL] =
    {
        .name = _("Alas vendaval"),
        .description = COMPOUND_STRING("Volador +1 prioridad."),
    },

    [ABILITY_ZUMBANDO] =
    {
        .name = _("Zumbando"),
        .description = COMPOUND_STRING("Bicho +1 prioridad."),
    },

    [ABILITY_MEGADISPARADOR] =
    {
        .name = _("Megadisparador"),
        .description = COMPOUND_STRING("+25% balísticos."),
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Pixilate"),
        .description = COMPOUND_STRING("Normal moves become Fairy."),
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Gooey"),
        .description = COMPOUND_STRING("Lowers Speed on contact."),
    },

    [ABILITY_CELESTE] =
    {
        .name = _("Celeste"),
        .description = COMPOUND_STRING("Volador +25%."),
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Parental Bond"),
        .description = COMPOUND_STRING("Moves hit twice."),
    },

    [ABILITY_STAMINA] =
    {
        .name = _("Stamina"),
        .description = COMPOUND_STRING("Boosts Defense when hit."),
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("Water Compaction"),
        .description = COMPOUND_STRING("Water boosts Defense."),
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("Merciless"),
        .description = COMPOUND_STRING("Criticals poisoned foes."),
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Steelworker"),
        .description = COMPOUND_STRING("Powers up Steel moves."),
    },

    [ABILITY_COLERA] =
    {
        .name = _("Cólera"),
        .description = COMPOUND_STRING("+1 At. esp. si PS -50%."),
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Quitanieves"),
        .description = COMPOUND_STRING("x2 Velocidad en granizo."),
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Remoto"),
        .description = COMPOUND_STRING("No hace contacto."),
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Liquid Voice"),
        .description = COMPOUND_STRING("Makes sound moves Water."),
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Triage"),
        .description = COMPOUND_STRING("Healing moves go first."),
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanize"),
        .description = COMPOUND_STRING("Normal moves turn Electric."),
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Corrosión"),
        .description = COMPOUND_STRING("Veneno x2 contra acero."),
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("Queenly Majesty"),
        .description = COMPOUND_STRING("Protects from priority."),
        .breakable = TRUE,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Battery"),
        .description = COMPOUND_STRING("Boosts ally's Sp. Atk."),
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Fluffy"),
        .description = COMPOUND_STRING("Tougher but flammable."),
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Dazzling"),
        .description = COMPOUND_STRING("Protects from priority."),
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Soul-Heart"),
        .description = COMPOUND_STRING("KOs raise Sp. Atk."),
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Rizos rebeldes"),
        .description = COMPOUND_STRING("Baja velocidad al contacto."),
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receiver"),
        .description = COMPOUND_STRING("Copies ally's ability."),
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Power Of Alchemy"),
        .description = COMPOUND_STRING("Copies ally's ability."),
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Beast Boost"),
        .description = COMPOUND_STRING("KOs boost best stat."),
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Cotton Down"),
        .description = COMPOUND_STRING("Lower Speed of all when hit."),
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Propeller Tail"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Mirror Armor"),
        .description = COMPOUND_STRING("Reflect stat decreases."),
        .breakable = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("Stalwart"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Steam Engine"),
        .description = COMPOUND_STRING("Fire or Water hits up Speed."),
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .description = COMPOUND_STRING("Ups and resists sound."),
        .breakable = TRUE,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Ice Scales"),
        .description = COMPOUND_STRING("Halves special damage."),
        .breakable = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Power Spot"),
        .description = COMPOUND_STRING("Powers up ally moves."),
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Screen Cleaner"),
        .description = COMPOUND_STRING("Removes walls of light."),
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Steely Spirit"),
        .description = COMPOUND_STRING("Boosts ally's Steel moves."),
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Gorilla Tactics"),
        .description = COMPOUND_STRING("Ups Attack and locks move."),
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Neutralizing Gas"),
        .description = COMPOUND_STRING("All Abilities are nullified."),
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = COMPOUND_STRING("Ups Electric-type moves."),
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("Dragon's Maw"),
        .description = COMPOUND_STRING("Ups Dragon-type moves."),
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Wind Rider"),
        .description = COMPOUND_STRING("Ups Attack if hit by wind."),
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Guard Dog"),
        .description = COMPOUND_STRING("Cannot be intimidated."),
        .breakable = TRUE,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Wind Power"),
        .description = COMPOUND_STRING("Gets charged by wind."),
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("Electromorphosis"),
        .description = COMPOUND_STRING("Gets Charged when hit."),
    },

    [ABILITY_EXUVIA] =
    {
        .name = _("Exuvia"),
        .description = COMPOUND_STRING("Inmune a ataques de estado."),
        .breakable = TRUE,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Cud Chew"),
        .description = COMPOUND_STRING("Eats a used berry again."),
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Cortante"),
        .description = COMPOUND_STRING("Cortantes +25%."),
    },

    [ABILITY_OLOR_FLUVIAL] =
    {
        .name = _("Olor fluvial"),
        .description = COMPOUND_STRING("+25% evasión si llueve."),
        .breakable = TRUE,
    },

    [ABILITY_DISPARO_CERTERO] =
    {
        .name = _("Disparo certero"),
        .description = COMPOUND_STRING("+2 índice crítico."),
    },

    [ABILITY_ATAQUE_RELAMPAGO] =
    {
        .name = _("Ataque relámpago"),
        .description = COMPOUND_STRING("+1 prioridad balísticos."),
    },

    [ABILITY_ALAS_HIDROFOBAS] =
    {
        .name = _("Alas hidrófobas"),
        .description = COMPOUND_STRING("+1 velocidad si recibe agua."), // + Nado rápido
        .breakable = TRUE,
    },

    [ABILITY_BELLO_PLUMAJE] =
    {
        .name = _("Bello plumaje"),
        .description = COMPOUND_STRING("Protege de prioridad."),
        .breakable = TRUE,
    },

    [ABILITY_OJOS_PRESTOS] =
    {
        .name = _("Ojos prestos"),
        .description = COMPOUND_STRING("+1 prioridad miradas."),
    },

    [ABILITY_CARA_DURA] =
    {
        .name = _("Cara dura"),
        .description = COMPOUND_STRING("+1 prioridad cabezazos."),
    },

    [ABILITY_PESTE_BUBONICA] =
    {
        .name = _("Peste bubónica"),
        .description = COMPOUND_STRING("Mordiscos 50% de envenenar."),
    },

    [ABILITY_AGUJA_ENVENENADA] =
    {
        .name = _("Aguja envenenada"),
        .description = COMPOUND_STRING("Punzantes 50% de envenenar."),
    },

    [ABILITY_AVE_RAPAZ] =
    {
        .name = _("Ave rapaz"),
        .description = COMPOUND_STRING("Volador x2 a Normal."),
    },

    [ABILITY_CARPINTERO] =
    {
        .name = _("Carpintero"),
        .description = COMPOUND_STRING("Punzantes +25%."),
    },

    [ABILITY_SURFERO] =
    {
        .name = _("Surfero"),
        .description = COMPOUND_STRING("Agua +25%."),
    },

    [ABILITY_GENERADOR] =
    {
        .name = _("Generador"),
        .description = COMPOUND_STRING("+25% Eléctricos de equipo."),
    },

    [ABILITY_SUENO_ELECTRICO] =
    {
        .name = _("Sueño eléctrico"),
        .description = COMPOUND_STRING("Paraliza si atacan dormido."),
    },

    [ABILITY_VOZ_HELADA] =
    {
        .name = _("Voz helada"),
        .description = COMPOUND_STRING("Sonido 50% de helar."),
    },

    [ABILITY_IRA_PRIMATE] =
    {
        .name = _("Ira primate"),
        .description = COMPOUND_STRING("+1 At. cada golpe recibido."),
    },

    [ABILITY_LUNA_MENGUANTE] =
    {
        .name = _("Luna menguante"),
        .description = COMPOUND_STRING("Siniestro +25%."),
    },

    [ABILITY_NUEVE_COLAS] =
    {
        .name = _("Nueve colas"),
        .description = COMPOUND_STRING("50% de maldecir al contacto."),
    },

    [ABILITY_VIDAS_PASADAS] =
    {
        .name = _("Vidas pasadas"),
        .description = COMPOUND_STRING("Fantasma +25%."),
    },

    [ABILITY_EXTRASENSORIAL] =
    {
        .name = _("Extrasensorial"),
        .description = COMPOUND_STRING("Psíquico +25%."),
    },

    [ABILITY_PARASITO] =
    {
        .name = _("Parásito"),
        .description = COMPOUND_STRING("50% de drenadoras al contacto."),
    },

    [ABILITY_TIERRA_HUMEDA] =
    {
        .name = _("Tierra húmeda"),
        .description = COMPOUND_STRING("Resiste fuego, inmune quemaduras."),
    },

    [ABILITY_HIBERNADOR] =
    {
        .name = _("Hibernador"),
        .description = COMPOUND_STRING("+50% evasión si duerme."),
        .breakable = TRUE,
    },

    [ABILITY_TERRITORIAL] =
    {
        .name = _("Territorial"),
        .description = COMPOUND_STRING("Impide que le quiten objeto."),
        .breakable = TRUE,
    },

    [ABILITY_HUMEDAD_RELATIVA] =
    {
        .name = _("Humedad relativa"),
        .description = COMPOUND_STRING("Beneficios de granizo en lluvia."),
    },

    [ABILITY_VOZ_CANTANTE] =
    {
        .name = _("Voz cantante"),
        .description = COMPOUND_STRING("+1 prioridad sonido."),
    },

    [ABILITY_PACIFISTA] =
    {
        .name = _("Pacifista"),
        .description = COMPOUND_STRING("Estado +1 prioridad."),
    },

    [ABILITY_GLOBO] =
    {
        .name = _("Globo"),
        .description = COMPOUND_STRING("+1 defensa si recibe viento."),
        .breakable = TRUE,
    },

    [ABILITY_VOZ_DULCE] =
    {
        .name = _("Voz dulce"),
        .description = COMPOUND_STRING("Sonido 50% de adormecer."),
    },

    [ABILITY_ULTRASONIDO] =
    {
        .name = _("Ultrasonido"),
        .description = COMPOUND_STRING("Sonido 50% de confundir."),
    },

    [ABILITY_CARNIVORO] =
    {
        .name = _("Carnívoro"),
        .description = COMPOUND_STRING("Recupera 1/3 de PS al vencer."),
    },

    [ABILITY_PERCUSIONISTA] =
    {
        .name = _("Percusionista"),
        .description = COMPOUND_STRING("Sonido +1 crítico + 25% pot."),
    },

    [ABILITY_MARTILLADOR] =
    {
        .name = _("Martillador"),
        .description = COMPOUND_STRING("Martillos +25%."),
    },

    [ABILITY_TIERRA_SUELTA] =
    {
        .name = _("Tierra suelta"),
        .description = COMPOUND_STRING("Tierra +1 prioridad ."),
    },

    [ABILITY_PUNZON] =
    {
        .name = _("Punzón"),
        .description = COMPOUND_STRING("Lanza púas al contacto."),
    },

    [ABILITY_IMPENETRABLE] =
    {
        .name = _("Impenetrable"),
        .description = COMPOUND_STRING("Ajusta defensas favorablemente."),
    },

    [ABILITY_RESERVA_NATURAL] =
    {
        .name = _("Reserva natural"),
        .description = COMPOUND_STRING("Ajusta defensas favorablemente."),
    },

    [ABILITY_DINOCOLA] =
    {
        .name = _("Dinocola"),
        .description = COMPOUND_STRING("Colas +25%."),
    },

    [ABILITY_CORNAMENTA] =
    {
        .name = _("Cornamenta"),
        .description = COMPOUND_STRING("Punzantes +25%."),
    },

    [ABILITY_NINJA] =
    {
        .name = _("Ninja"),
        .description = COMPOUND_STRING("No hace contacto."),
    },

    [ABILITY_FUNDICION] =
    {
        .name = _("Fundición"),
        .description = COMPOUND_STRING("Fuego x2 contra roca."),
    },

    [ABILITY_NAVAJAS] =
    {
        .name = _("Navajas"),
        .description = COMPOUND_STRING("+25% mordiscos."),
    },

    [ABILITY_BANO_BARRO] =
    {
        .name = _("Baño de barro"),
        .description = COMPOUND_STRING("+PS si recibe Tierra."),
        .breakable = TRUE,
    },

    [ABILITY_ESCALOFRIO] =
    {
        .name = _("Escalofrío"),
        .description = COMPOUND_STRING("+25% hielo."),
    },

    [ABILITY_CERO_ABSOLUTO] =
    {
        .name = _("Cero absoluto"),
        .description = COMPOUND_STRING("Inmune a fuego."),
        .breakable = TRUE,
    },

    [ABILITY_LENGUALARGA] =
    {
        .name = _("Lengualarga"),
        .description = COMPOUND_STRING("Lenguas +25%."),
    },

    [ABILITY_MATAMOSCAS] =
    {
        .name = _("Matamoscas"),
        .description = COMPOUND_STRING("Atrapa bichos y les pega x2 siempre."),
    },

    [ABILITY_ENVIO_EXPRESS] =
    {
        .name = _("Envío express"),
        .description = COMPOUND_STRING("Regalos +1 prioridad."),
    },

    [ABILITY_FOTOSINTESIS] =
    {
        .name = _("Fotosíntesis"),
        .description = COMPOUND_STRING("Recupera 1/8 PS en sol."),
    },

    [ABILITY_ARTES_OSCURAS] =
    {
        .name = _("Artes oscuras"),
        .description = COMPOUND_STRING("Siniestro +25%."),
    },

    [ABILITY_VENENOSO] =
    {
        .name = _("Venenoso"),
        .description = COMPOUND_STRING("Veneno +25%."),
    },

    [ABILITY_BAILARIN] =
    {
        .name = _("Bailarín"),
        .description = COMPOUND_STRING("+1 prioridad baile."),
    },

    [ABILITY_HAZLO_TRIPLE] =
    {
        .name = _("Hazlo triple"),
        .description = COMPOUND_STRING("Ataques dobles golpean 3 veces."),
    },

    [ABILITY_EN_METALICO] =
    {
        .name = _("En metálico"),
        .description = COMPOUND_STRING("Acero +25%."),
    },

    [ABILITY_TERRESTRE] =
    {
        .name = _("Terrestre"),
        .description = COMPOUND_STRING("Tierra +25%."),
    },

    [ABILITY_GUARDIAN] =
    {
        .name = _("Guardián"),
        .description = COMPOUND_STRING("Resiste siniestro/fantasma."),
        .breakable = TRUE,
    },

    [ABILITY_NOCTURNO] =
    {
        .name = _("Nocturno"),
        .description = COMPOUND_STRING("Siniestro +25%."),
    },

    [ABILITY_VAMPIRO] =
    {
        .name = _("Vampiro"),
        .description = COMPOUND_STRING("Recupera 1/3 de PS al vencer."),
    },

    [ABILITY_ADIVINO] =
    {
        .name = _("Adivino"),
        .description = COMPOUND_STRING("Inmune a prioridad."),
        .breakable = TRUE,
    },

    [ABILITY_SUPERORDENADOR] =
    {
        .name = _("Superordenador"),
        .description = COMPOUND_STRING("Psíquico +1 prioridad."),
    },

    [ABILITY_MAGO] =
    {
        .name = _("Mago"),
        .description = COMPOUND_STRING("Intercambia objeto al entrar."),
    },

    [ABILITY_HECHICERO] =
    {
        .name = _("Hechicero"),
        .description = COMPOUND_STRING("Psíquico 50% de quemar."),
    },

    [ABILITY_ALTO_VOLTAJE] =
    {
        .name = _("Alto voltaje"),
        .description = COMPOUND_STRING("Lucha 50% de paralizar."),
    },

    [ABILITY_CABLE_PELADO] =
    {
        .name = _("Cable pelado"),
        .description = COMPOUND_STRING("+1 At. si PS -50%."),
    },
};
