#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

TABLEAU newArray() { // on initialise un tableau dynamique
	TABLEAU elt; // on crée une variable de type TABLEAU
	elt.size = TAILLEINITIALE; //on donne sa taille
	elt.elt = (int*)malloc(elt.size * sizeof(int)); //on fait une allocation de memoire
	if (elt.elt == NULL) return elt; //si l'allocation echoue on 
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
		int tailleAvantAlloc = tab->size;
		incrementArraySize(tab, pos - (tab->size));
		for (int i = tailleAvantAlloc; i < pos - 1; i++) { *(tab->elt + i) = 0; }
		tab->elt[pos - 1] = element;
	}
	return pos;
}
int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (startPos > tab->size || endPos > tab->size || startPos < 0 || endPos < 0) { //en cas de valeur non correcte on retourne -1
		return -1;
	}
	if (startPos > endPos) { //si position début > position de fin
		for (int i = endPos; i < startPos; i++) { //on fait une boucle en affichant de la "derniere" à la "premiere" valeur
			printf("%d ", *(tab->elt + i));
		}
	}
	else if (startPos == endPos) { printf("%d ", *(tab->elt + startPos - 1)); } //si position début = position de fin on affiche juste la valeur
	else { //si position de fin < position de fin
		for (int i = startPos; i < endPos; i++) { //on fait une boucle en affichant de la "premiere" à la "derniere" valeur
			printf("%d ", *(tab->elt + i));
		}
	}
	return 0;
}
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (startPos > tab->size || endPos > tab->size || startPos < 0 || endPos < 0) { //en cas de valeur non correcte on retourne -1
		return -1;
	}
	for (int i = 0; i < abs(startPos - endPos) +1; i++) { //on fait une boucle en affichant de la "derniere" à la "premiere" valeur
		tab->elt[startPos + i] = tab->elt[endPos + i];
	}
	tab->size -= abs(startPos - endPos) + 1;


	int tmp = (int*)realloc(tab->elt, tab->size* sizeof(int));
	if (tmp == NULL) { return -1; }
	tab->elt = tmp;
	return tab->size; //a


}