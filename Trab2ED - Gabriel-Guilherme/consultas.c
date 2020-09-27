#include"consultas.h"
#include"leitura_geo.h"
#include"util.h"
#include"svg.h"
#include"lista.h"
#include"./elementos/forma.h"
#include"./elementos/quadra.h"
#include"./elementos/semaforo.h"
#include"./elementos/hidrante.h"
#include"./elementos/radioBase.h"


void consulta_o(Lista listaForma, char j[], char k[], FILE *svg2, FILE*txt, FILE *aux_txt){
double distancia;
int id_j, id_k;

Forma forma1;
Forma forma2;

forma1 = get(listaForma, j);
forma2 = get(listaForma, k);
    if(forma1 == NULL){
        return;
    }
    if(forma2 == NULL){
        return;
    }

    if((strcmp(getTipoForma(forma1), "c") == 0) && (strcmp(getTipoForma(forma2),"c") == 0)){
        if(circulo_circulo(forma1, forma2)){
            fprintf(txt,"o? %s %s\n",j,k);
            fprintf(txt,"%s: circulo %s: circulo SIM\n\n",j,k);
            imprimir_retangulo_delimitador(forma1,forma2,true,aux_txt);

        }
        else{
            fprintf(txt,"o? %s %s\n",j,k);
            fprintf(txt,"%s: circulo %s: circulo NAO\n\n",j,k);
            imprimir_retangulo_delimitador(forma1,forma2,false,aux_txt);
        }          
    }

    else if((strcmp(getTipoForma(forma1), "r") == 0) && (strcmp(getTipoForma(forma2),"r") == 0)){
        if(retangulo_retangulo(forma1, forma2)){
            fprintf(txt,"o? %s %s\n",j,k);
            fprintf(txt,"%s: retangulo %s: retangulo SIM\n\n",j,k);
            imprimir_retangulo_delimitador(forma1,forma2,true,aux_txt);
        }
        else{
            fprintf(txt,"o? %s %s\n",j,k);
            fprintf(txt,"%s: retangulo %s: retangulo NAO\n\n",j,k);
            imprimir_retangulo_delimitador(forma1,forma2,false,aux_txt);
        }          

    }

    else if((strcmp(getTipoForma(forma1), "c") == 0) && (strcmp(getTipoForma(forma2),"r") == 0) || (strcmp(getTipoForma(forma1), "r") == 0) && (strcmp(getTipoForma(forma2),"c") == 0)){
        if(circulo_ou_retangulo(forma1,forma2)){
            if(strcmp(getTipoForma(forma1),"c") == 0){
                fprintf(txt,"o? %s %s\n",j,k);
                fprintf(txt,"%s: circulo %s: retangulo SIM\n\n",j,k);
                imprimir_retangulo_delimitador(forma1,forma2,true,aux_txt);
            }
            else{
                fprintf(txt,"o? %s %s\n",j,k);
                fprintf(txt,"%s: retangulo %s: circulo SIM\n\n",j,k);
                imprimir_retangulo_delimitador(forma1,forma2,true,aux_txt);
            }
            
        }
        else{
            if(strcmp(getTipoForma(forma1),"c") == 0){
                fprintf(txt,"o? %s %s\n",j,k);
                fprintf(txt,"%s: circulo %s: retangulo NAO\n\n",j,k);
                imprimir_retangulo_delimitador(forma1,forma2,false,aux_txt);
            }
            else{
                fprintf(txt,"o? %s %s\n",j,k);
                fprintf(txt,"%s: retangulo %s: circulo NAO\n\n",j,k);
                imprimir_retangulo_delimitador(forma1,forma2,false,aux_txt);
        
            }
        }
    }    
}

