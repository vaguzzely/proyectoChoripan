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


typedef struct {
    char nombre[50];
    int prioridad;
    bool completada;
} datosTarea;

/*typedef struct
{
  char nombreNotas[50];
  char textoNotas[500];
}nota;


//función que crea jugador, se llama el la función opcion1
void crearJugador(char nombre[], HashMap * jugadores)
{
  nota  *p = (nota *)malloc(sizeof(nota));
  
  strcpy(p->nota, nombre);
  p->pHabilidad = 0; //Se pide que los P.H de cada jugador comience en 0
  p->item = 0; //inventario vacío
  p->acciones = (Stack*)malloc(sizeof(Stack*));
  insertMap(jugadores, nombre, p);
}

//crea al jugador
void opcion1(HashMap * jugadores)
{
  char nombre[Max];
  
  getchar();
  printf("\nIngrese nombre de jugador: ");
  scanf("%[^\n]%*c", nombre);
  crearJugador(nombre, jugadores);
}
//muestra el jugador y su equipamiento
void opcion2(char nombre[Max], HashMap *jugadores)
{
  Pair *buscado = searchMap(jugadores, nombre);
  Jugador * aux;
  
  while(buscado != NULL)
  {
    aux = buscado->value;
    if(strcmp(aux->nombre, nombre) == 0)
    { 
      printf("\nDatos del jugador buscado\n");
      puts("======================================================");
      printf("\tNombre              : %s\n", aux->nombre);
      printf("\tPuntos de habilidad : %i\n", aux->pHabilidad);
      printf("\tCantidad de item    : %i\n", aux->item);
      
      for(int i = 0; i < aux->item; i++)
      {
        printf("\tItems               : %s\n", aux->items[i]);
      }
      puts("======================================================");
      return;
    }
    else
    {
      printf("\nNombre del jugador no existe.\n");
      return;
    }
  }
}*/

char* quitarSalto(char* linea) //quita los saltos de línea para leer bien los datos con el fgets, así se evitan errores
{
  if ((strlen(linea) > 0) && (linea[strlen(linea) - 1] == '\n'))
  {
    linea[strlen(linea) - 1] = '\0';
  }
  return linea;
}

void agregarTareas(TreeMap * arbolTareas)
{
  datosTarea *tareas = NULL;
  tareas = (datosTarea*) malloc(sizeof(datosTarea));
  //se ingresan los datos del tareas
  printf("Ingrese el nombre de la tarea.\n");
  fflush(stdin);
  fgets(tareas->nombre, 30,stdin);
  strcpy(tareas->nombre, quitarSalto(tareas->nombre));
  if (searchTreeMap(arbolTareas, tareas->nombre) != NULL)
  {
    printf("no se pueden ingresar tareas con nombres iguales :(\n");
      return;
  }
  printf("Ingrese la prioridad de la tarea.\n");
  do{
    scanf("%d", &(tareas->prioridad));
    if (tareas->prioridad==0)
    {
      printf("ERROR: ups! lo sentimos, pero las tareas no pueden tener esa prioridad :(.\n");
    }
  } while (tareas->prioridad < 0);
  //getchar(); //verificar si se puede ingresar el numero de telefono
  tareas->completada = false; //se inicializan todas las tareas en false para facilitar el trabajo al marcarlas como completadas
  insertTreeMap(arbolTareas, tareas->nombre, tareas);
  return;
}

void marcarTareaCompletada(TreeMap * arbolTareas)
{
  char nombre[50];
  printf("Ingrese el nombre de la tarea que desea marcar como completada.\n");
  fflush(stdin);
  fgets(nombre, 30,stdin);
  strcpy(nombre, quitarSalto(nombre));

  datosTarea *tarea = searchTreeMap(arbolTareas, nombre)->value;
  
  if (tarea != NULL)
  {
    //marcar la tarea como completada.
    tarea->completada = true;

    //strcat(nombre, " ✔ hecho"); para función 4
    
    printf("La tarea se ha marcado como completada(\n");
    return;
  }
  
  printf("La tarea no fue encontrada.\n");
}

void eliminarTarea(TreeMap * arbolTareas)
{
  
  char nombre[50];
  printf("Ingrese el nombre de la tarea que desea eliminar.\n");
  fflush(stdin);
  fgets(nombre, 30,stdin);
  strcpy(nombre, quitarSalto(nombre));

  datosTarea *tarea = searchTreeMap(arbolTareas, nombre)->value;
  
  if (tarea != NULL)
  {
    //marcar la tarea como completada.
    eraseTreeMap(arbolTareas, nombre);
    
    printf("La tarea se ha eliminado correctamente(\n");
    return;
  }
  printf("La tarea no fue encontrada.\n");
}


