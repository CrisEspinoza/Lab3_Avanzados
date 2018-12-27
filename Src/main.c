#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/struct.h"

int main()
{    
	// Se declaran las variables que se van a utilizar
    char name[25];
    int option,flag;
    List* listNodo;
    listNodo = NULL; // Se inicializa la lista como nula
 
    do
    {
        printf( "\n   1. Leer archivo");
        printf( "\n   2. Realizar tranferencias de basuras");
        printf( "\n   3. Reiniciar Programa (Liberar memoria) ");
        printf( "\n   4. Creditos" );
        printf( "\n   5. Salir" );
        printf( "\n\n   Introduzca opcion (1-5): ");

        scanf( "%d", &option );

        /* Inicio del anidamiento */

        switch ( option )
        {
            case 1: system("clear");
                    if (flag == 0)
                    {
                        printf("Ingrese nombre del archivo a leer (Sin extension) \n");
                        scanf("%s",name); // Se carga el nombre del archivo
                        listNodo = loadListNodo (name); // Se lee el archivo y se almacena en memoria el grafo
                        //printf("sale");
                        printListNodo(listNodo);
                        if (listNodo != NULL)
                            flag = 1 ;
                        break;
                    }
                    printf("Ya abrio un archivo reinicie el programa antes de cargar un nuevo archivo\n");
                    break;              

            case 2: system("clear");
                    if (listNodo != NULL && flag == 1)
            		{
                        goloso(listNodo);
                        flag = 2;
            			break;
                   	}
                    printf("Primero debe cargar alguna matriz, elegir opcion 1 \n");
                    break;     

            case 3: system("clear");
                    freeMemory(listNodo);
                    flag = 0 ;
                    break;

            case 4: system("clear");
                    printf(" * Autor: CRISTIAN EDUARDO ESPINOZA SILVA \n ");
                    printf(" * Universidad santiago de chile \n");
                    break;
        }

    }while(option != 5);

    return 0;
}