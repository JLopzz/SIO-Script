#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

#define LLAVE4 40404
#define MAX 25

struct msj{
	long tipo;
	char text[MAX];
};

int getRandom(int init){
	time_t t;
	unsigned int seed = &t;
	srand(seed + init);
	return (rand() % 103) + 2;
}


char randomCharacter(int init) {
  char randomChar;
  randomChar= 65 + (getRandom(init) % 57);
  if((randomChar <= 96) && (randomChar >= 91)) return randomCharacter(init++);
  else return randomChar;    
}

//Funcion principal
void main(){
	int id;
	unsigned int lenmsg;
	struct msj msj;
	msj.tipo = 1;

	for(int i = 0; i<20; i++) msj.text[i] = randomCharacter(i);

	lenmsg = strlen(msj.text);
	if((id=msgget(LLAVE4,0600|IPC_CREAT))==-1) perror("error msgget");
	if(msgsnd(id,&msj,(lenmsg+1),0)==-1) perror("error msgsnd");
	 
}

