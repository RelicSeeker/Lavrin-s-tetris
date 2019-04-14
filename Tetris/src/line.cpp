#include "line.h"

line::line(int color_) : Figure(color_)
{
    position = 0;
}

line::~line()
{
    //dtor
}

void line::gen(table map_)
{
    point p1(1,1);
    point p2(1,0);
    point p3(1,-1);
    point p4(1,-2);
    p1.Setcolor(2);
    p2.Setcolor(2);
    p3.Setcolor(2);
    p4.Setcolor(2);


    set_cord(p1);
    set_cord(p2);
    set_cord(p3);
    set_cord(p4);

}

void line::rot(table map_, Figure* enemy)
{
    if (position == 0)
    {
        if (spisok[0].x < map_.get_x_size() - 3)
        {
            for(int i = 0; i < 3; i++)
                spisok.pop_back();
            for(int i = 1; i < 4; i++)
            {
                point curr(spisok[0].x+i,spisok[0].y);
                spisok.push_back(curr);
            }

            int flag = this->detect_colision(enemy);

            if (flag)
            {
                for(int i = 0; i < 3; i++)
                    spisok.pop_back();
                for(int i = 1; i < 4; i++)
                {
                    point curr(spisok[0].x,spisok[0].y-i);
                    spisok.push_back(curr);
                }
                return;
            }
            position = 1;
            return;
        }
    }

    if (position == 1)
    {
        if (1)
        {
            for(int i = 0; i < 3; i++)
                spisok.pop_back();
            for(int i = 1; i < 4; i++)
            {
                point curr(spisok[0].x,spisok[0].y-i);
                spisok.push_back(curr);
            }

            int flag = this->detect_colision(enemy);

            if (flag)
            {
                for(int i = 0; i < 3; i++)
                    spisok.pop_back();
                for(int i = 1; i < 4; i++)
                {
                    point curr(spisok[0].x+i,spisok[0].y);
                    spisok.push_back(curr);
                }
                return;
            }
            position = 0;
            return;
        }
    }
}
