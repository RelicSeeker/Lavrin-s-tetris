#include "point.h"

point::point(int x_, int y_)
{
    x = x_, y = y_;
}

point::~point()
{
    //dtor
}
void point::Setcolor(int c)
{
	color = c;
}

int point::Getcolor()
{
	return color;
}
