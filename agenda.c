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
    contatos *contato;
};

struct lista{
	Agenda* dado;
	Lista* prox;
};
 
Lista* cria_lista(void){
	return NULL;
}

Lista* insere_lista(Lista* l, Agenda dado){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	if (novo == NULL)
    {
        printf("ERRO - memoria insuficiente!");
        exit(1);
    }
	strcpy(dado.nome, novo);
    strcpy(char* prox = l, novo);
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


/*int main(){
Lista* l = lst_cria(); 
	l = lst_insere(l, 2); 
	l = lst_insere(l, 5);
	l = lst_insere(l, 4);
	l= lst_retira(l, 2);
	l= lst_busca(4, l);
	lst_imprime(l);
}*/





/*struct flano{
    flacontatos dado;
    no *prox;
};
 
struct lista{
    no * inicio;
};
 
void criar_inicio(flalista *lista, flacontatos dado){
    no * novo = (no*) malloc (sizeof(no));
    novo =! NULL ? novo->prox = NULL : novo;
    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}*/
 
void adiciona(){
  /*if (lista.inicio == NULL){
    criar_inicio();
  } */
}
 