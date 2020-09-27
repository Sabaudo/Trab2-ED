#ifndef _SVG_H_
#define _SVG_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
#include"leitura_geo.h"
#include"./elementos/forma.h"
#include"./elementos/texto.h"
#include"./elementos/quadra.h"
#include"./elementos/hidrante.h"
#include"./elementos/semaforo.h"
#include"./elementos/radioBase.h"


/*
*   imprime as formas no formato svg
*   necessita de um arquivo svg e de uma lista de formas
*   nao retorna nada
*/
void svg_imprimir_forma(FILE *arqsvg, Forma forma);


/*
*   imprime as quadras no formato svg
*   necessita de um arquivo svg e de uma lista de quadras
*   nao retorna nada
*/
void svg_imprimir_quadra(FILE *arqsvg, Quadra quadra);


/*
*   imprime os hidrantes no formato svg
*   necessita de um arquivo svg e de uma lista de hidrantes
*   nao retorna nada
*/
void svg_imprimir_hidrante(FILE *arqsvg, Hidrante hidrante);


/*
*   imprime os semaforos no formato svg
*   necessita de um arquivo svg e de uma lista de semaforos
*   nao retorna nada
*/
void svg_imprimir_semaforo(FILE *arqsvg, Semaforo semaforo);


/*
*   imprime os radio bases no formato svg
*   necessita de um arquivo svg e de uma lista de radio bases
*   nao retorna nada
*/
void svg_imprimir_rb(FILE *arqsvg, RadioBase radiobase);


/*
*   imprime um ponto no formato svg
*   necessita de um arquivo svg e de coordenadas dadas
*   nao retorna nada
*/
void svg_imprimir_ponto(FILE *arqsvg, char cor[], double x, double y);



/*
*   imprime os textos no formato svg
*   necessita de um arquivo svg e de uma lista de textos
*   nao retorna nada
*/
void svg_imprimirTexto(FILE *arqtxt, Texto texto);


/*
*   imprime uma linha no formato svg
*   necessita de um arquivo svg, coordenadas e cor para a linha
*   nao retorna nada
*/
void svg_imprimir_linha (FILE *svg, double x1, double y1, double x2, double y2, char cor[]);


/*
*   imprime uma quadra arredondada no formato svg, quando o comando dq for chamado
*   necessita de um arquivo svg e de uma lista de quadras
*   nao retorna nada
*/
void svg_imprimir_quadArrend(FILE *arqsvg, Quadra quadra);


/*
*   imprime um anel no formato svg, quando o comando dq for chamado
*   necessita de um arquivo svg, de um elemento e seu tipo
*   nao retorna nada
*/
void anelGrosso(FILE *arqsvg, Elemento e, char tipo[]);


#endif
