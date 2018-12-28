#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"

#define DEBUG

// **************** Funciones auxiliares ******************

/* 
Entrada: Recibe la matriz que se utiliza actualmente.
Procedimiento: Se encarga de ir imprimiendo cada uno de los caminos generados y su respectivo costo de viaje.
Salida: -.
*/
void printCurrent(List* listNodo, int indexOrigin, int indexDestination, float cost,int aux)
{
    #ifdef DEBUG
    printf("\n");
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
    printf("| Distancia a la ciudad | | Distancia a la ciudad  || Costo de translado | \n");
    printf("|         %d             -            %d            :          %f        | \n", listNodo->nodo[indexOrigin].distanceOrigin, listNodo->nodo[indexDestination].distanceOrigin, cost);
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
    printf("\n");
    printf("Presione una tecla para continuar ... .. . \n");
    printf("\n");
    if (aux == 1)
    {
        printf("|************************************************************************|\n");
        printf("|                                                                        |\n");
        printf("|                       Pasando a otro nodo                              |\n");
        printf("|                                                                        |\n");
        printf("|************************************************************************|\n");
    }
    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
    #endif
}

/* 
Entrada: Recibe la variable matriz.
Procedimiento: Se encarga de liberar la memoria de la variable matriz que se ocupa a lo largo del programa, que ayuda a reiniciar el programa 
sin necesidad que se tenga que volver a ejecutar.
Salida: -.
*/

void freeMemory(List* listNodo)
{
    free(listNodo->nodo);
    free(listNodo);
}

/* 

*/

List* createListNodo(int numberCollectionCenter, int numberCollectionAvailable , int govermentMoney , List* listNodo)
{
    listNodo->numberCollectionCenter = numberCollectionCenter;
    listNodo->numberCollectionAvailable = numberCollectionAvailable;
    listNodo->govermentMoney = govermentMoney;

    listNodo->nodo = (Nodo*)malloc(sizeof(Nodo)*numberCollectionCenter);

    return listNodo;
}

void printListNodo (List* listNodo)
{
    printf("Cantidad total = %d \n ", listNodo->numberCollectionCenter);
    printf("Cantidad disponible = %d \n ", listNodo->numberCollectionAvailable);
    printf("Cantidad de dinero del gobierno = %f millones \n", listNodo->govermentMoney*1000000);
    printf("Cantidad de dinero utilizada es de: %f \n ", listNodo->cost);

    int i ;

    for (i = 0 ; i < listNodo->numberCollectionCenter; i++)
    {
        printf("El costo es de : %d y tonelada de : %f \n", listNodo->nodo[i].distanceOrigin, listNodo->nodo[i].weigth);
    }
}
