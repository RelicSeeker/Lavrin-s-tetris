#include "teshka.h"

teshka::teshka(int color_) : Figure(color_)
{
    position = 0;
}

teshka::~teshka()
{
    //dtor
}

void teshka::gen(table map_)
{

    point p1(1,1);
    point p2(2,1);
    point p3(3,1);
    point p4(2,2);
    p1.Setcolor(3);
    p2.Setcolor(3);
    p3.Setcolor(3);
    p4.Setcolor(3);

    set_cord(p2);
    set_cord(p1);
    set_cord(p3);
    set_cord(p4);

}

void teshka::rot(table map_, Figure* enemy)
{
    if (position == 0)
    {
        if (1)
        {
            for(int i = 0; i < 3; i++)
                spisok.pop_back();

            point p1(spisok[0].x-1,spisok[0].y);
            point p2(spisok[0].x,spisok[0].y+1);
            point p3(spisok[0].x,spisok[0].y-1);

            set_cord(p1);
            set_cord(p2);
            set_cord(p3);

            int flag = this->detect_colision(enemy);

            if (flag)
            {
                for(int i = 0; i < 3; i++)
                    spisok.pop_back();

                point p1(spisok[0].x-1,spisok[0].y);
                point p2(spisok[0].x+1,spisok[0].y);
                point p3(spisok[0].x,spisok[0].y+1);

                set_cord(p1);
                set_cord(p2);
                set_cord(p3);

                return;
            }
            position = 1;
            return;
        }
    }

    if (position == 1)
        {
            if (spisok[0].x < map_.get_x_size() - 2)
            {
                for(int i = 0; i < 3; i++)
                    spisok.pop_back();

                point p1(spisok[0].x-1,spisok[0].y);
                point p2(spisok[0].x,spisok[0].y-1);
                point p3(spisok[0].x+1,spisok[0].y);

                set_cord(p1);
                set_cord(p2);
                set_cord(p3);

                int flag = this->detect_colision(enemy);

                if (flag)
                {
                    for(int i = 0; i < 3; i++)
                        spisok.pop_back();

                    point p1(spisok[0].x,spisok[0].y-1);
                    point p2(spisok[0].x,spisok[0].y+1);
                    point p3(spisok[0].x-1,spisok[0].y);

                    set_cord(p1);
                    set_cord(p2);
                    set_cord(p3);
                    return;
                }
                position = 2;
                return;
            }
        }

        if (position == 2)
    {
        if (spisok[0].y < map_.get_y_size()-1)
        {
            for(int i = 0; i < 3; i++)
                spisok.pop_back();

            point p1(spisok[0].x,spisok[0].y-1);
            point p2(spisok[0].x,spisok[0].y+1);
            point p3(spisok[0].x+1,spisok[0].y);

            set_cord(p1);
            set_cord(p2);
            set_cord(p3);

            int flag = this->detect_colision(enemy);

            if (flag)
            {
                for(int i = 0; i < 3; i++)
                    spisok.pop_back();

                point p1(spisok[0].x-1,spisok[0].y);
                point p2(spisok[0].x,spisok[0].y-1);
                point p3(spisok[0].x+1,spisok[0].y);

                set_cord(p1);
                set_cord(p2);
                set_cord(p3);
                return;
            }
            position = 3;
            return;
        }
    }
    if (position == 3)
    {
        if (spisok[0].x >= 1)
        {
            for(int i = 0; i < 3; i++)
                spisok.pop_back();

            point p1(spisok[0].x,spisok[0].y+1);
            point p2(spisok[0].x-1,spisok[0].y);
            point p3(spisok[0].x+1,spisok[0].y);

            set_cord(p1);
            set_cord(p2);
            set_cord(p3);

            int flag = this->detect_colision(enemy);

            if (flag)
            {
                for(int i = 0; i < 3; i++)
                    spisok.pop_back();

                point p1(spisok[0].x,spisok[0].y-1);
                point p2(spisok[0].x,spisok[0].y+1);
                point p3(spisok[0].x+1,spisok[0].y);

                set_cord(p1);
                set_cord(p2);
                set_cord(p3);
                return;
            }
            position = 0;
            return;
        }

    }
}
