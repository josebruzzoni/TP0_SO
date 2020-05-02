#ifndef NEW_POKEMON_H
#define NEW_POKEMON_H

#include "mensajes.h"
#include "posiciones.h"

typedef struct{
    uint32_t tamanio_nombre;
    char* nombre;
    t_posicion posicion;
    uint32_t cantidad;
} t_new_pokemon;

t_new_pokemon* new_pokemon_create(char* nombre, uint32_t posX, uint32_t posY, uint32_t cantidad);
op_code new_pokemon_codigo(t_new_pokemon* new_pokemon);
t_buffer* new_pokemon_to_buffer(t_new_pokemon* new_pokemon);
t_new_pokemon* new_pokemon_from_buffer(t_buffer* buffer);
void new_pokemon_mostrar(t_new_pokemon* new_pokemon);
void new_pokemon_destroy(t_new_pokemon* new_pokemon);

#endif
