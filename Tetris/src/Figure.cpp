#include "Figure.h"

Figure::Figure(int color_ = 0)
{
    color = color_;
}

Figure::~Figure()
{
    //dtor
}

void Figure::set_cord(point p)
{
    spisok.push_back(p);
    return;
}

void Figure::gen(table map_)
{
}

void Figure::rot(table map_, Figure* enemy)
{
}

int Figure::detect_colision(Figure* enemy)
{
    int flag = 0; // 0 - no colision, 1 - yes colision

    for(unsigned int i=0; i < enemy->spisok.size(); i++)
    {
        for(unsigned int j=0; j < this->spisok.size(); j++)
        {
            if ((enemy->spisok[i].x == this->spisok[j].x)&&(enemy->spisok[i].y == this->spisok[j].y))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    return flag;
}

int Figure::if_exist(point p)
{
    int flag = 0;

    for(unsigned int i=0; i<spisok.size(); i++)
    {
        if ( (p.x == spisok[i].x) && (p.y == spisok[i].y) )
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

void Figure::right(table map_, Figure* enemy)
{
    int flag = 0; // 0 - Ok, >0 - exit from the board

    for(unsigned int i=0; i<spisok.size(); i++)
    {
        spisok[i].x++;
        if (spisok[i].x >= map_.get_x_size())
            flag++;
    }

    if (flag)
    {
        for(unsigned int i=0; i<spisok.size(); i++)
            spisok[i].x--;
    }

    if (detect_colision(enemy))
    {
        for(unsigned int i=0; i<spisok.size(); i++)
            spisok[i].x--;
    }
    return;
}

void Figure::up(table map_)
{
    for(unsigned int i=0; i<spisok.size(); i++)
    {
        spisok[i].y--;
    }
}

void Figure::left(table map_, Figure* enemy)
{
    int flag = 0; // 0 - Ok, >0 - exit from the board

    for(unsigned int i=0; i<spisok.size(); i++)
    {
        spisok[i].x--;
        if (spisok[i].x < 0)
            flag++;
    }

    if (flag)
    {
        for(unsigned int i=0; i<spisok.size(); i++)
            spisok[i].x++;
    }

    if (detect_colision(enemy))
    {
        for(unsigned int i=0; i<spisok.size(); i++)
            spisok[i].x++;
    }

    return;
}

void Figure::clear_all()
{
    int L = spisok.size();

    for (int i=0; i<L;i++)
        spisok.pop_back();
}

int Figure::down(table map_, Figure* enemy)
{
    int flag = 1;

    for(unsigned int i=0; i<spisok.size(); i++)
    {
        if (spisok[i].y == map_.get_y_size() - 1)
        {
            flag = 0;
            break;
        }
    }


    if (flag)
    {
        for(unsigned int i=0; i<spisok.size(); i++)
        {
            spisok[i].y++;
        }
    }

    if(detect_colision(enemy))
    {
        Figure::up(map_);
        flag = 0;
    }

    return flag;
}

void Figure::clear_line(int y)
{
    std::vector<point> cash;

    for(unsigned int i=0; i<spisok.size(); i++)
    {
        if(spisok[i].y < y)
        {
            point slide(spisok[i].x, spisok[i].y + 1);
            cash.push_back(slide);
        }
        if(spisok[i].y > y)
        {
            point slide(spisok[i].x, spisok[i].y );
            cash.push_back(slide);
        }
    }

    this->clear_all();

    for(unsigned int i=0; i<cash.size(); i++)
    {
        spisok.push_back(cash[i]);
    }

}

int Figure::del_full_lines(table map_)
{
    int i = map_.get_y_size() - 1;

    int result = 0;

    while (i)
    {
        int counter = 0;

        for(unsigned int j=0; j<spisok.size(); j++)
        {
            if(spisok[j].y == i)
                counter++;
        }

        if(counter == map_.get_x_size())
        {
            this->clear_line(i);
            i++;
            result+= map_.get_x_size();
        }

        i--;
    }
    return result;
}
