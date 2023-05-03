#ifndef FLAGENDA_H_INCLUDED
#define FLAGENDA_H_INCLUDED
 
typedef struct contact contatos;
 
typedef struct agenda Agenda;
 
typedef struct no No;
 
typedef struct lista Lista;

Lista* cria_lista(void);

Lista* lista_insere(Lista* l, Agenda dado);

int lista_vazia(Lista *l);

void lista_imprime(Lista*l);

Lista * lista_busca(Agenda* elemento, Lista* l);

Lista * lista_retira(Lista*l,  Agenda* v);

void lista_libera(Lista* l);

Lista* lista_insere_ordenada(Lista * l, Agenda* v);




#endif
 