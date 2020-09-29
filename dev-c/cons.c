#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

//Llaves de comunicacion de mensajes enviados de productores
#define LLAVE1 10101	//productor 1
#define LLAVE2 20202	//productor 2
#define LLAVE3 30303	//productor 3
#define LLAVE4 40404	//productor 4

//Tamaño maximo de char[]
#define MAX 25

//Colores de consola
#define BLUE "\x1b[44m"
#define RESET "\x1b[0m"
#define CYAN "\x1b[36m"

struct msj{
	long tipo;
	char text[MAX];
};

//Funcion principal, escucha todos los mensajes vinientes de cada productor
int main(){
	int id, x=0;
	unsigned int lenmsg;
	struct msj msj;


	/***************************	PRODUCTOR 1	****************************/

  printf("\nMensajes de Productor 1, " BLUE "Numero Primos Aleatorios" RESET "\n");
	//Obtencion de ID de mensaje, a partir de la LLAVE1
	if((id=msgget(LLAVE1, 0600|IPC_CREAT))==-1) perror("error msgget");
	//Bucle de recepcion e impresion de mensaje obtenido
	while(strcmp(msj.text,"-10101")){
		if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
		if(strcmp(msj.text,"-10101")) 
			printf("%d)\tNumero obtenido de Productor 1: " CYAN "%s" RESET "\n", x++ +1, msj.text);
	}
	//Se cierra la comunicacion de mensajeria con ID => LLAVE1
  if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
	x=0; //Reinicio de contador

	
	sleep(1);
	/***************************	PRODUCTOR 2	****************************/

  printf("\nMensajes de Productor 2, " BLUE "Numero Pares Aleatorios" RESET "\n");
	//Obtencion de ID de mensaje, a partir de la LLAVE2
	if((id=msgget(LLAVE2, 0600|IPC_CREAT))==-1) perror("error msgget");
	//Bucle de recepcion e impresion de mensaje obtenido
	while(strcmp(msj.text,"-20202")){
		if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
		if(strcmp(msj.text,"-20202"))
			printf("%d)\tNumero obtenido de Productor 2: " CYAN "%s" RESET "\n", x++ +1, msj.text);
	}
	//Se cierra la comunicacion de mensajeria con ID => LLAVE2
	if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
  x=0; //Reinicio de contador

	
	sleep(1);
	/***************************	PRODUCTOR 3	****************************/

  printf("\nMensajes de Productor 3, " BLUE "Numero Impares Aleatorios" RESET "\n");
	//Obtencion de ID de mensaje, a partir de la LLAVE3
  if((id=msgget(LLAVE3, 0600|IPC_CREAT))==-1) perror("error msgget");
	//Bucle de recepcion e impresion de mensaje obtenido
	while(strcmp(msj.text,"-30303")){
		if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
		if(strcmp(msj.text,"-30303"))
			printf("%d)\tNumero obtenido de Productor 3: " CYAN "%s" RESET "\n", x++ +1, msj.text);
	}
	//Se cierra la comunicacion de mensajeria con ID => LLAVE3
	if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
	
	
	sleep(1);
	/***************************	PRODUCTOR 4	****************************/

  printf("\nMensajes de Productor 4, " BLUE "Caracteres Aleatorios" RESET "\n");
	//Obtencion de ID de mensaje, a partir de la LLAVE4
	if((id=msgget(LLAVE4, 0600|IPC_CREAT))==-1) perror("error msgget");
	//Recibidor de mensaje de productor 4
	if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
	//Se cierra la comunicacion de mensajeria con ID => LLAVE4
	if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
  lenmsg = strlen(msj.text);
	//impresion de mesaje recibido
  for(int i =0; i<lenmsg-2; i++) printf("%d)\tCaracter obtenido de Productor 4: " CYAN "%c" RESET "\n", i+1, msj.text[i]);

  return 0;
}	