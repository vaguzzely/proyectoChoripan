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

//Se establece los registros de la categoria "General" y las categorias que agrega el usuario.
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

/*Se comprueba que el usuario no alcance el maximo de categorias disponible, en caso que pueda agregar categorias, se agrega el nombre de la categoria al mapa y se inicializan todos los montos en 0.*/
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

/*Esta funcion solo pregunta el nombre de la categoria que se quiere crear y llama a la funcion de "agregarCategoria".*/
void crearCate(MapaIngresos *mapa)
{
  char nombre[MAX];
  
  printf("\nIngrese el nombre de la nueva categoría:\n");
  scanf("%s", nombre);
  agregarCategoria(mapa, nombre);
}

/*Se busca en el mapa el nombre de la categoria que se quiere busca y en caso de no encontrar la categoria se retorna -1.*/
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

/*Se pregunta el nombre de la categoria que se quiere mostras y se busca con la funcion "buscarCategoria". Si la categoria no fue encontrada se muestra este mensaje "Categoría no encontrada".*/
void mostrarCate(List *listaC, MapaIngresos* mapa)
{
  char categoria[MAX];
  
  printf("\nIngrese el nombre de la categoría que desea mostrar:\n");
  scanf("%s", categoria);
  
  int search = buscarCategoria(mapa, categoria);

  if(search != -1)
  {
    printf("\nMonto en la categoría %s: %ld\n", categoria, mapa->registros[search].monto);
  }
  else
  {
    printf("\nCategoría no encontrada.\n");
  }    
}

/*Se comprueba que la categoria se encuentre en el mapa, despues se mueven los elementos un espacio y se disminuye el numero de registros. Si la categoria no fue encontrada se muestra este mensaje "Categoría no encontrada".*/
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

/*Esta funcion esta encargada de mostrar las opciones que se pueden realizar en la opcion de Categorias.*/
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

/*Repite todas las veces que el usuario quiera el submenu de Categorias y dependiendo de la opcion que el usuario escoga es la funcion que llama para realizar lo requerido. (Funciones que puede llamar: crearCate(), eliminarCate(), mostrarCate()).*/
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

/*Se busca en el mapa la categoria ingresada por el usuario, cuando es encontrada se muestra el monto que se encuentra en la categoria y el presupuesto que tiene. En caso de no encontrar sale el mensaje de "La categoría no existe".*/
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
    printf("\nVolviendo al menu de presupuestos...\n");
  }    
}

/*Se busca en el mapa la categoria ingresada por el usuario, cuando es encontrada se elimina del mapa el presupuesgto en la parte de presupuestos. En caso de no encontrar sale el mensaje de "La categoría no existe".*/
void eliminarPresu(MapaIngresos *mapa)
{
  char presupuesto[MAX];
  int search = buscarCategoria(mapa, presupuesto);
  
  printf("\nIngrese la categoría para la cual desea eliminar el presupuesto:\n");
  scanf("%s", presupuesto);
  
  if(search != -1)
  {
    mapa->registros[search].presupuesto = 0;
    printf("\nPresupuesto eliminado \n");
  }
  else
  {
    printf("\nCategoría no encontrada. \n");
    printf("\nVolviendo al menu de presupuestos...\n");
  }
}

/*Se busca en el mapa la categoria ingresada por el usuario, cuando es encontrada se pregunta el presupuesto para esa categoria y se agrega al mapa en la parte de presupuestos. En caso de no encontrar sale el mensaje de "La categoría no existe".*/
void agregarPresu(MapaIngresos *mapa)
{
  char presupuesto[MAX];
  int search = buscarCategoria(mapa, presupuesto);
  
  printf("\nIngrese la categoría para la cual desea crear el presupuesto:\n");
  scanf("%s", presupuesto);
  
  if(search != -1)
  {
    long cantpresu = 0;
    
    printf("\nIngrese el monto presupuestado : \n");
    scanf("%ld", &cantpresu);
    mapa->registros[search].presupuesto = cantpresu;
  }
  else
  {
    printf("\nCategoría no encontrada. \n");
    printf("\nVolviendo al menu de presupuestos...\n");
  }
}

/*Esta funcion esta encargada de mostrar las opciones que se puede realizar en la opcion de Presupuesto.*/
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

/*Repite todas las veces que el usuario quiera el submenu de Presupuesto y dependiendo de la opcion que el usuario escoga es la funcion que llama para realizar lo requerido. (Funciones que puede llamar: agregarPresu(), eliminarPresu(), mostrarPresu()).*/
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
        break;

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

/*Se le pregunta al usuario la cantidad de dinero que desea ingresar y la categoria, se comprueba que la categoria este en el mapa, cuando se encuentra la categoria se agrega el dinero y se muestra un mensaje con el dinero agregado a la categoria y el dinero total que tiene la categoria. En caso de no encontrar la categoria se pone el mensaje de "La categoría no existe".*/
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

/*Se le pregunta al usuario la cantidad de dinero de la transacciion y la categoria, se comprueba que la categoria este en el mapa, cuando se encuentra la categoria se elimina el dinero y se muestra un mensaje con el dinero agregado a la categoria(pero en negativo) y el dinero total que tiene la categoria. En caso de no encontrar la categoria se pone el mensaje de "La categoría no fue encontrada.".*/
void transaccion(List *listaT, MapaIngresos *mapa)
{
  Registro *lisMont = (Registro*)malloc(sizeof(Registro));
  long mont;
  char categoria[MAX];
  
  printf("\nIndique monto de la transacción:\n");
  scanf("%ld", &mont);
  printf("\nIndique categoría :\n");
  scanf("%s", categoria);
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
  else
  {
    printf("\nLa categoría \"%s\" no fue encontrada.\n", categoria);
    printf("\nRegresando al menú de Registros...\n");
  }
}

/*Esta funcion esta encargada de mostrar las opciones que se puede realizar en la opcion de Registro de transacciones.*/
void subOpciones1() //Menu de R.F
{
  puts("\n==================================================");
  puts("\t1.- INGRESO");
  puts("\t2.- TRANSACCION");
  puts("\t3.- VOLVER AL MENU DE GESTION DE FINANZAS");
  puts("==================================================");
  printf("\nSeleccione una opción (1-3)\n");
}

/*Repite todas las veces que el usuario quiera el submenu de Registro de transacciones y dependiendo de la opcion que el usuario escoga es la funcion que llama para realizar lo requerido. (Funciones que puede llamar: ingreso(), transaccion()).*/
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