#ifndef MENSAJES_H
#define MENSAJES_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum
{
	NEW_POKEMON,
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

typedef struct{
	uint32_t posicionX;
	uint32_t posicionY;
}t_posicion;


// para envio de mensajes
t_buffer* mensaje_to_buffer(char* mensaje);

//para recibir mensajes
char* mensaje_from_buffer(t_buffer* buffer);


#endif 
