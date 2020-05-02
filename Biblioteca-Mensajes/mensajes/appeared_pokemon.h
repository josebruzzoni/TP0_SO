#ifndef APPEARED_POKEMON_H
#define APPEARED_POKEMON_H

#include "mensajes.h"
#include "posiciones.h"

typedef struct{
    uint32_t tamanio_nombre;
    char* nombre;
    t_posicion posicion;
} t_appeared_pokemon;

t_appeared_pokemon* appeared_pokemon_create(char* nombre, uint32_t posX, uint32_t posY);
op_code appeared_pokemon_codigo(t_appeared_pokemon* appeared_pokemon);
t_buffer* appeared_pokemon_to_buffer(t_appeared_pokemon* appeared_pokemon);
t_appeared_pokemon* appeared_pokemon_from_buffer(t_buffer* buffer);
void appeared_pokemon_mostrar(t_appeared_pokemon* appeared_pokemon);
void appeared_pokemon_destroy(t_appeared_pokemon* appeared_pokemon);

#endif
