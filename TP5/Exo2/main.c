#include <stdio.h>
#include <stdlib.h>
#include "tab.h"


//J'ai mis les fonctions comme pour l'exo 1 dans un tab.h et tab.c (il n'y avait pas de précision mais ça me semble plus clair comme ça)



int main() {
	TABLEAU tab = newArray(); // on crée un tableau, tab, de type TABLEAU
	//incrementArraySize(&tab, 30);
	setElement(&tab, 10, 1);
	setElement(&tab, 11, 2);
	setElement(&tab, 12, 3);
	setElement(&tab, 13, 4);
	setElement(&tab, 14, 5);
	setElement(&tab, 15, 6);
	setElement(&tab, 16, 7);
	setElement(&tab, 17, 8);
	setElement(&tab, 18, 9);
	setElement(&tab, 19, 10);
	// je mets des valeurs dans le tableau pour tester la suppression et l'affichage
	deleteElements(&tab, 12, 15);
	displayElements(&tab, 0, tab.size);


}