#pragma once
#include<stdio.h>
#include<stdlib.h>

int initTab(int* tab, int size)
{
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) *(tab + i) = 0;
		return size;
	}
}
int afficheTab(int* tab, int size, int nbElts) {
	if (size < 0 || tab == NULL || size<nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) printf("\n %d", *(tab + i));
		return 0;
	}



}
