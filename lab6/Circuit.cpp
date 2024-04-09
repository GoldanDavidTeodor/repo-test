<<<<<<< HEAD
#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
#include <string>

using namespace std;

Circuit::Circuit()
{
	nr_cars = 0;
}

void Circuit::SetLength(int length)
{
	this->length = length;
}

void Circuit::SetWeather(int weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car_type)
{
	this->nr_cars++;
	cars[nr_cars] = car_type;
}

void Circuit::swap(int i, int j)
{

	Car* aux = cars[i];
	cars[i] = cars[j];
	cars[j] = aux;

	float auxi = EndTimeCircuit[i];
	EndTimeCircuit[i] = EndTimeCircuit[j];
	EndTimeCircuit[j] = auxi;

	bool a = finish[i];
	finish[i] = finish[j];
	finish[j] = a;
}

void Circuit::sort_race_time()
{
	for (int i = 1; i <= nr_cars - 1; i++)
	{
		for (int j = 1; j <= nr_cars - i; j++)
		{
			if (EndTimeCircuit[j] > EndTimeCircuit[j + 1])
			{
				swap(j, j + 1);
			}
		}
	}
}

void Circuit::Race()
{
	for (int i = 1; i <= nr_cars; i++)
	{
		bool Finish;
		EndTimeCircuit[i] = cars[i]->calculateTime(weather, length, Finish);
		finish[i] = Finish;
	}
	sort_race_time(); 
}

void Circuit::ShowFinalRanks()
{
	cout << "Final ranks are: " << endl;
	int rank = 1;
	for (int i = 1; i <= nr_cars; i++)
	{
		cout << cars[i]->GetName() << ": " << rank << " (Time: " << EndTimeCircuit[i] << ")" << endl;

		if ((i < nr_cars) && (EndTimeCircuit[i] == EndTimeCircuit[i + 1]))
		{
			continue;
		}
		rank++;
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	cout << "The cars that did not finish the race are: " << endl;
	for (int i = 1; i <= nr_cars; i++)
	{
		if (finish[i] == 0)
		{
			cout << cars[i]->GetName() << endl;
		}
	}
=======
#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
#include <string>

using namespace std;

Circuit::Circuit()
{
	nr_cars = 0;
}

void Circuit::SetLength(int length)
{
	this->length = length;
}

void Circuit::SetWeather(int weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car_type)
{
	this->nr_cars++;
	cars[nr_cars] = car_type;
}

void Circuit::swap(int i, int j)
{

	Car* aux = cars[i];
	cars[i] = cars[j];
	cars[j] = aux;

	float auxi = EndTimeCircuit[i];
	EndTimeCircuit[i] = EndTimeCircuit[j];
	EndTimeCircuit[j] = auxi;

	bool a = finish[i];
	finish[i] = finish[j];
	finish[j] = a;
}

void Circuit::sort_race_time()
{
	for (int i = 1; i <= nr_cars - 1; i++)
	{
		for (int j = 1; j <= nr_cars - i; j++)
		{
			if (EndTimeCircuit[j] > EndTimeCircuit[j + 1])
			{
				swap(j, j + 1);
			}
		}
	}
}

void Circuit::Race()
{
	for (int i = 1; i <= nr_cars; i++)
	{
		bool Finish;
		EndTimeCircuit[i] = cars[i]->calculateTime(weather, length, Finish);
		finish[i] = Finish;
	}
	sort_race_time(); 
}

void Circuit::ShowFinalRanks()
{
	cout << "Final ranks are: " << endl;
	int rank = 1;
	for (int i = 1; i <= nr_cars; i++)
	{
		cout << cars[i]->GetName() << ": " << rank << " (Time: " << EndTimeCircuit[i] << ")" << endl;

		if ((i < nr_cars) && (EndTimeCircuit[i] == EndTimeCircuit[i + 1]))
		{
			continue;
		}
		rank++;
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	cout << "The cars that did not finish the race are: " << endl;
	for (int i = 1; i <= nr_cars; i++)
	{
		if (finish[i] == 0)
		{
			cout << cars[i]->GetName() << endl;
		}
	}

}