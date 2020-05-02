#ifndef CADENA_H
#define CADENA_H

#include "mensajes.h"

op_code cadena_codigo(char* catch_pokemon);
t_buffer* cadena_to_buffer(char* mensaje);
char* cadena_from_buffer(t_buffer* buffer);
void cadena_mostrar(char* cadena);
void cadena_destroy(char* cadena);

#endif
