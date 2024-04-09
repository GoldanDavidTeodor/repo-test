#pragma once
#include "Car.h"


class Seat : public Car
{
public:
	Seat();
	float calculateTime(int, int, bool&) override;
	const char* GetName() override;
};

