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
	memcpy(stream + offset, &(new_pokemon->posicion->posicionX), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, &(new_pokemon->posicion->posicionY), sizeof(uint32_t));
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
	memcpy(new_pokemon->nombre, stream, new_pokemon->tamanio_nombre);
	stream += (new_pokemon->tamanio_nombre);
	memcpy(&(new_pokemon->posicion->posicionX), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	memcpy(&(new_pokemon->posicion->posicionY), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	memcpy(&(new_pokemon->cantidad), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);

	return new_pokemon;
}

t_buffer* localized_pokemon_to_buffer(t_localized_pokemon* localized_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	//tam_nombre y cant posiciones, nombre, posiciones
	buffer->size = sizeof(uint32_t) * 2
			+ localized_pokemon->tamanio_nombre
			+ (sizeof(uint32_t) * 2) * localized_pokemon->cantidad;

	void* stream = malloc(buffer->size);
	int offset = 0;

	memcpy(stream + offset, &(localized_pokemon->tamanio_nombre), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, localized_pokemon->nombre, localized_pokemon->tamanio_nombre);
	offset += localized_pokemon->tamanio_nombre;
	memcpy(stream + offset, &(localized_pokemon->cantidad), sizeof(uint32_t));
	offset += sizeof(uint32_t);

	//Por cada posicion segun la cantidad, hago memcpy de x e y.
	for(int i = 0 ; i < localized_pokemon->cantidad ; i++){
		memcpy(stream + offset, *(localized_pokemon->posiciones + i)->posicionX, sizeof(uint32_t));
		offset += sizeof(uint32_t);
		memcpy(stream + offset, *(localized_pokemon->posiciones + i)->posicionY, sizeof(uint32_t));
		offset += sizeof(uint32_t);
	}

	buffer->stream = stream;

	return buffer;
}

t_localized_pokemon* localized_pokemon_from_buffer(t_buffer* buffer){
	t_localized_pokemon* localized_pokemon = malloc( sizeof(t_localized_pokemon) );

	void* stream = buffer->stream;

	memcpy(&(localized_pokemon->tamanio_nombre), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	localized_pokemon->nombre = malloc(localized_pokemon->tamanio_nombre);
	memcpy(localized_pokemon->nombre, stream, localized_pokemon->tamanio_nombre);
	stream += localized_pokemon->tamanio_nombre;
	memcpy(&(localized_pokemon->cantidad), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);

	localized_pokemon->posiciones = malloc(sizeof(t_posicion) * localized_pokemon->cantidad);
	for(int i = 0 ; i < localized_pokemon->cantidad ; i++){
		memcpy(*(localized_pokemon->posiciones + i)->posicionX, stream, sizeof(uint32_t));
		stream += sizeof(uint32_t);
		memcpy(*(localized_pokemon->posiciones + i)->posicionY, stream, sizeof(uint32_t));
		stream += sizeof(uint32_t);
	}

	return localized_pokemon;
}

t_buffer* get_pokemon_to_buffer(t_get_pokemon* get_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer->size = sizeof(uint32_t) + get_pokemon->tamanio_nombre;

	void* stream = malloc(buffer->size);
	int offset = 0;

	memcpy(stream + offset, &(get_pokemon->tamanio_nombre), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, get_pokemon->nombre, get_pokemon->tamanio_nombre);
	offset += get_pokemon->tamanio_nombre;

	buffer->stream = stream;

	return buffer;
}

t_get_pokemon* get_pokemon_from_buffer(t_buffer* buffer){
	t_get_pokemon* get_pokemon = malloc( sizeof(t_get_pokemon) );
	void* stream = buffer->stream;

	memcpy(&(get_pokemon->tamanio_nombre), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	get_pokemon->nombre = malloc(get_pokemon->tamanio_nombre);
	memcpy(get_pokemon->nombre, stream, get_pokemon->tamanio_nombre);
	stream += get_pokemon->tamanio_nombre;

	return get_pokemon;
}

t_buffer* appeared_pokemon_to_buffer(t_appeared_pokemon* appeared_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer->size = sizeof(uint32_t) * 3 + appeared_pokemon->tamanio_nombre;

	void* stream = malloc(buffer->size);
	int offset = 0;

	memcpy(stream + offset, &(appeared_pokemon->tamanio_nombre), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, appeared_pokemon->nombre, appeared_pokemon->tamanio_nombre);
	offset += appeared_pokemon->tamanio_nombre;
	memcpy(stream + offset, &(appeared_pokemon->posicion->posicionX), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, &(appeared_pokemon->posicion->posicionY), sizeof(uint32_t));
	offset += sizeof(uint32_t);

	buffer->stream = stream;

	return buffer;
}

t_appeared_pokemon* appeared_pokemon_from_buffer(t_buffer* buffer){
	t_appeared_pokemon* appeared_pokemon = malloc( sizeof(t_appeared_pokemon) );
	void* stream = buffer->stream;

	memcpy(&(appeared_pokemon->tamanio_nombre), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	appeared_pokemon->nombre = malloc(appeared_pokemon->tamanio_nombre);
	memcpy(appeared_pokemon->nombre, stream, appeared_pokemon->tamanio_nombre);
	stream += appeared_pokemon->tamanio_nombre;
	memcpy(&(appeared_pokemon->posicion->posicionX), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);
	memcpy(&(appeared_pokemon->posicion->posicionY), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);

	return appeared_pokemon;
}

t_buffer* catch_pokemon_to_buffer(t_catch_pokemon* catch_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	return buffer;
}

t_catch_pokemon* catch_pokemon_from_buffer(t_buffer* buffer){
	t_catch_pokemon* catch_pokemon = malloc( sizeof(t_catch_pokemon) );
	return catch_pokemon;
}

t_buffer* caught_pokemon_to_buffer(t_caught_pokemon* caught_pokemon){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer->size = sizeof(uint32_t);

	void* stream = malloc(buffer->size);
	int offset = 0;
	memcpy(stream + offset, &(caught_pokemon->atrapado), sizeof(uint32_t));
	offset += sizeof(uint32_t);

	buffer->stream = stream;

	return buffer;
}

t_caught_pokemon* caught_pokemon_from_buffer(t_buffer* buffer){
	t_caught_pokemon* caught_pokemon = malloc( sizeof(t_caught_pokemon) );
	void* stream = buffer->stream;

	memcpy(&(caught_pokemon->atrapado), stream, sizeof(uint32_t));
	stream += sizeof(uint32_t);

	return caught_pokemon;
}

char* mensaje_from_buffer(t_buffer* buffer){
	char* mensaje;
	return mensaje;
}



