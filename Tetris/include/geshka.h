#ifndef GESHKA_H
#define GESHKA_H

#include "Figure.h"

class geshka : public Figure
{
    public:
        geshka(int color_);
        ~geshka();

        void gen(table map_);
        void rot(table map_, Figure* enemy);

    protected:

    private:

        int position; // 0 - geshka, 1 - ����� ����, 2 - ����� �����, 3 - ����� �����
};

#endif // GESHKA_H
