#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agenda.h"
 
#define MAX_CHAR 100
 
struct contact{
    char nome[MAX_CHAR];
    int idade;
    int tel;
    char email[MAX_CHAR];
};
 
struct agenda{
    char nome[MAX_CHAR];
    int cod;
    int num;
    contatos * contato;
};

struct no_lista{
	Agenda * dado;
	Node * prox;
};

Node * criar_lista(Agenda dado){
    Node * inicio = (node *) malloc (sizeof(node));
	if(inicio == NULL){
		printf("Erro ao tentar locar memória")
	}
    inicio->dado = dado;
    inicio->prox = NULL;
    return inicio;
}
 
int main(void) {
    Node* inicio = create_list(1);
    Node* lista = inicio;
    while (lista != NULL) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    return 0;
}




/*Lista* cria_lista(void){
	return NULL;
}

Lista* lista_insere(Lista* l, Agenda v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	if (novo == NULL)
    {
        printf("ERRO - memoria insuficiente!");
        exit(1);
    }
	strcpy(v.nome, novo);
	novo->prox = l;
	return novo;
}

int lista_vazia(Lista *l){
	return (l==NULL);
}

void lista_imprime(Lista*l){
	Lista* p;
	for(p = l; p != NULL; p = p->prox){
		printf(" Info = %s \n", p->dado); //lembrete: consertar erro de leitura do tipo de dado
	}
}

Lista * lista_busca(Agenda* elemento, Lista* l){
	Lista * p;
	for(p=l; p!=NULL; p=p->prox){
		if(p->dado == elemento)
			return p;
	}
	return NULL;
}

Lista * lista_retira(Lista*l,  Agenda* v){
    Lista* ant = NULL; 
    Lista* p = l; 
    while(p->dado!=v){
    	if (p==NULL)
        	return l; 
        ant = p;
        p = p->prox;
    }
    
    if (ant==NULL)
        l = p->prox;
    else
        ant->prox = p->prox;
    free(p);
    return l;
}

void lista_libera(Lista* l){
    Lista* p = l;
    Lista* t;
    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}



Lista* lista_insere_ordenada(Lista * l, Agenda* v){
	Lista * novo;
	Lista * ant = NULL;
	Lista * p =l;
	while(p!=NULL && p->dado<v){
		ant = p;
		p = p->prox;
	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->dado = v;
	if(ant ==NULL){
		novo->prox = l;
		l = novo;
	}
	else {
		novo->prox = ant-> prox;
		ant->prox = novo;
	}
	return l;
}




/*struct no{
    Agenda dado;
    No *prox;
};
 
struct lista{
    No * inicio;
};
 
void adiciona(){
  /*if (lista.inicio == NULL){
    criar_inicio();
  } 
}*/
 