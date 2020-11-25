#pragma once
typedef struct Tableau {
	int* elt; // le tableau d’entiers 
	int size; // la taille de ce tableau d’entiers 
	int eltsCount; // le nombre d’éléments dans le tableau 
} TABLEAU;
TABLEAU newArray();
int incrementArraySize(TABLEAU* tab, int incrementValue);
int setElement(TABLEAU* tab, int pos, int element);
#define TAILLEINITIALE 100