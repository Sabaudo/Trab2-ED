#ifndef _CONSULTAS_H_
#define _CONSULTAS_H_

#include"leitura_geo.h"
typedef void* Elemento;


/*
*   realiza a operação do o? do arquivo .qry
*   necessita do comando o? ter sido chamado
*   nao retorna nada
*/
void consulta_o(Lista listaForma, char j[], char k[], FILE *svg2, FILE*txt, FILE *aux_txt);


/*
*   realiza a operação do i? do arquivo .qry
*   necessita do comando i? ter sido chamado
*   nao retorna nada
*/
void consulta_i(Lista listaForma, char j[], double x, double y, FILE *svg2, FILE *txt, FILE *aux_txt);


/*
*   realiza a operação do pnt do arquivo .qry
*   necessita do comando pnt ter sido chamado
*   nao retorna nada
*/
void consulta_pnt(Lista listaForma, Lista listaTexto, char j[], char corBorda[], char corPreenchimento[], FILE *svg2, FILE *txt);

/*
*   realiza a operação do pnt* do arquivo .qry
*   necessita do comando pnt* ter sido chamado
*   nao retorna nada
*/
void consulta_pnt_2(Lista listaForma, Lista listaTexto, int j_num, int k_num, char corBorda[], char corPreenchimento[], FILE *svg2, FILE *txt);

/*
*   realiza a operação do delf do arquivo .qry
*   necessita do comando delf ter sido chamado
*   nao retorna nada
*/
void consulta_delf(Lista listaForma, Lista listaTexto, char j[], FILE *svg2, FILE *txt);

/*
*   realiza a operação do delf* do arquivo .qry
*   necessita do comando delf* ter sido chamado
*   nao retorna nada
*/
void consulta_delf_2(Lista listaForma, Lista listaTexto, int j_num, int k_num, FILE *svg2, FILE *txt);


/*
*   realiza a operação dq do arquivo .qry
*   necessita do comando dq ter sido chamado
*   nao retorna nada
*/
void consulta_dq(Lista listaForma,Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, char aux[], char j[], double r, bool verificador, FILE* svg2, FILE* txt);


/*
*   realiza a operação del do arquivo .qry
*   necessita do comando del ter sido chamado
*   nao retorna nada
*/
void consulta_del(FILE* aux, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, char id[], FILE *svg2, FILE *txt);


/*
*   realiza a operação crd do arquivo .qry
*   necessita do comando crd ter sido chamado
*   nao retorna nada
*/
void consulta_crd(Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, char id[],FILE* svg2, FILE *txt);


/*
*   realiza a operação cbq do arquivo .qry
*   necessita do comando cbq ter sido chamado
*   nao retorna nada
*/
void consulta_cbq(Lista listaQuadra, char id[],FILE* svg2, FILE *txt, double x, double y, double r, char corB[]);


/*
*   realiza a operação car do arquivo .qry
*   necessita do comando car ter sido chamado
*   nao retorna nada
*/
void consulta_car(FILE* aux, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, FILE* svg2, FILE* txt, double x, double y, double w, double h);
#endif