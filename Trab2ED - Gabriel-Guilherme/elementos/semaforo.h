#ifndef SEMAFORO__H
#define SEMAFORO__H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD SEMAFORO
typedef void* Semaforo;

/*
*   cria um objeto semaforo
*   necessita do comando s ter sido chamado
*   retorna um novo objeto semaforo criado
*/
Semaforo criaSemaforo (char id[], char tipo[],double x, double y, char cor1[], char cor2[], char sw[]);



/*  
*   busca o X do semaforo
*   necessita de um semaforo criado
*   retorna o X do semaforo
*/
double getXSema (Semaforo semaforo);


/*
*   busca o Y do semaforo
*   necessita de um semaforo criado
*   retorna o Y do semaforo
*/
double getYSema (Semaforo semaforo);


/*
*   busca o ID/CEP do semaforo
*   necessita de um semaforo criado
*   retorna o ID/CEP do semaforo
*/
char* getIDSema (Semaforo semaforo);


/*
*   busca a cor de borda do semaforo
*   necessita de um semaforo criado
*   retorna a cor de borda do semaforo
*/
char* getcorBordaSema (Semaforo semaforo);


/*
*   busca a cor de preenchimento do semaforo
*   necessita de um semaforo criado
*   retorna a cor de preenchimento do semaforo
*/
char* getcorPreenchimentoSema (Semaforo semaforo);


/*
*   busca o SW do semaforo
*   necessita de um semaforo criado
*   retorna o SW do semaforo
*/
char* getSWSema (Semaforo semaforo);


/*
*   libera a memoria do objeto semaforo
*   necessita de um semaforo criado
*   nao retorna nada
*/
void freeSemaforo (Semaforo semaforo);


#endif