#ifndef LINE_H
#define LINE_H

#include "Figure.h"

class line : public Figure
{
    public:
        line(int color_);
        ~line();

        void gen(table map_);
        void rot(table map_, Figure* enemy);

    protected:

    private:

        int position; // 0 - vertical, 1 - horizontal
};

#endif // LINE_H
