#ifndef _LEITURA_GRY_H_
#define _LEITURA_GRY_H_
#include"leitura_geo.h"

/*  
*   realiza toda a leitura do arquivo .qry e chama as funções para cada operacão 
*   necessita de um arquivo .qry, as listas de forma, texto e objetos
*   nao retorna nada
*/
void Ler_arquivo_gry(FILE *qry, FILE *svg2, FILE *txt, Lista listaForma, Lista listaTexto, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase);


#endif
