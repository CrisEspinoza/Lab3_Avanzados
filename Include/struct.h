# ifndef STRUCT_H
# define STRUCT_H

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct Nodo
{
	int distanceOrigin;
	float weigth;
}Nodo;

typedef struct List
{
	int numberCollectionCenter;
	int numberCollectionAvailable;
	float govermentMoney;
	float cost;
	Nodo* nodo;
}List;

// Definimos las funciones que se van a utilizar dentro del codigo 

List* loadListNodo (char nombre[]);
List* createListNodo(int numberCollectionCenter, int numberCollectionAvailable , int govermentMoney , List* listNodo);
void goloso(List* listNodos);
void printCurrent();
void printListNodo (List* listNodo);
void freeMemory(List* listNodo);

# endif