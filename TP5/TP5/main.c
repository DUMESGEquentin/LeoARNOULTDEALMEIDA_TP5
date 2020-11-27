#pragma once
#include "tab.h"
#include<stdio.h>
#include<stdlib.h>

#define TAB2SIZE 100

int main() {
	int myTab1[10]; //on cr�e le tableau
	initTab(myTab1, 10); //On l'initialise
	afficheTab(myTab1, 10, 5); // on l'affiche

	printf("\n");
		
	int* myTab2 = NULL; //on cr�e le pointeur
	int tabSize = TAB2SIZE; //taille initialis�e
	
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); //allocation taille pointeur
	if (myTab2 != NULL) { initTab(myTab2, tabSize); } // initalisation tableau � 0
	else { printf("m�moire insuffisante"); return(-1); } //en cas d'erreur d'allocation, tab devient NULL
	
	int nbElts = 20;
	for (int i = 0; i < nbElts; i++) *(myTab2 + i) = i+1; //on remplit le tableau des valeurs de 1 � 20

	
	afficheTab(myTab2, tabSize, nbElts); //affichage des 20 premieres valeurs

	myTab2 = ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 30); //on ajoute 30 au tableau (si on met TAB2SIZE = 20 voir fonction)
	printf("\n");
	afficheTab(myTab2, tabSize, nbElts); //on affiche apr�s ajout



	free(myTab2); //on d�truit le tableau

	
	
}

