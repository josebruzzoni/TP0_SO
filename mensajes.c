#include "mensajes.h"

t_buffer* mensaje_to_buffer(char* mensaje){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer->size = strlen(mensaje) + 1;
	buffer->stream = mensaje;
	return buffer;
}

t_buffer* new_pokemon_to_buffer(t_new_pokemon* new_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer->size = sizeof(uint32_t)*4 + new_pokemon->tamanio_nombre;

	void* stream = malloc(buffer->size);
	int offset = 0; // Desplazamiento

	memcpy(stream + offset, &(new_pokemon->tamanio_nombre), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, new_pokemon->nombre, new_pokemon->tamanio_nombre);
	offset += new_pokemon->tamanio_nombre;
	memcpy(stream + offset, &(new_pokemon->posicionX), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, &(new_pokemon->posicionY), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, &(new_pokemon->cantidad), sizeof(uint32_t));
	offset += sizeof(uint32_t);

	buffer->stream = stream;

	return buffer;
}


t_new_pokemon* new_pokemon_from_buffer(t_buffer* buffer){
	t_new_pokemon* new_pokemon = malloc( sizeof(t_new_pokemon));

	void* stream = buffer->stream;

	memcpy(&(new_pokemon->tamanio_nombre), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	new_pokemon->nombre = malloc(new_pokemon->tamanio_nombre);
	memcpy(&(new_pokemon->nombre), stream, new_pokemon->tamanio_nombre);

	stream += (new_pokemon->tamanio_nombre);
	memcpy(&(new_pokemon->posicionX), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	memcpy(&(new_pokemon->posicionY), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	memcpy(&(new_pokemon->cantidad), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);

	return new_pokemon;
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
