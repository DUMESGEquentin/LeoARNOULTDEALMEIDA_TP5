#pragma once
#include<stdio.h>
#include<stdlib.h>

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
	if (size < 0 || tab == NULL || size < nbElts) {
		return -1;
	}
	else if (size == nbElts) {
		*size += 1;
		int *save = tab;
		tab = (int*) realloc(tab, *size * sizeof(int));
		if (tab == NULL) {
			tab = save;
			*size -= 1;
			printf("\n Mémoire insuffisante \n");
			return(-1);
		}
		else {
			*nbElts += 1;
			*(tab + *nbElts) = element;
			return *nbElts;
		}
	}
	else {
		*(tab + *nbElts) = element;
		//*nbElts += 1;
		return *nbElts;
	}


}
