#ifndef MENSAJES_H
#define MENSAJES_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum
{
	NEW_POKEMON = 1,
    LOCALIZED_POKEMON,
    GET_POKEMON,
    APPEARED_POKEMON,
    CATCH_POKEMON,
    CAUGHT_POKEMON,
    MENSAJE
}op_code;

typedef struct{
	int size;
	void* stream;
} t_buffer;

typedef struct{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;

void* serializar_paquete(t_paquete* paquete, int *bytes);
t_paquete* empaquetar_buffer(t_buffer* buffer, op_code codigo);
void enviar_mensaje(void* mensaje,op_code codigo, int socket_cliente);
void* recibir_mensaje(int socket_cliente, op_code* codigo_operacion);

#endif 
