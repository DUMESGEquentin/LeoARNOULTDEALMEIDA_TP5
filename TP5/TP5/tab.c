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
		return size; // on retourne la taille
	}
}
int afficheTab(int* tab, int size, int nbElts) {
	if (size < 0 || tab == NULL || size<nbElts) { // on retourne -1 en cas de parametre non valide
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) printf("%d ", *(tab + i)); // on fait une boucle de tout les éléments du tableau
		return 0; // en incrémentant le pointeur tab de i et on affiche cette valeur
	}
}
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || size == NULL || nbElts == NULL || *size < 0 || *nbElts < 0) { return NULL; } // on retoune -1 si valeur non valide
	if (*nbElts + 1 > * size) { // on ajoute les instructions suivantes si le tableau est trop petit
		int* tmp = tab; // on sauvegarde le tableau en cas d'erreur
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int)); // on réallou le tableau avec tailleajout (50) en plus
		if (tab == NULL) { tab = tmp; return NULL;} // si il y a une erreur on retourne NULL
		*size += TAILLEAJOUT; //on ajoute tailleajout à la taille du tableau
	}
	*(tab + *nbElts) = element; //on donne la valeur element au bout de la liste
	*nbElts += 1; // on augmente de 1 le nombre d'element
	return tab; // on retourne le tableau
}