/*
// Función de comparación para qsort
int compararTareas(const void *a, const void *b) {
    datosTarea *tareaA = (datosTarea *)a;
    datosTarea *tareaB = (datosTarea *)b;
    
    return strcmp(tareaA->nombre, tareaB->nombre);
}

void ordenarTareas(TreeMap *arbolTareas) {
    // Contar la cantidad de tareas en el árbol
    int cantidadTareas = sizeTreeMap(arbolTareas);
    
    // Crear un arreglo para almacenar las tareas
    datosTarea *tareas = (datosTarea *)malloc(cantidadTareas * sizeof(datosTarea));
    if (tareas == NULL) {
        printf("Error al asignar memoria para el arreglo de tareas.\n");
        return;
    }
    
    // Extraer las tareas del árbol y almacenarlas en el arreglo
    int indice = 0;
    TreeMapIterator iter = firstTreeMap(arbolTareas);
    while (iter != NULL) {
        datosTarea *tarea = (datosTarea *)getValueTreeMapIterator(iter);
        tareas[indice] = *tarea;
        
        iter = nextTreeMapIterator(iter);
        indice++;
    }
    
    // Ordenar el arreglo de tareas utilizando qsort
    qsort(tareas, cantidadTareas, sizeof(datosTarea), compararTareas);
    
    // Reconstruir el árbol con las tareas ordenadas
    clearTreeMap(arbolTareas);
    for (int i = 0; i < cantidadTareas; i++) {
        putTreeMap(arbolTareas, tareas[i].nombre, &tareas[i]);
    }
    
    // Liberar la memoria del arreglo de tareas
    free(tareas);
    
    printf("Las tareas se han ordenado.\n");
}
*/

// Función de comparación para qsort
int compararTareas(const void *a, const void *b) {
    datosTarea *tareaA = *(datosTarea **)a;
    datosTarea *tareaB = *(datosTarea **)b;
    
    return strcmp(tareaA->nombre, tareaB->nombre);
}


void verEstadoActual(TreeMap* arbolTareas)
{
  ArrayList *arregloAuxTareas = createArrayList();
  for (Pair * aux = firstTreeMap(arbolTareas); aux == NULL; aux = nextTreeMap(arbolTareas))
  {
    append(arregloAuxTareas, aux->value);
  }
  // Ordenar el ArrayList de tareas utilizando qsort
  qsort(getArreglo(arregloAuxTareas), get_size(arregloAuxTareas), sizeof(datosTarea *), compararTareas);

  for (int i = 0; i < get_size(arregloAuxTareas); i++) {
        datosTarea *tarea = get(arregloAuxTareas, i);
        printf("Tarea: %s\n", tarea->nombre);
        printf("Prioridad: %d\n", tarea->prioridad);
        printf("Completada: %s\n", tarea->completada ? " ✔ Sí" : "✘ No");
        printf("---------------------\n");
    }
    
    // Liberar la memoria del arreglo auxiliar de tareas
    free(arregloAuxTareas);
}

void gestionarListaTareas() {
   // printf("Gestionando Lista de Tareas...\n");
    // Implementar registrar tarea, entre otras opcionews
}

void gestionarNotas() {
   // printf("Gestionando Notas...\n");
    // Implementar 
}

void gestionarContactos() {
   // printf("Gestionando Contactos...\n");
    // Implementar
}





void mosOpc1() //Opciones para Organizador personal
{
  printf("----- Organizador Personal -----\n");
  printf("1. Lista de Tareas\n");
  printf("2. Notas\n");
  printf("3. Contactos\n");
  printf("4. Salir\n");
  printf("Ingrese una opción (1-4): \n");
}

void mostrarMenuTareas() {
    printf("----- Lista de Tareas -----\n");
    printf("1. Agregar tarea\n");
    printf("2. Marcar tarea como completada\n");
    printf("3. Eliminar tarea\n");
    printf("4. Ver estado actual de las tareas\n");
    printf("5. Volver al menú anterior\n");
    printf("Ingrese una opción: ");
}

void mostrarMenuNotas() {
    printf("----- Notas -----\n");
    printf("1. Crear nota\n");
    printf("2. Editar nota\n");
    printf("3. Eliminar nota\n");
    printf("4. Ver notas existentes\n");
    printf("5. Volver al menú anterior\n");
    printf("Ingrese una opción: ");
}

void mostrarMenuContactos() {
    printf("----- Contactos -----\n");
    printf("1. Agregar contacto\n");
    printf("2. Buscar contacto\n");
    printf("3. Editar contacto\n");
    printf("4. Eliminar contacto\n");
    printf("5. Volver al menú anterior\n");
    printf("Ingrese una opción: ");
}
