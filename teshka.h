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

        int position; // 0 - �, 1 - ����� �����, 2 - ����� �����, 3 - ����� ������
};

#endif // TESHKA_H
