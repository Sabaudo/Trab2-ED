#ifndef __lista__
#define __lista__

//TADS
typedef void* No;
typedef void* Lista;
typedef void* Elemento;

/*
*   cria uma lista vazia
*   sem requerimentos
*   retorna uma lista vazia
*/
Lista create();

/*
*   insere um elemento na lista
*   necessita de uma lista iniciada
*   nao retorna nada
*/
void insert(Lista l, Elemento elemento, char tipo[]);

/*
*   imprime todos os elementos da lista
*   uma lista com pelo menos um elemento
*   nao retorna nada
*/
void print(FILE* svg, Lista l);

/*
*   procura o elemento na lista
*   necessita de uma lista iniciada
*   retorna o elemento especificado
*/
No get(Lista l, char id[]);


/*
*   procura o tipo do elemento na lista
*   necessita de uma lista iniciada
*   retorna o tipo do elemento especificado
*/
char* getTipo(Lista l, char id[]);


/*
*   remove um elemento especificado
*   necessita de pelo menos 1 elemento na lista
*   nao retorna nada
*/
void remover (Lista l, char id[]);

/*
*    insere um elemento antes do id inserido
*    necessita uma lista iniciada
*    nao retornada nada
*/
void insertBefore(Lista l, Elemento elemento, char id[], char *tipo);


/*
*    insere um elemento depois do id inserido
*    necessita uma lista iniciada
*    nao retornada nada
*/
void insertAfter(Lista l, Elemento elemento, char id[], char *tipo);


/*
*   pega o primeiro elemento da lista
*   necessita uma lista com pelo menos 1 elemento
*   retorna o primeiro elemento
*/
No getFirst(Lista l);


/*
*   pega o ultimo elemento da lista
*   necessita uma lista com pelo menos 1 elemento
*   retorna o ultimo elemento
*/
No getLast(Lista l);


/*
*   pega o elemento seguinte do id inserido
*   necessita de uma lista com pelo menos mais de 1 elemento
*   retorna o proximo elemento do id inserido
*/
No getNext(Lista l, char id[]);


/*
*   pega o elemento anterior do id inserido
*   necessita de pelo menos uma lista com mais de 1 elemento
*   retorna o elemento anterior do id inserido
*/  
No getPrevious(Lista l, char id[]);


/*
*   percorre as listas para efetuar o comando qry dq
*   necessita do comando dq ter sido chamado
*   nao retorna nada
*/
void Dq_percorrer(Lista quadra, Elemento e, double r, char tipo[], FILE *txt, FILE* svg2, bool verificador);

/*
*   percorre as quadras para mudar as cores dos respectivos ceps lidos
*   necessita do comando cbq ter sido chamado
*   nao retorna nada
*/
void cbqFunction(Lista quadra,  FILE* txt, FILE* svg2, double x, double y, double r, char CorBorda[]);


/*
*   percorre as quadras para realizar os devidos calculos
*   necessita do comando car ter sido chamado
*   retorna a area total calculada
*/
double carFunction(FILE* aux, FILE* txt, Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase, double x, double y, double h, double w);


/*
*   percorre as listas para buscar os elementos que existem
*   necessita de elementos inseridos na lista
*   retorna o elemento existente
*/
No encontrarElementoListas(char id[], Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase);


/*
*   da free nas listas e nos elementos
*   necessita de uma lista com pelo menos 1 elemento
*   nao retorna nada
*/
void freeMem(Lista lista, void *freeElemento);


/*
*   percorre as listas para identificar o tipo do elemento desejado
*   necessita de uma lista com pelo menos 1 elemento
*   retorna o tipo do elemento encontrado
*/
char* encontrarTipo (char id[], Lista listaQuadra, Lista listaHidrante, Lista listaSemaforo, Lista listaRadioBase);

#endif
