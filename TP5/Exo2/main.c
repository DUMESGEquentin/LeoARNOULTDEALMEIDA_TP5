#include <stdio.h>
#include <stdlib.h>
#include "tab.h"


//expliquer fichier tab.h ect



int main() {
	TABLEAU tab = newArray();
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
	
	deleteElements(&tab, 12, 15);
	displayElements(&tab, 0, tab.size);


}