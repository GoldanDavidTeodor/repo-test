#pragma once
#include <iostream>
#include <string>

class Student
{
	std::string studentName;
	float mathGrade;
	float englishGrade;
	float historyGrade;
public:
	void init(std::string name, float math, float english, float history);
	void getInfo();
	void setName(std::string name);
	void setMath(float math);
	void setEnglish(float english);
	void setHistory(float history);
	std::string getName();
	float getMath();
	float getEnglish();
	float getHistory();
	float getAverage();

};

