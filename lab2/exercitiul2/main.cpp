#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Student.h"
#include "globals.h"

using namespace std;

int main() {
	Student s1;
	s1.init("David", 9, 8, 10);
	s1.setHistory(5.3);
	s1.getInfo();
	cout << s1.getAverage() << '\n';
	Student s2;
	s2.init("David", 7, 8.8, 10);
	s2.getInfo();
	cout << s2.getAverage() << '\n';
	Student s3;
	s3.init("Pavel", 9.2, 9, 10);
	s3.getInfo();
	cout << s3.getAverage() << '\n';

	cout << compareMath(s1, s3) << '\n';
	cout << compareEnglish(s1, s3) << '\n';
	cout << compareHistory(s3, s1) << '\n';
	cout << compareAverage(s1, s3) << '\n';
	cout << compareNames(s1, s2) << '\n';

	return 0;
}