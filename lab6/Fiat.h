#pragma once
#include "Car.h"


class Fiat : public Car
{
public:
	Fiat();
	float calculateTime(int, int, bool&) override;
	const char* GetName() override;
};

