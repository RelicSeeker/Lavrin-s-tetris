#include "table.h"

table::table(int x_ = 10, int y_ = 16)
{
    x_size = x_;
    y_size = y_;
}

table::~table()
{
    //dtor
}

int table::get_x_size()
{
    return x_size;
}

int table::get_y_size()
{
    return y_size;
}


