#include "NumberList.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	NumberList l1;
	l1.Init();
	l1.Add(2);
	l1.Add(3);
	l1.Add(1);
	l1.Add(9);
	l1.Add(7);
	l1.Add(6);
	l1.Print();
	l1.Sort();
	l1.Print();

	return 0;
}