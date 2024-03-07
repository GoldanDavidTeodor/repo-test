#include "globals.h"
#include <string>

int compareMath(Student student1, Student student2)
{
	if (student1.getMath() < student2.getMath()) return -1;
	else if (student1.getMath() > student2.getMath()) return 1;
	else return 0;
}

int compareEnglish(Student student1, Student student2)
{
	if (student1.getEnglish() < student2.getEnglish()) return -1;
	else if (student1.getEnglish() > student2.getEnglish()) return 1;
	else return 0;
}

int compareHistory(Student student1, Student student2)
{
	if (student1.getHistory() < student2.getHistory()) return -1;
	else if (student1.getHistory() > student2.getHistory()) return 1;
	else return 0;
}

int compareAverage(Student student1, Student student2)
{
	if (student1.getAverage() < student2.getAverage()) return -1;
	else if (student1.getAverage() > student2.getAverage()) return 1;
	else return 0;
}

int compareNames(Student student1, Student student2)
{
	//if (student1.getName() < student2.getName()) return -1;
	//else if (student1.getName() > student2.getName()) return 1;
	//else return 0;
	return student1.getName().compare(student2.getName());
}


