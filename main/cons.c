#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

#define LLAVE1 10101
#define LLAVE2 20202
#define LLAVE3 30303
#define LLAVE4 40404
#define MAX 25
#define BLUE "\x1b[44m"
#define RESET "\x1b[0m"
#define CYAN "\x1b[36m"

struct msj{
	long tipo;
	char text[MAX];
};

int main(){
	int id;
	unsigned int lenmsg;
	struct msj msj;

  printf("\nMensajes de Productor 1, " BLUE "Numero Primos Aleatorios" RESET "\n");
	if((id=msgget(LLAVE1, 0600|IPC_CREAT))==-1) perror("error msgget");
	if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
	if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
  lenmsg = strlen(msj.text);
  for(int i =0; i<lenmsg-2; i++) printf("%d)\tNumero obtenido de Productor 1: " CYAN "%d" RESET "\n", i+1, msj.text[i]);

  printf("\nMensajes de Productor 2, " BLUE "Numero Pares Aleatorios" RESET "\n");
	if((id=msgget(LLAVE2, 0600|IPC_CREAT))==-1) perror("error msgget");
	if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
	if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
  lenmsg = strlen(msj.text);
  for(int i =0; i<lenmsg-2; i++) printf("%d)\tNumero obtenido de Productor 2: " CYAN "%d" RESET "\n", i+1, msj.text[i]);

  printf("\nMensajes de Productor 3, " BLUE "Numero Impares Aleatorios" RESET "\n");
  if((id=msgget(LLAVE3, 0600|IPC_CREAT))==-1) perror("error msgget");
	if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
	if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
  lenmsg = strlen(msj.text);
  for(int i =0; i<lenmsg-2; i++) printf("%d)\tNumero obtenido de Productor 3: " CYAN "%d" RESET "\n", i+1, msj.text[i]);

  printf("\nMensajes de Productor 4, " BLUE "Caracteres Aleatorios" RESET "\n");
	if((id=msgget(LLAVE4, 0600|IPC_CREAT))==-1) perror("error msgget");
	if(msgrcv(id,&msj, MAX,0,0)==-1) perror("error msgrcv");
	if(msgctl(id,IPC_RMID,NULL)==-1) perror("error msgctl");
  lenmsg = strlen(msj.text);
  for(int i =0; i<lenmsg-2; i++) printf("%d)\tCaracter obtenido de Productor 4: " CYAN "%c" RESET "\n", i+1, msj.text[i]);

  return 0;
}	