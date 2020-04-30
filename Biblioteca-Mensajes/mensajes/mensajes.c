#include "mensajes.h"


//--TAD MENSAJE --------------
t_buffer* mensaje_to_buffer(char* mensaje){
	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer->size = strlen(mensaje) + 1;
	buffer->stream = mensaje;
	return buffer;
}

char* mensaje_from_buffer(t_buffer* buffer){
	char* mensaje = buffer->stream;
	return mensaje;
}


