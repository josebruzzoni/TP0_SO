#include "catch_pokemon.h"

t_catch_pokemon* catch_pokemon_create(char* nombre, uint32_t posX, uint32_t posY){
	t_catch_pokemon* catch_pokemon = malloc( sizeof(t_catch_pokemon) );
	catch_pokemon->nombre = nombre;
	catch_pokemon->posicion.posicionX = posX;
	catch_pokemon->posicion.posicionY = posY;
	catch_pokemon->tamanio_nombre = strlen(nombre) + 1;
	return catch_pokemon;
}

t_buffer* catch_pokemon_to_buffer(t_catch_pokemon* catch_pokemon){
	t_buffer* buffer;
	return buffer;
}
t_catch_pokemon* catch_pokemon_from_buffer(t_buffer* buffer){
	t_catch_pokemon* catch_pokemon;
	return catch_pokemon;
}
void catch_pokemon_mostrar(t_catch_pokemon* catch_pokemon){
	printf("Mensaje - Catch Pokemon:\n");
	printf("Nombre: %s\n",catch_pokemon->nombre);
	printf("Tamanio del nombre: %d\n",catch_pokemon->tamanio_nombre);
	printf("Posicion x: %d\n",catch_pokemon->posicion.posicionX);
	printf("Posicion y: %d\n",catch_pokemon->posicion.posicionY);
	puts("------------");
}
void catch_pokemon_destroy(t_catch_pokemon* catch_pokemon){
	free(catch_pokemon);
}
