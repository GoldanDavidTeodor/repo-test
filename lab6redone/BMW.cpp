#include "BMW.h"
#include "Weather.h"
#include <string>

BMW::BMW()
{
	fuelCapacity = 56;
	fuelConsumption = 7;
	averageSpeed[Weather::Rain] = 60;
	averageSpeed[Weather::Snow] = 30;
	averageSpeed[Weather::Sun] = 200;
	CarName = "BMW";
}

float BMW::calculateTime(int weather, int length, bool& Finish)
{
	int speed = averageSpeed[weather];
	float a = fuelCapacity / fuelConsumption;
	float d = a * speed;

	if (d >= length) {
		Finish = 1;
	}
	else Finish = 0;

	float ftime = length * a / d;
	return ftime;
}

const char* BMW::GetName()
{
	return CarName;
}
