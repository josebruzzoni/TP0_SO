/*
 * conexiones.c
 *
 *  Created on: 2 mar. 2019
 *      Author: utnso
 */

#include "utils.h"


void* serializar_paquete(t_paquete* paquete, int *bytes)
{
	int size_serializado  = sizeof(paquete->codigo_operacion) + sizeof(paquete->buffer->size) + paquete->buffer->size;
	void *buffer = malloc(size_serializado);

	int bytes_escritos = 0;

	memcpy(buffer + bytes_escritos,&(paquete->codigo_operacion),sizeof(paquete->codigo_operacion));
	bytes_escritos += sizeof(paquete->codigo_operacion);

	memcpy(buffer  + bytes_escritos,&(paquete->buffer->size),sizeof(paquete->buffer->size));
	bytes_escritos += sizeof(paquete->buffer->size);

	memcpy(buffer + bytes_escritos,paquete->buffer->stream,paquete->buffer->size);
	bytes_escritos += paquete->buffer->size;

	(*bytes) = size_serializado;
	return buffer;
}

int crear_conexion(char *ip, char* puerto)
{
	struct addrinfo hints;
	struct addrinfo *server_info;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(ip, puerto, &hints, &server_info);

	int socket_cliente = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

	if(connect(socket_cliente, server_info->ai_addr, server_info->ai_addrlen) == -1)
		printf("error");

	freeaddrinfo(server_info);

	return socket_cliente;
}

t_paquete* empaquetar_buffer(t_buffer* buffer, op_code codigo){
	t_paquete* paquete = malloc( sizeof(t_paquete) );
	paquete->codigo_operacion = codigo;
	paquete->buffer = buffer;
	return paquete;
}

//TODO
void enviar_mensaje(void* mensaje,op_code codigo, int socket_cliente)
{
	t_buffer* buffer;

	switch(codigo){
		case MENSAJE:
			buffer = mensaje_to_buffer((char*)mensaje);
			break;
		case NEW_POKEMON:
			buffer = new_pokemon_to_buffer((t_new_pokemon*) mensaje);
			break;
		case LOCALIZED_POKEMON:
			buffer = localized_pokemon_to_buffer((t_localized_pokemon*) mensaje);
			break;
		case GET_POKEMON:
			buffer = get_pokemon_to_buffer((t_get_pokemon*) mensaje);
			break;
		case APPEARED_POKEMON:
			buffer = appeared_pokemon_to_buffer((t_appeared_pokemon*) mensaje) ;
			break;
		case CATCH_POKEMON:
			buffer = catch_pokemon_to_buffer((t_catch_pokemon*) mensaje);
			break;
		case CAUGHT_POKEMON:
			buffer = caught_pokemon_to_buffer((t_caught_pokemon*) mensaje);
			break;
		default:
			break;
	}

	t_paquete* paquete = empaquetar_buffer(buffer,codigo);

	int size_serializado;
	void* serializado = serializar_paquete(paquete, &size_serializado);

	send(socket_cliente,serializado,size_serializado,0);
	free(serializado);
	free(paquete->buffer);
	free(paquete);
}

//TODO
char* recibir_mensaje(int socket_cliente)
{
	op_code operacion;
	recv(socket_cliente, &operacion, sizeof(operacion),0);
	int buffer_size;
	recv(socket_cliente, &buffer_size, sizeof(buffer_size),0);
	char *buffer = malloc(sizeof(buffer_size));
	recv(socket_cliente, buffer, buffer_size,0);
	if(buffer[buffer_size - 1] != '\0'){
		printf("WARNING - El buffer recibido no es un string\n");
	}
	return buffer;
}


void liberar_conexion(int socket_cliente)
{
	close(socket_cliente);
}


