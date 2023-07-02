#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "stack.h"
#include "hashmap.h"
//#include "treemap.h"
#include "arraylist.h"

#define MAX 10000
#define MIN 20
/*
se creo este archivo para las funciones que tienen que ver con los recordatorios aca es un archivo aparte pero integrado al codigo

todo en base a recordatorio

a continuacion se presenta una estruc que se utilizara para el codigo en general
*/
typedef struct
{
  char dia[MIN] ;
  char mes[MIN] ;
  char ano[MIN] ;
  
  char texto[MAX];
}Recordatorio;


/*
se crea una estructura que guarda los datos de cuando quiera el recordatorio
*/
/*
en la funcion crear mapa se busca si es que esta el mes ocupado con algun dato (utilizan listas en si es un mapa con una clave mes y data la lista con los textos) de estar ocupado se se saca la data y se agrega el recordatorio, de no estar solo se agrega
*/
void crearMapa(List* list,Recordatorio* rec,HashMap* mapaMeses)//rec es la variable de recordatorio
{
  
  if(searchMap(mapaMeses, rec->mes) == NULL)
  {
    insertMap(mapaMeses,rec->mes, list);
  }else{
    
    hashPair * buscado = searchMap(mapaMeses, rec->mes);
    Recordatorio* temp = buscado->value;
    
    List* aux = createList();
    pushBack(aux, temp);
    pushBack(aux, rec);
    insertMap(mapaMeses, rec->mes, aux);
  }

  
}
/* la funcion crear recordatorio es crear la base en donde se agrega la fecha y el texto */
void crearRecordatorio(List *listaRecordatorios,HashMap* mapaMeses)
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
  
  while(strlen(aux)<10 || strlen(aux)>10)
  {
    puts("formato 00/00/0000");
    printf("ingrese la fecha del recordatorio valida: ");
    getchar();
    scanf("%[^\n]",aux);
  }
  
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
  crearMapa(listaRecordatorios,recordatorio,mapaMeses);
}

void borrarRecordatorio(List * listRecord)
{
  popBack(listRecord);
  puts("borrado");
}
/* funcion para mostrar los recordatorios segun el mes que el usuario seleccione*/
void mostrarSegunMes(HashMap* mapa)
{
  char busqMes[MIN];

  puts("Ingrese el mes segun quiera revisar - tipo 00");

  getchar();
  scanf("%[^\n]",busqMes);
  

  hashPair* aux = searchMap(mapa, busqMes);
  if(aux == NULL)
  {
    puts("no tiene recordatorios para este mes");
  }
  else
  {
    List* temp = createList();
    temp = aux->value;
    Recordatorio * datos = firstList(temp);
      
    while(datos != NULL)
    {
      printf("con fecha del %s/%s/%s\n",datos->dia,datos->mes,datos->ano);
      printf("%s\n",datos->texto);

      datos = nextList(temp);    
    }
  
  }
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
// menu para mostrar los recordatorios
void menuOpcMostrar()
{
  puts("\n==============================================");
  puts("\t1.- MOSTRAR POR MES");
  puts("\t2.- MOSTRAR TODOS - POR ORDEN DE INGRESO");
  puts("\t3.- VOLVER A MENU");
  puts("==============================================");
  printf("\nSeleccione una opción (1-3)\n");
}
/* los menus se selecionan segun la opcion que elija el usuario en esta estructura de switch*/
void SUBMENURECOR(List * listRecord,HashMap* mapaPorMeses)
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
        mostrarSegunMes(mapaPorMeses);
        break;

      case 2:
        printf("Has seleccionado la opción 2.\n");
        system("clear");
        mostrarTodos(listRecord);
        break;

      case 3:
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

void mostrarRecordatorios(List * listRecord,HashMap* mapa)
{
  SUBMENURECOR(listRecord,mapa);
}







