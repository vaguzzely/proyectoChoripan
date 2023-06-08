#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data; // es un arreglo de datos data
    int capacity;//capacidad
    int size;//current
} ArrayList;

void **getArreglo(ArrayList* array)
{
  return(array->data);
}

/* Implemente la función `ArrayList *createList()`. Esta función crea un nuevo dato de tipo ArrayList inicializando sus variables. Considere que la capacidad incial es de 2 casillas para el arreglo.
   > Recuerde reservar memoria para el ArrayList y también para el arreglo dinámico `data`.
*/
ArrayList *createArrayList(void) {
  ArrayList * arreglo = (ArrayList *)malloc(sizeof(ArrayList));
  arreglo->data = (void**)malloc(sizeof(void*));
  arreglo->capacity = 2;
  arreglo->size = 0;
  return arreglo;
}
/*2. Implemente la función `void append(ArrayList * l, void * data)`. Esta función agrega el dato al final de la lista (es decir, en la posición `size`). 

  > Si el arreglo está lleno aumente la capacidad al **doble** usando la función `realloc` así:
    `data = realloc(data, nueva_capacidad)`

  > Recuerde aumentar el valor de la variable `size`.
*/
void append(ArrayList * l, void * data){
  if (l->size == l->capacity){
    l->data = realloc(l->data, sizeof(void*)*(l-> capacity *2));
    l->capacity = (l->capacity * 2);
    }
  l->data[l->size] = data;
  l->size++;
}

/* Implemente la función `void push(ArrayList * l, void * data, int i)`. Esta función ingresa el dato en la `i`-ésima posición de la lista (`i=0` es la primera posición). 

  > Si el arreglo está lleno, primero debe aumentar su capacidad al doble.

  > Recuerde mover los elementos siguientes una casilla a la derecha.

  > Si `i` es mayor a `size`, la función no debe hacer nada.*/

void push(ArrayList * l, void * data, int i){
if (i > l->size) 
{
  return;
}
if (l->size == l->capacity)
{
  l->data = realloc(l->data, (l-> capacity *2));
  l->capacity = (l->capacity * 2);
}
int aux;
for (aux = l->size; aux > i; aux--) 
{
l->data[aux] = l->data[aux-1];
}
l->data[i] = data;
l->size++;
}
/*Implemente la función `void* pop(ArrayList * l, int i)`. Esta función elimina **y retorna** el dato de la posición `i` de la lista. Valores negativos corresponden a los datos obtenidos desde el final al principio de la lista (vea la función get).

    > Recuerde que al eliminar un dato, debe mover los elementos que se encuentran a la derecha, una casilla hacia la izquierda
*/
void* pop(ArrayList * l, int i)
{
  if (i < 0) 
  {
    i = l->size + i;
    }
  if (i < 0 || i >= l->size) 
  {
    return NULL;
    }
  int aux;
  for (aux = i; aux < l->size - 1; aux++) {
    l->data[aux] = l->data[aux+1];
  }
  l->size--;
  // Retornar elemento eliminado
  return l->data[i];
}

void* get(ArrayList * l, int i){
  if (i >= l->size) 
  {
    return NULL;
  }
  
  if (i < 0) 
  {
    i = l->size + i;
  }
  
  if (i < 0 || i >= l->size) 
  {
    return NULL;
  }
  
  return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

/*Implemente la función `void clean(ArrayList * list)`. Esta función inicializa la capacidad y tamaño de la lista a sus valores iniciales y reduce el arreglo `data` a su tamaño inicial (2).*/

//remove elements
void clean(ArrayList * list)
{
  free(list->data);
  list->data = malloc(sizeof(void *) * 2);
  list->capacity = 2;
  list->size = 0;
}