void consulta_i(Lista listaForma, char j[], double x, double y, FILE *svg2, FILE *txt, FILE *aux_txt){
double distancia;

    fprintf(txt,"i? %s %lf %lf\n",j,x,y);
    Forma forma = get(listaForma, j);

    if(forma == NULL){
        return;
    }
 
    if(strcmp(getTipoForma(forma), "c" ) == 0){
        distancia =  distanciaEuclidiana(x, y, getXForma(forma), getYForma(forma));
        
        if(distancia <= getRaioForma(forma)){
            fprintf(txt,"%s: circulo INTERNO\n\n",j);
            svg_imprimir_ponto(aux_txt, "blue", x, y);
            svg_imprimir_linha(aux_txt, x, y, getXForma(forma), getYForma(forma),"blue");
        }
        else{
            fprintf(txt,"%s: circulo NAO INTERNO\n\n",j);
            svg_imprimir_ponto(aux_txt, "magenta", x, y);
            svg_imprimir_linha(aux_txt, x, y, getXForma(forma), getYForma(forma),"magenta");
        }
    }

    else if(strcmp(getTipoForma(forma), "r" ) == 0){
        if(x > getXForma(forma) && x < getXForma(forma)  + getWForma(forma) && y > getYForma(forma) && y < getYForma(forma) + getHForma(forma)){    
            fprintf(txt,"%s: retangulo INTERNO\n\n",j);
            svg_imprimir_ponto(aux_txt, "blue", x, y);
            svg_imprimir_linha(aux_txt, x, y, getXForma(forma) + (getWForma(forma) / 2), getYForma(forma) + (getHForma(forma) / 2),"blue");
        }
        else{
            fprintf(txt,"%s: retangulo NAO INTERNO\n\n",j);
            svg_imprimir_ponto(aux_txt, "magenta", x, y);
            svg_imprimir_linha(aux_txt, x, y, getXForma(forma) + (getWForma(forma) / 2),getYForma(forma) + (getHForma(forma) / 2),"magenta");
        }
    }     
}

void consulta_pnt(Lista listaForma, Lista listaTexto, char j[], char corBorda[], char corPreenchimento[], FILE *svg2, FILE *txt){

    Forma forma = get(listaForma, j);
    Texto texto = get(listaTexto, j);

    fprintf(txt,"pnt j:%s corb:%s corp:%s\n",j,corBorda,corPreenchimento);

    if(forma != NULL){
        if(strcmp(getTipoForma(forma), "c") == 0 ){
            fprintf(txt,"id:%s\n",getIdForma(forma));
            fprintf(txt,"tipo:circulo\n");
            fprintf(txt,"raio:%lf\n",getRaioForma(forma));
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
            fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
            fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
        }
        else if(strcmp(getTipoForma(forma), "r") == 0 ){
            fprintf(txt,"id:%s\n",getIdForma(forma));
            fprintf(txt,"tipo:retangulo\n");
            fprintf(txt,"altura:%lf\n",getHForma(forma));
            fprintf(txt,"comprimento:%lf\n",getWForma(forma));
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
            fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
            fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
        }  
        setcorBordaForma(forma, corBorda);
        setcorPreenchimentoForma(forma, corPreenchimento);
    }
    if(texto != NULL){
        if(strcmp(getTipoTexto(texto), "t") == 0){
            fprintf(txt,"id:%s\n",getIdTexto(texto));
            fprintf(txt,"tipo:texto\n");
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXTexto(texto),getYTexto(texto));
            fprintf(txt,"cor borda:%s\n",getcorBordaTexto(texto));
            fprintf(txt,"cor preenchimento:%s\n",getcorPreenchimentoTexto(texto));
            fprintf(txt,"conteudo:%s\n", getConteudoTexto(texto));
            setcorBordaTexto(texto, corBorda);
            setcorPreenchimentoTexto(texto, corPreenchimento);
        } 
    }
}

