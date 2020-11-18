#pragma once
#include "tab.h"
#include<stdio.h>
#include<stdlib.h>

#define TAB2SIZE 100

int main() {
	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 5);


	printf("\n");
	
		
	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 10;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }

	for (int i = 0; i < 20; i++) *(myTab2 + i) = i+1;

	afficheTab(myTab2, tabSize, nbElts);
	free(myTab2);


}

