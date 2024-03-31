#pragma once
#include <stdio.h>
class Number
{
	//
	char* valoare;
	int baza;
	//

public:
	Number(const char* value, int base);
	~Number();
	void Print();

	Number(); //default constructor
	Number(int n); 
	Number(const Number& n); //copy constructor
	Number(const Number&& n); //move constructor

	//operators

	Number operator+(Number ex);//adition
	Number operator+(int numar); //adition
	Number operator-(Number ex); //substract
	friend int operator-(Number ex, int numar); //substract

	void operator--(); //forma prefixata
	void operator--(int ex); //forma postfixata

	Number& operator=(Number&& ex); //move asignment operator

	friend Number toBiggestBase(const Number& num1, const Number& num2);
	friend Number operator+(const Number& num1, const Number& num2);
	friend Number operator-(const Number& num1, const Number& num2);


	bool operator<(const Number& other);
	bool operator>(const Number& other);
	bool operator<=(const Number& other);
	bool operator>=(const Number& other);
	bool operator==(const Number& other);
	bool operator<(int numar);
	bool operator>(int numar);
	bool operator<=(int numar);
	bool operator>=(int numar);
	bool operator==(int numar);

	void SwitchBase(int newBase);
	int GetDigitsCount();
	int GetBase();
};
