#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"
#include "stack.h"
#include "hashmap.h"
#include "treemap.h"
#include "arraylist.h"
#define MAX_CATEGORIAS 100
#define MAX 1000

typedef struct {
  char nombre[100];
  long monto;
  long montoTotal;
  long presupuesto;
} Registro;

typedef struct {
  Registro registros[MAX_CATEGORIAS];
  int numRegistros;
} MapaIngresos;

void inicializarMapa(MapaIngresos *mapa)
{
  // Inicializar el registro general
  strcpy(mapa->registros[0].nombre, "General");
  mapa->registros[0].monto = 0;
  mapa->registros[0].montoTotal = 0;

  // Inicializar el resto de los registros
  for (int i = 1; i < MAX_CATEGORIAS; i++)
  {
    strcpy(mapa->registros[i].nombre, "");
    mapa->registros[i].monto = 0;
    mapa->registros[i].montoTotal = 0;
  }
  mapa->numRegistros = 1; // Se inicializa con el registro general
}

void agregarCategoria(MapaIngresos *mapa, const char* nombre)
{
  if (mapa->numRegistros < MAX_CATEGORIAS)
  {
    strcpy(mapa->registros[mapa->numRegistros].nombre, nombre);
    mapa->registros[mapa->numRegistros].monto = 0;
    mapa->registros[mapa->numRegistros].montoTotal = 0;
    mapa->numRegistros++;
    printf("\nCategoría \"%s\" agregada.\n", nombre);
  }
  
  else
  {
    printf("No se pueden agregar más categorías. Máximo alcanzado.\n");
  }
}

void crearCate(MapaIngresos *mapa)
{
  char nombre[MAX];
  
  printf("\nIngrese el nombre de la nueva categoría:\n");
  scanf("%s", nombre);
  
  agregarCategoria(mapa, nombre);
}

int buscarCategoria(MapaIngresos* mapa, char* nombre)
{
  for (int i = 0; i < mapa->numRegistros; i++)
  {
    if (strcmp(mapa->registros[i].nombre, nombre) == 0)
    {
      return i;
    }
  }
  return -1;
}

void mostrarCate(List *listaC, MapaIngresos* mapa)
{
  char categoria[MAX];
  
  printf("\nIngrese el nombre de la categoría que desea mostrar (Si desea ver la totalidad del dinero en su cuenta, ingrese 'General'):\n");
  scanf("%s", categoria);
  
  int search = buscarCategoria(mapa, categoria);

  if(search != -1)
  {
    if(strcmp("General", categoria) != 0)
    {
      printf("\nMonto en la categoría %s: %ld\n", categoria, mapa->registros[search].monto);
    }
    else
    {
      printf("\nMonto Total: %ld", mapa->registros[search].montoTotal);
    }
  }

  else
  {
    printf("\nCategoría no encontrada.\n");
  }    
}

void eliminarCate(MapaIngresos* mapa)
{
  char categoria[MAX];
  
  printf("\nIngrese el nombre de la categoría que desea eliminar:\n");
  scanf("%s", categoria);
  
  int eliminar = buscarCategoria(mapa, categoria);
  
  if(eliminar != -1)
  {
    for (int i = eliminar; i < mapa->numRegistros - 1; i++)
    {
      strcpy(mapa->registros[i].nombre, mapa->registros[i+1].nombre);
      mapa->registros[i].presupuesto = mapa->registros[i+1].presupuesto;
    }
    mapa->numRegistros--;
    printf("\nCategoría \"%s\" eliminada.\n\n", categoria);
  }
  else
  {
    printf("\nCategoría no encontrada.\n");
  }
}

void subOpciones2() //Menu de C
{
  puts("\n==================================================");
  puts("\t1.- CREAR CATEGORIA");
  puts("\t2.- ELIMINAR CATEGORIA");
  puts("\t3.- MOSTRAR CATEGORIA");
  puts("\t4.- VOLVER AL MENU DE GESTION DE FINANZAS");
  puts("==================================================");
  printf("\nSeleccione una opción (1-4)\n");
}

