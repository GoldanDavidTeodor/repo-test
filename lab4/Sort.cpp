#include "Sort.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <stdarg.h>
#include <stdio.h>


Sort::Sort(int NumberOfElements, int MinVal, int MaxVal)
{
	time_t t;
	this->nrElem = NumberOfElements;
	vector = new int[NumberOfElements];
	srand((unsigned)time(&t));
	for (int i = 0; i < NumberOfElements; i++)
		this->vector[i] = MinVal + rand() % (MaxVal-MinVal+1);
}

Sort::Sort(int* v, int NumberOfElements)
{
	this->nrElem = NumberOfElements;
	vector = new int[NumberOfElements];
	for (int i = 0; i < NumberOfElements; i++)
		this->vector[i] = v[i];
}

Sort::Sort(int count, ...)
{
	vector = new int[count];
	va_list vl;
	va_start(vl, count);
	this->nrElem = count;
	for (int i = 0; i < count; i++)
		this->vector[i] = va_arg(vl, int);
	va_end(vl);
}

Sort::Sort(char* c)
{
	int lg = 0;
	int nr = 0; 
	int cnt = 0;
	for (int i = 0; c[i]; i++)
		lg++;
	vector = new int[lg];
	for (int i = 0; i <= lg; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
			nr = nr * 10 + c[i] - '0';
		else if (c[i] == ',')
		{
			vector[cnt] = nr;
			cnt++;
			nr = 0;
		}
	}
	if (nr) vector[cnt++] = nr;
	this->nrElem = cnt;
}

Sort::~Sort()
{
	delete this->vector;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < Sort::GetElementCount(); i++)
	{
		int p = i;
		while (p > 0 && Sort::GetElementFromIndex(p) < Sort::GetElementFromIndex(p - 1))
		{
			int aux = this->vector[p];
			this->vector[p] = this->vector[p - 1];
			this->vector[p - 1] = aux;
			p--;
		}
	}
}

void Sort::DoQuickSort(int minim, int maxim)
{
	if (minim < maxim)
	{
		int pivot = Sort::Partition(minim, maxim);
		Sort::DoQuickSort(minim, pivot - 1);
		Sort::DoQuickSort(pivot + 1, maxim);
	}
}
int Sort::Partition(int minim, int maxim)
{
	int i = minim + 1;
	int j = maxim;
	int k;
	int x = this->vector[minim];
	while (i <= j)
	{
		if (this->vector[i] <= x)
			i++;
		if (this->vector[j] >= x)
			j--;
		if (i<j && this->vector[i]>x && this->vector[j] < x)
		{
			int aux = this->vector[i];
			this->vector[i] = this->vector[j];
			this->vector[j] = aux;
			i++;
			j--;
		}
	}
	k = i - 1;
	this->vector[minim] = this->vector[k];
	this->vector[k] = x;
	return k;
}
void Sort::QuickSort(bool ascendent)
{
	Sort::DoQuickSort(0, this->nrElem - 1);
}

void Sort::BubbleSort(bool ascendent)
{
	bool sortat;
	do
	{
		sortat = true;
		for (int i = 0; i < Sort::GetElementCount()-1; i++)
			if (this->vector[i] > this->vector[i + 1])
			{
				int aux = this->vector[i];
				this->vector[i] = this->vector[i + 1];
				this->vector[i + 1] = aux;
				sortat = false;
			}
	} while (!sortat);
}

void Sort::Print()
{
	for (int i = 0; i < Sort::GetElementCount(); i++)
		std::cout << Sort::GetElementFromIndex(i) << ' ';
	std::cout << '\n';
}

int Sort::GetElementCount()
{
	return this->nrElem;
}

int Sort::GetElementFromIndex(int index)
{
	return this->vector[index];
}
