<<<<<<< HEAD
#pragma once

#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Fiat.h"

class Circuit
{
private:
	int length;
	int weather;

	Car* cars[7];

	float EndTimeCircuit[7];
	bool finish[7];

	int nr_cars = 0;
	void swap(int, int);

public:
	Circuit();
	void SetLength(int);
	void SetWeather(int); 
	void AddCar(Car*);
	void Race();
	void sort_race_time();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
=======
#pragma once

#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Fiat.h"

class Circuit
{
private:
	int length;
	int weather;

	Car* cars[7];

	float EndTimeCircuit[7];
	bool finish[7];

	int nr_cars = 0;
	void swap(int, int);

public:
	Circuit();
	void SetLength(int);
	void SetWeather(int); 
	void AddCar(Car*);
	void Race();
	void sort_race_time();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
>>>>>>> 213d2f5e7ac5de0bbbbcc8a7391d0736a1733357
};