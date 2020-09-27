#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include"lista.h"
#include"svg.h"
#include"util.h"
#include"./elementos/quadra.h"
#include"./elementos/hidrante.h"
#include"./elementos/semaforo.h"
#include"./elementos/radioBase.h"
#include"./elementos/texto.h"


typedef struct N{
    void *info;
	char tipo[4];
    struct N *anterior;
    struct N *proximo;
} no;

typedef struct L{
    no *primeiro;
    no *ultimo;
    int size;
} list;

Lista create(){
    list* lista = (list*) malloc(sizeof(list));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
	lista->size = 0;
    return lista;
}

void insert(Lista l, Elemento elemento, char tipo[]){
    list* lista = (list*) l;

    no* node = (no*) malloc(sizeof(no));
    node->info = elemento;
	strcpy(node->tipo, tipo);
    if(lista->primeiro == NULL) {
        node->anterior = NULL;
        lista->primeiro = node;
    } else {
        lista->ultimo->proximo = node;
        node->anterior = lista->ultimo;
    }
    lista->size++;
    node->proximo = NULL;
    lista->ultimo = node;
}

void print(FILE*svg, Lista l){
    int i = 1;

    list* lista = (list*) l;
    no* node = lista->primeiro;
    while(node != NULL) {
		if(strcmp(node->tipo, "c") == 0){
			svg_imprimir_forma(svg, node->info);
		}else if(strcmp(node->tipo, "r") == 0){
			svg_imprimir_forma(svg, node->info);
		}else if(strcmp(node->tipo, "q") == 0){
			svg_imprimir_quadra(svg, node->info);
		}else if(strcmp(node->tipo, "h") == 0){
			svg_imprimir_hidrante(svg, node->info);
		}else if(strcmp(node->tipo, "s") == 0){
			svg_imprimir_semaforo(svg, node->info);
		}else if(strcmp(node->tipo, "rb") == 0){
			svg_imprimir_rb(svg, node->info);
		}else if(strcmp(node->tipo, "t") == 0){
			svg_imprimirTexto(svg, node->info);
		}

        node = node->proximo;
        i++;
    }
}


No get(Lista l, char id[]){
    list* lista = (list*) l;
	no *node = lista->primeiro;
	while(node != NULL){
		if(strcmp(node->info,id) == 0){
			return node->info;
		}
		node = node->proximo;
	}
	return NULL;
}

void Dq_percorrer(Lista quadra, Elemento e, double r, char tipo[], FILE *txt, FILE* svg2, bool verificador){
	list* lista = (list*) quadra;
	no *node = lista->primeiro;
	double x, y;
	if(strcmp(tipo, "h") == 0){
		x = getXHid(e);
		y = getYHid(e);
		fprintf(txt, "Elemento urbano: %s\n", getIDHid(e));
	}else if(strcmp(tipo, "s") == 0){
		x = getXSema(e);
		y = getXSema(e);
		fprintf(txt, "Elemento urbano: %s\n", getIDSema(e));
	}else if(strcmp(tipo, "rb") == 0){
		x = getXRB(e);
		y = getYRB(e);
		fprintf(txt, "Elemento urbano: %s\n", getIDRB(e));
	}
	int cont=0;
	while(node != NULL){
		if(distanciaEuclidiana(x, y, getXQuadra(node->info), getYQuadra(node->info) <= r))
			cont++;
		if (distanciaEuclidiana (x, y, getXQuadra (node->info) + getWQuadra (node->info), getYQuadra (node->info)) <= r) 
            cont++;
        if (distanciaEuclidiana (x, y, getXQuadra (node->info), getYQuadra (node->info) + getHQuadra (node->info)) <= r) 
            cont++;
        if (distanciaEuclidiana (x, y, getXQuadra (node->info) + getWQuadra (node->info), getYQuadra (node->info) + getHQuadra (node->info)) <= r) 
            cont++;
		if (cont == 4){
			fprintf(txt, "Cep removido: %s\n", getCEPQuadra(node->info));
			if(verificador){
				svg_imprimir_quadArrend(svg2, node->info);
				remover(quadra, getCEPQuadra(node->info));
			}else{
				remover(quadra, getCEPQuadra(node->info));
			}
			
		}
		cont=0;
		node = node->proximo;
	}
	fprintf(txt, "\n");
}

