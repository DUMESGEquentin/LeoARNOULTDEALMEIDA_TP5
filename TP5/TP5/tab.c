#pragma once
#include<stdio.h>
#include<stdlib.h>

#define TAILLEAJOUT 50

int initTab(int* tab, int size)
{
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) *(tab + i) = 0;
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
	if (tab == NULL || size == NULL || nbElts == NULL || *size < 0 || *nbElts < 0) { return NULL; }     // Si les valeurs entr�es sont non , alors on retourne NULL.
	if (*nbElts + 1 > * size) {      // Test si d�passement de capacit�.
		int* tmp = tab;       // Sauvegarde de l'ancien pointeur dans un pointeur temporaire "tmp".
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));     // Allocation de la m�moire suppl�mentaire.
		if (tab == NULL) {      // V�rification que la m�moire a bien �t� allou�e.
			tab = tmp;
			return NULL;
		}
		*size += TAILLEAJOUT;
	}
	*(tab + *nbElts) = element;
	*nbElts += 1;
	return tab;
}