<<<<<<< HEAD
#pragma once
#include "Car.h"


class Volvo : public Car
{
public:
	Volvo();
	float calculateTime(int, int, bool&) override;
	const char* GetName() override;
};

=======
#pragma once
#include "Car.h"


class Volvo : public Car
{
public:
	Volvo();
	float calculateTime(int, int, bool&) override;
	const char* GetName() override;
};

>>>>>>> 213d2f5e7ac5de0bbbbcc8a7391d0736a1733357
