 /*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"
#include <mensajes/new_pokemon.h>
#include <mensajes/mensajes.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	void* mensaje;


	t_log* logger;
	t_config* config;

	logger = iniciar_logger();
	log_info(logger,"soy un log");

	log_info(logger, "creando config...");
	config = leer_config();

	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");

	log_info(logger, "Lei la ip %s y el puerto %s\n",ip,puerto);

//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque
	//lo necesitaremos para lo que sigue.

	//crear conexion
	conexion = crear_conexion(ip,puerto);

	//enviar mensaje
	t_new_pokemon * new_pokemon = new_pokemon_create("Pikachu",4,3,2);

	enviar_mensaje((void*)new_pokemon,NEW_POKEMON,conexion);


	//recibir mensaje
	op_code operacion;
	mensaje = recibir_mensaje(conexion, &operacion);

	switch(operacion){

			case MENSAJE:
				char* cadena = (char*)mensaje;
				log_info(logger,"El mensaje recibido es: %s\n", cadena);
				break;
			case NEW_POKEMON:
				t_new_pokemon* pokemon = (t_new_pokemon*) mensaje;
				log_info(logger,"El nombre es: %s\n",pokemon->nombre);
				log_info(logger,"El tamanio del nombre es: %d\n",pokemon->tamanio_nombre);
				log_info(logger,"La posicion en x es: %d\n",pokemon->posicion.posicionX);
				log_info(logger,"La posicion en y es: %d\n",pokemon->posicion.posicionY);
				log_info(logger,"La cantidad que hay es: %d\n",pokemon->cantidad);
				break;
			case LOCALIZED_POKEMON:
				t_localized_pokemon* pokemonLocalizado = (t_localized_pokemon*) mensaje;
				log_info(logger,"El nombre es: %s\n", pokemonLocalizado->nombre);
				log_info(logger,"El tamanio del nombre es: %d\n",pokemonLocalizado->tamanio_nombre);
				log_info(logger,"La cantidad que hay es: %d\n",pokemonLocalizado->cantidadPos);
				log_info(logger,"Las posiciones son: %d\n",pokemonLocalizado->posiciones);
				break;
			case GET_POKEMON:
				t_get_pokemon* pokemonConseguir = (t_get_pokemon*) mensaje;
				log_info(logger,"El nombre es: %s\n", pokemonConseguir->nombre);
				log_info(logger,"El tamanio del nombre es: %d\n:",pokemonConseguir->tamanio_nombre);
				break;
			case APPEARED_POKEMON:
				t_appeared_pokemon* pokemonAparecido = (t_appeared_pokemon*) mensaje;
				log_info(logger,"El nombre es: %s\n",pokemonAparecido->nombre);
				log_info(logger,"El tamanio del nombre es: %d\n",pokemonAparecido->tamanio_nombre);
				log_info(logger,"La posicion en x es: %d\n",pokemonAparecido->posicion.posicionX);
				log_info(logger,"La posicion en y es: %d\n",pokemonAparecido->posicion.posicionY);
				break;
			case CATCH_POKEMON:
				t_catch_pokemon* atraparPokemon = (t_catch_pokemon*) mensaje;
				log_info(logger,"El nombre es: %s\n",atraparPokemon->nombre);
				log_info(logger,"El tamanio del nombre es: %d\n",atraparPokemon->tamanio_nombre);
				log_info(logger,"La posicion en x es: %d\n",atraparPokemon->posicion.posicionX);
				log_info(logger,"La posicion en y es: %d\n",atraparPokemon->posicion.posicionY);
				break;
			case CAUGHT_POKEMON:
				t_caught_pokemon* pokemonAtrapado = (t_caught_pokemon*) mensaje;
				log_info(logger,"EL pokemon fue atrapado: %d\n", pokemonAtrapado->atrapado);
				break;
			default:
				break;
		}


	terminar_programa(conexion, logger, config);

}

//TODO
t_log* iniciar_logger(void)
{
	t_log* logger;
	if((logger = log_create("tp0.log","tp0",true,LOG_LEVEL_INFO)) == NULL)
	{
		printf("No se pudo crear el log\n");
		exit(1);
	}
	return logger;
}

//TODO
t_config* leer_config(void)
{
	t_config *config;
	if((config = config_create("./tp0.config")) == NULL)
	{
		printf("No pude leer la config\n");
		exit(2);
	}
	return config;
}

//TODO
void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);
	liberar_conexion(conexion);

	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	log_info(logger, "finalizando programa...");
	liberar_conexion(conexion);
	if(logger != NULL)
	{
		log_destroy(logger);
	}
	if(config != NULL)
	{
		config_destroy(config);
	}

}

