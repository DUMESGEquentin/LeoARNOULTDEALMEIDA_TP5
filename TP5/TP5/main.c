#pragma once
#include "tab.h"
#include<stdio.h>
#include<stdlib.h>

#define TAB2SIZE 20

int main() {
	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 5);


	printf("\n");
	
		
	int* myTab2 = NULL; //Crée le pointeur
	int tabSize = TAB2SIZE; //taille initialisée
	
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); //allocation pointeur
	if (myTab2 != NULL) { initTab(myTab2, tabSize); } // initalisation tableau à 0
	else { printf("mémoire insuffisante"); return(-1); }
	
	int nbElts = 20;
	for (int i = 0; i < nbElts; i++) *(myTab2 + i) = i+1; //valeur de 1 à 20

	
	afficheTab(myTab2, tabSize, nbElts); //affichage des 20 premieres valeurs
	printf("\n");

	ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 30);
	printf("\n");
	afficheTab(myTab2, tabSize, nbElts);
	printf("\n %d \n %d", tabSize, nbElts);



	free(myTab2);

	
	
}

