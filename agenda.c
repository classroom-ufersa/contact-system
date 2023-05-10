#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

#define MAX_CHAR 100

struct contact
{
  char nome[MAX_CHAR];
  int idade;
  long unsigned tel;
  char email[MAX_CHAR];
};

struct agenda
{
  char nome[MAX_CHAR];
  int cod;
  int num;
  Node2 *contato;
};

struct no_lista_Agenda
{
  Agenda dado;
  Node *prox;
};

struct no_lista_Contato
{
  contatos dado;
  Node2 *prox;
};

void exportarAgenda(Node *inicio, const char *nomeArquivo)
{
  FILE *arquivo = fopen(nomeArquivo, "w");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  Node *temp = inicio;
  while (temp != NULL)
  {
    if (temp->dado.cod == 0)
      break;
    fprintf(arquivo, "AGENDA_COMECO\n");
    fprintf(arquivo, "%s\n%d\n%d\n", temp->dado.nome, temp->dado.cod, temp->dado.num);
    fprintf(arquivo, "AGENDA_FIM\n");

    Node2 *contato = temp->dado.contato;
    fprintf(arquivo, "CONTATOS_COMECO\n");
    while (contato != NULL)
    {
      fprintf(arquivo, "%s\n%d\n%lu\n%s\n", contato->dado.nome, contato->dado.idade, contato->dado.tel, contato->dado.email);
      if (contato->prox != NULL)
        contato = contato->prox;
      else
        break;
    }

    fprintf(arquivo, "CONTATOS_FIM\n");

    temp = temp->prox;
  }

  fclose(arquivo);
  printf("Agenda exportada com sucesso.\n");
}

Node *importarAgenda(const char *nomeArquivo)
{
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo para leitura.\n");
    return NULL;
  }

  Node *inicio = NULL;
  Node *temp = NULL;

  char linha[MAX_CHAR];

  while (fgets(linha, MAX_CHAR, arquivo) != NULL)
  {
    if (linha[strlen(linha) - 1] == '\n')
    {
      linha[strlen(linha) - 1] = '\0';
    }

    if (strcmp(linha, "FIM_CONTATOS") == 0)
    {
      if (inicio == NULL)
      {
        inicio = temp;
      }
      else
      {
        Node *ultimo = inicio;
        while (ultimo->prox != NULL)
        {
          ultimo = ultimo->prox;
        }
        ultimo->prox = temp;
      }
      temp = NULL;
    }
    else
    {
      if (temp == NULL)
      {
        temp = (Node *)malloc(sizeof(Node));
        strcpy(temp->dado.nome, linha);
      }
      else if (temp->dado.contato == NULL)
      {
        Node2 *contato = (Node2 *)malloc(sizeof(Node2));
        strcpy(contato->dado.nome, linha);
        temp->dado.contato = contato;
      }
      else
      {
        Node2 *ultimo = temp->dado.contato;
        while (ultimo->prox != NULL)
        {
          ultimo = ultimo->prox;
        }
        Node2 *contato = (Node2 *)malloc(sizeof(Node2));
        strcpy(contato->dado.nome, linha);
        ultimo->prox = contato;
      }
    }
  }

  fclose(arquivo);
  printf("Agenda importada com sucesso.\n");

  return inicio;
}

void gnomeSort(Node2 **inicio)
{
  if (*inicio == NULL || (*inicio)->prox == NULL)
    return;

  Node2 *atual = *inicio;
  while (atual != NULL)
  {
    if (atual->prox != NULL && strcmp(atual->dado.nome, atual->prox->dado.nome) > 0)
    {
      contatos temp = atual->dado;
      atual->dado = atual->prox->dado;
      atual->prox->dado = temp;
      if (atual == *inicio)
        atual = atual->prox;
      else
        atual = *inicio;
      // atual = atual->prox;
    }
    else
    {
      atual = atual->prox;
    }
  }
}

void editar_char(char *alvo)
{
  if (alvo == NULL)
  {
    printf("char possivelmente não alocado.\n");
    exit(1);
  }
  fgets(alvo, MAX_CHAR, stdin);
  alvo[strcspn(alvo, "\n")] = '\0';
}

