#pragma once
#include "tab.h"
#include<stdio.h>
#include<stdlib.h>

#define TAB2SIZE 100

int main() {
	int myTab1[10]; //on crée le tableau
	initTab(myTab1, 10); //On l'initialise
	afficheTab(myTab1, 10, 5); // on l'affiche

	printf("\n");
		
	int* myTab2 = NULL; //on crée le pointeur
	int tabSize = TAB2SIZE; //taille initialisée
	
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); //allocation taille pointeur
	if (myTab2 != NULL) { initTab(myTab2, tabSize); } // initalisation tableau à 0
	else { printf("mémoire insuffisante"); return(-1); } //en cas d'erreur d'allocation, tab devient NULL
	
	int nbElts = 20;
	for (int i = 0; i < nbElts; i++) *(myTab2 + i) = i+1; //on remplit le tableau des valeurs de 1 à 20

	
	afficheTab(myTab2, tabSize, nbElts); //affichage des 20 premieres valeurs

	myTab2 = ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 30); //on ajoute 30 au tableau (si on met TAB2SIZE = 20 voir fonction)
	printf("\n");
	afficheTab(myTab2, tabSize, nbElts); //on affiche aprés ajout



	free(myTab2); //on détruit le tableau

	
	
}

