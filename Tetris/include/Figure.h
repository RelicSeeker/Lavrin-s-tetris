#ifndef FIGURE_H
#define FIGURE_H

//colors: 0 - red, 1 - yellow, 2 - green, 3 - blue
#include <vector>
#include "point.h"
#include "table.h"

class Figure
{
    public:
        std::vector<point> spisok;

        Figure(int color_);
        virtual ~Figure();

        void set_cord(point p);
        void clear_all();
        int if_exist(point* p);
        int where_exist(point* p);
        int whatcolor(int i);
        int detect_colision(Figure* enemy);

        void up(table map_);
        int down(table map_, Figure* enemy);
        void right(table map_, Figure* enemy);
        void left(table map_, Figure* enemy);

        void clear_line(int y);
        int del_full_lines(table map_);


        virtual void gen(table map_);
        virtual void rot(table map_, Figure* enemy);
        virtual int getcolor();
        virtual void setcolor(int c);
        int color;

    protected:

       

    private:
};

#endif // FIGURE_H
