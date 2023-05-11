#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

#define MAX_CHAR 100

struct contact{
  char nome[MAX_CHAR];
  int idade;
  long unsigned tel;
  char email[MAX_CHAR];
};

struct agenda{
  char nome[MAX_CHAR];
  int cod;
  int num;
  Node2 *contato;
};

struct no_lista_Agenda{
  Agenda dado;
  Node *prox;
};

struct no_lista_Contato{
  contatos dado;
  Node2 *prox;
};

void editar_char(char *alvo){
  if (alvo == NULL){
    printf("Erro ao alocar memória\n");
    exit(1);
  }
  fgets(alvo, MAX_CHAR, stdin);
  alvo[strcspn(alvo, "\n")] = '\0';
}

Node *criar_lista_Agenda(void){
  Node *inicio = (Node *)malloc(sizeof(Node));
  if (inicio == NULL){
    printf("Erro ao tentar alocar memória");
    exit(1);
  }
  inicio->dado.cod = 0; 
  inicio->prox = NULL;
  return inicio;
}

Node *lista_busca_Agenda(int elemento, Node *l, Node **anterior){
  Node *p;
  for (p = l; p != NULL; p = p->prox){
    if (p->dado.cod == elemento){
      return p;
    }if (anterior != NULL){
      *anterior = p;
    }
  }
  return NULL;
}

void lista_retira_Agenda(Node *l, int v){
  Node **anteriorAddress = (Node **)malloc(sizeof(Node *));
  if (anteriorAddress == NULL){
    printf("Erro ao alocar memória!");
    exit(1);
  }
  Node *alvo = lista_busca_Agenda(v, l, anteriorAddress);
  Node *anterior = *anteriorAddress;
  if (alvo != NULL){
    if (anterior != NULL){
      anterior->prox = alvo->prox;
    }else{
      *l = *l->prox;
    }
  }
}

void lista_insere_Agenda(Node *l, Agenda v){
  Node *alvo = lista_busca_Agenda(0, l, NULL);
  alvo->dado = v;
  alvo->prox = (Node *)malloc(sizeof(Node));
}

int lista_vazia_Agenda(Node *l){ 
  return (l == NULL);
}

void lista_imprime_Agenda(Node *l, int quantidadeAdiciona){
  Node *p;
  for (p = l; p->prox != NULL; p = p->prox){
    printf("Nome = %s\nCódigo = %i\nNúmero = %i\n", p->dado.nome, p->dado.cod, p->dado.num);
  }
}

void lista_libera_Agenda(Node *l){
  Node *p = l;
  Node *temp;
  while (p != NULL){
    temp = p->prox;
    free(p);
    p = temp;
  }
}

Node2 *criar_lista_Contato(void){
  Node2 *start = (Node2 *)malloc(sizeof(Node2));
  if (start == NULL){
    printf("Erro ao tentar alocar memória");
    exit(1);
  }
  start->dado.idade = 0; 
  start->prox = NULL;
  return start;
}

Node2 *lista_busca_Contato(char *element, Node2 *m, Node2 **previous){
  Node2 *pointer;
  for (pointer = m; pointer != NULL; pointer = pointer->prox){
    if (strcmp(pointer->dado.nome, element) == 0){
      return pointer;
    }if (previous != NULL)
      *previous = pointer;
  }
  return NULL;
}

void lista_retira_Contato(Node2 *m, char *w){
  Node2 **previousAddress = (Node2 **)malloc(sizeof(Node2 *));
  if (previousAddress == NULL){
    printf("Erro ao alocar memória!");
    exit(1);
  }
  Node2 *target = lista_busca_Contato(w, m, previousAddress);
  Node2 *previous = *previousAddress;
  if (target != NULL){
    if (previous != NULL){
      previous->prox = target->prox;
    }else{
      *m = *m->prox;
    }
  }
}