void consulta_pnt_2(Lista listaForma, Lista listaTexto,  int j_num, int k_num, char corBorda[32], char corPreenchimento[32], FILE *svg2, FILE *txt){
int aux;
char j[32], k[32];
 
 //if reponsalvel por verificar qual variavel é a menor em comparação com a outra
   if(j_num > k_num){
        aux = j_num;
        j_num = k_num;
        k_num = aux;
    }
  

    fprintf(txt,"pnt* j:%d k:%d corb:%s corp:%s\n",j_num,k_num,corBorda,corPreenchimento);
    int aux_j_num = j_num; 

    for(j_num; j_num <= k_num; j_num++){
        sprintf(j, "%d", j_num);
        Forma forma = get(listaForma, j);
        Texto texto = get(listaTexto, j);

        if(forma != NULL){  
            if(strcmp(getTipoForma(forma), "c") == 0 ){
                fprintf(txt,"id:%s\n",getIdForma(forma));
                fprintf(txt,"tipo:circulo\n");
                fprintf(txt,"raio:%lf\n",getRaioForma(forma));
                fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
                fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
                fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
            }
            else if(strcmp(getTipoForma(forma), "r") == 0 ){
                fprintf(txt,"id:%s\n",getIdForma(forma));
                fprintf(txt,"tipo:retangulo\n");
                fprintf(txt,"altura:%lf\n",getHForma(forma));
                fprintf(txt,"comprimento:%lf\n",getWForma(forma));
                fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
                fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
                fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
            }  
            setcorBordaForma(forma, corBorda);
            setcorPreenchimentoForma(forma, corPreenchimento);
        }
        if(texto != NULL){
            if(strcmp(getTipoTexto(texto), "t") == 0 ){
                fprintf(txt,"id:%s\n",getIdTexto(texto));
                fprintf(txt,"tipo:texto\n");
                fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXTexto(texto),getYTexto(texto));
                fprintf(txt,"cor borda:%s\n",getcorBordaTexto(texto));
                fprintf(txt,"cor preenchimento:%s\n",getcorPreenchimentoTexto(texto));
                fprintf(txt,"conteudo:%s\n", getConteudoTexto(texto));
                setcorBordaTexto(texto, corBorda);
                setcorPreenchimentoTexto(texto, corPreenchimento);
            }
        }  
    }
}

void consulta_delf(Lista listaForma, Lista listaTexto, char j[], FILE *svg2, FILE *txt){
    Forma forma = get(listaForma, j);
    Texto texto = get(listaTexto, j);

    fprintf(txt,"delf j:%s\n",j);

    if(forma != NULL){  
        if(strcmp(getTipoForma(forma), "c") == 0 ){
            fprintf(txt,"id:%s\n",getIdForma(forma));
            fprintf(txt,"tipo:circulo\n");
            fprintf(txt,"raio:%lf\n",getRaioForma(forma));
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
            fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
            fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
        }
        else if(strcmp(getTipoForma(forma), "r") == 0 ){
            fprintf(txt,"id:%s\n",getIdForma(forma));
            fprintf(txt,"tipo:retangulo\n");
            fprintf(txt,"altura:%lf\n",getHForma(forma));
            fprintf(txt,"comprimento:%lf\n",getWForma(forma));
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
            fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
            fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
        }  
        remover(listaForma, j);
    }
    if(texto != NULL){  
        if(strcmp(getTipoTexto(texto), "t") == 0){
        fprintf(txt,"id:%s\n",getIdTexto(texto));
        fprintf(txt,"tipo:texto\n");
        fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXTexto(texto),getYTexto(texto));
        fprintf(txt,"cor borda:%s\n",getcorBordaTexto(texto));
        fprintf(txt,"cor preenchimento:%s\n",getcorPreenchimentoTexto(texto));
        fprintf(txt,"conteudo:%s\n", getConteudoTexto(texto));
        remover(listaTexto, j);
        }
    } 
    
}

void consulta_delf_2 (Lista listaForma, Lista listaTexto, int j_num, int k_num, FILE *svg2, FILE *txt){
int id_j, id_k, aux;
char j[32];

   if(j_num > k_num){
        aux = j_num;
        j_num = k_num;
        k_num = aux;
    }

    fprintf(txt,"delf* j:%d k:%d\n",j_num, k_num);
    int id_j_aux = id_j;

    for(j_num; j_num <= k_num; j_num++){
        sprintf(j, "%d", j_num);
        Forma forma = get(listaForma, j);
        Texto texto = get(listaTexto, j);

        if(forma != NULL){
            if(strcmp(getTipoForma(forma), "c") == 0 ){
                fprintf(txt,"id:%s\n",getIdForma(forma));
                fprintf(txt,"tipo:circulo\n");
                fprintf(txt,"raio:%lf\n",getRaioForma(forma));

                fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
                fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
                fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
            }
            else if(strcmp(getTipoForma(forma), "r") == 0 ){
                fprintf(txt,"id:%s\n",getIdForma(forma));
                fprintf(txt,"tipo:retangulo\n");
                fprintf(txt,"altura:%lf\n",getHForma(forma));
                fprintf(txt,"comprimento:%lf\n",getWForma(forma));
                fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXForma(forma),getYForma(forma));
                fprintf(txt,"cor borda:%s\n",getcorBordaForma(forma));
                fprintf(txt,"cor preenchimento:%s\n\n",getcorPreenchimentoForma(forma));
            }  
            remover(listaForma, j);
        }
        if(texto != NULL){
            if(strcmp(getTipoTexto(texto), "t") == 0 ){
                fprintf(txt,"id:%s\n",getIdTexto(texto));
                fprintf(txt,"tipo:texto\n");
                fprintf(txt,"(X,Y) = (%lf,%lf)\n",getXTexto(texto),getYTexto(texto));
                fprintf(txt,"cor borda:%s\n",getcorBordaTexto(texto));
                fprintf(txt,"cor preenchimento:%s\n",getcorPreenchimentoTexto(texto));
                fprintf(txt,"conteudo:%s\n", getConteudoTexto(texto));
            }
            remover(listaTexto, j);
        }
    }
}

