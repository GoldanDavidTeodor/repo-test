#include "Fiat.h"
#include "Weather.h"
#include <string>

Fiat::Fiat()
{
	fuelCapacity = 47;
	fuelConsumption = 4;
	averageSpeed[Weather::Rain] = 50;
	averageSpeed[Weather::Snow] = 30;
	averageSpeed[Weather::Sun] = 180;
	CarName = "Fiat";
}

float Fiat::calculateTime(int weather, int length, bool& Finish)
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

const char* Fiat::GetName()
{
	return CarName;
}
