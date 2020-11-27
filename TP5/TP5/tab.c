#pragma once
#include<stdio.h>
#include<stdlib.h>

#define TAILLEAJOUT 50

int initTab(int* tab, int size) //fonction pour initialiser le tableau à 0
{
	if (size < 0 || tab == NULL) { // si le pointeur est nul ou size < 0 on retourne -1
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) *(tab + i) = 0; //on fait une boucle où l'on donne la valeur 0 à tout le tableau
		return size;
	}
}
int afficheTab(int* tab, int size, int nbElts) {
	if (size < 0 || tab == NULL || size<nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) printf("%d ", *(tab + i));
		return 0;
	}
}
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || size == NULL || nbElts == NULL || *size < 0 || *nbElts < 0) { return NULL; } 
	if (*nbElts + 1 > * size) {
		int* tmp = tab;
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));
		if (tab == NULL) { tab = tmp; return NULL;}
		*size += TAILLEAJOUT;
	}
	*(tab + *nbElts) = element;
	*nbElts += 1;
	return tab;
}