void consulta_dq(Lista listaForma,Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, char aux[], char j[], double r, bool verificador, FILE *svg2, FILE* txt){
    char id[32], *tipo_elemento;
    double raio;

    Elemento elemento;
        
    if(verificador){
        
        strcpy(id, j);
        raio = r;
    }else{
        strcpy(id, aux);
        raio = r;

    }
    elemento = encontrarElementoListas(id, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase);
    tipo_elemento = encontrarTipo(id, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase);
    if(strcmp(aux,"#") == 0){
        fprintf(txt, "dq: # cep:%s raio:%lf\n",id, raio);
    }
    else{
        fprintf(txt, "dq: cep:%s raio:%lf\n",id, raio);
    }
    
    Dq_percorrer(listaQuadra, elemento, raio, tipo_elemento, txt, svg2, verificador);
    anelGrosso(svg2, elemento, tipo_elemento);
    fprintf(txt,"\n\n");
}

void consulta_del(FILE* aux, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, char id[], FILE *svg2, FILE *txt){
    char *tipo;
    Elemento elemento;
    double x, y;

    elemento = encontrarElementoListas(id, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase);
    tipo = encontrarTipo(id, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase);
    fprintf(txt,"del: cep|id:%s\n",id);
    if(elemento != NULL){
        if (strcmp(tipo, "q") == 0){
            x = getXQuadra(elemento) + getWQuadra(elemento)/2;
            y = getYQuadra(elemento) + getHQuadra(elemento)/2;
            fprintf (txt, "Quadra x = %lf y = %lf w = %lf h = %lf\n\n", getXQuadra (elemento), getYQuadra (elemento), getWQuadra (elemento), getHQuadra (elemento));
            remover(listaQuadra, id);
            svg_imprimir_linha(aux, x, y, x, 0, "black");
            fprintf(svg2, "\n\t<text\n\t\tx=\"%lf\"", x + 10);
            fprintf(svg2, "\n\t\ty=\"0\"");
            fprintf(svg2, "\n\t\tstroke=\"black\"");
            fprintf(svg2, "\n\t\tfill=\"black\">");
            fprintf(svg2, "\n\t\t%s", id);
            fprintf(svg2, "\n\t</text>\n");
        }
        if (strcmp(tipo, "h") == 0){
            fprintf (txt, "Hidrante x = %lf y = %lf\n\n", getXHid (elemento), getYHid(elemento));
            remover(listaHidrante, id);
            svg_imprimir_linha(aux, getXHid(elemento), getYHid(elemento), getXHid(elemento), 0, "black");
            fprintf(svg2, "\n\t<text\n\t\tx=\"%lf\"", getXHid(elemento) + 10);
            fprintf(svg2, "\n\t\ty=\"0\"");
            fprintf(svg2, "\n\t\tstroke=\"black\"");
            fprintf(svg2, "\n\t\tfill=\"black\">");
            fprintf(svg2, "\n\t\t%s", id);
            fprintf(svg2, "\n\t</text>\n");
        }
        if (strcmp(tipo, "s") == 0){
            fprintf (txt, "Semaforo x = %lf y = %lf\n\n", getXSema (elemento), getYSema(elemento));
            remover(listaSemaforo, id);
            svg_imprimir_linha(aux, getXSema(elemento), getYSema(elemento), getXSema(elemento), 0, "black");
            fprintf(svg2, "\n\t<text\n\t\tx=\"%lf\"", getXSema(elemento) + 10);
            fprintf(svg2, "\n\t\ty=\"0\"");
            fprintf(svg2, "\n\t\tstroke=\"black\"");
            fprintf(svg2, "\n\t\tfill=\"black\">");
            fprintf(svg2, "\n\t\t%s", id);
            fprintf(svg2, "\n\t</text>\n");
        }
       if (strcmp(tipo, "rb") == 0){
            fprintf (txt, "Radio base x = %lf y = %lf\n\n", getXRB (elemento), getYRB(elemento));
            remover(listaRadioBase, id);
            svg_imprimir_linha(aux, getXRB(elemento), getYRB(elemento), getXRB(elemento), 0, "black");
            fprintf(svg2, "\n\t<text\n\t\tx=\"%lf\"", getXRB(elemento) + 10);
            fprintf(svg2, "\n\t\ty=\"0\"");
            fprintf(svg2, "\n\t\tstroke=\"black\"");
            fprintf(svg2, "\n\t\tfill=\"black\">");
            fprintf(svg2, "\n\t\t%s", id);
            fprintf(svg2, "\n\t</text>\n");
            
        }
    }
    else {
        fprintf (txt, "Elemento nao encontrado!\n\n");
    }
}

