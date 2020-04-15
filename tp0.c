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
	char* mensaje;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();
	log_info(logger,"soy un log");

	log_info(logger, "creando config...");
	config = leer_config();

	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");

	log_info(logger, "Lei la ip %s y el puerto %s\n",ip,puerto);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque
	//lo necesitaremos para lo que sigue.

	//crear conexion
	conexion = crear_conexion(ip,puerto);

	//enviar mensaje
	enviar_mensaje("hola que tal",conexion);

	//recibir mensaje
	mensaje = recibir_mensaje(conexion);

	//loguear mensaje recibido
	log_info(logger,"El mensaje recibido es: %s\n",mensaje);

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
	/*
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
	*/
}
