#pragma once
#include "tab.h"
#include<stdio.h>
#include<stdlib.h>

//int initTab(int* tab, int size);
int main() {

	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 5);
}

