#ifndef POINT_H
#define POINT_H


class point
{
    public:

        int x, y;
        int color;

        point(int x_, int y_);
        virtual ~point();
        virtual void Setcolor(int c);
        virtual int Getcolor();
    protected:

    private:
};

#endif // POINT_H
