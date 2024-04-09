#pragma once
#include "Car.h"


class BMW : public Car 
{
public:
	BMW();
	float calculateTime(int, int, bool&) override;
	const char* GetName() override;
};

