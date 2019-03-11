#ifndef TABLE_H
#define TABLE_H


class table
{
    public:
        table(int x_, int y_);
        virtual ~table();

        int get_x_size();
        int get_y_size();


    protected:

    private:

        int x_size, y_size;
};

#endif // TABLE_H