void opcion2(List *lista2, HashMap *mapa2) //Categorias
{
  int opc;
  
  while(1)
  {
    subOpciones2();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("\nHas seleccionado la opción 1.\n");
        crearCate(mapa2);
        break;
      
      case 2:
        printf("\nHas seleccionado la opción 2.\n");
        eliminarCate(mapa2);
        break;
      
      case 3:
        printf("\nHas seleccionado la opción 3.\n");
        mostrarCate(lista2, mapa2);
        break;

      case 4:
        printf("\nVolviendo al menu de finanzas...\n");
        return;

      default:
        printf("Opción inválida.\n");
        system("clear");
        break;
    }
  }
}

void mostrarPresu(List *listaC, MapaIngresos *mapa)
{
  char categoria[MAX];
  
  printf("\nIngrese el nombre de la categoría a la cual desea ver el presupuesto:\n");
  scanf("%s", categoria);
  
  int search = buscarCategoria(mapa, categoria);
  
  printf("\n%d\n", search);
  if(search > -1)
  {
    printf("\nMonto en la categoría %s: %ld\n", categoria, mapa->registros[search].monto);
    printf("Presupuesto de la categoría %s: %ld\n", categoria, mapa->registros[search].presupuesto);
  }
  else
  {
    printf("\nCategoría no encontrada.\n");
  }    
}

void eliminarPresu(MapaIngresos *mapa)
{
  char presupuesto[MAX];
  int search = buscarCategoria(mapa, presupuesto);
  
  printf("Ingrese la categoría para la cual desea eliminar el presupuesto:\n\n");
  scanf("%s", presupuesto);
  
  if(search > -1)
  {
    mapa->registros[search].presupuesto = 0;
  }
  else
  {
    printf("Categoría no encontrada. \n");
  }
}

void agregarPresu(MapaIngresos *mapa)
{
  char presupuesto[MAX];
  int search = buscarCategoria(mapa, presupuesto);
  
  printf("Ingrese la categoría para la cual desea crear el presupuesto:\n\n");
  scanf("%s",presupuesto);
  
  if(search > -1)
  {
    long cantpresu = 0;
    
    printf("Ingrese el monto presupuestado : \n\n");
    scanf("%ld", &cantpresu);
    mapa->registros[search].presupuesto = cantpresu;
  }
  else
  {
    long cantpresu = 0;
    
    printf("Categoría no encontrada. \n");
    agregarCategoria(mapa, presupuesto);
    printf("Ingrese el monto presupuestado : \n\n");
    scanf("%ld", &cantpresu);
    mapa->registros[search].presupuesto = cantpresu;
  }
}

void subopciones3()
{
  puts("\n==================================================");
  puts("\t1.- ASIGNAR PRESUPUESTO");
  puts("\t2.- ELIMINAR PRESUPUESTO");
  puts("\t3.- MOSTRAR CATEGORIA Y PRESUPUESTO");
  puts("\t4.- VOLVER AL MENU DE GESTION DE FINANZAS");
  puts("==================================================");
  printf("\nSeleccione una opción (1-4)\n");
}

void opcion3(List *lista3, HashMap *mapa3) //Presupuesto
{
  int opc;
  
  while(1)
  {
    subopciones3();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("\nHas seleccionado la opción 1.\n");
        agregarPresu(mapa3);
        break;
      
      case 2:
        printf("\nHas seleccionado la opción 2.\n");
        eliminarPresu(mapa3);
        break;
      
      case 3:
        printf("\nHas seleccionado la opción 3.\n");
        mostrarPresu(lista3, mapa3);
        return ;

      case 4:
        printf("\nVolviendo al menu de finanzas...\n");
        return ;

      default:
        printf("Opción inválida.\n");
        system("clear");
        break;
    }
  }
}

