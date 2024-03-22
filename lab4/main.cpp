#include <iostream>
#include "Sort.h"
#include <stdio.h>

int main()
{
	char c[] = { "18,100,14,19,7,4,88" };

	Sort s1(10, 2, 17);
	Sort s2(c);
	s1.Print();
	s1.BubbleSort();
	s1.Print();
	std::cout << "-------------------------\n";
	s2.Print();
	//s2.InsertSort();
	s2.QuickSort();
	s2.Print();
	system("pause");
	return 0;
}