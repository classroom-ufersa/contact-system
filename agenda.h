#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
 
typedef struct contact contatos;
 
typedef struct agenda Agenda;
 
typedef struct no_lista_Agenda Node;

typedef struct no_lista_Contato Node2;

void editar_char(char *alvo);

Node *criar_lista_Agenda(void);

Node *lista_busca_Agenda(int elemento, Node *l, Node **anterior);

void lista_insere_Agenda(Node *l, Agenda v);    

Node2 *lista_busca_Contato(char *element, Node2 *m, Node2 **previous);

void lista_retira_Contato(Node2 *m, char *w);

void lista_insere_Contato(Node2 *m, contatos w); 

void imprime_contato(Node2 *contato); 

void limparMemoriaNodes(Node * principio); 

void adiciona_contato(Node *l, int quantidadeAdiciona); 

void remover_contato(Node *l); 

void imprimir_contatos_cadastrado(Node *l); 

void editar_contato(Node *l); 

void buscar_contato(Node *l); 

void consultar_contato_em_agenda(Node *l); 

void quantitativo_agenda(Node *l); 

void gnomeSort(Node2 **inicio); 

void arquivoAgenda(Node *inicio, char *nomeArquivo); 


#endif
