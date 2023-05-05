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
 
struct no_lista_Agenda{
    Agenda dado;
    Node * prox;
};
struct no_lista_Contato{
  contatos dados;
  Node2 * proxi;
};
 
Node * criar_lista_Agenda(void){
  Node * inicio = (Node *) malloc (sizeof(Node));
  if(inicio == NULL){
    printf("Erro ao tentar alocar memória");
    exit(1);
    }
  // inicio->dado = NULL;
  inicio->dado.cod = 0; //verifica se o inicio setando o codigo é zero
  inicio->prox = NULL;
  return inicio;
}
 
Node * lista_busca_Agenda(int elemento, Node * l, Node** anterior){
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
 
void lista_retira_Agenda(Node * l, int v){
  Node** anteriorAddress = (Node**) malloc(sizeof(Node*));
  if(anteriorAddress == NULL){
    printf("Erro ao alocar memória!");
    exit(1);
  }
  Node * alvo = lista_busca_Agenda(v, l, anteriorAddress);
  Node * anterior = *anteriorAddress;
  if (alvo != NULL) {
    if (anterior != NULL) {
      anterior->prox = alvo->prox;
    } else {
      *l = *l->prox;
    }
  }
}
 
void lista_insere_Agenda(Node * l, Agenda v){
  // Node* l = lista principal
  // Agenda v = nova informação
  Node * alvo = lista_busca_Agenda(0,l,NULL);
  alvo->dado = v;
  alvo->prox = (Node*) malloc(sizeof(Node));
}
 
int lista_vazia_Agenda(Node * l){ // Questiona se lista está vazia
    return (l==NULL);
}
 
void lista_imprime_Agenda(Node * l){
    Node * p;
    for(p = l; p->prox != NULL; p = p->prox){
        printf("Nome = %s\nCódigo = %i\nNúmero = %i\n", p->dado.nome, p->dado.cod, p->dado.num);
    //lembrete: consertar erro de leitura do tipo de dado
    }
}
 
void lista_libera_Agenda(Node * l){
    Node * p = l;
    Node * temp;
    while (p != NULL) {
        temp = p->prox;
        free(p);
        p = temp;
    }
} //teste

Node2 * criar_lista_Contato(void){
  Node2 * start = (Node2 *) malloc (sizeof(Node2));
  if(start == NULL){
    printf("Erro ao tentar alocar memória");
    exit(1);
    }
  // inicio->dado = NULL;
  start->dados.idade = 0; //verifica se o start setando a idade é zero
  start->proxi = NULL;
  return start;
}

Node2 * lista_busca_Contato(int element, Node2 * m, Node2** previous){
  Node2 * pointer;
  for(pointer = m; pointer != NULL; pointer = pointer->proxi){
    if(pointer->dados.idade == element){
      return pointer;
    }
    if (previous != NULL)
      *previous = pointer;
  }
  return NULL;
}

void lista_retira_Contato(Node2 * m, int w){
  Node2** previousAddress = (Node2**) malloc(sizeof(Node2*));
  if(previousAddress == NULL){
    printf("Erro ao alocar memória!");
    exit(1);
  }
  Node2 * target = lista_busca_Contato(w, m, previousAddress);
  Node2 * previous = *previousAddress;
  if (target != NULL) {
    if (previous != NULL) {
      previous->proxi = target->proxi;
    } else {
      *m = *m->proxi;
    }
  }
}

void lista_insere_Contato(Node2 * m, contatos w){
  // Node* l = lista principal
  // Agenda v = nova informação
  Node2 * target = lista_busca_Contato(0,m,NULL);
  target->dados = w;
  target->proxi = (Node2*) malloc(sizeof(Node2));
}

int lista_vazia_Contato(Node2 * m){
  return (m==NULL);
}

void lista_imprime_Contato(Node2 * m){
  Node2 * pointer;
    for(pointer = m; pointer->proxi != NULL; pointer = pointer->proxi){
        printf("Nome = %s\nIdade = %u\nTelefone = %u\n", pointer->dados.nome, pointer->dados.idade, pointer->dados.tel);
    //lembrete: consertar erro de leitura do tipo de dado
    }
}

void lista_libera_Contato(Node2 * m){
  Node2 * pointer = m;
    Node2 * interim;
    while (pointer != NULL) {
        interim = pointer->proxi;
        free(pointer);
        pointer = interim;
    }
}

void adiciona_contato(){

}

void 

//buscando apenas dados de agendas (precisa buscar dados de contatos)

//adicionar contato -- agenda(criada - lista) contato() --------- criar uma função 

//remover contato -- agenda(criada - lista) contato () ----------- criar uma função

//listar contatos cadastrados ---------- imprimir contatos (ao optar por listar contatos questionar qual agenda deseja imprimir os contatos)

//editar o contato ------------- questionar de qual deseja editar

//buscar contato ------------ questionar de qual agenda

//consultar contato em uma dada agenda ----------------- questionar de qual agenda / talvez criar um arquivo texto separado para essa função

//consultar quantitativos de agendas ---------------- quantidade de agendas ou quantidade de contatos em uma agenda (?)

//gnomeSort -------------- duas funções uma pra contato outra para agenda

//arquivo texto ---------------- 1 para agenda e 1 para contato

//sair ----------- encerrar o programa
 
int main(void) {
  Node * lista = criar_lista_Agenda();
  Agenda novaAgenda;
  strcpy(novaAgenda.nome,"TESTE1");
  novaAgenda.num = 7;
  novaAgenda.cod = 235;
  lista_insere_Agenda(lista, novaAgenda);
  // Node* nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[1] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  // - Inserir o primeiro dado
  novaAgenda.num = 9;
  novaAgenda.cod = 236;
  strcpy(novaAgenda.nome,"TESTE2");
  lista_insere_Agenda(lista,novaAgenda);
  // nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[2] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  // - Inserir o segundo dado
  novaAgenda.num = 11;
  novaAgenda.cod = 237;
  strcpy(novaAgenda.nome,"TESTE3");
  lista_insere_Agenda(lista,novaAgenda);
  // nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[3] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  lista_imprime_Agenda(lista);
  printf("------------------------------------------------\n");
  lista_retira_Agenda(lista,235);
  lista_imprime_Agenda(lista);
  lista_libera_Agenda(lista);

  printf("\n\n\n");


  Node2 * lista2 = criar_lista_Contato();
  contatos novoContato;
  strcpy(novoContato.nome,"TESTE1.2");
  novoContato.tel = 19915126639;
  novoContato.idade = 19;
  lista_insere_Contato(lista2, novoContato);
  novoContato.tel = 18625488658;
  novoContato.idade = 23;
  strcpy(novoContato.nome,"TESTE2.2");
  lista_insere_Contato(lista2, novoContato);
  novoContato.tel = 11625488658;
  novoContato.idade = 23;
  strcpy(novoContato.nome,"TESTE3.2");
  lista_insere_Contato(lista2, novoContato);
  lista_imprime_Contato(lista2);
  printf("------------------------------------------------\n");
  lista_retira_Contato(lista2, 19);
  lista_imprime_Contato(lista2);
  lista_libera_Contato(lista2);


  //menu de opções
  return 0;
}


///////////////////////////////////////////////////LISTA DE COISAS FEITAS PARCIALMENTE//////////////////////////////////////////////
//-LISTAS DE AGENDA E CONTATO







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 
Lista* lista_insere_ordenada(Node * l, Agenda* v){
    Node * novo;
    Node * ant = NULL;
    Node * p = l;
    while(p != NULL && p->dado < v){
        ant = p;
        p = p->prox;
    }
    novo = (Node*) malloc(sizeof(Node));
    if(novo == NULL){
        printf("Erro de alocação de memória");
        exit(1);
    }
    novo->dado = v;
    if(ant == NULL){
        novo->prox = l;
        l = novo;
    }
    else {
        novo->prox = ant-> prox;
        ant->prox = novo;
    }
    return l;
}

void adiciona(){
  if (lista.inicio == NULL){
    criar_inicio();
  } 
}
*/