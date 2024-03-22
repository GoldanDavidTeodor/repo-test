#pragma once
class Sort
{
	int* vector;
	int nrElem;
public:
	Sort(int NumberOfElements, int MinVal, int MaxVal);
	Sort(int* v, int NumberOfElements);
	Sort(int count, ...);
	Sort(char* c);
	~Sort();
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	int Partition(int minim, int maxim);
	void DoQuickSort(int minim, int maxim);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementCount();
	int GetElementFromIndex(int index);
};

