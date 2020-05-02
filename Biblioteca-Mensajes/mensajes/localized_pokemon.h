#ifndef LOCALIZED_POKEMON_H
#define LOCALIZED_POKEMON_H

#include "mensajes.h"
#include "posiciones.h"

typedef struct{
	uint32_t tamanio_nombre;
	char* nombre;
	uint32_t cantidadPos;
	t_posicion* posiciones;
} t_localized_pokemon;



t_localized_pokemon* localized_pokemon_create(char* nombre,uint32_t cantidadPos, t_posicion* posiciones);
op_code localized_pokemon_codigo(t_localized_pokemon* localized_pokemon);
t_buffer* localized_pokemon_to_buffer(t_localized_pokemon* localized_pokemon);
t_localized_pokemon* localized_pokemon_from_buffer(t_buffer* buffer);
void localized_pokemon_mostrar(t_localized_pokemon* localized_pokemon);
void localized_pokemon_destroy(t_localized_pokemon* localized_pokemon);

#endif
