#ifndef GET_POKEMON_H
#define GET_POKEMON_H

#include "mensajes.h"

typedef struct{
    uint32_t tamanio_nombre;
    char* nombre;
} t_get_pokemon;

t_get_pokemon* get_pokemon_create(char* nombre);
op_code get_pokemon_codigo(t_get_pokemon* get_pokemon);
t_buffer* get_pokemon_to_buffer(t_get_pokemon* get_pokemon);
t_get_pokemon* get_pokemon_from_buffer(t_buffer* buffer);
void get_pokemon_mostrar(t_get_pokemon* get_pokemon);
void get_pokemon_destroy(t_get_pokemon* get_pokemon);

#endif
