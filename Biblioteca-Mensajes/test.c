#include "new_pokemon.h"
#include "get_pokemon.h"
#include "appeared_pokemon.h"
#include "catch_pokemon.h"
#include "caught_pokemon.h"
#include "localized_pokemon.h"

/*
void probarMensaje(){
	char mensaje_inicial[] = "estoy probando un mensaje";
	t_buffer* buffer = mensaje_to_buffer(mensaje_inicial);
	char* mensaje_final = mensaje_from_buffer(buffer);
	printf("Mensaje inicial: %s\n",mensaje_inicial);
	printf("Mensaje final: %s\n",mensaje_final);
}*/

void probarNewPokemon(){
	t_new_pokemon* new_pokemon_inicial = new_pokemon_create("pikachu",5,10,2);
	t_buffer* buffer = new_pokemon_to_buffer(new_pokemon_inicial);
	t_new_pokemon* new_pokemon_final = new_pokemon_from_buffer(buffer);
	printf("New pokemon inicial: \n");
	new_pokemon_mostrar(new_pokemon_inicial);
	printf("New pokemon final: \n");
	new_pokemon_mostrar(new_pokemon_final);
}

void probarGetPokemon(){
	t_get_pokemon* get_pokemon_inicial = get_pokemon_create("charmander");
	t_buffer* buffer = get_pokemon_to_buffer(get_pokemon_inicial);
	t_get_pokemon* get_pokemon_final = get_pokemon_from_buffer(buffer);
	printf("Get pokemon inicial: \n");
	get_pokemon_mostrar(get_pokemon_inicial);
	printf("Get pokemon final: \n");
	get_pokemon_mostrar(get_pokemon_final);
}

void probarCaughtPokemon(){
	t_caught_pokemon* caught_pokemon_inicial = caught_pokemon_create(1);
	t_buffer* buffer = caught_pokemon_to_buffer(caught_pokemon_inicial);
	t_caught_pokemon* caught_pokemon_final = caught_pokemon_from_buffer(buffer);
	printf("Caught pokemon inicial: \n");
	caught_pokemon_mostrar(caught_pokemon_inicial);
	printf("Caught pokemon final: \n");
	caught_pokemon_mostrar(caught_pokemon_final);
}

void probarCatchPokemon(){
	t_catch_pokemon* catch_pokemon_inicial = catch_pokemon_create("Bulbasaur",5,5);
	t_buffer* buffer = catch_pokemon_to_buffer(catch_pokemon_inicial);
	t_catch_pokemon* catch_pokemon_final = catch_pokemon_from_buffer(buffer);
	printf("Catch pokemon inicial: \n");
	catch_pokemon_mostrar(catch_pokemon_inicial);
	printf("Catch pokemon final: \n");
	catch_pokemon_mostrar(catch_pokemon_final);
}

void probarAppearedPokemon(){
	t_appeared_pokemon* appeared_pokemon_inicial = appeared_pokemon_create("Squirtle",4,4);
	t_buffer* buffer = appeared_pokemon_to_buffer(appeared_pokemon_inicial);
	t_appeared_pokemon* appeared_pokemon_final = appeared_pokemon_from_buffer(buffer);
	printf("Appeared pokemon inicial: \n");
	appeared_pokemon_mostrar(appeared_pokemon_inicial);
	printf("Appeared pokemon final: \n");
	appeared_pokemon_mostrar(appeared_pokemon_final);
}

void probarLocalizedPokemon(){
	t_posicion* posiciones = malloc( sizeof(t_posicion) * 2 );
	posiciones[0].posicionX = 2;
	posiciones[0].posicionY = 3;
	posiciones[1].posicionX = 1;
	posiciones[1].posicionY = 5;
	t_localized_pokemon* localized_pokemon_inicial = localized_pokemon_create("pikachu",2,posiciones);
	t_buffer* buffer = localized_pokemon_to_buffer(localized_pokemon_inicial);
	t_localized_pokemon* localized_pokemon_final = localized_pokemon_from_buffer(buffer);
	printf("Localized pokemon inicial:\n");
	localized_pokemon_mostrar(localized_pokemon_inicial);
	printf("Localized pokemon final:\n");
	localized_pokemon_mostrar(localized_pokemon_final);
}

int main(void){
	probarLocalizedPokemon();
	return 0;
}
