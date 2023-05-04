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
    Agenda dado;
    Node * prox;
};
 
Node * criar_lista(){
  Node * inicio = (Node *) malloc (sizeof(Node));
    if(inicio == NULL){
        printf("Erro ao tentar locar memória");
    exit(1);
    }
  // inicio->dado = NULL;
  Agenda agenda;
  strcpy(agenda.nome,"");
  inicio->dado = agenda;
  inicio->prox = NULL;
  return inicio;
}
 
Node * lista_busca(char* elemento, Node* l){
    Node* p;
    for(p=l; p!=NULL; p=p->prox){
        if(strcmp(p->dado.nome,elemento)==0){
            return p;
    }
    }
    return (elemento=NULL) ? p: NULL;
  // return NULL;
}
 
void lista_insere(Node* l, Agenda v){
  // Node* l = lista principal
  // Agenda* v = nova informação
  Node* alvo = lista_busca(NULL,l);
  alvo->dado = v;
  alvo->prox = NULL;
  /*
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL){
    printf("ERRO - memoria insuficiente!");
    exit(1);
  }
    strcpy(v.nome, novo);
  */
}
 
int lista_vazia(Node* l){ // Questiona se lista está vazia
    return (l==NULL);
}
 
int main(void) {
    Node* lista = criar_lista();
    // Agenda* novaAgenda = (Agenda*) malloc(sizeof(Agenda));
    Agenda novaAgenda;
    // novaAgenda->num = 7;
    strcpy(novaAgenda.nome,"PIROCA");
    novaAgenda.num = 7;
    lista_insere(lista, novaAgenda);
    Node* nodaAlvo = lista_busca(novaAgenda.nome, lista);
    printf("[1] Valor do Num: %i\n", nodaAlvo->dado.num);
    novaAgenda.num = 9;
    printf("[1] Valor do Num: %i\n", nodaAlvo->dado.num);
    /*
    lista_insere(lista,novaAgenda);
    nodaAlvo = lista_busca(novaAgenda, lista);
    printf("[2] Valor do Num: %i\n", nodaAlvo->dado->num);
    */
    /*
    while (lista != NULL) {
      lista = lista->prox;
    }
    */
    return 0;
}
/*
 
 
void lista_imprime(Lista*l){
    Lista* p;
    for(p = l; p != NULL; p = p->prox){
        printf(" Info = %s \n", p->dado); //lembrete: consertar erro de leitura do tipo de dado
    }
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
 
struct no{
    Agenda dado;
    No *prox;
};
 
struct lista{
    No * inicio;
};
 
void adiciona(){
  if (lista.inicio == NULL){
    criar_inicio();
  } 
}
*/
 