void cbqFunction(Lista quadra, FILE* txt, FILE* svg2, double x, double y, double r, char CorBorda[]){
	list* lista = (list*) quadra;
	no *node = lista->primeiro;

	int cont=0;
	while(node != NULL){
		if(distanciaEuclidiana(x, y, getXQuadra(node->info), getYQuadra(node->info) <= r))
			cont++;
		if (distanciaEuclidiana (x, y, getXQuadra (node->info) + getWQuadra (node->info), getYQuadra (node->info)) <= r) 
			cont++;
		if (distanciaEuclidiana (x, y, getXQuadra (node->info), getYQuadra (node->info) + getHQuadra (node->info)) <= r) 
			cont++;
		if (distanciaEuclidiana (x, y, getXQuadra (node->info) + getWQuadra (node->info), getYQuadra (node->info) + getHQuadra (node->info)) <= r) 
			cont++;
		if (cont == 4){
			setcorBordaQuadra(node->info, CorBorda);
			fprintf(txt, "Cep da quadra alterada: %s\n", getCEPQuadra(node->info));
		}
		cont=0;
		node = node->proximo;
	}
	fprintf(txt, "\n");
}

double carFunction(FILE* aux, FILE* txt, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, double x, double y, double h, double w){
	double areaQuadra = 0, areaHid = 0, areaSema = 0, areaRB = 0;
	double areaTotal=0;
	int cont = 0;
	char aq[32];
	list* lista;
	no *node;
	lista = (list*) listaQuadra;
	node = lista->primeiro;
	while(node != NULL){
		if (getXQuadra (node->info) > x && getXQuadra (node->info) < x + w && getYQuadra (node->info) > y && getYQuadra (node->info) < y + h)
			cont++;
		if (getXQuadra (node->info) + getWQuadra (node->info) > x && getXQuadra (node->info) + getWQuadra (node->info) < x + w && getYQuadra (node->info) > y && getYQuadra (node->info) < y + h)
			cont++;
		if (getXQuadra (node->info) > x && getXQuadra (node->info) < x + w && getYQuadra (node->info) + getHQuadra (node->info) > y && getYQuadra (node->info) + getHQuadra (node->info) < y + h)
			cont++;
		if (getXQuadra (node->info) + getWQuadra (node->info) > x && getXQuadra (node->info) + getWQuadra (node->info) < x + w && getYQuadra (node->info) + getHQuadra (node->info) > y && getYQuadra (node->info) + getHQuadra (node->info) < y + h)
			cont++;
		if(cont == 4){			
			areaQuadra += getHQuadra(node->info) * getWQuadra(node->info);
			areaTotal = areaTotal + areaQuadra;
			sprintf(aq, "%.2lf", areaQuadra);
			Texto text = criarTexto("0", "t", (getXQuadra(node->info) + getWQuadra(node->info)/2), 
			(getYQuadra(node->info) + getHQuadra(node->info)/2), "white", "black", aq);
			svg_imprimirTexto(aux, text);
			fprintf(txt, "cep quadra:%s, area: %lf\n", getCEPQuadra(node->info), areaQuadra);
			freeTexto(text);
		}
		cont = 0; 
		node = node->proximo;
	}
	fprintf(txt, "Area total: %lf\n\n", areaTotal);
	return areaTotal;
}


char* getTipo(Lista l, char id[]){
    list* lista = (list*) l;
	no *node = lista->primeiro;
	while(node != NULL){
		if(strcmp(node->info,id) == 0){
			return node->tipo;
		}
		node = node->proximo;
	}
	return NULL;
}

No encontrarElementoListas (char id[], Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase){
	
    no* elemento;
    elemento = get(listaQuadra, id);
    if (elemento == NULL) elemento = get(listaHidrante, id);
    else return elemento;
    if (elemento == NULL) elemento = get(listaSemaforo, id);
    else return elemento;
    if (elemento == NULL) elemento = get(listaRadioBase, id);
    else return elemento;
    return elemento;    
}
char* encontrarTipo(char id[], Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase){
	
    no* elemento;
	char *tipo;
    elemento = get(listaQuadra, id);
	tipo = getTipo(listaQuadra, id);
    if (elemento == NULL){
		elemento = get(listaHidrante, id);
		tipo = getTipo(listaHidrante, id);
	}
    else return tipo;
    if (elemento == NULL){
		elemento = get(listaSemaforo, id);
		tipo = getTipo(listaSemaforo, id);
	}
    else return tipo;
    if (elemento == NULL){
		elemento = get(listaRadioBase, id);
		tipo = getTipo(listaRadioBase, id);
	}
    else return tipo;
    return tipo;
}

