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
  Node2 * contato;
};
 
struct no_lista_Agenda{
  Agenda dado;
  Node * prox;
};

struct no_lista_Contato{
  contatos dado;
  Node2 * prox;
};
 

void editar_char(char* alvo){
  if (alvo==NULL){
    printf("char possivelmente não alocado.\n");
    exit(1);
  }
  getchar(); // remove possível lixo do scanf
  fgets(alvo, MAX_CHAR, stdin);
  alvo[strcspn(alvo, "\n")] = '\0'; 
}

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
  start->dado.idade = 0; //verifica se o start setando a idade é zero
  start->prox = NULL;
  return start;
}

Node2 * lista_busca_Contato(char* element, Node2 * m, Node2** previous){
  Node2 * pointer;
  for(pointer = m; pointer != NULL; pointer = pointer->prox){
    if(strcmp(pointer->dado.nome, element)==0){
      return pointer;
    }
    if (previous != NULL)
      *previous = pointer;
  }
  return NULL;
}

void lista_retira_Contato(Node2 * m, char* w){
  Node2** previousAddress = (Node2**) malloc(sizeof(Node2*));
  if(previousAddress == NULL){
    printf("Erro ao alocar memória!");
    exit(1);
  }
  Node2 * target = lista_busca_Contato(w, m, previousAddress);
  Node2 * previous = *previousAddress;
  if (target != NULL) {
    if (previous != NULL) {
      previous->prox = target->prox;
    } else {
      *m = *m->prox;
    }
  }
}

void lista_insere_Contato(Node2 * m, contatos w){
  // Node* l = lista principal
  // Agenda v = nova informação
  Node2 * target = lista_busca_Contato(0,m,NULL);
  target->dado = w;
  target->prox = (Node2*) malloc(sizeof(Node2));
}

int lista_vazia_Contato(Node2 * m){
  return (m==NULL);
}

void lista_imprime_Contato(Node2 * m){
  Node2 * pointer;
    for(pointer = m; pointer->prox != NULL; pointer = pointer->prox){
        printf("Nome = %s\nIdade = %u\nTelefone = %u\n", pointer->dado.nome, pointer->dado.idade, pointer->dado.tel);
    //lembrete: consertar erro de leitura do tipo de dado
    }
}

void lista_libera_Contato(Node2 * m){
  Node2 * pointer = m;
    Node2 * interim;
    while (pointer != NULL) {
        interim = pointer->prox;
        free(pointer);
        pointer = interim;
    }
}

void imprime_contato(Node2 * contato){
  printf("Nome: %s\nIdade: %i\nTelefone: %i\nEmail: %s\n",contato->dado.nome,contato->dado.idade,contato->dado.tel,contato->dado.email);
}

void adiciona_contato(Node2 * add){ // Revisar
  int qnt_add, index;
  Node2 contatoADD;
  printf("quantidade add: \n");
  scanf("%d", &qnt_add);
  for(index = 0; index < qnt_add; index++){
    printf("Nome: \n");
    editar_char(contatoADD.dado.nome);
    printf("Idade: \n");
    scanf("%u", &contatoADD.dado.idade);
    printf("Telefone: \n");
    scanf("%u", &contatoADD.dado.tel);
    printf("E-mail: \n");
    editar_char(contatoADD.dado.email); 
    //contatos[*qnt_add] = contatoADD;
    //*contatoADD = contatoADD + 1;
    printf("Contato adicionado com sucesso!\n");
  }
}

