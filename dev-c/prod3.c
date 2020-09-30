#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

#define LLAVE3 30303
#define MAX 25

struct msj{
	long tipo;
	char text[MAX];
};

/*funcion que genera numeros aleatoris, a partir de la funcion nativa rand()
genera una semilla, apartir de esta genera un nuevo numero aleatorio
*/
int getRandom(int init){
	time_t t;
	unsigned int seed = &t;
	srand(seed + init);
	return rand() % 10000;
}

/* Funcion Generadora de numeros impares aleatorios */
int getImpar(int init){
  int nPar = getRandom(init);
  if((nPar%2) == 1) return nPar;
  else return getImpar(init++);
}

/*
comprueba si el valor es unico, antes de asignarse
*/
int setUnic(int init, int n[]){
	int rdm = getImpar(init);
	for(int x = 0; x < init; x++)
		if(rdm == n[x]) return setUnic(init+x,n);
	return rdm;
}

//funcion Principal
int main(){
	int id;
	int num[21];
	unsigned int lenmsg;
	struct msj msj;
	msj.tipo = 1;

	for(int i = 0; i<21; i++){
		int rdm = setUnic(i,num);
		num[i] = rdm;
		if(i<20) sprintf(msj.text, "%i", rdm);
		else sprintf(msj.text, "%i", -30303);
		lenmsg = strlen(msj.text);
		if((id=msgget(LLAVE3,0600|IPC_CREAT))==-1) perror("error msgget");
		if(msgsnd(id,&msj,(lenmsg+1),0)==-1) perror("error msgsnd");	
	}

	return 0;
}