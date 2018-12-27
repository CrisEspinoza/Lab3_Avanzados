#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/struct.h"

// ******************   Funciones para realizar escritura y lectura de archivos  ******************//

List* loadListNodo (char nombre[])
{
	FILE *file; // Declaramos un puntero File para poder leer el file de entrada.
	char* route = (char*)calloc(100, sizeof(char));
	strcat(route, "../Documents/");
	strcat(route, nombre);
    strcat(route, ".in");
    file = fopen (route, "r"); // Estamos abriendo el file en modo lectura

    List* listNodo = (List*)malloc(sizeof(List));; // Se declara una variable de tipo matriz
    int numberCollectionCenter,numberCollectionAvailable, distanceOrigin, counter = 0; 
    float weigth,govermentMoney;
    //Verificamos si el file se encuentra nulo
    if( file == NULL)
    {
        printf("Error al abrir archivo \n");
        return NULL;
    }

    // Leemos las primeras lineas del file para un mejor manejo de este
    fscanf(file, "%d %d %f", &numberCollectionCenter, &numberCollectionAvailable, &govermentMoney );

    //printf("%d %d %d \n", numberCollectionCenter, numberCollectionAvailable, govermentMoney);

    listNodo = createListNodo(numberCollectionCenter,numberCollectionAvailable,govermentMoney,listNodo);

    while(getc(file) != '\n'); // Que lea el file siempre y cuando no sea un salto de linea
    while (!feof(file)) 
    {
        //printf("ENtre");
        fscanf(file, "%d %f",&distanceOrigin, &weigth);
        listNodo->nodo[counter].distanceOrigin = distanceOrigin;
        listNodo->nodo[counter].weigth = weigth;
        //printf("%d %f \n" , distanceOrigin,weigth);
        counter++;
    }
    
    fclose(file); // Cerramos el file
 
    return listNodo; //Retornamo la variable matriz, con el tablero contenido, el cual se leyó desde el file ingresado

}
