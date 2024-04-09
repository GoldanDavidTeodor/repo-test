#include "Number.h"
#include <cstring>
#include <iostream>

Number::Number(const char* value, int base)
{
	int i;
	i = strlen(value);
	valoare = new char[i+1];
	for (int j = 0; j < i; j++)
		this->valoare[j] = value[j];
	valoare[i] = '\0';
	baza = base;
}

Number::~Number()
{
	delete[] valoare;
	valoare = nullptr;
}

void Number::Print()
{
	std::cout << this->valoare << " in baza: " << this->baza << '\n';
}

Number::Number() {
	valoare = nullptr;
	baza = 0;
}

Number::Number(int n) {
	this->baza = 10;
	int nn = n, lg = 0, j;
	char c;
	do {
		lg++;
		nn = nn / 10;
	} while (nn > 0);

	valoare = new char[lg + 1];
	j = lg - 1;
	nn = n;

	if (n == 0) {
		valoare[0] = '0';
		valoare[1] = '\0';
	}
	else {
		while (nn) {
			c = nn % 10 + '0';
			valoare[j] = c;
			j--;
			nn = nn / 10;
		}
		valoare[lg] = '\0';
	}
}

int toBase10(const char* value, int base) {
	int result = 0;
	int power = 1;
	int len = strlen(value);
	for (int i = len - 1; i >= 0; --i) {
		int digitValue = (isdigit(value[i])) ? value[i] - '0' : value[i] - 'A' + 10;
		result += digitValue * power;
		power *= base;
	}
	return result;
}

Number toBiggestBase(const Number& num1, const Number& num2) {
	int biggestBase = (num1.baza > num2.baza) ? num1.baza : num2.baza;
	int val1 = toBase10(num1.valoare, num1.baza);
	int val2 = toBase10(num2.valoare, num2.baza);
	char buffer[100]; 
	return Number(buffer, biggestBase);
}

Number operator+(const Number& num1, const Number& num2)
{
	return toBiggestBase(num1, num2);
}

// Subtraction operator (-)
Number operator-(const Number& num1, const Number& num2)
{
	return toBiggestBase(num1, num2);
}

Number::Number(const Number& n) { //copy constructor
	this->baza = n.baza;
	this->valoare = nullptr;
	this->valoare = n.valoare;
}

Number::Number(const Number&& n) { //move constructor
	int i;
	i = strlen(n.valoare);
	valoare = new char[i + 1];
	for (int j = 0; j < i; j++)
		this->valoare[j] = n.valoare[j];
	valoare[i] = '\0';
	this->baza = n.baza;

}

void Number::operator--() {
	this->valoare[Number::GetDigitsCount() - 1] = '\0';
}

void Number::operator--(int numar) {
	for (int i = 0; i < Number::GetDigitsCount() - 1;i++)
		this->valoare[i] = this->valoare[i + 1];
	this->valoare[Number::GetDigitsCount() - 1] = '\0';
}

Number& Number::operator=(Number&& ex) {
	this->valoare = ex.valoare;
	this->baza = ex.baza;
	return *this;
}
bool Number::operator<(const Number& other)
{
	int val1 = toBase10(valoare, baza);
	int val2 = toBase10(other.valoare, other.baza);
	return val1 < val2;
}
bool Number::operator>(const Number& other) 
{
	int val1 = toBase10(valoare, baza);
	int val2 = toBase10(other.valoare, other.baza);
	return val1 > val2;
}
bool Number::operator<=(const Number& other)
{
	int val1 = toBase10(valoare, baza);
	int val2 = toBase10(other.valoare, other.baza);
	return val1 <= val2;
}
bool Number::operator>=(const Number& other)
{
	int val1 = toBase10(valoare, baza);
	int val2 = toBase10(other.valoare, other.baza);
	return val1 >= val2;
}
bool Number::operator==(const Number& other)
{
	int val1 = toBase10(valoare, baza);
	int val2 = toBase10(other.valoare, other.baza);
	return val1 == val2;
}
bool Number::operator<(int numar) {
	int val1 = toBase10(valoare, baza);
	return val1 < numar;
}
bool Number::operator>(int numar) {
	int val1 = toBase10(valoare, baza);
	return val1 > numar;
}
bool Number::operator<=(int numar) {
	int val1 = toBase10(valoare, baza);
	return val1 <= numar;
}
bool Number::operator>=(int numar) {
	int val1 = toBase10(valoare, baza);
	return val1 >= numar;
}
bool Number::operator==(int numar) {
	int val1 = toBase10(valoare, baza);
	return val1 == numar;
}

void Number::SwitchBase(int newBase)
{
	if (newBase == baza)
		return;

	int decimalValue = 0;
	for (int i = 0; i < strlen(valoare); ++i)
	{
		decimalValue = decimalValue * baza;
		if ('0' <= valoare[i] && valoare[i] <= '9')
			decimalValue += valoare[i] - '0';
		else if ('A' <= valoare[i] && valoare[i] <= 'Z')
			decimalValue += valoare[i] - 'A' + 10;
	}

	delete[] valoare;

	int length = 0;
	int tempValue = decimalValue;
	while (tempValue > 0)
	{
		tempValue /= newBase;
		length++;
	}

	valoare = new char[length + 1];

	int index = length - 1;
	while (decimalValue > 0)
	{
		int remainder = decimalValue % newBase;
		if (remainder < 10)
		{
			valoare[index] = remainder + '0';
		}
		else
		{
			valoare[index] = remainder - 10 + 'A';
		}
		index--;
		decimalValue /= newBase;
	}
	valoare[length] = '\0';
	baza = newBase;
}

int Number::GetDigitsCount()
{
	int i;
	i = strlen(this->valoare);
	return i;
}

int Number::GetBase()
{
	return this->baza;
}


