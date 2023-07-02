#include "hashmap.h"
#include "list.h"
#include "stack.h"
#include "treemap.h"
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 1000

int lower_than_string(void *key1, void *key2) {
  char *k1 = (char *)key1;
  char *k2 = (char *)key2;
  if (strcmp(k1, k2) < 0)
    return 1;
  return 0;
}

void mosOpc1() // Opciones para Organizador personal
{
  printf("----- Organizador Personal -----\n");
  printf("1. Lista de Tareas\n");
  printf("2. Notas\n");
  printf("3. Contactos\n");
  printf("4. Salir\n");
  printf("Ingrese una opción (1-4): \n");
}

void mostrarMenuTareas(TreeMap* arbolTareas) {
  printf("----- Lista de Tareas -----\n");
  printf("1. Agregar tarea\n");                   // O(1)
  printf("2. Marcar tarea como completada\n");    // O(1)
  printf("3. Eliminar tarea\n");                  // O(1)
  printf("4. Ver estado actual de las tareas\n"); // O(n)
  printf("5. Volver al menú anterior\n");         // O(1)
  printf("Ingrese una opción: ");

  int opcion;
  scanf("%d", &opcion);
  getchar();
  switch (opcion) {
  case 1:
    // lógica para agregar tarea
    agregarTareas(arbolTareas); 
    return;
  case 2:
    // lógica para marcar tarea como completada
    marcarTareaCompletada(arbolTareas);
    break;
  case 3:
    // lógica para eliminar tarea
    eliminarTarea(arbolTareas);
    break;
  case 4:
    verEstadoActual(arbolTareas);
    break;
  case 5:
    printf("Presione 5 nuevamente.\n");
    break;
    // Lógica para volver al menú anterior (creo q un return)
  default:
    printf("Opción inválida.\n");
    break;
  }
}

void mostrarMenuNotas(HashMap *mapaNotas) {
  printf("----- Notas -----\n");
  printf("1. Crear nota\n");    // O(1)
  printf("2. Eliminar nota\n"); // O(1)
  printf("3. Ver nota\n");      // O(n)
  printf("4. Volver al menú anterior\n");
  printf("Ingrese una opción: ");

  int opcion;
  scanf("%d", &opcion);
  getchar();

  switch (opcion) {
  case 1:
    // lógica para crear nota
    crearNota(mapaNotas);
    break;
  case 2:
    eliminarNota(mapaNotas);
    break;
  case 3:
    // lógica para ver una nota ingresando el nombre de ella
    verNota(mapaNotas);
    break;
  case 4:
    // Lógica para volver al menú anterior (puede ser un return)
    break;
  default:
    printf("Opción inválida.\n");
    break;
  }
}

void mostrarMenuContactos(HashMap *mapaContactos) {

  printf("----- Contactos -----\n");
  printf("1. Agregar contacto\n");            // O(1)
  printf("2. Buscar contacto\n");             // O(1)
  printf("3. Eliminar contacto\n");           // //O(1)
  printf("4. Mostrar todos los contactos\n"); // O(n)
  printf("5. Volver al menú anterior\n");
  printf("Ingrese una opción: ");

  int opcion;
  scanf("%d", &opcion);
  getchar();

  switch (opcion) {
  case 1:
    crearContacto(mapaContactos);
    break;
  case 2:
    verContacto(mapaContactos);
    // lógica para buscar e imprimir el nombre del contacto y su info
    break;
  case 3:
    eliminarContacto(mapaContactos);
    break;
  case 4:
    mostrarTodosContactos(mapaContactos);
    break;
  case 5:
    // Lógica para volver al menú anterior (puede ser un return)
    break;
  default:
    printf("Opción inválida.\n");
    break;
  }
}

void opcionesRecordatorio() /*opciones de las opcion recordatorio*/
{
  puts("\n==============================================");
  puts("\t1.- CREAR RECORDATORIO");
  puts("\t2.- DESHACER RECORDATORIO");
  puts("\t3.- MOSTRAR RECORDATORIOS");
  puts("\t4.- VOLVER A MENU");
  puts("==============================================");
  printf("\nSeleccione una opción (1-4)\n");
}

