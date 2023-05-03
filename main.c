#include <stdio.h>
#include <stdlib.h>
 
void menu();
 
int main (void){
  menu();
  exit(0);
  return 0;
}
 
void menu(){
  int escolha = 0;
  printf( "1.\tAdicionar contato\n"
          "2.\tRemover contato\n"
          "3.\tListar contatos cadastrados\n" 
          "4.\tEditar contato\n" 
          "5.\tBuscar contato\n" 
          "6.\tConsultar contato em uma dada agenda\n" 
          "7.\tConsultar quantitativo de agendas\n" 
          "8.\tSair\n"); 
  do {
    printf("\tDigite uma opção: ");
    scanf("%d", &escolha);
  } while (escolha < 1 || escolha > 8);
 
  switch (escolha) {
    /*
    case 1:
      
    case 2:
      
    case 3:
      
    case 4:
      
    case 5:
      
    case 6:
      
    case 7:
      
    */
    case 8:
      return; // seguido de um exit na main, para burlar o aviso de função recursiva infinita.
  }
  menu();
}