void lista_insere_Contato(Node2 *m, contatos w){
  if (!m){
    printf("Contato sem endereço!\n");
    exit(1);
  }
  Node2 *target = lista_busca_Contato("\000", m, NULL); 
  target->dado = w;
  target->prox = (Node2 *)malloc(sizeof(Node2));
}

int lista_vazia_Contato(Node2 *m){
  return (m == NULL);
}

void imprime_contato(Node2 *contato){
  if (contato->dado.idade != 0){
    printf("\nNome: %s\nIdade: %u\nTelefone: %lu\nEmail: %s\n", contato->dado.nome, contato->dado.idade, contato->dado.tel, contato->dado.email);
  }
}

void lista_imprime_Contato(Node2 *m){
  Node2 *pointer;
  for (pointer = m; pointer->prox != NULL; pointer = pointer->prox){
    imprime_contato(pointer);
  }
}

void lista_libera_Contato(Node2 *m){
  Node2 *pointer = m;
  Node2 *interim;
  while (pointer != NULL){
    interim = pointer->prox;
    free(pointer);
    pointer = interim;
  }
}

void adiciona_contato(Node *l, int quantidadeAdiciona){
  int index, cod;
  for (index = 0; index < quantidadeAdiciona; index++){
    Node2 *contatoAdiciona = (Node2 *)malloc(sizeof(Node2));
    printf("%dº Contato:\n", index + 1);
    printf("\nNome:\n");
    editar_char(contatoAdiciona->dado.nome);
    printf("\nIdade:\n");
    scanf(" %u", &contatoAdiciona->dado.idade); getchar();
    printf("\nTelefone:\n");
    scanf(" %lu", &contatoAdiciona->dado.tel); getchar();
    printf("\nE-mail:\n");
    editar_char(contatoAdiciona->dado.email);
    printf("\nInforme o código da agenda destinatária desse contato: \n");
    scanf(" %i", &cod); getchar();
    Node *alvo = lista_busca_Agenda(cod, l, NULL);
    if (alvo){
      lista_insere_Contato(alvo->dado.contato, contatoAdiciona->dado);
      alvo->dado.num++;
      printf("\nContato inserido\n");
    } else{
      printf("\nEssa agenda não existe\nDeseja criar uma nova agenda com este código?\n");
      int escolha;
      printf("\n1 - Sim\n\n2 - Não\n");
      scanf(" %i", &escolha); getchar();
      switch (escolha){
      case 1:
        Agenda novaAgenda;
        printf("\nDigite o nome da agenda:\n");
        editar_char(novaAgenda.nome);
        novaAgenda.cod = cod;
        lista_insere_Agenda(l, novaAgenda);
        Node *novoAlvo = lista_busca_Agenda(cod, l, NULL);
        if (!novoAlvo){
          printf("\nProblema de alocação\n");
          exit(1);
        }
        novoAlvo->dado.num = 0;
        novoAlvo->dado.contato = (Node2 *)malloc(sizeof(Node2));
        lista_insere_Contato(novoAlvo->dado.contato, contatoAdiciona->dado);
        novoAlvo->dado.num++;
        printf("\nContato adicionado.\n\n");
        break;
      case 2:
        printf("\nVoltando para MENU...\n");
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA\n");
        break;
      }
    }
    free(contatoAdiciona);
  }
}

