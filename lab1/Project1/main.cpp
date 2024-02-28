//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	printf("-----------------[EXEMPLU PROBLEMA 1]------------------------\n");
	FILE* fp;
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		printf("Am deschis fisierul cu success!\n");
		char myString[200];
		/*
		if (fgets(myString, 200, fp))
		{
			printf("Am citit din fisier: %s\n", myString);
		}
		*/
		while (fgets(myString, 200, fp))
		{
			myString[strlen(myString) - 1] = '\0';
			printf("Am citit din fisier: %s\n", myString);
		}
	}
	printf("-----------------------------------------------------");
	printf("\n\n");

	
	system("pause");
	return 0;
}