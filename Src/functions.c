#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"


// ****************** Funcion principal ******************//

void goloso(List* listNodos)
{
    FILE *txt;  // Incialzamos una variable de tipo FILE para poder trabajar con los archivos
    txt = fopen("../Out/Salida.out", "wt");

    int sumTotal, auxSum, indexOrigin ,indexDestination, flag = 0 ,counter = listNodos->numberCollectionCenter,i,j;
    float x,auxCost;

    while (counter > listNodos->numberCollectionAvailable )
    {
        for (i = 0; i < listNodos->numberCollectionCenter; i++)
        {
            if (listNodos->nodo[i].weigth != 0.0)
            {
                x = listNodos->nodo[i].weigth - (listNodos->nodo[i].weigth / listNodos->govermentMoney );
                
                for (j = 0; j < listNodos->numberCollectionCenter; j++)
                {
                    if ( i != j && (listNodos->nodo[j].weigth != 0.0) )
                    {
                        //printf("Valor de i es: %d , valor de j es : %d \n" ,i ,j);
                        if (flag == 0)
                        {
                            //printf("Entre aca 1 ");
                            sumTotal = (float)abs(listNodos->nodo[i].distanceOrigin - listNodos->nodo[j].distanceOrigin) * x ;
                            flag = 1;
                            indexOrigin = i;
                            indexDestination = j; 
                            auxCost = abs((float)listNodos->nodo[indexOrigin].distanceOrigin - (float)listNodos->nodo[indexDestination].distanceOrigin) * x ; 
                        }
                        else
                        {
                            auxSum = (float)abs(listNodos->nodo[i].distanceOrigin - listNodos->nodo[j].distanceOrigin) * x ;
                            if (sumTotal > auxSum)
                            {
                                sumTotal = auxSum;
                                indexOrigin = i;
                                indexDestination = j;
                                //printf("EL numero decimal es: %f \n", listNodos->nodo[i].weigth - (listNodos->nodo[i].weigth / listNodos->govermentMoney ));
                                auxCost = abs(listNodos->nodo[indexOrigin].distanceOrigin - listNodos->nodo[indexDestination].distanceOrigin) * x ; 
                                //printf("EL resultado es: %f \n", auxCost);
                            }
                        }
                        if (j == (listNodos->numberCollectionCenter - 1) )
                            printCurrent(listNodos,i,j,auxCost,1);
                        else
                            printCurrent(listNodos,i,j,auxCost,0);
                    }
                }
            }
        }
        fprintf(txt,"%d -> %d ", listNodos->nodo[indexOrigin].distanceOrigin, listNodos->nodo[indexDestination].distanceOrigin) ; // Se coloca el peso total ocupado en la ruta minima obtenida y se pone en el archivo
        fprintf(txt,"\n");
        //printf("Los ganadores son: i = %d, j = %d \n" , indexOrigin , indexDestination);
        //printf("Origin - destino : %d - %d , Peso de: %f \n", listNodos->nodo[indexOrigin].distanceOrigin , listNodos->nodo[indexDestination].distanceOrigin , listNodos->nodo[indexOrigin].weigth);
        //printf("\n");
        //printf("Costo = %f  \n", auxCost);
        //printf("\n");
        listNodos->cost = listNodos->cost + auxCost ;
        listNodos->nodo[indexDestination].weigth = listNodos->nodo[indexOrigin].weigth + listNodos->nodo[indexDestination].weigth;
        listNodos->nodo[indexOrigin].weigth = 0.0;
        counter--;
        sumTotal = 0;
        auxSum = 0;
        flag = 0;
        indexDestination = 0;
        indexOrigin = 0;
        x = 0;
        auxCost = 0;
    }

    for(i = 0 ; i < listNodos->numberCollectionCenter ; i++)
    {
        if (listNodos->nodo[i].weigth != 0)
        {
            fprintf(txt,"Centro %d : %f Toneladas", listNodos->nodo[i].distanceOrigin, listNodos->nodo[i].weigth);
            fprintf(txt,"\n");
        } 
    }

    fprintf(txt,"Costo: %f", listNodos->cost);

    fclose(txt); // Cerramos el archivo

    //printListNodo(listNodos);
}
