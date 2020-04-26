#include "mensajes.h"

t_buffer* mensaje_to_buffer(char* mensaje){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer->size = strlen(mensaje) + 1;
	buffer->stream = mensaje;
	return buffer;
}

t_buffer* new_pokemon_to_buffer(t_new_pokemon* new_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	return buffer;
}

t_buffer* localized_pokemon_to_buffer(t_localized_pokemon* localized_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	return buffer;
}

t_buffer* get_pokemon_to_buffer(t_get_pokemon* get_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	return buffer;
}

t_buffer* appeared_pokemon_to_buffer(t_appeared_pokemon* appeared_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	return buffer;
}

t_buffer* catch_pokemon_to_buffer(t_catch_pokemon* catch_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	return buffer;
}

t_buffer* caught_pokemon_to_buffer(t_caught_pokemon* caught_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	return buffer;
}

char* mensaje_from_buffer(t_buffer* buffer){
	char* mensaje;
	return mensaje;
}

t_new_pokemon* new_pokemon_from_buffer(t_buffer* buffer){
	t_new_pokemon* new_pokemon = malloc( sizeof(t_new_pokemon) );
	return new_pokemon;
}

t_localized_pokemon* localized_pokemon_from_buffer(t_buffer* buffer){
	t_localized_pokemon* localized_pokemon = malloc( sizeof(t_localized_pokemon) );
	return localized_pokemon;
}

t_get_pokemon* get_pokemon_from_buffer(t_buffer* buffer){
	t_get_pokemon* get_pokemon = malloc( sizeof(t_get_pokemon) );
	return get_pokemon;
}

t_appeared_pokemon* appeared_pokemon_from_buffer(t_buffer* buffer){
	t_appeared_pokemon* appeared_pokemon = malloc( sizeof(t_appeared_pokemon) );
	return appeared_pokemon;
}

t_catch_pokemon* catch_pokemon_from_buffer(t_buffer* buffer){
	t_catch_pokemon* catch_pokemon = malloc( sizeof(t_catch_pokemon) );
	return catch_pokemon;
}

t_caught_pokemon* caught_pokemon_from_buffer(t_buffer* buffer){
	t_caught_pokemon* caught_pokemon = malloc( sizeof(t_caught_pokemon) );
	return caught_pokemon;
}
