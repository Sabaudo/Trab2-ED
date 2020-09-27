#ifndef RADIOBASE__H
#define RADIOBASE__H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD RADIO BASE
typedef void* RadioBase;

/*
*   cria um novo objeto radio base
*   necessita do comando rb ter sido chamado
*   retorna um novo objeto radio base
*/
RadioBase criaRadioBase (char cep[], char tipo[], double x, double y, char corBorda[], char corPreenchimento[], char sw[]);


/*
*   busca o X do radio base
*   necessita de um objeto radio base ter sido criado
*   retorna o X do radio base
*/
double getXRB (RadioBase radioBase);


/*
*   busca o Y do radio base
*   necessita de um objeto radio base ter sido criado
*   retorna o Y do radio base
*/
double getYRB (RadioBase radioBase);


/*
*   busca o ID/CEP do radio base
*   necessita de um objeto radio base ter sido criado
*   retorna o ID/CEP do radio base
*/
char* getIDRB (RadioBase radioBase);


/*
*   busca a cor de borda do radio base
*   necessita de um objeto radio base ter sido criado
*   retorna a cor de borda do radio base
*/
char* getcorBordaRB (RadioBase radioBase);


/*
*   busca a cor de preenchimento do radio base
*   necessita de um objeto radio base ter sido criado
*   retorna a cor de preenchimento do radio base
*/
char* getcorPreenchimentoRB (RadioBase radioBase);


/*
*   busca o SW do radio base
*   necessita de um objeto radio base ter sido criado
*   retorna o SW do radio base
*/
char* getSWRB (RadioBase radioBase);


/*
*   libera a memoria do objeto radio base
*   necessita de um objeto radio base ter sido criado
*   nao retorna nada
*/
void freeRadioBase (RadioBase radioBase);


#endif