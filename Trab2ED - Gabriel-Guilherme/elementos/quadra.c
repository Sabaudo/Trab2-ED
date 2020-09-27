#include"quadra.h"
struct StQuadra {
    char  cep[50], corBorda[32], corPreenchimento[32], tipo[4], sw[32];
    double x, y, w, h;
   
};

typedef struct StQuadra *QuadraImp;

Quadra criaQuadra (char cep[], char tipo[], double x, double y, double w, double h, char corBorda[], char corPreenchimento[], char sw[]){
    QuadraImp novo;
    novo = (QuadraImp)malloc(sizeof(struct StQuadra));

    strcpy(novo->cep, cep);
    novo->x = x;
    novo->y = y;
    novo->w = w;
    novo->h = h;
    strcpy(novo->tipo,"q");
    strcpy(novo->corBorda, corBorda);
    strcpy(novo->corPreenchimento, corPreenchimento);
    strcpy(novo->sw, sw );

    return novo;
}

char* getcorBordaQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->corBorda;
}

char* getcorPreenchimentoQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->corPreenchimento;
}

char* getCEPQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->cep;
}

double getXQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->x; 
}

double getYQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->y; 
}

double getWQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->w; 
}

double getHQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->h; 
}

char* getSWQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->sw;
}

void setcorBordaQuadra(Quadra quadra, char corBorda[]){
    QuadraImp q;
    q = (QuadraImp) quadra;
    strcpy(q->corBorda, corBorda);
}


void freeQuadra (Quadra quadra){
    QuadraImp q;
    q = (QuadraImp) quadra;
    free (q);
}