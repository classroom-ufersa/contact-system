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
        printf("Erro ao tentar alocar memória");
    exit(1);
    }
  // inicio->dado = NULL;
  inicio->dado.cod = 0;
  inicio->prox = NULL;
  return inicio;
}
 
Node * lista_busca(int elemento, Node * l, Node** anterior){
  Node * p;
  for(p = l; p != NULL; p = p->prox){
    if(p->dado.cod == elemento){
      return p;
    }
    if (anterior != NULL)
      *anterior = p;
  }
  return NULL;
}
 
void lista_retira(Node * l, int v){
  Node** anteriorAddress = (Node**) malloc(sizeof(Node*));
  if(anteriorAddress == NULL){
    printf("Erro ao alocar memória!");
  }
  Node * alvo = lista_busca(v, l, anteriorAddress);
  Node * anterior = *anteriorAddress;
  if (anterior == NULL){
  }
  if (alvo != NULL) {
    if (anterior != NULL) {
      anterior->prox = alvo->prox;
    } else {
      *l = *l->prox;
    }
  }
}
 
void lista_insere(Node * l, Agenda v){
  // Node* l = lista principal
  // Agenda v = nova informação
  Node * alvo = lista_busca(0,l,NULL);
  alvo->dado = v;
  alvo->prox = (Node*) malloc(sizeof(Node));
}
 
int lista_vazia(Node * l){ // Questiona se lista está vazia
    return (l==NULL);
}
 
void lista_imprime(Node * l){
    Node * p;
    for(p = l; p->prox != NULL; p = p->prox){
        printf("Nome = %s\nCódigo = %i\nNúmero = %i\n", p->dado.nome, p->dado.cod, p->dado.num);
    //lembrete: consertar erro de leitura do tipo de dado
    }
}


 
void lista_libera(Node * l){
    Node * p = l;
    Node * temp;
    while (p != NULL) {
        temp = p->prox;
        free(p);
        p = temp;
    }
} //teste

//adicionar contato -- lista_insere-agenda

//remover contato -- lista_retira-agenda

//listar contatos cadastrados

//editar o contato

//buscar contato -- lista_busca-agenda

//consultar contato em uma dada agenda

//consultar quantitativos de agendas

//gnomeSort

//arquivo texto

//sair
 
int main(void) {
  Node * lista = criar_lista();
  Agenda novaAgenda;
  strcpy(novaAgenda.nome,"TESTE1");
  novaAgenda.num = 7;
  novaAgenda.cod = 235;
  lista_insere(lista, novaAgenda);
  // Node* nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[1] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  // - Inserir o primeiro dado
  novaAgenda.num = 9;
  novaAgenda.cod = 236;
  strcpy(novaAgenda.nome,"TESTE2");
  lista_insere(lista,novaAgenda);
  // nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[2] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  // - Inserir o segundo dado
  novaAgenda.num = 11;
  novaAgenda.cod = 237;
  strcpy(novaAgenda.nome,"TESTE3");
  lista_insere(lista,novaAgenda);
  // nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[3] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  lista_imprime(lista);
  printf("------------------------------------------------\n");
  lista_retira(lista,235);
  lista_imprime(lista);
  lista_libera(lista);

  //menu de opções
  return 0;
}
 
 
/*
 
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