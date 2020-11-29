#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

TABLEAU newArray() { // on initialise un tableau dynamique
	TABLEAU elt; // on crée une variable de type TABLEAU
	elt.size = TAILLEINITIALE; //on donne sa taille
	elt.elt = (int*)malloc(elt.size * sizeof(int)); //on fait une allocation de memoire
	if (elt.elt == NULL) return elt; //si l'allocation echoue on 
	for (int i = 0; i < TAILLEINITIALE; i++) *(elt.elt + i) = 0; //on fait une boucle de 0 à la taille initiale pour incrémenter le pointeur du tableau pour leurs donner la valeur 0
	elt.eltsCount = 0; // pour l'instant il n 'y a pas de valeur
	return elt;
}
int incrementArraySize(TABLEAU* tab, int incrementValue) { // on augmente la taille du tableau de incrementValue

	int tmp = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int)); // on réalou de taille qui existe deja par incrementValue
	if (tmp == NULL) {return -1;} //en cas d'erreur d'allocation on retourne -1 et le tableau ne change pas
	tab->elt = tmp; // on donne la valeur temporaire au tableau que l'on utilise
	tab->size += incrementValue; // on augmente la taille de incrementValue
	return tab->size; //on retourne la taille

}
int setElement(TABLEAU* tab, int pos, int element) { // on fixe la valeur d'un élément dans le tableau à rang
	if (pos < 0) return 0; //si il y a une erreur dans la position on retourne 0
	else if (pos < tab->size) { tab->elt[pos - 1] = element; } // si la position est dans le tableau deja alloué on donne juste la valeur à sa postion
	else{ 
		int tailleAvantAlloc = tab->size; //on sauvegarde cette valeur car on la change aprés l'augmentation de la taille du tableau 
		incrementArraySize(tab, pos - (tab->size)); // on augmente la taille du tableau
		for (int i = tailleAvantAlloc; i < pos - 1; i++) { *(tab->elt + i) = 0; } // on donne la valeur 0 entre la derniere valeur et position
		tab->elt[pos - 1] = element; // on redonne la valeur element à la position
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
	else if (startPos > endPos) { // si startPos > endPos
		for (int i = 0; i < startPos - endPos + 1; i++) { //on fait une boucle de la "derniere" à la "premiere" valeur de notre intervalle
			tab->elt[endPos + i] = tab->elt[startPos + i]; // on décalle les valeurs aprés startPos
		}
		tab->size -= startPos - endPos + 1; // on diminue la taille 
	}
	else { //si endPos > startPos
		for (int i = 0; i < endPos - startPos + 1; i++) { //on fait une boucle de la "premiere" à la "derniere" valeur de notre intervalle
			tab->elt[startPos + i] = tab->elt[endPos + i];// on décalle les valeurs aprés endPos
		}
		tab->size -= endPos - startPos + 1;  // on diminue la taille 
	}

	int tmp = (int*)realloc(tab->elt, tab->size* sizeof(int)); // on réalloue pour supprimer les valeurs aprés endPos
	if (tmp == NULL) { return -1; } //en cas d'erreur on retourne -1
	tab->elt = tmp; //on alloue le nouveau pointeur avec le pointeur temporaire
	return tab->size; //en retourne la taille


}