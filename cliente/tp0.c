 /*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();
	log_info(logger,"soy un log");

	log_info(logger, "creando config...");
	config = leer_config();

	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");

	log_info(logger, "Lei la ip %s y el puerto %s\n",ip,puerto);

	//crear conexion
	conexion = crear_conexion(ip,puerto);
	log_info(logger, "Cree una conexion con el ip: %s en el puerto %s\n",ip,puerto);

	//creo el mensaje new_pokemon
	char men[] = "Soy un log";
	enviar_mensaje((void*)men,MENSAJE,conexion);

	log_info(logger,"Envie el mensaje\n");

	//recibir mensaje
	op_code operacion;
	char* mensaje = (char*) recibir_mensaje(conexion, &operacion);

	log_info(logger, "El mensaje es: %s\n", mensaje);

	log_info(logger,"Termine el programa correctamente\n");
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
