#include "tp0.h"

int main(void)
{
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

	conexion = crear_conexion(ip,puerto);
	log_info(logger, "Cree una conexion con el ip: %s en el puerto %s\n",ip,puerto);

	t_new_pokemon* pikachu_enviado = new_pokemon_create("pikachu",2,3,5);
	enviar_mensaje((void*)pikachu_enviado,NEW_POKEMON,conexion);
	log_info(logger,"Envie el mensaje\n");

	op_code operacion;
	t_new_pokemon* pikachu_recibido = (t_new_pokemon*) recibir_mensaje(conexion, &operacion);
	if(operacion == NEW_POKEMON){
		log_info(logger,"Llego un mensaje - New Pokemon\n");
		log_info(logger,"Su nombre es %s\n", pikachu_recibido->nombre);
		log_info(logger,"Su nombre tiene %d  letras\n",pikachu_recibido->tamanio_nombre);
		log_info(logger,"Estan en (x,y) = (%d,%d)\n",pikachu_recibido->posicion.posicionX,pikachu_recibido->posicion.posicionY);
		log_info(logger,"En esas coordenadas hay %d cantidad\n",pikachu_recibido->cantidad);
	}

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
