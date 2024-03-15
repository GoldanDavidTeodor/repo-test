#include "Math.h"
#include <cstring>
#include <cstdarg>
#include <iostream>
int Math::Add(int a, int b)
{
	return a+b;
}

int Math::Add(int a, int b, int c)
{
	return a+b+c;
}

int Math::Add(double a, double b)
{
	return int(a+b);
}

int Math::Add(double a, double b, double c)
{
	return int(a+b+c);
}

int Math::Mul(int a, int b)
{
	return a*b;
}

int Math::Mul(int a, int b, int c)
{
	return a*b*c;
}

int Math::Mul(double a, double b)
{
	return int(a*b);
}

int Math::Mul(double a, double b, double c)
{
	return int(a*b*c);
}

int Math::Add(int count, ...)
{
	int res=0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++) {
		int a= va_arg(vl, int);
		res += a;
	}
	va_end(vl);

	return res;
}

char* Math::Add(const char* nr1, const char* nr2)
{
	int carry = 0, a, b, t = 0, size3, size1 = 0, size2 = 0;
	for (int i = 0; nr1[i]; i++)
		size1++;
	for (int i = 0; nr2[i]; i++)
		size2++;

	if (size1 < size2)size3 = size2;
	else size3 = size1;
	char* nr3 = new char[size3 + 1];

	int i, j;
	if (size1 >= size2) {
		for (i = size1 - 1, j = size2 - 1; i >= 0; i--, j--) {
			a = b = 0;
			if (nr1[i] >= '0' && nr1[i] <= '9')a = nr1[i] - '0';
			if (nr2[j] >= '0' && nr2[j] <= '9')b = nr2[j] - '0';
			t = t + a + b;	
			nr3[i + 1] = char(t % 10 + '0');
			t = t / 10;
		}
	}
	else {
		for (i = size1 - 1, j = size2 - 1; j >= 0; i--, j--) {
			a = b = 0;
			if (nr1[i] >= '0' && nr1[i] <= '9')a = nr1[i] - '0';
			if (nr2[j] >= '0' && nr2[j] <= '9')b = nr2[j] - '0';
			t = t + a + b;
			nr3[j + 1] = char(t % 10 + '0');
			t = t / 10;
		}
	}
	if (t)nr3[0] = '1', carry = 1;

	if (carry == 0) {
		for (i = 0; i < size3; i++)
			nr3[i] = nr3[i + 1];
		nr3[size3] = '\0';
	}
	else nr3[size3 + 1] = '\0';

	return nr3;
}