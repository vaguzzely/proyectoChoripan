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
#include <time.h>


typedef struct {
    char nombre[50];
    int prioridad;
    bool completada;
} datosTarea;


typedef struct {
  char nombreNotas[50];
  char textoNotas[500];
} nota;


typedef struct {
  char nombreContacto[50];
  char numTelefono[12];
  char correo[40];
} contacto;




char* quitarSalto(char* linea) //quita los saltos de línea para leer bien los datos con el fgets, así se evitan errores
{
  if ((strlen(linea) > 0) && (linea[strlen(linea) - 1] == '\n'))
  {
    linea[strlen(linea) - 1] = '\0';
  }
  return linea;
}

void agregarTareas(TreeMap* arbolTareas)
{
  datosTarea* tareas = NULL;
  tareas = (datosTarea*)malloc(sizeof(datosTarea));

  // Ingresar los datos de la tarea
  printf("Ingrese el nombre de la tarea:\n");
  fflush(stdin);
  fgets(tareas->nombre, 30, stdin);
  strcpy(tareas->nombre, quitarSalto(tareas->nombre));

  if (searchTreeMap(arbolTareas, tareas->nombre) != NULL)
  {
    printf("No se pueden ingresar tareas con nombres iguales. Presione 5.\n");
    return;
  }

  printf("Ingrese la prioridad de la tarea:\n");
  do
  {
    scanf("%d", &(tareas->prioridad));
    if (tareas->prioridad == 0)
    {
      printf("¡Ups! Lo sentimos, pero las tareas no pueden tener esa prioridad. Presione 5.\n");
    }
  } while (tareas->prioridad < 0);

  tareas->completada = false;

  if (searchTreeMap(arbolTareas, tareas->nombre) == NULL)
  {
    insertTreeMap(arbolTareas, tareas->nombre, tareas);
  }

  printf("Tarea agregada exitosamente. Presione 5\n");
}

/*
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
  if (searchTreeMap(arbolTareas, tareas->nombre) == NULL)
  {
    insertTreeMap(arbolTareas, tareas->nombre, tareas);
  }
  return;
}
*/
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

  
    
    printf("La tarea se ha marcado como completada. Presione 5.\n");
    return;
  }
  
  printf("La tarea no fue encontrada. Presione 5.\n");
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
    
    printf("La tarea se ha eliminado correctamente. Presione 5.\n");
    return;
  }
  printf("La tarea no fue encontrada. Presione 5.\n");
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

/*
void verEstadoActual(TreeMap* arbolTareas)
{
  ArrayList *arregloAuxTareas = createArrayList();
  for (PairTree * aux = firstTreeMap(arbolTareas); aux == NULL; aux = nextTreeMap(arbolTareas))
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
    
    // kiberar la memoria del arreglo auxiliar de tareas
    free(arregloAuxTareas);
}*/

/*
void verEstadoActual(TreeMap* arbolTareas)
{
  if (arbolTareas == NULL)
  {
    printf("No hay tareas registradas actualmente.\n");
    return;
  }

  printf("Estado actual de las tareas:\n");
  printf("---------------------------\n");

  // Recorrer el TreeMap
  for (PairTree* pair = firstTreeMap(arbolTareas); pair != NULL; pair = nextTreeMap(arbolTareas))
  {
    datosTarea* tarea = (datosTarea*)pair->value;

    printf("Tarea: %s\n", tarea->nombre);
    printf("Prioridad: %d\n", tarea->prioridad);
    printf("Completada: %s\n", tarea->completada ? "Sí" : "No");
    printf("---------------------------\n");
  }
}*/
//+++++++++++++++++++++++++++++++++++++++++++++AQUIAQUIAQUIAQUI
/*
void swap(datosTarea** tarea1, datosTarea** tarea2) {
    datosTarea* temp = *tarea1;
    *tarea1 = *tarea2;
    *tarea2 = temp;
}

void ordenarPorPrioridad(datosTarea* tareas, int numTareas) {
    for (int i = 0; i < numTareas - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numTareas; j++) {
            if (tareas[j].prioridad < tareas[minIndex].prioridad) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&tareas[i], &tareas[minIndex]);
        }
    }
}
*/
void verEstadoActual(TreeMap* arbolTareas)
{
    if (arbolTareas == NULL)
    {
        printf("No hay tareas registradas actualmente. Presione 5.\n");
        return;
    }

    int numTareas = sizeTreeMap(arbolTareas);
    datosTarea* tareas = (datosTarea*)malloc(numTareas * sizeof(datosTarea));

    int index = 0;
    // Copiar las tareas al arreglo
    for (PairTree* pair = firstTreeMap(arbolTareas); pair != NULL; pair = nextTreeMap(arbolTareas))
    {
        datosTarea* tarea = (datosTarea*)pair->value;
        tareas[index++] = *tarea;
    }

    printf("Estado actual de las tareas:\n");
    printf("---------------------------\n");

    // Imprimir las tareas ordenadas
    for (int i = 0; i < numTareas; i++) {
        datosTarea tarea = tareas[i];

        printf("Tarea: %s\n", tarea.nombre);
        printf("Prioridad: %d\n", tarea.prioridad);
        printf("Completada: %s\n", tarea.completada ? "Sí" : "No");
        printf("---------------------------\n");
    }
    printf("Presione 5.\n");
    free(tareas);
}


