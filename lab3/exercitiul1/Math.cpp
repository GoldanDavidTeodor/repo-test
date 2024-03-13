#include "Math.h"
#include <cstring>
#include <cstdarg>

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
	char t;
	int v;
	int c = 0;
	int size3;
	int size1 = strlen(nr1);
	int size2 = strlen(nr2);
	if (size1 > size2)
		size3 = size1+1;
	else size3 = size2+1;
	char* rez = new char[size3];
	size3--;
	for (int i = size3; i >= 0; i--) {
		v = c + (nr1[i - 1]+nr2[i-1] - '0');
		if (v > 9)c = v / 10;
		rez[i+1] = char(v % 10);
	}
	
	return rez;
}
