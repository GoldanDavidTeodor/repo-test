<<<<<<< HEAD
#include <iostream>
#include <string>
#include "Circuit.h"
#include "Weather.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Sun);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); 
	c.ShowWhoDidNotFinish(); 
	return 0;
=======
#include <iostream>
#include <string>
#include "Circuit.h"
#include "Weather.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Sun);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); 
	c.ShowWhoDidNotFinish(); 
	return 0;
>>>>>>> 213d2f5e7ac5de0bbbbcc8a7391d0736a1733357
}