void crearNota(HashMap * mapaNotas)
{
  nota *datosNotas = NULL;
  datosNotas = (nota*)malloc(sizeof(nota));
  printf("Ingrese el nombre de la nota.\n");
  fflush(stdin);
  fgets(datosNotas->nombreNotas, 50,stdin);
  strcpy(datosNotas->nombreNotas, quitarSalto(datosNotas->nombreNotas));
  printf("Ingrese nota.\n");
  fflush(stdin);
  fgets(datosNotas->textoNotas, 500,stdin);
  strcpy(datosNotas->textoNotas, quitarSalto(datosNotas->textoNotas));
  if (searchMap(mapaNotas, datosNotas->nombreNotas) == NULL)
  {
    insertMap(mapaNotas, datosNotas->nombreNotas, datosNotas->textoNotas);
    printf("Nota agregada exitosamente. Presione 5.\n");
  }
  else{
    printf("Lo sentimos :(, ya existe una nota con el mismo nombre, por favor intente nuevamente. Presione 5.\n");
  }
}



void eliminarNota(HashMap *mapaNotas)
{
  printf("Ingrese el nombre de la nota a eliminar: ");
  char nombreNota[50];
  fflush(stdin);
  fgets(nombreNota, 50, stdin);
  strcpy(nombreNota, quitarSalto(nombreNota));

  // revisa si existe
  if (searchMap(mapaNotas, nombreNota) != NULL)
  {
    eraseMap(mapaNotas, nombreNota);
    printf("Nota eliminada exitosamente. Presione 5.\n");
  }
  else
  {
    printf("No se encontró una nota con ese nombre. Presione 5.\n");
  }
}

void verNota(HashMap *mapaNotas)
{
  printf("Ingrese el nombre de la nota que desea ver: ");
  char nombreNota[50];
  fflush(stdin);
  fgets(nombreNota, 50, stdin);
  strcpy(nombreNota, quitarSalto(nombreNota));

  hashPair *datosNotas = searchMap(mapaNotas, nombreNota);
  
  if (datosNotas != NULL)
  {
    printf("Nombre de la nota: %s\n", datosNotas->key);
    printf("Contenido de la nota:\n%s\n", datosNotas->value);
  }
  else
  {
    printf("No se encontró una nota con ese nombre. Presione 5.\n");
  }
  printf("Presione 5.\n");
}



void crearContacto(HashMap *mapaContactos)
{
  contacto *datosContacto = (contacto*) malloc(sizeof(contacto));

  printf("Ingrese el nombre del contacto:\n");
  fflush(stdin);
  fgets(datosContacto->nombreContacto, 50, stdin);
  strcpy(datosContacto->nombreContacto,
  quitarSalto(datosContacto->nombreContacto));

  printf("Ingrese el número de teléfono:\n");
  fflush(stdin);
  fgets(datosContacto->numTelefono, 12, stdin);
  strcpy(datosContacto->numTelefono, quitarSalto(datosContacto->numTelefono));

  printf("Ingrese el correo electrónico:\n");
  fflush(stdin);
  fgets(datosContacto->correo, 40, stdin);
  strcpy(datosContacto->correo, quitarSalto(datosContacto->correo));

  if (searchMap(mapaContactos, datosContacto->nombreContacto) == NULL)
  {
    insertMap(mapaContactos, datosContacto->nombreContacto, datosContacto);
    printf("Contacto agregado exitosamente. Presione 5\n");
  }
  else
  {
    printf("Lo sentimos :(, ya existe un contacto con el mismo nombre, por favor intente nuevamente. Presione 5\n"); 
  }
}


void verContacto(HashMap *mapaContactos)
{
  printf("Ingrese el nombre del contacto que desea ver: ");
  char nombreContacto[50];
  fflush(stdin);
  fgets(nombreContacto, 50, stdin);
  strcpy(nombreContacto, quitarSalto(nombreContacto));

  hashPair *datosContacto = searchMap(mapaContactos, nombreContacto);
  contacto *datosAux = datosContacto->value;

  if (datosContacto != NULL)
  {
    printf("Nombre del contacto: %s\n", datosAux->nombreContacto);
    printf("Número de teléfono: %s\n", datosAux->numTelefono);
    printf("Correo electrónico: %s\n", datosAux->correo);
  }
  else
  {
    printf("No se encontró un contacto con ese nombre.\n");
  }
  printf("Presione 5.\n");
}


