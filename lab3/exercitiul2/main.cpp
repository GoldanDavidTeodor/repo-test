#include "Canvas.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	Canvas c1(50, 50);
	c1.DrawCircle(15, 15, 2, 'o');
	c1.FillCircle(30, 30, 6, 'o');
	c1.DrawRect(40, 40, 47, 47, 'o');
	c1.FillRect(5, 20, 20, 30, 'o');
	c1.SetPoint(2, 2, 'o');
	c1.DrawLine(4, 4, 40, 9, 'o');
	//c1.Clear();
	c1.Printt();
	return 0;
}