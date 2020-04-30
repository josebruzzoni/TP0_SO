#ifndef CAUGHT_POKEMON_H
#define CAUGHT_POKEMON_H

#include "mensajes.h"

typedef struct{
    uint32_t atrapado;
} t_caught_pokemon;

t_caught_pokemon* caught_pokemon_create(uint32_t fueAtrapado);
op_code caught_pokemon_codigo(t_caught_pokemon* caught_pokemon);
t_buffer* caught_pokemon_to_buffer(t_caught_pokemon* caught_pokemon);
t_caught_pokemon* caught_pokemon_from_buffer(t_buffer* buffer);
void caught_pokemon_mostrar(t_caught_pokemon* caught_pokemon);
void caught_pokemon_destroy(t_caught_pokemon* caught_pokemon);

#endif
