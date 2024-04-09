<<<<<<< HEAD
#include "Volvo.h"
#include "Weather.h"
#include <string>

Volvo::Volvo()
{
	fuelCapacity = 50;
	fuelConsumption = 4;
	averageSpeed[Weather::Rain] = 58;
	averageSpeed[Weather::Snow] = 24;
	averageSpeed[Weather::Sun] = 100;
	CarName = "Volvo";
}

float Volvo::calculateTime(int weather, int length, bool& Finish)
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

const char* Volvo::GetName()
{
	return CarName;
}
=======
#include "Volvo.h"
#include "Weather.h"
#include <string>

Volvo::Volvo()
{
	fuelCapacity = 50;
	fuelConsumption = 4;
	averageSpeed[Weather::Rain] = 58;
	averageSpeed[Weather::Snow] = 24;
	averageSpeed[Weather::Sun] = 100;
	CarName = "Volvo";
}

float Volvo::calculateTime(int weather, int length, bool& Finish)
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

const char* Volvo::GetName()
{
	return CarName;
}
>>>>>>> 213d2f5e7ac5de0bbbbcc8a7391d0736a1733357