// submenú si se presiona la opción de recordatorios
void MenuRecordatorios(List *recordatorios) {
  HashMap *mapaMeses = createMap(13);

  int opc;

  while (1) {
    opcionesRecordatorio();
    scanf("%i", &opc);

    switch (opc) {
    case 1:
      printf("Has seleccionado la opción 1.\n");
      system("clear");
      crearRecordatorio(recordatorios, mapaMeses);
      break;

    case 2:
      printf("Has seleccionado la opción 2.\n");
      system("clear");
      borrarRecordatorio(recordatorios);
      break;

    case 3:
      printf("Has seleccionado la opción 3.\n");
      system("clear");
      mostrarRecordatorios(recordatorios, mapaMeses);
      break;

    case 4:
      printf("\nVolviendo al menu principal...\n");
      system("clear");
      return;

    default:
      printf("Opción inválida.\n");
      system("clear");
      break;
    }
  }
}

void mostrarMenuExportar(HashMap *mapaNotas) 
{
  printf("----- Exportar -----\n");
  printf("1. Exportar tareas\n");
  printf("2. Exportar notas\n");
  printf("3. Exportar contactos\n");
  printf("4. Volver al menú anterior\n");
  printf("Ingrese una opción: ");

  int opcion;
  scanf("%d", &opcion);

  switch (opcion) {
    case 1:
      printf("Has seleccionado la opción 1: Exportar tareas. Presione 1.\n");
      break;
    
    case 2:
      printf("Has seleccionado la opción 2: Exportar notas. Presione 2.\n");
      // Lógica para exportar notas
    break;
    case 3:
      printf("Has seleccionado la opción 3: Exportar contactos. Presione 3.\n");
            // Lógica para exportar contactos
    break;
    
    case 4:
      printf("Volviendo al menú anterior. Presione 5.\n");
            // Lógica para volver al menú anterior
    break;
    default:
      printf("Opción inválida.\n");
      break;
    }
}

void mosOpc2() //Opciones para Gestion de Finanzas
{
  puts("\n==================================================");
  puts("\t1.- REGISTRO DE TRANSACCIONES");
  puts("\t2.- CATEGORIAS");
  puts("\t3.- PRESUPUESTO");
  puts("\t4.- INFORME FINANCIERO");
  puts("\t5.- VOLVER A MENU");
  puts("==================================================");
  printf("\nSeleccione una opción (1-5)\n");
}

//submenú si se presiona la opción 2, gestión de finanzas
void subMenu2()
{
  int opc;
  List *listaM = createList();
  HashMap *mapCat = createMap(MAX);

  while (1)
  {
    mosOpc2();
    scanf("%i", &opc);

    switch (opc) {
    case 1:
      printf("\nHas seleccionado la opción 1.\n");
      opcion1(listaM, mapCat);
      break;

    case 2:
      printf("\nHas seleccionado la opción 2.\n");
      opcion2(listaM, mapCat);
      break;

    case 3:
      printf("\nHas seleccionado la opción 3.\n");
      opcion3(listaM, mapCat);
      break;

    case 4:
      printf("\nHas seleccionado la opción 4.\n");
      opcion4(listaM, mapCat);
      break;

    case 5:
      printf("\nVolviendo al menu principal...\n");
      return;

    default:
      printf("\nOpción inválida.\n");
      system("clear");
      break;
    }
  }
}

// opciones menú principal organizador
void mostrarOpciones() {
  puts("\n==================================================");
  puts("\t1.- ORGANIZADOR PERSONAL");
  puts("\t2.- GESTION DE FINANZAS PERSONALES");
  puts("\t3.- RECORDATORIOS");
  puts("\t4.- AYUDA");
  puts("\t5.- EXPORTAR");
  puts("\t6.- SALIR"); // te lleva al menú principal
  puts("==================================================\n");
  printf("Seleccione una opción (1-6)\n");
}

