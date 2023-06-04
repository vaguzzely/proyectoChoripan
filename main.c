#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

void mostrarOpciones()
{
  puts("================================================================");
  puts("\t1.- ORGANIZADOR PERSONAL");
  puts("\t2.- GESTION DE FINANZAS PERSONALES");
  puts("\t3.- RECORDATORIOS");
  puts("\t4.- CONFIGURACIONES");
  puts("\t5.- EXTRAER E IMPRIMIR");
  puts("\t6.- SALIR");
  puts("================================================================");
  printf("Seleccione una opción (1-6)");
}

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
        printf("Has seleccionado la opción 5.\n");
        break;

      case 6:
        printf("Has seleccionado la opción 6.\n");
        break;

      case 0:
        printf("Saliendo del programa...\n");
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

  
  menu();
  
  return 0;
}