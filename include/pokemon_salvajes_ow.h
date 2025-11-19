#ifndef GUARD_POKEMON_SALVAJES_OW_H
#define GUARD_POKEMON_SALVAJES_OW_H

struct PokemonSalvajeOw
{
    u8 idObjetoEvento;
    u8 nivel;
    u8 estado;
    u8 terreno;
    u16 especie;
    u16 temporizador;
    u32 personalidad;
    s16 x, y;
};

void IniciarPokemonSalvajesOw(void);
void ActualizarPokemonSalvajesOw(void);

#endif // GUARD_POKEMON_SALVAJES_OW_H