void eliminarContacto(HashMap *mapaContactos)
{
  char nombre[50];
  printf("Ingrese el nombre del contacto que desea eliminar:\n");
  fflush(stdin);
  fgets(nombre, 50, stdin);
  strcpy(nombre, quitarSalto(nombre));

  if (searchMap(mapaContactos, nombre) != NULL)
  {
    eraseMap(mapaContactos, nombre);
    printf("Contacto eliminado correctamente. Presione 5.\n");
  }
  else
  {
    printf("El contacto no fue encontrado. Presione 5.\n");
  }
}

void mostrarTodosContactos(HashMap *mapaContactos)
{
  printf("----- Lista de contactos -----\n");

  // obtener el primer par clave-valor del HashMap
  hashPair *pair = firstMap(mapaContactos);

  // Iterar hasta que no haya más elementos en el HashMap
  while (pair != NULL)
  {
    contacto *datosContacto = (contacto*)pair->value;
    printf("Nombre: %s\n", datosContacto->nombreContacto);
    printf("Teléfono: %s\n", datosContacto->numTelefono);
    printf("Correo: %s\n\n", datosContacto->correo);

    // Obtener el siguiente par clave-valor del HashMap
    pair = nextMap(mapaContactos);
  }
  printf("Presione 5.");
}

void exportarCsvNotas(HashMap *mapaNotas) {
    time_t tiempoActual = time(NULL);
    struct tm *tiempoInfo = localtime(&tiempoActual);

    char nombreArchivo[100];
    sprintf(nombreArchivo, "notas_%d-%02d-%02d_%02d-%02d-%02d.csv",
            tiempoInfo->tm_year + 1900, tiempoInfo->tm_mon + 1, tiempoInfo->tm_mday,
            tiempoInfo->tm_hour, tiempoInfo->tm_min, tiempoInfo->tm_sec);

    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    hashPair *par = firstMap(mapaNotas);
    while (par != NULL) {
        nota *datosNota = par->value;
        fprintf(archivo, "%s,%s\n", datosNota->nombreNotas, datosNota->textoNotas);
        par = nextMap(mapaNotas);
    }

    fclose(archivo);
    printf("Archivo exportado exitosamente como %s.\n", nombreArchivo);
    printf("Presione 5.\n");
}




void exportarCsvContactos(HashMap *mapaContactos) {
    time_t tiempoActual = time(NULL);
    struct tm *tiempoInfo = localtime(&tiempoActual);

    char nombreArchivo[100];
    sprintf(nombreArchivo, "contactos_%d-%02d-%02d_%02d-%02d-%02d.csv",
            tiempoInfo->tm_year + 1900, tiempoInfo->tm_mon + 1, tiempoInfo->tm_mday,
            tiempoInfo->tm_hour, tiempoInfo->tm_min, tiempoInfo->tm_sec);

    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    hashPair *par = firstMap(mapaContactos);
    while (par != NULL) {
        contacto *datosContacto = par->value;
        fprintf(archivo, "%s,%s,%s\n", datosContacto->nombreContacto, datosContacto->numTelefono, datosContacto->correo);
        par = nextMap(mapaContactos);
    }

    fclose(archivo);
    printf("Archivo exportado exitosamente como %s.\n", nombreArchivo);
    printf("Presione 5.\n");
}



void exportarCsvTareas(TreeMap* arbolTareas) {
    time_t tiempoActual = time(NULL);
    struct tm *tiempoInfo = localtime(&tiempoActual);

    char nombreArchivo[100];
    sprintf(nombreArchivo, "tareas_%d-%02d-%02d_%02d-%02d-%02d.csv",
            tiempoInfo->tm_year + 1900, tiempoInfo->tm_mon + 1, tiempoInfo->tm_mday,
            tiempoInfo->tm_hour, tiempoInfo->tm_min, tiempoInfo->tm_sec);

    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    PairTree* par = firstTreeMap(arbolTareas);
    while (par != NULL) {
        datosTarea* datos = par->value;
        //const char* completadaStr = datos->completada ? "Completada" : "No completada";
      if (datos->completada == true)
      {
        fprintf(archivo, "%s,%d,%s\n", datos->nombre, datos->prioridad, "Si");
        }
      else
      {
        fprintf(archivo, "%s,%d,%s\n", datos->nombre, datos->prioridad, "No");
      }
        
        par = nextTreeMap(arbolTareas);
    }

    fclose(archivo);
    printf("Archivo exportado exitosamente como %s.\n", nombreArchivo);
    printf("Presione 5.\n");
}












