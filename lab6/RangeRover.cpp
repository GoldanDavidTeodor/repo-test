#include "RangeRover.h"
#include "Weather.h"
#include <string>

RangeRover::RangeRover()
{
	fuelCapacity = 104;
	fuelConsumption = 12;
	averageSpeed[Weather::Rain] = 80;
	averageSpeed[Weather::Snow] = 40;
	averageSpeed[Weather::Sun] = 140;
	CarName = "RangeRover";
}

float RangeRover::calculateTime(int weather, int length, bool& Finish)
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

const char* RangeRover::GetName()
{
	return CarName;
}
