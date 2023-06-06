#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

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

void mostrarOpciones()
{
  puts("\n================================================================");
  puts("\t1.- ORGANIZADOR PERSONAL");
  puts("\t2.- GESTION DE FINANZAS PERSONALES");
  puts("\t3.- RECORDATORIOS");
  puts("\t4.- CONFIGURACIONES");
  puts("\t5.- EXTRAER E IMPRIMIR");
  puts("\t6.- SALIR");
  puts("================================================================\n");
  printf("Seleccione una opción (1-6)\n");
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
        printf("\nHas seleccionado la opción 2.\n");
        subMenu2();
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
  menu();
  
  return 0;
}