void remover_contato(Node *l){
  int cod;
  char *nome = (char *)malloc(MAX_CHAR * sizeof(char));
  if (nome == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  Node *alvoAgenda = (Node *)malloc(sizeof(Node));
  if (alvoAgenda == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  Node2 *alvo = (Node2 *)malloc(sizeof(Node2));
  if (alvo == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  printf("\nInforme a agenda em que o contato está para removê-lo:\n");
  scanf("%d", &cod); getchar();
  alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  if (!alvoAgenda){
    printf("\nAgenda não encontrada.\n");
    return;
  }
  printf("\nInforme o nome do contato que será removido: \n");
  editar_char(nome);
  alvo = lista_busca_Contato(nome, alvoAgenda->dado.contato, NULL);
  if (alvo){
    lista_retira_Contato(alvo, nome);
    alvoAgenda->dado.num--;
  }else{
    printf("\nContato não encontrado na agenda.\n");
    return;
  }
  printf("\nContato removido com sucesso!\n");
}

void imprimir_contatos_cadastrado(Node *l){ 
  int cod;
  printf("\nInforme o código da agenda para listar contatos: \n");
  scanf("%d", &cod); getchar();
  Node *alvo = lista_busca_Agenda(cod, l, NULL);
  if (!alvo){
    printf("\nAgenda não encontrada.\n");
    return;
  }
  gnomeSort(&alvo->dado.contato);
  Node2 *index;
  for (index = alvo->dado.contato; index != NULL; index = index->prox){
    imprime_contato(index);
    printf("\n");
  }
}

void editar_contato(Node *l){
  int cod;
  printf("\nInforme o código da agenda para editar um contato: \n");
  scanf("%d", &cod); getchar();
  Node *alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  if (!alvoAgenda){
    printf("\nAgenda não encontrada!\n");
    return;
  }
  printf("\nDigite o nome do contato que deseja editar: \n");
  char *nome = (char *)malloc(MAX_CHAR * sizeof(char));
  editar_char(nome);
  Node2 *alvoContato = lista_busca_Contato(nome, alvoAgenda->dado.contato, NULL);
  if (alvoContato != NULL){
    printf("\nDigite o novo nome: \n");
    editar_char(alvoContato->dado.nome);
    printf("\nDigite a idade: \n");
    scanf(" %u", &alvoContato->dado.idade); getchar();
    printf("\nDigite o novo número de telefone: \n");
    scanf(" %lu", &alvoContato->dado.tel); getchar();
    printf("\nDigite o novo endereço de e-mail: \n");
    editar_char(alvoContato->dado.email);
    printf("\nContato %s atualizado com sucesso!\n\n", alvoContato->dado.nome);
  }else{
    printf("\nContato %s não encontrado na agenda.\n", nome);
  }
}

void buscar_contato(Node *l){
  char *name = (char *)malloc(MAX_CHAR * sizeof(char));
  if (name == NULL){
    printf("Erro ao alocar memória\n");
    exit(1);
  }
  printf("\nDigite nome do contato:\n");
  editar_char(name);
  Node *p;
  Node2 *alvo;
  for (p = l; p != NULL; p = p->prox){ 
    alvo = lista_busca_Contato(name, p->dado.contato, NULL);
    if (alvo){ 
      imprime_contato(alvo);
      return;
    }else{ 
      alvo = NULL;
    }
  }
  printf("\nContato não encontrado.\n");
}

void consultar_contato_em_agenda(Node *l){
  int cod;
  printf("\nDigite o código da agenda que deseja buscar um contato: \n");
  scanf("%d", &cod); getchar();
  Node *alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  if (!alvoAgenda){
    printf("\nAgenda não encontrada!\n");
    return;
  }
  printf("\nDigite nome do contato: \n");
  char *alvo = (char *)malloc(MAX_CHAR * sizeof(char));
  editar_char(alvo);
  Node2 *alvoContato = lista_busca_Contato(alvo, alvoAgenda->dado.contato, NULL);
  if (alvoContato != NULL){
    imprime_contato(alvoContato);
  }else{
    printf("\nContato não encontrado.\n");
  }
}

void quantitativo_agenda(Node *l){
  int contador = 0;
  Node *index;

  for (index = l; index != NULL; index = index->prox){
    contador++;
  }
  printf("\nHá um total de %i agenda(s).\n", contador - 1);
}

void gnomeSort(Node2 **inicio){
  if (*inicio == NULL || (*inicio)->prox == NULL)
    return;

  Node2 *atual = *inicio;
  while (atual != NULL){
    if (atual->prox != NULL && atual->prox->dado.idade > 0 && strcmp(atual->dado.nome, atual->prox->dado.nome) > 0){
      contatos temp = atual->dado;
      atual->dado = atual->prox->dado;
      atual->prox->dado = temp;
      if (atual == *inicio)
        atual = atual->prox;
      else
        atual = *inicio;
    }else{
      atual = atual->prox;
    }
  }
}

void exportarAgenda(Node *inicio, char *nomeArquivo){ 
  FILE *arquivo = fopen("Agenda.txt", "w"); 
  if (arquivo == NULL){
    printf("Erro ao abrir o arquivo para escrita.\n"); 
    return;
  }

  Node *temp = inicio;
  while (temp != NULL){
    if (temp->dado.cod == 0){ 
      break;
    }
    fprintf(arquivo, "\nInformações da agenda\n\n"); 
    fprintf(arquivo, "Nome:\t%s\nCódigo:\t%d\nNúmero de contatos:\t%d\n\n", temp->dado.nome, temp->dado.cod, temp->dado.num); 
    Node2 *contato = temp->dado.contato;
    fprintf(arquivo, "Contatos da agenda\n\n"); 
    while (contato != NULL){ 
      fprintf(arquivo, "Nome: %s\nIdade: %d\nTelefone: %lu\nEmail: %s\n\n", contato->dado.nome, contato->dado.idade, contato->dado.tel, contato->dado.email);
      if (contato->prox != NULL && contato->prox->dado.idade > 0) 
        contato = contato->prox;
      else
        break; 
    }
    fprintf(arquivo, "Listagem de contatos chegou ao fim\n"); 
    fprintf(arquivo, "------------------------------------------------------------------------------------------\n\n");
    temp = temp->prox; 
  }
  fclose(arquivo);                           
}

Node *importarAgenda(char *nomeArquivo){    
  FILE *arquivo = fopen(nomeArquivo, "r"); 
  if (arquivo == NULL){                    
    printf("Erro ao abrir o arquivo para leitura.\n");
    return NULL;
  }

  Node *inicio = NULL; 
  Node *temp = NULL;   

  char linha_temp[MAX_CHAR]; 

  while (fgets(linha_temp, MAX_CHAR, arquivo) != NULL) 
  {
    if (linha_temp[strlen(linha_temp) - 1] == '\n'){ 
      linha_temp[strlen(linha_temp) - 1] = '\0';
    }if (strcmp(linha_temp, "Listagem de contatos chegou ao fim") == 0){ 
      if (inicio == NULL){ 
        inicio = temp; 
      }else{ 
        Node *ultimo = inicio;       
        while (ultimo->prox != NULL){ 
          ultimo = ultimo->prox; 
        }
        ultimo->prox = temp; 
      }
      temp = NULL;
    }else{ 
      if (temp == NULL){ 
        temp = (Node *)malloc(sizeof(Node)); 
        if (temp == NULL){ 
          printf("Alocação de memória mal sucedida");
          exit(1);
        }
        strcpy(temp->dado.nome, linha_temp); 
      }else if(temp->dado.contato == NULL){ 
        Node2 *contatoTemp= (Node2 *)malloc(sizeof(Node2)); 
        if(contatoTemp == NULL){
          printf("Alocação de memória mal sucedida"); 
          exit(1);
        }
        strcpy(contatoTemp->dado.nome, linha_temp); 
        temp->dado.contato = contatoTemp; 
      }else{ 
        Node2 *ultimo = temp->dado.contato; 
        while (ultimo->prox != NULL){ 
          ultimo = ultimo->prox;
        }
        Node2 *contatoTemp = (Node2 *)malloc(sizeof(Node2)); 
        strcpy(contatoTemp->dado.nome, linha_temp); 
        ultimo->prox = contatoTemp; 
      }
    }
  }
  fclose(arquivo); 
  return inicio; 
}