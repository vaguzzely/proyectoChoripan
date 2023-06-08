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


typedef struct
{
  char texto[10000];
}Recordatorio;

void crearRecordatorio()
{
  
}

void opcionesRecordatorio()/*opciones de las opcion recordatorio*/
{
    puts("\n==============================================");
  puts("\t1.- CREAR RECORDATORIO");
  puts("\t2.- DESHACER RECORDATORIO");
  puts("\t3.- MOSTRAR RECORDATORIOS");
  puts("\t4.- VOLVER A MENU");
  puts("==============================================");
  printf("\nSeleccione una opción (1-4)\n");
}
//submenú si se presiona la opción de recordatorios
void recordatorios()
{
  int opc;
  
  while(1)
  {
    opcionesRecordatorio();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("Has seleccionado la opción 1.\n");
        crearRecordatorio();
        break;

      case 2:
        printf("Has seleccionado la opción 2.\n");
        break;

      case 3:
        printf("Has seleccionado la opción 3.\n");
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


void mosOpc2() //Opciones para Gestion de Finanzas
{
  puts("\n==============================================");
  puts("\t1.- REGISTRO DE TRANSACCIONES");
  puts("\t2.- CATEGORIAS");
  puts("\t3.- PRESUPUESTO");
  puts("\t4.- INFORME FINANCIERO");
  puts("\t5.- VOLVER A MENU");
  puts("==============================================");
  printf("\nSeleccione una opción (1-5)\n");
}

//submenú si se presiona la opción 2, gestión de finanzas
void subMenu2()
{
  int opc;
  
  while(1)
  {
    mosOpc2();
    scanf("%i", &opc);

    switch(opc) 
    {
      case 1:
        printf("Has seleccionado la opción 1.\n");
        break;

      case 2:
        printf("Has seleccionado la opción 2.\n");
        break;

      case 3:
        printf("Has seleccionado la opción 3.\n");
        break;

      case 4:
        printf("Has seleccionado la opción 4.\n");
        break;

      case 5:
        printf("\nVolviendo al menu principal...\n");
        return ;

      default:
        printf("Opción inválida.\n");
        system("clear");
        break;
    }
  }
}

//opciones menú principal
void mostrarOpciones()
{
  puts("\n================================================================");
  puts("\t1.- ORGANIZADOR PERSONAL");
  puts("\t2.- GESTION DE FINANZAS PERSONALES");
  puts("\t3.- RECORDATORIOS");
  puts("\t4.- CONFIGURACIONES");
  puts("\t5.- EXTRAER E IMPRIMIR");
  puts("\t6.- SALIR");//te lleva al menú principal
  puts("================================================================\n");
  printf("Seleccione una opción (1-6)\n");
}

//menú principal
void menu()
{
  int opcion;

  while(1)
  {
    mostrarOpciones();
    scanf("%i",&opcion);

    switch (opcion) 
    {
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
                    mostrarMenuTareas();
                    scanf("%d", &opcionSubMenu1);

                    switch (opcionSubMenu1) {
                        case 1:
                            printf("Agregar tarea seleccionado.\n");
                            // para agregar tarea
                            break;
                        case 2:
                            printf("Marcar tarea como completada seleccionado.\n");
                            // para marcar tarea como completada
                            break;
                        case 3:
                            printf("Eliminar tarea seleccionado.\n");
                            //para eliminar tarea
                            break;
                        case 4:
                            printf("Ver estado actual de las tareas seleccionado.\n");
                            // para ver estado actual de las tareas
                            break;
                        case 5:
                            printf("Volviendo al menú principal...\n");
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
                    mostrarMenuNotas();
                    scanf("%d", &opcionSubMenu1);

                    switch (opcionSubMenu1) {
                      case 1:
                        printf("Crear nota seleccionado.\n");
                        //para crear nota
                      break;
                      case 2:
                        printf("Editar nota seleccionado.\n");
                        //para editar nota
                      break;
                      case 3:
                        printf("Eliminar nota seleccionado.\n");
                        // para eliminar nota
                      break;
                      case 4:
                        printf("Ver notas existentes seleccionado.\n");
                        //para ver notas existentes
                      break;
                      case 5:
                        printf("Volviendo al menú principal...\n");
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
                mostrarMenuContactos();
                scanf("%d", &opcionSubMenu1);

                switch (opcionSubMenu1) {
                    case 1:
                        printf("Contacto agregado exitosamente.\n");
                        //para agregar contacto
                        break;
                    case 2:
                        printf("Contacto encontrado exitosamente.\n");
                        //para buscar contacto
                        break;
                    case 3:
                        printf("Cambios en el perfil de contacto realizados exitosamente.\n");
                        //para editar contacto
                        break;
                    case 4:
                        printf("Contacto eliminado exitosamente.\n");
                        //para eliminar contacto
                        break;
                    case 5:
                        printf("Volviendo al menú principal...\n");
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
//fin opciones organizador de tareas
      case 2:
        printf("\nHas seleccionado la opción 2.\n");
        subMenu2();
        break;

      case 3:
        printf("Has seleccionado la opción 3.\n");
        system("clear");
        recordatorios();
        break;

      case 4:
        printf("Has seleccionado la opción 4.\n");
        break;

      case 5:
        printf("Has seleccionado la opción 5.\n");
        break;

      case 6:
        printf("\nSaliendo del programa...\n");
        return ;

      default:
        printf("Opción inválida.\n");
        system("clear");
        break;
    }
  }    
}

int main() 
{
  List *listaTareas;
  listaTareas = createList();
  HashMap *notas = createMap(100000);
  List* recordatorios = createList();
  menu();
  
  return 0;
}