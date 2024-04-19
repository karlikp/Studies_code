module;

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

module BasicPlane.Figures:Circle;

double radius(const Circle& c)
{
	return sqrt(pow((c.centre.x - c.border.x),2) + pow((c.centre.y - c.border.y), 2));
}

double area(const Circle& c)
{
	return M_PI * radius(c);
}

