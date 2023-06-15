#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "stack.h"

#define MAX 10000
#define MIN 20

typedef struct
{
  char dia[MIN] ;
  char mes[MIN] ;
  char ano[MIN] ;
  
  char texto[MAX];
}Recordatorio;

void crearRecordatorio(List *listaRecordatorios)
{
  Recordatorio* recordatorio = (Recordatorio*) malloc(sizeof(Recordatorio));
  char aux[MIN];
  char text[MAX];
  puts("==============================================");
  puts("                recordatorio:");
  puts("==============================================");

  puts("formato 00/00/0000");
  printf("ingrese la fecha del recordatorio: ");
  getchar();
  scanf("%[^\n]",aux);
  
  for(int i = 0; i < 11; i++)
  {
    if(i<2)
    {
      recordatorio->dia[i] = aux[i];
    }
    
    if(i>2 && i<5)
    {
      recordatorio->mes[i-3] = aux[i];
    }
    
    if(i>5)
    {
      recordatorio->ano[i-6] = aux[i];
    }
  }
  /*
  printf("%s\n",recordatorio->dia);
  printf("%s\n",recordatorio->mes);
  printf("%s\n",recordatorio->ano);
  */

  printf("TEXTO: ");
  getchar();
  scanf("%[^\n]",text);
  getchar();
  
  strcpy(recordatorio->texto, text);

  pushBack(listaRecordatorios, recordatorio);
}

void borrarRecordatorio(List * listRecord)
{
  popBack(listRecord);
  puts("borrado");
}

void mostrarTodos(List * listRecord)
{
  Recordatorio* aux  = firstList(listRecord);

  while(aux != NULL)
  {
    printf("con fecha del %s/%s/%s\n",aux->dia,aux->mes,aux->ano);
    printf("%s\n",aux->texto);

    aux = nextList(listRecord);
  }
}

void menuOpcMostrar()
{
  puts("\n==============================================");
  puts("\t1.- MOSTRAR POR MES");
  puts("\t2.- MOSTRAR TODOS, POR ORDEN DE INGRESO");
  puts("\t3.- VOLVER A MENU");
  puts("==============================================");
  printf("\nSeleccione una opción (1-3)\n");
}

void SUBMENURECOR(List * listRecord)
{
  int opc;
  
  while(1)
  {
    menuOpcMostrar();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("Has seleccionado la opción 1.\n");
        system("clear");
        break;

      case 2:
        printf("Has seleccionado la opción 2.\n");
        system("clear");
        mostrarTodos(listRecord);
        break;

      case 4:
        printf("\nVolviendo al menu principal...\n");
        system("clear");
        return ;

      default:
        printf("Opción inválida.\n");
        system("clear");
        break;
    }
  }
}

void mostrarRecordatorios(List * listRecord)
{
  SUBMENURECOR(listRecord);
}







