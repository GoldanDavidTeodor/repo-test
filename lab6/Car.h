#pragma once

class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[3]; 
	const char* CarName;
public:
	virtual float calculateTime(int, int, bool&) = 0;
	virtual const char* GetName() = 0;
};