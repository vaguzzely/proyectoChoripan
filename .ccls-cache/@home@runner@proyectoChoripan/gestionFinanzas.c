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
} Registro;

typedef struct {
    Registro registros[MAX_CATEGORIAS];
    int numRegistros;
} MapaIngresos;

void opcion4() //Informe
{
  printf("INFORME");
}

void opcion3() //Presupuesto
{
  printf("NO TENGO IDEA QUE SE HACE");
}

void inicializarMapa(MapaIngresos* mapa)
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

int buscarCategoria(MapaIngresos* mapa, const char* nombre)
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

void agregarCategoria(MapaIngresos* mapa, const char* nombre)
{
  if (mapa->numRegistros < MAX_CATEGORIAS)
  {
    strcpy(mapa->registros[mapa->numRegistros].nombre, nombre);
    mapa->registros[mapa->numRegistros].monto = 0;
    mapa->registros[mapa->numRegistros].montoTotal = 0;
    mapa->numRegistros++;
    printf("\nCategoría \"%s\" agregada.\n", nombre);
  } else
    {
      printf("No se pueden agregar más categorías. Máximo alcanzado.\n");
    }
}

/*void mostrarCate(List *listaC, MapaIngresos* mapa)
{

}*/

/*void eliminarCate(MapaIngresos* mapa)
{

}*/

/*void crearCate(MapaIngresos* mapa)
{
  
}*/

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

void opcion2() //Categorias
{
  int opc;
  List *listaM = createList();
  HashMap *mapCat = createMap(MAX);  
  
  while(1)
  {
    subOpciones2();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("\nHas seleccionado la opción 1.\n");
        //crearCate();
        break;
      
      case 2:
        printf("\nHas seleccionado la opción 2.\n");
        //eliminarCate();
        break;
      
      case 3:
        printf("\nHas seleccionado la opción 3.\n");
        //mostrarCate();
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

void ingreso(List *listaI, MapaIngresos* mapa)
{
  Registro *lisMon = (Registro*)malloc(sizeof(Registro));
  long monto;
  char nombre[100];

  printf("\nIndique monto:\n");
  scanf("%ld", &monto);

  printf("\nIngrese el nombre de la categoría (o ingrese \"general\" para dinero en general):\n");
  scanf("%s", nombre);

  if (strcmp(nombre, "general") == 0)
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
    mapa->registros[0].monto += monto;
    mapa->registros[0].montoTotal += monto;
  } else
    {
      int indice = buscarCategoria(mapa, nombre);
      if (indice == -1)
      {
        printf("\nLa categoría \"%s\" no existe. Creando nueva categoría.\n", nombre);
        agregarCategoria(mapa, nombre);
        indice = mapa->numRegistros - 1;
      }
      lisMon->monto = monto;
      lisMon->montoTotal = 0;
      pushBack(listaI, lisMon);

      Registro *mostrar = firstList(listaI);
      while (mostrar != NULL)
      {
        lisMon->montoTotal += mostrar->monto;
        mostrar = nextList(listaI);
      }
      printf("\nTotal agregado: %ld\n", lisMon->monto);
      printf("Dinero total: %ld\n", lisMon->montoTotal);
      mapa->registros[indice].monto += monto;
      mapa->registros[indice].montoTotal += monto;
      mapa->registros[0].monto += monto;
      mapa->registros[0].montoTotal += monto;
    }
}

void transaccion(List *listaT, MapaIngresos *mapa)
{
  Registro *lisMont = (Registro*)malloc(sizeof(Registro));
  long mont;
  char categoria[MAX];
  long suma = 0;
  
  printf("\nIndique monto de la transacción:\n");
  scanf("%ld", &mont);
  printf("Indique categoría (General para dinero general):\n");
  scanf("%s", categoria);

  lisMont->monto = -mont; 
  lisMont->montoTotal = 0;
  pushBack(listaT, lisMont);

  Registro *mostrar = firstList(listaT);
  while(mostrar != NULL)
  {
    //printf("%ld, ", mostrar->monto);
    suma += mostrar->monto;
    mostrar = nextList(listaT);
  }
  printf("%ld\n", suma);

  if (mapa != NULL)
  {
    int i;
    for (i = 0; i < mapa->numRegistros; i++)
    {
      if (strcmp(mapa->registros[i].nombre, categoria) == 0)
      {
        mapa->registros[i].monto -= lisMont->monto;
        mapa->registros[i].montoTotal -= lisMont->monto;
        printf("\nDinero restante en esta categoría: %ld\n", mapa->registros[i].monto);
        printf("\nTotal dinero restante:  %ld\n",suma);
      }
      if (strcmp(mapa->registros[i].nombre, "General") == 0)
      {
        mapa->registros[i].monto += lisMont->monto;
        mapa->registros[i].montoTotal += lisMont->monto;
      }
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

void opcion1() //Registro de finanzas
{
  int opc;
  List *listaM = createList();
  HashMap *mapCat = createMap(MAX);
  
  while(1)
  {
    subOpciones1();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("\nHas seleccionado la opción 1.\n");
        ingreso(listaM, mapCat);
        break;
      
      case 2:
        printf("\nHas seleccionado la opción 2.\n");
        transaccion(listaM, mapCat);
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