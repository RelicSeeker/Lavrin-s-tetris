#include "square.h"

square::square(int color_) : Figure(color_)
{
    //ctor
}

square::~square()
{
    //dtor
}

void square::gen(table map_)
{
    point p1(1,1);
    point p2(1,2);
    point p3(2,1);
    point p4(2,2);

    set_cord(p1);
    set_cord(p2);
    set_cord(p3);
    set_cord(p4);

}

void square::rot(table map_, Figure* enemy)
{
}
