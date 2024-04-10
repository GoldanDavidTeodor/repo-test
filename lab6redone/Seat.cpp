#include "Seat.h"
#include "Weather.h"
#include <string>

Seat::Seat()
{
	fuelCapacity = 60;
	fuelConsumption = 5;
	averageSpeed[Weather::Rain] = 50;
	averageSpeed[Weather::Snow] = 30;
	averageSpeed[Weather::Sun] = 110;
	CarName = "Seat";
}

float Seat::calculateTime(int weather, int length, bool& Finish)
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

const char* Seat::GetName()
{
	return CarName;
}
