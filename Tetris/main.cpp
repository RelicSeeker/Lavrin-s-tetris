#include <iostream>
#include "table.h"

#include "square.h"
#include "line.h"
#include "teshka.h"
#include "geshka.h"

#include "point.h"
#include "conio.h"
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <random>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
default_random_engine generator;
uniform_int_distribution<int> distribution(1,4);

void draw(table* map_, Figure* curr, Figure* heap, int points)
{
    for (int k=0; k<15; k++)
    {
        cout << "-----------------------------" << endl;
    }
    cout << "-------------" << points << "--------------" << endl;
    for( int j = 0; j < map_->get_y_size(); j++)
    {
        for( int i = 0; i < map_->get_x_size(); i++)
        {
            point curr_point(i, j);

            if (curr->if_exist(curr_point) || (heap->if_exist(curr_point)))
                cout << 'X';
            else
                cout << '~';
        }
        cout << endl;
    }
}

void curr_to_heap(Figure* curr, Figure* heap)
{
    for(unsigned int i=0; i<curr->spisok.size(); i++)
    {
        heap->set_cord(curr->spisok[i]);
    }
}

main()
{
    int decision = 1; // 1 - curr, 0 - new

    int counter = 0;

    table* mymap;
    table MYMAP(10, 15);
    mymap = &MYMAP;

    square SQUARE(0);
    line LINE(0);
    teshka TESHKA(0);
    geshka GESHKA(0);

    Figure* heap;
    Figure HEAP(0);
    heap = &HEAP;

    Figure* curr;

    curr = &SQUARE;
    curr->gen(MYMAP);

    while(1)
    {
        if (!decision)
        {
            int dice_roll = distribution(generator);

            switch (dice_roll)
            {
                case 1:
                    curr = &SQUARE;
                    break;
                case 2:
                    curr = &LINE;
                    break;
                case 3:
                    curr = &TESHKA;
                    break;
                case 4:
                    curr = &GESHKA;
                    break;
            }
            curr->gen(MYMAP);
            decision = 1;
        }

        draw(mymap, curr, heap, counter);

        char moving;

        moving = getch();

        switch(moving)
        {
            case 'a': curr->left(MYMAP, heap);break;
            case 'd': curr->right(MYMAP, heap);break;
            case 'w': curr->rot(MYMAP, heap);break;
            default: decision = curr->down(MYMAP, heap);break;
        }

        sleep_for(milliseconds(80));

        int flag = 0; // 0 - continue; 1 - exit

        if(!decision)
        {
            for(int i=0; i<4; i++)
            {
                if(curr->spisok[i].y == 0)
                {
                    flag = 1;
                    break;
                }
            }
            curr_to_heap(curr, heap);
            counter += heap->del_full_lines(MYMAP);

            curr->clear_all();
        }

        if(flag)
        {
            cout << "------------" << "GAME OVER. YOUR SCORE: " << counter << "------------" << endl;;
            break;
        }
    }
    getchar();
    return 0;
}
