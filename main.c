#include <stdio.h>
#include <stdlib.h>
#include "agenda.c"

#define arquivoNome "Agenda.txt"

void menu(Node * lista);
 
int main (void){
  Node *lista = criar_lista_Agenda();
  menu(lista);
  return 0;
}

void menu(Node * lista){
  int escolha = 0;
  printf( "\n1.\tAdicionar contato\n"
          "2.\tRemover contato\n"
          "3.\tListar contatos cadastrados\n" 
          "4.\tEditar contato\n" 
          "5.\tBuscar contato\n" 
          "6.\tConsultar contato em uma dada agenda\n" 
          "7.\tConsultar quantitativo de agendas\n" 
          "8.\tSair\n\n"); 
  do {
    printf("\tDigite uma opção válida: ");
    scanf("%d", &escolha); getchar();
  } while (escolha < 1 || escolha > 8);
  switch (escolha) {
    case 1:
      adiciona_contato(lista,1);
    break;
    case 2:
      remover_contato(lista);
    break;
    case 3:
      imprimir_contatos_cadastrado(lista);
    break;
    case 4:
      editar_contato(lista);
    break;
    case 5:
      buscar_contato(lista);
    break;
    case 6:
      consultar_contato_em_agenda(lista);
    break;
    case 7:
      quantitativo_agenda(lista);
    break;
    case 8:
      arquivoAgenda(lista,arquivoNome);
      limparMemoriaNodes(lista);
      return; 
    break;
  }
  menu(lista);
}
