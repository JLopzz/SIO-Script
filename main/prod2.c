#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

#define LLAVE2 20202
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
	return rand() % 103;
}
/* Funcion Generadora de numeros pares aleatorios */
int par(int init){
  int nPar = getRandom(init);
  if((nPar%2) == 1) return par(init++);
  else return nPar;
}

//funcion Principal
int main(){
	int id;
	unsigned int lenmsg;
	struct msj msj;
	msj.tipo = 1;

	for(int i = 0; i<20; i++) msj.text[i] = par(i);
	lenmsg = strlen(msj.text);
	if((id=msgget(LLAVE2,0600|IPC_CREAT))==-1) perror("error msgget");
	if(msgsnd(id,&msj,(lenmsg+1),0)==-1) perror("error msgsnd");
	
	return 0;
}