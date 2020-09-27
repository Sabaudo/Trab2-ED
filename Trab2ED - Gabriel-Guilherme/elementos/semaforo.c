#include"semaforo.h"
struct StSemaforo {
    char  id[50], tipo[4], corBorda[32],corPreenchimento[32], sw[20];
    double x, y;
    
};

typedef struct StSemaforo *SemaforoImp;

Semaforo criaSemaforo (char id[], char tipo[], double x, double y, char corBorda[], char corPreenchimetno[], char sw[]){
    SemaforoImp novo;
    novo = (SemaforoImp) malloc (sizeof (struct StSemaforo));
    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    strcpy(novo->tipo,"s");
    strcpy (novo->corBorda, corBorda);
    strcpy (novo->corPreenchimento, corPreenchimetno);
    strcpy (novo->sw, sw);
    return novo;
}

double getXSema(Semaforo semaforo){
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->x; 
}

double getYSema(Semaforo semaforo){
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->y; 
}

char* getIDSema(Semaforo semaforo){
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->id;
}

char* getcorBordaSema(Semaforo semaforo){
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->corBorda;
}

char* getcorPreenchimentoSema(Semaforo semaforo){
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->corPreenchimento;
}

char* getSWSema(Semaforo semaforo){
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->sw;
}

void freeSemaforo(Semaforo semaforo){
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    free (s);
}