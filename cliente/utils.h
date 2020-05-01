/*
 * conexiones.h
 *
 *  Created on: 2 mar. 2019
 *      Author: utnso
 */

#ifndef UTILS_H_
#define UTILS_H_

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>

#include<mensajes/mensajes.h>
#include<mensajes/appeared_pokemon.h>
#include<mensajes/catch_pokemon.h>
#include<mensajes/caught_pokemon.h>
#include<mensajes/get_pokemon.h>
#include<mensajes/localized_pokemon.h>
#include<mensajes/new_pokemon.h>

int crear_conexion(char* ip, char* puerto);
void enviar_mensaje(void* mensaje,op_code codigo, int socket_cliente);
void* recibir_mensaje(int socket_cliente, op_code* codigo_operacion);
void eliminar_paquete(t_paquete* paquete);
void liberar_conexion(int socket_cliente);
void* serializar_paquete(t_paquete* paquete, int *bytes);

#endif /* UTILS_H_ */
