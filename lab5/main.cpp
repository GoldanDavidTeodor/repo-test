#include "Number.h"
#include <iostream>

Number Get(Number ex) { return ex; }

int main() {
	Number n1("123", 10);
	Number n2("543", 10);
	Number n4("AAAA", 15);
	Number n3(1453);
	n1.Print();
	n2.Print();
	n3.Print();
	n2.SwitchBase(14);
	n2.Print();
	n2.SwitchBase(10);
	n2.Print();
	--n3;
	n3.Print();
	n3--;
	n3.Print();

	if (n1 > n4)
		std::cout << "primul este mai mare\n";
	else
		std::cout << "primul este mai mic\n";

	if (n1 == 123)
		std::cout << "egale\n";
	else
		std::cout << "nu sunt egale\n";

	/*
	printf("1.-------------------------------\n");
	Number ex1;
	Number ex2;

	printf("2.-------------------------------\n");
	ex1 = Number(5); //move asignment operator
	ex2 = Number(8);

	printf("3.-------------------------------\n");
	Number ex3 = ex1; //apel pentru copy constructor
	Number ex4 = Get(Number()); //default constructor pentru exemple(), move constructor pentru ex4

	printf("4.-------------------------------\n");
	ex4 = ex1 + ex2;
	printf("ex1 - 10: %d\n", ex1 - 10);

	printf("5.-------------------------------\n");
	ex4 = ex1 - ex2 + ex3;

	printf("6.-------------------------------\n");
	++ex1;
	ex1++;
	--ex2;
	ex2--;

	printf("7.-------------------------------\n");
	if (ex1 > ex2) printf("Ex1\n");
	if (ex1 < ex2) printf("Ex2\n");

	printf("8.-------------------------------\n");
	ex1 < 5;
	ex1 == 6;
	ex2 == 7;
	ex2 < 8;

	printf("9.-------------------------------\n");
	int a = ex1[1] + ex2[1];
	printf("a value = %d\n", a);

	printf("10.------------------------------\n");
	bool x = !ex2;
	printf("x value = %d\n", x);
	*/
	return 0;
}