Node *criar_lista_Agenda(void)
{
  Node *inicio = (Node *)malloc(sizeof(Node));
  if (inicio == NULL)
  {
    printf("Erro ao tentar alocar memória");
    exit(1);
  }
  inicio->dado.cod = 0; // verifica se o inicio setando o codigo é zero
  inicio->prox = NULL;
  return inicio;
}

Node *lista_busca_Agenda(int elemento, Node *l, Node **anterior)
{
  Node *p;
  for (p = l; p != NULL; p = p->prox)
  {
    if (p->dado.cod == elemento)
    {
      return p;
    }
    if (anterior != NULL)
      *anterior = p;
  }
  return NULL;
}

void lista_retira_Agenda(Node *l, int v)
{
  Node **anteriorAddress = (Node **)malloc(sizeof(Node *));
  if (anteriorAddress == NULL)
  {
    printf("Erro ao alocar memória!");
    exit(1);
  }
  Node *alvo = lista_busca_Agenda(v, l, anteriorAddress);
  Node *anterior = *anteriorAddress;
  if (alvo != NULL)
  {
    if (anterior != NULL)
    {
      anterior->prox = alvo->prox;
    }
    else
    {
      *l = *l->prox;
    }
  }
}

void lista_insere_Agenda(Node *l, Agenda v)
{
  Node *alvo = lista_busca_Agenda(0, l, NULL);
  alvo->dado = v;
  alvo->prox = (Node *)malloc(sizeof(Node));
}

int lista_vazia_Agenda(Node *l)
{ // Questiona se lista está vazia
  return (l == NULL);
}

void lista_imprime_Agenda(Node *l)
{
  Node *p;
  for (p = l; p->prox != NULL; p = p->prox)
  {
    printf("Nome = %s\nCódigo = %i\nNúmero = %i\n", p->dado.nome, p->dado.cod, p->dado.num);
  }
}

void lista_libera_Agenda(Node *l)
{
  Node *p = l;
  Node *temp;
  while (p != NULL)
  {
    temp = p->prox;
    free(p);
    p = temp;
  }
}

Node2 *criar_lista_Contato(void)
{
  Node2 *start = (Node2 *)malloc(sizeof(Node2));
  if (start == NULL)
  {
    printf("Erro ao tentar alocar memória");
    exit(1);
  }
  start->dado.idade = 0; // verifica se o start setando a idade é zero
  start->prox = NULL;
  return start;
}

Node2 *lista_busca_Contato(char *element, Node2 *m, Node2 **previous)
{
  Node2 *pointer;
  for (pointer = m; pointer != NULL; pointer = pointer->prox)
  {
    if (strcmp(pointer->dado.nome, element) == 0)
    {
      return pointer;
    }
    if (previous != NULL)
      *previous = pointer;
  }
  return NULL;
}

void lista_retira_Contato(Node2 *m, char *w)
{
  Node2 **previousAddress = (Node2 **)malloc(sizeof(Node2 *));
  if (previousAddress == NULL)
  {
    printf("Erro ao alocar memória!");
    exit(1);
  }
  Node2 *target = lista_busca_Contato(w, m, previousAddress);
  Node2 *previous = *previousAddress;
  if (target != NULL)
  {
    if (previous != NULL)
    {
      previous->prox = target->prox;
    }
    else
    {
      *m = *m->prox;
    }
  }
}

void lista_insere_Contato(Node2 *m, contatos w)
{
  if (!m)
  {
    printf("Contato sem endereço!\n");
    exit(1);
  }
  Node2 *target = lista_busca_Contato("\000", m, NULL); // retornar o primeiro vazio
  target->dado = w;
  target->prox = (Node2 *)malloc(sizeof(Node2));
}

int lista_vazia_Contato(Node2 *m)
{
  return (m == NULL);
}

void imprime_contato(Node2 *contato)
{
  if (contato->dado.idade != 0)
  {
    printf("Nome: %s\nIdade: %u\nTelefone: %lu\nEmail: %s\n", contato->dado.nome, contato->dado.idade, contato->dado.tel, contato->dado.email);
  }
}

