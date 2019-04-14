#ifndef TESHKA_H
#define TESHKA_H

#include "Figure.h"

class teshka : public Figure
{
    public:
        teshka(int color_);
        ~teshka();

        void gen(table map_);
        void rot(table map_, Figure* enemy);

    protected:

    private:

        int position; // 0 - т, 1 - штука влево, 2 - штука вверх, 3 - штука вправо
};

#endif // TESHKA_H
