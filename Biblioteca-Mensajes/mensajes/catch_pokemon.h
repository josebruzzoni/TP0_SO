#ifndef CATCH_POKEMON_H
#define CATCH_POKEMON_H

#include "mensajes.h"

typedef struct{
    uint32_t tamanio_nombre;
    char* nombre;
    t_posicion posicion;
} t_catch_pokemon;

t_catch_pokemon* catch_pokemon_create(char* nombre, uint32_t posX, uint32_t posY);
op_code catch_pokemon_codigo(t_catch_pokemon* catch_pokemon);
t_buffer* catch_pokemon_to_buffer(t_catch_pokemon* catch_pokemon);
t_catch_pokemon* catch_pokemon_from_buffer(t_buffer* buffer);
void catch_pokemon_mostrar(t_catch_pokemon* catch_pokemon);
void catch_pokemon_destroy(t_catch_pokemon* catch_pokemon);

#endif
