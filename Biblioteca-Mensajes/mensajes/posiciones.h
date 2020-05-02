#ifndef POSICIONES_H
#define POSICIONES_H

#include <stdint.h>

typedef struct{
	uint32_t posicionX;
	uint32_t posicionY;
}t_posicion;

typedef struct{
	t_posicion* posiciones;
	int cantidad;
	int indice;
}t_posiciones;

t_posicion posicion_create(uint32_t posX, uint32_t posY);
uint32_t posicion_get_X(t_posicion posicion);
uint32_t posicion_get_Y(t_posicion posicion);
t_posiciones* posiciones_create(int cantidad);
void posiciones_add_XY(t_posiciones* posiciones, uint32_t posX, uint32_t posY);
void posiciones_add_posicion(t_posiciones* posiciones, t_posicion posicion);
t_posicion* posiciones_get_posicion_in(t_posiciones* posiciones, int indice);
void posiciones_destroy(t_posiciones* posiciones);

#endif