void lista_imprime_Contato(Node2 *m)
{
  Node2 *pointer;
  for (pointer = m; pointer->prox != NULL; pointer = pointer->prox)
  {
    imprime_contato(pointer);
  }
}

void lista_libera_Contato(Node2 *m)
{
  Node2 *pointer = m;
  Node2 *interim;
  while (pointer != NULL)
  {
    interim = pointer->prox;
    free(pointer);
    pointer = interim;
  }
}

void adiciona_contato(Node *l)
{ // Revisar
  int quantidade_adiciona, index, cod;
  printf("Quantos contatos deseja adicionar?\n");
  scanf(" %d", &quantidade_adiciona);
  getchar();
  for (index = 0; index < quantidade_adiciona; index++)
  {
    Node2 *contatoAdiciona = (Node2 *)malloc(sizeof(Node2));
    printf("Contato %i:\n", index + 1);
    printf("Nome:\n");
    editar_char(contatoAdiciona->dado.nome);
    printf("Idade:\n");
    scanf(" %u", &contatoAdiciona->dado.idade);
    getchar();
    printf("Telefone:\n");
    scanf(" %lu", &contatoAdiciona->dado.tel);
    getchar();
    printf("E-mail:\n");
    editar_char(contatoAdiciona->dado.email);
    // contatos[*qnt_add] = contatoADD;
    printf("Agora digite o código da agenda destinatária desse contato: \n");
    scanf(" %i", &cod);
    getchar();
    Node *alvo = lista_busca_Agenda(cod, l, NULL);
    if (alvo)
    {
      lista_insere_Contato(alvo->dado.contato, contatoAdiciona->dado);
      printf("Contato inserido\n");
    }
    else
    {
      printf("Essa agenda não existe\nDeseja criar uma nova com este código?\n");
      int escolha;
      printf("1 - Sim\n\n2 - Não\n");
      scanf(" %i", &escolha);
      getchar();
      switch (escolha)
      {
      case 1:
        Agenda novaAgenda;
        printf("Digite o nome da agenda:\n");
        editar_char(novaAgenda.nome);
        novaAgenda.cod = cod;
        lista_insere_Agenda(l, novaAgenda);
        Node *novoAlvo = lista_busca_Agenda(cod, l, NULL);
        if (!novoAlvo)
        {
          printf("Problema de alocação\n");
          exit(1);
        }
        novoAlvo->dado.contato = (Node2 *)malloc(sizeof(Node2));
        lista_insere_Contato(novoAlvo->dado.contato, contatoAdiciona->dado);
        novoAlvo->dado.num++;
        printf("Contato adicionado.\n\n");
        break;
      case 2:
        printf("Voltando para MENU...\n");
        break;
      default:
        printf("OPÇÃO INVÁLIDA\n");
        break;
      }
    }
    free(contatoAdiciona);
  }
}

void remover_contato(Node *l)
{
  int cod;
  char *nome = (char *)malloc(MAX_CHAR * sizeof(char));
  if (nome == NULL)
  {
    printf("Erro ao alocar memória");
    exit(1);
  }
  Node *alvoAgenda = (Node *)malloc(sizeof(Node));
  if (alvoAgenda == NULL)
  {
    printf("Erro ao alocar memória");
    exit(1);
  }
  Node2 *alvo = (Node2 *)malloc(sizeof(Node2));
  if (alvo == NULL)
  {
    printf("Erro ao alocar memória");
    exit(1);
  }
  printf("Informe a agenda em que o contato está para removê-lo:\n");
  scanf("%i", &cod);
  getchar();
  alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  if (!alvoAgenda)
  {
    printf("Agenda não encontrada.\n");
    return;
  }
  printf("Informe o nome do contato que será removido: \n");
  editar_char(nome);
  alvo = lista_busca_Contato(nome, alvoAgenda->dado.contato, NULL);
  if (alvo)
  {
    lista_retira_Contato(alvo, nome);
  }
  else
  {
    printf("Contato não encontrado na agenda.\n");
    return;
  }
}