void ingreso(List *listaI, MapaIngresos *mapa)
{
  Registro *lisMon = (Registro*)malloc(sizeof(Registro));
  long monto;
  char nombre[MAX];

  printf("\nIndique monto:\n");
  scanf("%ld", &monto);

  printf("\nIngrese el nombre de la categoría :\n");
  scanf("%s", nombre);

    int indice = buscarCategoria(mapa, nombre);
    
    if(indice != -1)
    {
      lisMon->monto = monto;
      lisMon->montoTotal = 0;
      pushBack(listaI, lisMon);
  
      Registro *mostrar = firstList(listaI);
      
      while (mostrar != NULL)
      {
        lisMon->montoTotal += mostrar->monto;
        mostrar = nextList(listaI);
      }
      mapa->registros[indice].monto += monto;
      mapa->registros[indice].montoTotal += monto;
      printf("\nTotal agregado: %ld\n", lisMon->monto);
      printf("Dinero total: %ld\n", lisMon->montoTotal);
    }
    
    else
      {
        printf("\nLa categoría no existe\n");
        printf("\nRegresando al menú de Registros...\n"); 
      }
    }


void transaccion(List *listaT, MapaIngresos *mapa)
{
  Registro *lisMont = (Registro*)malloc(sizeof(Registro));
  long mont;
  char categoria[MAX];
  
  printf("\nIndique monto de la transacción:\n");
  scanf("%ld", &mont);
  printf("\nIndique categoría (o \"General\" para dinero general):\n");
  scanf("%s", categoria);

  if (strcmp(categoria, "General") == 0)
  {
    lisMont->monto = -mont;
    lisMont->montoTotal = 0;
    pushBack(listaT, lisMont);

    Registro *mostrar = firstList(listaT);
    
    while (mostrar != NULL)
    {
      lisMont->montoTotal += mostrar->monto;
      mostrar = nextList(listaT);
    }
    mapa->registros[0].monto += -mont;
    mapa->registros[0].montoTotal += -mont;
    printf("\nTotal agregado: %ld\n", lisMont->monto);
    printf("Dinero total: %ld\n", lisMont->montoTotal);
  }
  else
  {
    int indice = buscarCategoria(mapa, categoria);
    
    if(indice != -1)
    {
      lisMont->monto = -mont;
      lisMont->montoTotal = 0;
      pushBack(listaT, lisMont);
  
      Registro *mostrar = firstList(listaT);
      
      while (mostrar != NULL)
      {
        lisMont->montoTotal += mostrar->monto;
        mostrar = nextList(listaT);
      }
      mapa->registros[indice].monto += -mont;
      mapa->registros[indice].montoTotal += -mont;
      printf("\nTotal agregado: %ld\n", lisMont->monto);
      printf("Dinero total: %ld\n", lisMont->montoTotal);
    }
    
    if (indice == -1)
    {
      printf("\nLa categoría \"%s\" no fue encontrada.\n", categoria);
    }
  }
}

void subOpciones1() //Menu de R.F
{
  puts("\n==================================================");
  puts("\t1.- INGRESO");
  puts("\t2.- TRANSACCION");
  puts("\t3.- VOLVER AL MENU DE GESTION DE FINANZAS");
  puts("==================================================");
  printf("\nSeleccione una opción (1-3)\n");
}

void opcion1(List *lista1, HashMap *mapa1) //Registro de finanzas
{
  int opc;
  
  while(1)
  {
    subOpciones1();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("\nHas seleccionado la opción 1.\n");
        ingreso(lista1, mapa1);
        break;
      
      case 2:
        printf("\nHas seleccionado la opción 2.\n");
        transaccion(lista1, mapa1);
        break;
      
      case 3:
        printf("\nVolviendo al menu de finanzas...\n");
        return ;

      default:
        printf("Opción inválida.\n");
        system("clear");
        break;
    }
  }
}

void opcion4(List *lista4, HashMap *mapa4) //Informe
{
  printf("INFORME");
}