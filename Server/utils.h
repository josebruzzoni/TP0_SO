/*
 * conexiones.h
 *
 *  Created on: 3 mar. 2019
 *      Author: utnso
 */

#ifndef CONEXIONES_H_
#define CONEXIONES_H_

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<commons/log.h>
#include<commons/collections/list.h>
#include<string.h>
#include<pthread.h>

#include <mensajes/mensajes.h>

#define IP "127.0.0.1"
#define PUERTO "4444"


pthread_t thread;

void iniciar_servidor(void);
void esperar_cliente(int);
void serve_client(int *socket);


#endif /* CONEXIONES_H_ */
