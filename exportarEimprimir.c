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
//#include <>

/*
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
        nota *datosNota = par->data;
        fprintf(archivo, "%s,%s\n", datosNota->nombreNotas, datosNota->textoNotas);
        par = nextMap(mapaNotas);
    }

    fclose(archivo);
    printf("Archivo exportado exitosamente como %s.\n", nombreArchivo);
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
        contacto *datosContacto = par->data;
        fprintf(archivo, "%s,%s,%s\n", datosContacto->nombreContacto, datosContacto->numTelefono, datosContacto->correo);
        par = nextMap(mapaContactos);
    }

    fclose(archivo);
    printf("Archivo exportado exitosamente como %s.\n", nombreArchivo);
}


*/
/*
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

    treePair* par = firstTreeMap(arbolTareas);
    while (par != NULL) {
        datosTarea* datos = par->data;
        const char* completadaStr = datos->completada ? "Completada" : "No completada";
        fprintf(archivo, "%s,%d,%s\n", datos->nombre, datos->prioridad, completadaStr);
        par = nextTreeMap(arbolTareas);
    }

    fclose(archivo);
    printf("Archivo exportado exitosamente como %s.\n", nombreArchivo);
}
*/
/*void exportarCsvFinanzas{
}*/
