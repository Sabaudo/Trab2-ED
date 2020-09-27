#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leitura_gry.h"
#include"leitura_geo.h"
#include"consultas.h"
#include"svg.h"
#include"lista.h"


void Ler_arquivo_gry(FILE *qry, FILE *svg2, FILE *txt, Lista listaForma, Lista listaTexto, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase ){
char operacao[6],corBorda[32],corPreenchimento[32], linha_txt[1024], aux[32];
char j[32], k[32];
int j_num, k_num;
int contador;
double x, y, r, w, h;
bool verificador;


    FILE * txt_aux;

    txt_aux = fopen("aux.txt","w+");    

    while(1){
        fscanf(qry, "%s", operacao);

        if(feof(qry)){
            break;
        }

        if(strcmp(operacao, "o?") == 0){
            fscanf(qry,"%s", j);
            fscanf(qry,"%s", k);
            consulta_o(listaForma, j ,k, svg2, txt, txt_aux);
        }

        else if(strcmp(operacao, "i?") == 0 ){
            fscanf(qry,"%s",  j);
            fscanf(qry,"%lf", &x);
            fscanf(qry,"%lf", &y);
            consulta_i(listaForma, j, x, y, svg2, txt, txt_aux);
        } 

        else if(strcmp(operacao, "pnt") == 0){
            fscanf(qry,"%s", j);
            fscanf(qry,"%s", corBorda);
            fscanf(qry,"%s",corPreenchimento);
            consulta_pnt(listaForma, listaTexto, j,corBorda,corPreenchimento,svg2,txt);

        }

        else if(strcmp(operacao, "pnt*") == 0){
            fscanf(qry,"%d", &j_num);
            fscanf(qry,"%d", &k_num);
            fscanf(qry,"%s",corBorda);
            fscanf(qry,"%s",corPreenchimento);
            consulta_pnt_2(listaForma, listaTexto, j_num, k_num, corBorda, corPreenchimento, svg2, txt);
        }

        else if(strcmp(operacao, "delf") == 0){
            fscanf(qry,"%s", j);
            consulta_delf(listaForma, listaTexto, j, svg2, txt);
        }

        else if(strcmp(operacao, "delf*") == 0){
            fscanf(qry,"%d", &j_num);
            fscanf(qry,"%d", &k_num);
            consulta_delf_2(listaForma, listaTexto, j_num, k_num, svg2, txt);
        }

        else if(strcmp(operacao, "dq") == 0){
            fscanf(qry, "%s", aux);
            if(strcmp(aux, "#") == 0){
                fscanf(qry, "%s %lf", j, &r);
                verificador = true;
            }else{
                fscanf(qry,"%lf", &r);
                verificador = false;
            }
            consulta_dq(listaForma,listaQuadra, listaHidrante, listaSemaforo, listaRadioBase, aux, j, r, verificador, svg2, txt);
        }

        else if(strcmp(operacao, "del") == 0){
            fscanf(qry, "%s", j);
            consulta_del(txt_aux, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase, j, svg2, txt);
        }

        else if(strcmp(operacao, "crd?") == 0){
            fscanf(qry, "%s", j);
            consulta_crd(listaQuadra, listaHidrante, listaSemaforo, listaRadioBase, j, svg2, txt);
        }

        else if(strcmp(operacao, "cbq") == 0){
            fscanf(qry, "%lf %lf %lf %s", &x, &y, &r, corBorda);
            consulta_cbq(listaQuadra, j, svg2, txt, x, y, r, corBorda);
        }
        
        else if(strcmp(operacao, "car") == 0){
            fscanf(qry, "%lf %lf %lf %lf", &x, &y, &w, &h);
            consulta_car(txt_aux, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase, svg2, txt, x, y, w, h);
        }
    }

    print(svg2,listaForma);
    print(svg2,listaQuadra);
    print(svg2,listaHidrante);
    print(svg2,listaSemaforo);
    print(svg2,listaRadioBase);
    print(svg2,listaTexto);

    rewind(txt_aux);
    while(1){
        fgets(linha_txt,1024,txt_aux);
            if(feof(txt_aux))
                break;
        fprintf(svg2,"%s",linha_txt);
    }
    fclose(txt_aux);
    remove("aux.txt");  
}        