<<<<<<< HEAD
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
=======
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
>>>>>>> 213d2f5e7ac5de0bbbbcc8a7391d0736a1733357
};