void remover_contato(Node2 * contatos){
  int qnt_remove, index, cont, procura = 0;
  char* nome = (char*) malloc(MAX_CHAR*sizeof(char));
  if(nome == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  Node2* alvo = (Node2*) malloc(sizeof(Node2));
  if(alvo == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  printf("Quantos contatos deseja remover?\n");
  scanf("%d", &qnt_remove);
  for(index = 0; index < qnt_remove; index++){
    printf("Dite o nome do contato que deseja remover:\n");
    editar_char(nome);
    alvo=lista_busca_Contato(nome, contatos, NULL);
    if (alvo){
      lista_retira_Contato(alvo, nome);
    } else {
      printf("Contato não encontrado na agenda.\n");
      continue;
    }
    /*for (int index = 0; index < *contatoRemov; index++) { //adicionar nas funções de lista agenda: contatoRemov 
        if (strcmp(contatos[index].nome, nome) == 0) {
            procura = 1;
            for (int cont = index; cont < *contatoRemov - 1; cont++) {
                contatos[cont] = contatos[cont + 1];
            }
            (*contatosRemmov)--;
            printf("Contato \"%s\" removido com sucesso!\n", nome);
            break;
        }
    }
    if (!procura) {
        printf("Contato %s não encontrado na agenda.\n", nome);
    }*/
    //lista_retira_Contato(lista2, 19);
  }
  //return(contatoRemov);
}

void imprimir_contatos_cadastrado(Node * l){ // Imprimir contatos de uma agenda específica
  int cod; 
  printf("Dite o código da agenda para listar contatos:");
  scanf("%i",&cod);
  Node * alvo = lista_busca_Agenda(cod, l, NULL);
  Node2 * index;
  for(index = alvo->dado.contato; index != NULL; index = index->prox){
    printf("Nome: %s\nIdade: %u\nTelefone: %u\nEmail: %s\n", index->dado.nome, index->dado.idade, index->dado.tel, index->dado.email);
  }
  //lista_imprime_Contato(lista2);
}

void editar_contato(Node * l){ // Contato único
  int cod; 
  printf("Dite o código da agenda para editar um contato:");
  scanf("%i",&cod);
  Node * alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  printf("Digite o nome do contato que deseja editar:");
  char* nome = (char*) malloc(MAX_CHAR*sizeof(char));
  editar_char(nome);
  Node2 * alvoContato = lista_busca_Contato(nome, alvoAgenda->dado.contato, NULL);
  Node2 * index;
  if (alvoContato!=NULL) {
      printf("Digite a nova idade: \n");
      editar_char(alvoContato->dado.nome);
      printf("Digite o novo número de telefone: \n");
      scanf("%i", &alvoContato->dado.tel);
      getchar();
      printf("Digite o novo endereço de e-mail: \n");
      editar_char(alvoContato->dado.email);
      printf("Contato %s atualizado com sucesso!\n", nome);
  } else {
    printf("Contato %s não encontrado na agenda.\n", nome);
  }
}

void buscar_contato(Node * l){
  int cod;
  printf("Digite qual agenda deseja buscar um contato:\n");
  scanf("%i",&cod);
  Node * alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  printf("Digite nome do contato:\n");
  char * alvo = (char*)malloc(MAX_CHAR*sizeof(char));
  editar_char(alvo);
  Node2 * alvoContato = lista_busca_Contato(alvo, alvoAgenda->dado.contato, NULL);
  if (alvoContato!=NULL){
    imprime_contato(alvoContato);
  } else {
    printf("Contato não encontrado.\n");
  }
}

/*
void consultar_contato_em_agenda(){
  char nome[MAX_CHAR];
  printf("Digite o nome do contato: ");
  fgets(nome, MAX_CHAR, stdin);
  int index, procura = 0;
  for (index = 0; index < Contatos; index++) {
      if (strcmp(Agenda[index].contatos.nome, nome) == 0) {
          procura = 1;
          printf("Nome: %s\n", agenda[index].contatos.nome);
          printf("Idade: %u\n", agenda[index].contatos.idade);
          printf("Telefone: %u\n", agenda[index].contatos.tel);
          printf("E-mail: %s\n", agenda[index].contatos.email);
          break;
        }
    }
    if (!procura) {
        printf("Contato %s não encontrado na agenda.\n", nome);
    }
}
*/
void quantitativo_agenda(){

}

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
  contatos * Contato = (contatos*) malloc (sizeof(contatos));
  if(Contato == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  Node * lista = criar_lista_Agenda();
  Agenda novaAgenda;
  //menu
  adiciona_contato(Contato);
  remover_contato(Contato);
  imprimir_contatos_cadastrado(Contato);
  editar_contato(Contato);
  buscar_contato(Contato);
  //consultar_contato_agenda(Contato);
  //quantitativo_agenda(Agenda);





  //strcpy(novaAgenda.nome,"TESTE1");
  //novaAgenda.num = 7;
  //novaAgenda.cod = 235;
  //lista_insere_Agenda(lista, novaAgenda);
  // Node* nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[1] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  // - Inserir o primeiro dado
  //novaAgenda.num = 9;
  //novaAgenda.cod = 236;
  //strcpy(novaAgenda.nome,"TESTE2");
  //lista_insere_Agenda(lista,novaAgenda);
  // nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[2] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  // - Inserir o segundo dado
  //novaAgenda.num = 11;
  //novaAgenda.cod = 237;
  //strcpy(novaAgenda.nome,"TESTE3");
  //lista_insere_Agenda(lista,novaAgenda);
  // nodaAlvo = lista_busca(novaAgenda.cod, lista);
  // printf("[3] Valor do Num: %i\nValor do nome: %s\n", nodaAlvo->dado.num, nodaAlvo->dado.nome);
  //lista_imprime_Agenda(lista);
  printf("------------------------------------------------\n");
  //lista_retira_Agenda(lista,235);
  //lista_imprime_Agenda(lista);
  //lista_libera_Agenda(lista);

  printf("\n\n\n");


  //Node2 * lista2 = criar_lista_Contato();
  //contatos novoContato;
  ///strcpy(novoContato.nome,"TESTE1.2");
  //novoContato.tel = 19915126639;
  //novoContato.idade = 19;
  //lista_insere_Contato(lista2, novoContato);
  //novoContato.tel = 18625488658;
  //novoContato.idade = 23;
  //strcpy(novoContato.nome,"TESTE2.2");
  //lista_insere_Contato(lista2, novoContato);
  //novoContato.tel = 11625488658;
  //novoContato.idade = 23;
  //strcpy(novoContato.nome,"TESTE3.2");
  //lista_insere_Contato(lista2, novoContato);
  //lista_imprime_Contato(lista2);
  printf("------------------------------------------------\n");
  // lista_retira_Contato(lista2, 19);
  //lista_imprime_Contato(lista2);
  //lista_libera_Contato(lista2);


  //menu de opções
  return 0;
}


///////////////////////////////////////////////////LISTA DE COISAS FEITAS PARCIALMENTE//////////////////////////////////////////////
//-LISTAS DE AGENDA E CONTATO
//-MENU ADICIONAR CONTATO
//-MENU REMOVER CONTATO
//-MENU LISTAR CONTATO







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