void imprimir_contatos_cadastrado(Node *l)
{ // Imprimir contatos de uma agenda específica
  int cod;
  printf("Informe o código da agenda para listar contatos: \n");
  scanf("%d", &cod);
  getchar();
  Node *alvo = lista_busca_Agenda(cod, l, NULL);
  Node2 *index;
  for (index = alvo->dado.contato; index != NULL; index = index->prox)
  {
    imprime_contato(index);
    printf("\n");
  }
}

void editar_contato(Node *l)
{ // Contato único
  int cod;
  printf("Informe o código da agenda para editar um contato: \n");
  scanf("%d", &cod);
  getchar();
  Node *alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  printf("Digite o nome do contato que deseja editar: \n");
  char *nome = (char *)malloc(MAX_CHAR * sizeof(char));
  editar_char(nome);
  Node2 *alvoContato = lista_busca_Contato(nome, alvoAgenda->dado.contato, NULL);
  if (alvoContato != NULL)
  {
    printf("Digite o novo nome: \n");
    editar_char(alvoContato->dado.nome);
    printf("Digite a idade: \n");
    scanf(" %u", &alvoContato->dado.idade);
    getchar();
    printf("Digite o novo número de telefone: \n");
    scanf(" %lu", &alvoContato->dado.tel);
    getchar();
    printf("Digite o novo endereço de e-mail: \n");
    editar_char(alvoContato->dado.email);
    printf("Contato %s atualizado com sucesso!\n\n", alvoContato->dado.nome);
  }
  else
  {
    printf("Contato %s não encontrado na agenda.\n", nome);
  }
}

void buscar_contato(Node *l)
{
  char *name = (char *)malloc(MAX_CHAR * sizeof(char));
  if (name == NULL)
  {
    printf("Erro ao alocar memória\n");
    exit(1);
  }
  printf("Digite nome do contato para buscar:\n");
  editar_char(name);
  Node *p;
  Node2 *alvo;
  for (p = l; p != NULL; p = p->prox)
  { // Iterar nas agendas para procurar em todas
    alvo = lista_busca_Contato(name, p->dado.contato, NULL);
    if (alvo)
    { // existe
      imprime_contato(alvo);
      return;
    }
    else
    { // não existe
      alvo = NULL;
    }
  }
  printf("Contato não encontrado.\n");
}

void consultar_contato_em_agenda(Node *l)
{
  int cod;
  printf("Digite o código da agenda que deseja buscar um contato: \n");
  scanf("%d", &cod);
  getchar();
  Node *alvoAgenda = lista_busca_Agenda(cod, l, NULL);
  printf("Digite nome do contato: \n");
  char *alvo = (char *)malloc(MAX_CHAR * sizeof(char));
  editar_char(alvo);
  Node2 *alvoContato = lista_busca_Contato(alvo, alvoAgenda->dado.contato, NULL);
  if (alvoContato != NULL)
  {
    imprime_contato(alvoContato);
  }
  else
  {
    printf("Contato não encontrado.\n");
  }
}

void quantitativo_agenda(Node *l)
{
  int contador = 0;
  Node *index;

  for (index = l; index != NULL; index = index->prox)
  {
    contador++;
  }
  printf("Há um total de %i agenda(s).\n", contador - 1);
}

int main(void)
{
  Node2 *Contato = (Node2 *)malloc(sizeof(Node2));
  if (Contato == NULL)
  {
    printf("Erro ao alocar memória");
    exit(1);
  }
  Node *lista = criar_lista_Agenda(); // Primordial
  // Node *lista = importarAgenda("dados"); // Primordial
  adiciona_contato(lista);
  // imprimir_contatos_cadastrado(lista);
  exportarAgenda(lista, "dados");

  // Node *arquivoImportado = importarAgenda("dados");
  // imprimir_contatos_cadastrado(arquivoImportado);

  // editar_contato(lista);
  // buscar_contato(lista);
  // consultar_contato_em_agenda(lista);
  // quantitativo_agenda(lista);
  // remover_contato(lista);
  // gnomeSort(&lista->dado.contato);
  // imprimir_contatos_cadastrado(lista);

  // free(lista);
  return 0;
}