// menú principal
void menu(List *recordatorios,TreeMap *arbolTareas,HashMap *mapaNotas,HashMap *mapaContactos) {
  int opcion;

  while (1) {
    mostrarOpciones();
    scanf("%i", &opcion);

    switch (opcion) {
    case 1:
      printf("Has seleccionado la opción 1.\n");
      int opcionOrganizador = 0;
      int opcionSubMenu1 = 0;
      while (opcionOrganizador != 4) {
        mosOpc1();
        scanf("%d", &opcionOrganizador);

        switch (opcionOrganizador) {
        case 1:
          while (opcionSubMenu1 != 5) {
            mostrarMenuTareas(arbolTareas);
            scanf("%d", &opcionSubMenu1);

            switch (opcionSubMenu1) {
            case 1:
              printf("Agregar tarea seleccionado.\n");
              break;
            case 2:
              printf("Marcar tarea como completada seleccionado.\n");
              break;
            case 3:
              printf("Eliminar tarea seleccionado.\n");
              // para eliminar tarea
              break;
            case 4:
              printf("Ver estado actual de las tareas seleccionado.\n");
              // para ver estado actual de las tareas
              break;
            case 5:
              printf("Volviendo al menú...\n");
              break;
            default:
              printf("Opción inválida. Intente nuevamente.\n");
              break;
            }

            printf("\n");
          }
          opcionSubMenu1 = 0;
          break;
        case 2:
          while (opcionSubMenu1 != 5) {
            mostrarMenuNotas(mapaNotas);
            scanf("%d", &opcionSubMenu1);

            switch (opcionSubMenu1) {
            case 1:
              printf("Crear nota seleccionado.\n");
              // para crear nota
              break;
            case 2:
              printf("Editar nota seleccionado.\n");
              // para editar nota
              break;
            case 3:
              printf("Eliminar nota seleccionado.\n");
              // para eliminar nota
              break;
            case 4:
              printf("Ver notas existentes seleccionado.\n");
              // para ver notas existentes
              break;
            case 5 : printf("Volviendo al menú...\n");
              break;
            default:
              printf("Opción inválida. Intente nuevamente.\n");
              break;
            }
            printf("\n");
          }
          opcionSubMenu1 = 0;
          break;
        case 3:
          while (opcionSubMenu1 != 5) {
            mostrarMenuContactos(mapaContactos);
            scanf("%d", &opcionSubMenu1);

            switch (opcionSubMenu1) {
            case 1:
              printf("Contacto agregado exitosamente.\n");
              // para agregar contacto
              break;
            case 2:
              printf("Contacto encontrado exitosamente.\n");
              // para buscar contacto
              break;
            case 3:
              printf("Cambios en el perfil de contacto realizados "
                     "exitosamente.\n");
              // para editar contacto
              break;
            case 4:
              printf("Contacto eliminado exitosamente.\n");
              // para eliminar contacto
              break;
            case 5:
              printf("Volviendo al menú...\n");
              break;
            default:
              printf("Opción inválida. Intente nuevamente.\n");
              break;
            }

            printf("\n");
          }
          opcionSubMenu1 = 0;
          break;
        case 4:
          printf("Saliendo del programa...\n");
          break;
        default:
          printf("Opción inválida. Intente nuevamente.\n");
          break;
        }
        printf("\n");
      }
      break;
      // fin opciones organizador de tareas
    case 2:
      printf("\nHas seleccionado la opción 2.\n");
      subMenu2();
      break;

    case 3:
      printf("Has seleccionado la opción 3.\n");
      system("clear");
      MenuRecordatorios(recordatorios);
      break;

    case 4:
      printf("\nHas seleccionado la opción 4.\n");
      menuAyuda();
      int opcionSubMenu4 = 0;
      scanf("%d", &opcionSubMenu4);

      switch (opcionSubMenu4) {
      case 1:
        printf("¿Cómo usar el organizador personal?\n\n");
        comOrganizador();
        break;
      case 2:
        printf("\n¿Cómo usar la gestión de finanzas personales?\n\n");
        comFinanzas();
        break;
      case 3:
        printf("¿Cómo usar los recordatorios?\n\n");
        comRecordatorios();
        break;
      case 4:
        printf("¿Cómo usar exportar?\n\n");
        // funcionalidad
        break;
      default:
        printf("Opción inválida. Intente nuevamente.\n\n");
        break;
      }
      break;
    // fin menú ayuda
    case 5:
      printf("Has seleccionado la opción 5.\n");
      mostrarMenuExportar(opcion);
      int opcionSubMenu5 = 0;
      scanf("%d", &opcionSubMenu5);

      switch (opcionSubMenu5) {
        case 1:
          printf("Has seleccionado exportar tu lista de tareas.\n");
          exportarCsvTareas(arbolTareas);
        // funcionalidad
        break;
        case 2:
          printf("Has seleccionado exportar tus notas. Presione 5.\n");
        // funcioinalidad
          exportarCsvNotas(mapaNotas);
        break;
        case 3:
          printf("Has seleccionado exportar tus contactos.Presione 5.\n");
          exportarCsvContactos(mapaContactos);
        // funcionalidad
        break;
      }
      break;
// fin menú exportar
      break;

    case 6:
      printf("\nSaliendo del programa...\n");
      return;

    default:
      printf("Opción inválida.\n");
      system("clear");
      break;
    }
  }
}

int main() {
  TreeMap *arbolTareas = createTreeMap(lower_than_string);
  HashMap *mapaNotas = createMap(100000);
  HashMap *mapaContactos = createMap(100000);
  List *recordatorios = createList();
  
  menu(recordatorios, arbolTareas, mapaNotas, mapaContactos);

  return 0;
}