void remover (Lista l, char id[]){
	char aux1[32];
    list* lista = (list*) l;
	no *aux = lista->primeiro;
	no *aux_ant = NULL;
	int cont = 0;

	while(aux != NULL && (strcmp(aux->info, id) != 0)){
		cont++;
		aux_ant = aux;
		aux = aux->proximo;
	}
	if(aux == NULL){
		return;
	}
	if(aux_ant == NULL){
		lista->primeiro = aux->proximo;
		if(aux->proximo != NULL){
			aux->proximo->anterior = NULL;
		}else{
			lista->ultimo = NULL;
		}
		free(aux);
	}else if(aux->proximo == NULL){
		aux->anterior->proximo = NULL;
		lista->ultimo = aux->anterior;
		free(aux);
	}else{
		aux_ant->proximo = aux->proximo;
		aux->proximo->anterior = aux_ant;
		free(aux);
	}
	lista->size--;
}

void freeMem(Lista l, void *freeElemento){
    list* lista = (list*) l;
	if(l == NULL){
	}
	no *node  = lista->primeiro;
	void (*auxFree) (Elemento elemento) = freeElemento;

    if (node == NULL){
        free(lista);
        return;
    }

    while (1){
        if (node->proximo == NULL){
            auxFree (node->info);
            free (node);
            break;
        }
       	else {
			auxFree (node->info);
            node = node->proximo;
			if(node->anterior != NULL){
				free(node->anterior);
			}
        }	
    }
	free(lista);
}

void insertBefore(Lista l, Elemento elemento, char id[], char *tipo){
int aux;
    list* lista = (list*) l;
	if(id == 0){
		insert(lista, elemento, tipo);
	}else{
		no *atual = get(lista, id);
		if(atual != NULL){
			sprintf(id,"%d",aux);
			no *anterior = get(lista, id - 1);
			no *novono = (no *) malloc(sizeof(no));
			novono->info = elemento;
			anterior->proximo = novono;
			novono->proximo = atual;
			lista->size++;
		}
	}
}

void insertAfter(Lista l, Elemento elemento, char id[], char *tipo){
int aux;
    list* lista = (list*) l;
	if(id == 0){
		insert(lista, elemento, tipo);
	}else{
		no *atual = get(lista, id);
		if(atual != NULL){
			sprintf(id,"%d",aux);
			no *posterior = get(lista, id + 1);
			no *novono = (no *) malloc(sizeof(no));
			novono->info = elemento;
			atual->proximo = novono;
			novono->proximo = posterior;
			lista->size++;
		}
	}
}

No getFirst(Lista l){
    list* lista = (list*) l;
	if(lista->size > 0){
		no *node = lista->primeiro;
		return node;		
	}
    else{
	    return NULL;
    }
}

No getLast(Lista l){
    list* lista = (list*) l;
	if(lista->size != 0){
		no *node = lista->primeiro;
		while(node->proximo != NULL){
			node = node->proximo;
		}
		return node;
	}
	return NULL;
}

No getNext(Lista l, char id[]){
	int aux;
    list* lista = (list*) l;
	sprintf(id, "%d", aux);
	if(aux >= 0 && aux < lista->size){
		no *node = lista->primeiro;
		int acr = aux+1;
		for(int i = 0; i < acr; i++){
			node = node->proximo;
			if(node->proximo == NULL){
				return NULL;
			}
		return node;
		}
	}
	return NULL;
}

No getPrevious(Lista l, char id[]){
    list* lista = (list*) l;
	int aux;
	sprintf(id, "%d", aux);
	if(aux >= 0 && aux < lista->size){
		no *node = lista->primeiro;
		if(aux == 0){
			return NULL;
		}
		int acr = aux-1;
		int i = 0;
		while(i < acr){
			node = node->proximo;
			i++;
		}
		return node->info;
	}
	return NULL;
}






