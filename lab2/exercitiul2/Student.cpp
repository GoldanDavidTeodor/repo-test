#include "Student.h"
#include <iostream>
#include <string>
void Student::init(std::string name, float math, float english, float history)
{
	this->studentName = name;
	if (math > 0 && math <= 10)this->mathGrade = math;
	else this->mathGrade = 1;
	if (english > 0 && english <= 10)this->englishGrade = english;
	else this->englishGrade = 1;
	if (history > 0 && history <= 10)this->historyGrade = history;
	else this->historyGrade = 1;
}

void Student::getInfo()
{
	std::cout << studentName << ' ' << mathGrade << ' ' << englishGrade << ' ' << historyGrade << '\n';
}

void Student::setName(std::string name)
{
	this->studentName = name;
}

void Student::setMath(float math)
{
	if (math > 0 && math <= 10)this->mathGrade = math;
}

void Student::setEnglish(float english)
{
	if (english > 0 && english <= 10)this->englishGrade = english;
}

void Student::setHistory(float history)
{
	if (history > 0 && history <= 10)this->historyGrade = history;
}

std::string Student::getName()
{
	return this->studentName;
}

float Student::getMath()
{
	return this->mathGrade;
}

float Student::getEnglish()
{
	return this->englishGrade;
}

float Student::getHistory()
{
	return this->historyGrade;
}

float Student::getAverage()
{
	return float((this->mathGrade + this->englishGrade + this->historyGrade) / 3);
}
