#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class square : public Figure
{
    public:
        square(int color_);
        ~square();

        void gen(table map_);
        void rot(table map_, Figure* enemy);

    protected:

    private:
};

#endif // SQUARE_H
