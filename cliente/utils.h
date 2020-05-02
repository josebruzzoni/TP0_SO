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

#include <mensajes/localized_pokemon.h>
#include <mensajes/caught_pokemon.h>
#include <mensajes/catch_pokemon.h>
#include <mensajes/get_pokemon.h>
#include <mensajes/new_pokemon.h>
#include <mensajes/appeared_pokemon.h>
#include <mensajes/cadena.h>

int crear_conexion(char* ip, char* puerto);
void liberar_conexion(int socket_cliente);

#endif /* UTILS_H_ */
