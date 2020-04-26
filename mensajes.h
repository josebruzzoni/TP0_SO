#ifndef MENSAJES_H
#define MENSAJES_H

typedef enum
{
	NEW_POKEMON,
    LOCALIZED_POKEMON,
    GET_POKEMON,
    APPEARED_POKEMON,
    CATCH_POKEMON,
    CAUGHT_POKEMON,
    MENSAJE
}op_code;

typedef struct{
	int size;
	void* stream;
} t_buffer;

typedef struct{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;

typedef struct{
    uint_32 tamanio_nombre;
    char* nombre;
    uint_32 posicionX;
    uint_32 posicionY;
    uint_32 cantidad;
} t_new_pokemon;

typedef struct{

} t_localized_pokemon;

typedef struct{
    uint_32 tamanio_nombre;
    char* nombre;
} t_get_pokemon;

typedef struct{
    uint_32 tamanio_nombre;
    char* nombre;
    uint_32 posicionX;
    uint_32 posicionY;
} t_appeared_pokemon;

typedef struct{
    uint_32 tamanio_nombre;
    char* nombre;
    uint_32 posicionX;
    uint_32 posicionY;
} t_catch_pokemon;

typedef struct{
    uint_32 atrapado;
} t_caught_pokemon;

t_buffer* mensaje_to_buffer(char* mensaje);
char* mensaje_from_buffer(t_buffer* buffer);

t_buffer* new_pokemon_to_buffer(t_new_pokemon* new_pokemon);
t_new_pokemon* new_pokemon_from_buffer(t_buffer* buffer);

t_buffer* localized_pokemon_to_buffer(t_localized_pokemon* localized_pokemon);
t_localized_pokemon* localized_pokemon_from_buffer(t_buffer* buffer);

t_buffer* get_pokemon_to_buffer(t_get_pokemon get_pokemon);
t_get_pokemon* get_pokemon_from_buffer(t_buffer* buffer);

t_buffer* appeared_pokemon_to_buffer(t_appeared_pokemon* appeared_pokemon);
t_appeared_pokemon* appeared_pokemon_from_buffer(t_buffer* buffer);

t_buffer* catch_pokemon_to_buffer(t_catch_pokemon* catch_pokemon);
t_catch_pokemon* catch_pokemon_from_buffer(t_buffer* buffer);

t_buffer* caught_pokemon_to_buffer(t_caught_pokemon* caught_pokemon);
t_caught_pokemon* caught_pokemon_from_buffer(t_buffer* buffer);

#endif 
