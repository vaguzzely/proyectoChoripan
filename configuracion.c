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

void menuAyuda()
{
  printf("\nMenú de Ayuda\n");
  printf("1. ¿Cómo usar el organizador personal?\n");
  printf("2. ¿Cómo usar la gestión de finanzas personales?\n");
  printf("3. ¿Cómo usar los recordatorios?\n");
  printf("4. ¿Cómo usar extraer e imprimir?\n");
  printf("\nSeleccione una opción (1-4):\n");
}

void comOrganizador()
{
  printf("Organizador personal:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("El organizador personal es una herramienta diseñada para ayudarte a gestionar y organizar tu vida diaria de manera más efectiva. Con esta aplicación, podrás mantener un seguimiento de tus tareas, tomar notas de cosas importantes, establecer prioridades y administrar tus contactos de manera sencilla y práctica.\n");
  
  printf("El organizador personal te ofrece las siguientes opciones (submenús) para ayudarte en tus tareas diarias:\n");
   printf("\n\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("1.1 Lista de tareas:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\n\n");
  
  printf("En esta sección, puedes crear y administrar tú lista de tareas. Con la opción de agregar nuevas tareas, marcar tareas como completadas, eliminar tareas y ver el estado actual de tus tareas pendientes. Organiza tus actividades de manera eficiente y asegúrate de completar todas tus responsabilidades a tiempo.\n");
  printf("\n\n");
  printf("1.1.1 Agregar tarea: Selecciona esta opción para agregar una nueva tarea a tu lista. Podrás ingresar los detalles de la tarea, como su nombre y prioridad. Mantén tu lista actualizada y añade todas las tareas que necesitas realizar.\n");
  printf("1.1.2 Marcar tarea como completada: Utiliza esta opción cuando hayas finalizado una tarea. Selecciona la tarea que has completado y márcala como finalizada. Esto te ayudará a mantener un seguimiento de tu progreso y visualizar las tareas que aún quedan por hacer.\n");
  
  printf("1.1.3 Eliminar tarea: Si una tarea ya no es relevante o necesaria, puedes seleccionar esta opción para eliminarla de tu lista. Asegúrate de elegir la tarea correcta para eliminar. De esta manera, podrás mantener tu lista de tareas actualizada y sin elementos innecesarios.\n");
  
  printf("1.1.4 Ver estado actual de las tareas: Con esta opción, podrás obtener una visión general del estado actual de tus tareas. Podrás ver cuántas tareas tienes pendientes y cuántas has completado. Esto te ayudará a tener una idea clara de tus responsabilidades y prioridades.*Las tareas no se muestran en orden*\n");
  
  printf("1.1.5 Volver al menú anterior: Si deseas regresar al menú principal del organizador personal, Presiona la tecla 5 y luego enter. Te permitirá explorar las otras funcionalidades y características disponibles en el programa.\n");
  printf("\n\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("1.2. Notas:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\n\n");
  printf(" La opción de notas te permite tomar apuntes de cosas importantes que necesites recordar. Puedes crear nuevas notas, escribir información relevante y acceder a ellas cuando las necesites. También tendrás la posibilidad de visualizar y eliminar notas para mantener tu espacio de trabajo limpio y ordenado.\n");
  printf("1.2.1. Crear nota: Selecciona esta opción para crear una nueva nota. Podrás ingresar el contenido de la nota y asignarle un título. Guarda información importante y accede a ella en cualquier momento.\n");
  
    printf("1.2.2. Eliminar nota: Utiliza esta opción para eliminar una nota existente. Selecciona la nota que deseas eliminar y confirma tu elección para eliminarla de manera permanente.\n");
    
    printf("1.2.3. Ver nota: Puedes utilizar esta opción para ver el contenido de una nota específica. Selecciona la nota que deseas ver y se mostrará su contenido completo en pantalla.\n");
    
    printf("1.2.4. Volver al menú anterior: Si deseas regresar al menú principal del organizador personal, presiona la tecla 4 y luego enter. Esto te permitirá explorar las otras funcionalidades y características disponibles en el programa.\n");
    printf("\n\n");
  
   
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
     printf("3. Contactos:\n");
     printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n");
    printf("Aquí encontrarás todas las herramientas necesarias para administrar tus contactos de manera eficaz. Puedes agregar nuevos contactos, proporcionando su nombre, número de teléfono y correo electrónico. También tendrás la capacidad de buscar contactos existentes en caso de que necesites encontrar información específica. Además, podrás ver una lista completa de todos tus contactos y eliminar aquellos que ya no sean necesarios.\n");
    printf("\n\n");
    printf("1.3.1. Agregar contacto: Selecciona esta opción para agregar un nuevo contacto a tu lista. Podrás ingresar el nombre del contacto, su número de teléfono y su correo electrónico. Mantén tu lista de contactos actualizada y guarda la información de tus contactos importantes.\n");
    printf("1.3.2. Buscar contacto: Utiliza esta opción para buscar un contacto existente en tu lista. Ingresa el nombre del contacto que deseas buscar y se mostrará su información completa en pantalla si se encuentra en la lista de contactos.\n");
    printf("1.3.3. Eliminar contacto: Selecciona esta opción para eliminar un contacto existente de tu lista. Se te pedirá que ingreses el nombre del contacto que deseas eliminar y, una vez confirmado, el contacto se eliminará de manera permanente.\n");
    printf("1.3.4. Mostrar todos los contactos: Utiliza esta opción para ver una lista completa de todos tus contactos. Se mostrará el nombre, número de teléfono y correo electrónico de cada contacto en pantalla.\n");
    printf("1.3.5. Volver al menú anterior: Si deseas regresar al menú principal del organizador personal, presiona la tecla 5 y luego enter. Esto te permitirá explorar las otras funcionalidades y características disponibles en el programa.\n");
    printf("\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\n\n");
   printf("Utilizar el organizador personal es muy sencillo. Simplemente ingresa el número correspondiente a la opción del menú que deseas utilizar a través de la consola y luego presiona enter. Explora las diferentes funcionalidades y submenús disponibles!!. Aprovecha al máximo esta herramienta y mantén tu vida organizada, productiva y libre de estrés.\n");
   printf("\n\n");
   printf("Recuerda que el objetivo principal del organizador personal es ayudarte a mantener el control de tus tareas, notas y contactos de manera eficiente. ¡Disfruta de una vida más organizada y enérgica con el organizador personal!\n");

}

void comFinanzas()
{
  printf("Gestion de finanzas personales:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Gestion de finanzas es una herramienta diseñada para ayudarte a gestionar tus ingresos de manera más efectiva.\n\n");
  
  printf("Gestion de finanzas te ofrece las siguientes opciones (submenús):\n\n");

  printf("1. Registro de transacciones:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("1.1 Registro de ingreso:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Al ingresar a Registro de Ingresos, se le consultará al usuario el monto que desea agregar, una vez puesto el monto, se consultará por la categoría que debe haber sido ingresada previamente. Con esto listo, se desplegarán dos burbujas de texto, la primera indicando el monto en la categoría seleccionada y la seguna mostrando el monto total en la cartera virtual del usuario.\n\n");

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("1.2 Registro de transacción:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Al ingresar a Registro de transacción, se le consultará al usuario el monto que desea transferir, una vez puesto el monto, se consultará por la categoría que debe haber sido ingresada previamente. Con esto listo, se desplegarán dos burbujas de texto, la primera indicando el monto restante en la categoría seleccionada y la seguna mostrando el monto total en la cartera virtual del usuario.\n\n");
  
  printf("2. Categorias:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("2.1 Agregar Categoría:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Para agregar una categoría nueva, el usuario debe de ingresar el nombre de esta. Si es que la categoría no existe se creará una nueva con monto en 0.\n\n");

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("2.2 Eliminar Categoría:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Al seleccionar esta alternativa en el menú, esta consultará por el nombre de la categoría que se desea eliminar. Una vez eliminada, tambien se eliminará el dinero almacenado en esta, asi que ten cuidado al momento de hacerlo, debes estar completamente seguro ya que no habrá una confirmación.\n\n");

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("2.3 Mostrar Categoría:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Al ingresar a la opcion de mostrar categorias, esta preguntará al usuario el nombre de la categoria que desea ver en pantalla. Asegurate de escribir el nombre correctamente, ya que si la categoría no existe, mostrará un mensaje indicando lo anterior. Si la categoría fue ingresada correctamente, mostrará la cantidad de dinero que esta almacena.\n\n");
  
  printf("3. Presupuesto:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("3.1 Asignar Presupuesto:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Para asignar el presupuesto, se consultará al usuario el nombre de la categoría para la cual desea asignar el presupuesto. Una vez ingresado el nombre de una categoría existente, se debe ingresar el monto presupuestado. Presupuesto no funciona como un limite de dinero a ingresar en categorias, si no, como una proyeccion de cuanto dinero se planea mantener en esta.\n\n");

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("3.2 Eliminar Presupuesto:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Para eliminar el presupuesto, se consultará al usuario la categoria a la cual desea eliminar el presupuesto. Al ingresar una categoria valida, el presupuesto quedará en 0.\n\n");

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("3.3 Mostrar Categoría y presupuesto:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("La utilidad de esta función es poder enseñar al usuario el monto existente en la Categoría junto con el Presupuesto o el dinero que se tiene estimado. Al ingresar, se le consultará al usuario por el nombre de una Categoría. Asegurese de ingresar una categoría válida. Una vez hecho esto, el usuario podrá ver correctamente lo anterior mencionado.\n\n");
  
  printf("4. Informe financiero:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Informe financiero exportará los datos almacenados en Gestion de Finanzas a un archivo CSV (excel). El cual debe abrirse externo a EasyLife para poder imprimir el informe si se desea\n\n");
}

/*
void comRecordatorios
{
  
}
*/

/*
void comExtraer
{
  
}
*/