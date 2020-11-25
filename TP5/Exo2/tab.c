#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

TABLEAU newArray() {
	TABLEAU elt;
	elt.size = TAILLEINITIALE;
	elt.elt = (int*)malloc(elt.size * sizeof(int));
	if (elt.elt == NULL) return elt;
	for (int i = 0; i < TAILLEINITIALE; i++) *(elt.elt + i) = 0;
	elt.eltsCount = 0;
	return elt;
}
int incrementArraySize(TABLEAU* tab, int incrementValue) {

	int tmp = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
	if (tmp == NULL) {return -1;}
	tab->elt = tmp;
	tab->size += incrementValue;
	return tab->size;

}
int setElement(TABLEAU* tab, int pos, int element) {
	if (pos < 0) return 0;
	else if (pos < tab->size) { tab->elt[pos - 1] = element; }
	else{ 
		incrementArraySize(tab, pos - (tab->size));
		tab->elt[pos - 1] = element;
	}
	return pos;
	

}