void consulta_crd(Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, char id[], FILE* svg2, FILE *txt){
    Elemento e;
    char *tipo;

    e = encontrarElementoListas(id, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase);
    tipo = encontrarTipo(id, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase);
    fprintf(txt,"crd: cep|id:%s\n",id);
    if(e != NULL){
        if(strcmp(tipo, "q") == 0){
            fprintf(txt, "Coordenadas do equipamento: x:%lf,  y:%lf\n", getXQuadra(e), getYQuadra(e));
            fprintf(txt, "Tipo: Quadra\n");
        }
        if(strcmp(tipo, "h") == 0){
            fprintf(txt, "Coordenadas do equipamento: x:%lf,  y:%lf\n", getXHid(e), getYHid(e));
            fprintf(txt, "Tipo do equip. urbano: Hidrante\n");
        }
        if(strcmp(tipo, "s") == 0){
            fprintf(txt, "Coordenadas do equipamento: x:%lf,  y:%lf\n", getXSema(e), getYSema(e));
            fprintf(txt, "Tipo do equip. urbano: Semaforo\n");
        }
        if(strcmp(tipo, "rb") == 0){
            fprintf(txt, "Coordenadas do equipamento: x:%lf,  y:%lf\n", getXRB(e), getYRB(e));
            fprintf(txt, "Tipo do equip. urbano: Radio base\n");
        }
    }else{
        fprintf(txt, "Elemento nao encontrado!\n");
    }
}

void consulta_cbq(Lista listaQuadra, char id[],FILE* svg2, FILE *txt, double x, double y, double r, char corB[]){

    fprintf(txt, "cbq: - x:%lf - y:%lf - r:%lf - cor da borda:%s\n", x, y, r, corB);
    cbqFunction(listaQuadra, txt, svg2, x, y, r, corB);
}

void consulta_car(FILE* aux, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase,
    FILE* svg2, FILE* txt, double x, double y, double w, double h){
    double area = 0;
    char a[32];
    Texto text;
    fprintf(txt,"car: retangulo: - x:%lf - y:%lf - w:%lf - h:%lf\n",x,y,w,h);
    Forma ret = criarForma("0", "r", x, y, 0, w, h, "black", "none", "1.0");
    area = carFunction(aux, txt, listaQuadra, listaHidrante, listaSemaforo, listaRadioBase, x, y ,h ,w);
    svg_imprimir_forma(aux, ret);
    svg_imprimir_linha(aux, x, y, x, 0, "black");
    sprintf(a, "%lf", area);
    text = criarTexto("0", "t", x, 0, "white", "black", a);
    svg_imprimirTexto(aux, text);
    freeForma(ret);
    freeTexto(text);
}