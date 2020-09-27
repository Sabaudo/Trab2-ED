#ifndef _LEITURA_GEO_H_
#define _LEITURA_GEO_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
#include"lista.h"

/*
*   Função que realiza a leitura do arquivo .geo 
*   necessita de um arquivo .geo, e das listas de objetos, formas e texto
*   nao retorna nada
*/
void Ler_arquivo_geo(FILE *geo, Lista listaForma, Lista listaTexto, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase);


#endif 