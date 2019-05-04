#include <iostream>
#include "table.h"
#include "table.cpp"
#include "conio.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <random>
#include "windows.h"
#include "time.h"

#include "square.h"
#include "square.cpp"
#include "line.h"
#include "line.cpp"
#include "teshka.h"
#include "teshka.cpp"
#include "geshka.h"
#include "geshka.cpp"
#include "point.h"
#include "point.cpp"
#include "ingame/"



using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
default_random_engine generator;
uniform_int_distribution<int> distribution(1,4);
void SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
void ColorTheField(int c)
{
	switch(c)
	{
		case 1: SetColor(1,0); break;
		case 2: SetColor(2,0); break;
		case 3: SetColor(3,0); break;
		case 4: SetColor(4,0); break;
		default: SetColor(5,0);break;
	}
}
void draw(table* map_, Figure* curr, Figure* heap, int points)
{
    system("cls");
    SetColor(7, 0);
    cout << "YOUR SCORE:"<< points << endl;
    for( int j = 0; j < map_->get_y_size(); j++)
    {
    	SetColor(6, 0);
        cout <<'*';
        for( int i = 0; i < map_->get_x_size(); i++)
        {
			point curr_point(i, j);//Cлава, за что ты так со мной?
            if (curr->if_exist(&curr_point))
            {
            	ColorTheField(curr->color);
                cout << 'X';
      		}
      		else
      		{
      			if (heap->if_exist(&curr_point))
           		{
            		ColorTheField(heap->whatcolor(heap->where_exist(&curr_point)));
            	    cout << 'O';
      			}
           		else
           		{	
            		SetColor(7, 0);
            		cout << '.';
				}
			}
              
        }
        SetColor(6, 0);
        cout <<'*'<< endl;
    }
    for( int i = 0; i < map_->get_x_size()+2; i++)
    {
			SetColor(6, 0);
            cout << '*';     
	}
	cout<<endl;
    
}

void curr_to_heap(Figure* curr, Figure* heap)
{
    for(unsigned int i=0; i<curr->spisok.size(); i++)
    {
        heap->set_cord(curr->spisok[i]);
    }
}
char GetterOfKey(int* time)
{
	int timer = 0;
	while(timer < *time)
	{ 
		Sleep(50);
		timer=timer+1;
		if (GetAsyncKeyState(VK_LEFT)) // get a
		{
			*time=*time - timer;
			return 'a';
		}
		if (GetAsyncKeyState(VK_RIGHT)) // get d
		{
			*time=*time - timer;
			return 'd';
		}
		if (GetAsyncKeyState(VK_UP)) // get w
		{
			*time=*time - timer;
			return 'w';
		}
		if (GetAsyncKeyState(VK_DOWN)) // get s
		{
			*time=*time - timer;
			return 's';
		}
	}
	*time=*time - timer;
	return 's';
}
void placeSeed(int seed)
{
	int i;
	while(seed>0)
	{
		i=distribution(generator);
		seed--;
	}
}
void ingame(int L,int W) //самый боьшой костыль евер
{
	int decision = 1; // 1 - curr, 0 - new
    int counter = 0;
    char moving;
    int currenttime = 0;
    int speed=0;
    int yourtime = currenttime;
    int flag=0;
    int difficult=0;
    int wanttoplay=1;

    table* mymap;
    table MYMAP(L, W);
    mymap = &MYMAP;

    square SQUARE(0);
    line LINE(0);
    teshka TESHKA(0);
    geshka GESHKA(0);

    Figure* heap;
    Figure HEAP(0);
    heap = &HEAP;

    Figure* curr;
    int dice_roll = distribution(generator);// объ€влени€ сложностей
    system("cls");
	SetColor(7,0);
	system("cls");
	SetColor(6, 0);
	cout << "Choose your level of difficult"<< endl;
	SetColor(2,0);
	cout<<"Easy -Left"<<endl;
	SetColor(14,0);
	cout << "Normal-UP"<< endl;
	SetColor(4,0);
	cout << "Hard-RIGHT"<< endl;
	SetColor(5,0);
	cout << "to give up-DOWN"<< endl;
	SetColor(7,0);
	while(1) // выбор уровн€ сложности
	{ 
		Sleep(1);
		if (GetAsyncKeyState(VK_LEFT)) 
		{
			speed = 0;
			currenttime = 30;
			break;
		}
		if (GetAsyncKeyState(VK_RIGHT)) 
		{
			speed = 0;
			currenttime = 10;
			break;
		}
		if (GetAsyncKeyState(VK_UP)) 
		{
			currenttime=20;
			break;
		}
		if (GetAsyncKeyState(VK_DOWN)) 
		{
			wanttoplay=0;
			break;
		}
	}
	Sleep(1000);
	system("cls");
    curr = &SQUARE;
    curr->gen(MYMAP);
	
    while(wanttoplay==1)//÷икл игры.
    {
        if (!decision)
        {
			dice_roll = distribution(generator);	
            switch (dice_roll)
            {
                case 1:
                    curr = &SQUARE;
                    curr->setcolor(1);
                    break;
                case 2:
                    curr = &LINE;
                    curr->setcolor(2);
                    break;
                case 3:
                    curr = &TESHKA;
                    curr->setcolor(3);
                    break;
                case 4:
                    curr = &GESHKA;
                    curr->setcolor(4);
                    break;
            }
            curr->gen(MYMAP);
            decision = 1;
        }

        draw(mymap, curr, heap, counter);
    	moving = GetterOfKey(&yourtime);

        switch(moving)
        {
            case 'a': 	curr->left(MYMAP, heap);break;
            case 'd': 	curr->right(MYMAP, heap);break;
            case 'w': 	curr->rot(MYMAP, heap);break;
            case 's':	currenttime=currenttime-speed;
						yourtime = currenttime;
						decision = curr->down(MYMAP, heap);
						break;
        }
        switch(dice_roll)
        {
        		case 1:
                    curr->setcolor(1);
                    break;
                case 2:
                    curr->setcolor(2);
                    break;
                case 3:
                    curr->setcolor(3);
                    break;
                case 4:
                    curr->setcolor(4);
                    break;
		}

        sleep_for(milliseconds(10));

        flag = 0; // 0 - continue; 1 - exit

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
            cout << "------------" << "GAME OVER.YOUR SCORE:" << counter << endl;;
            break;
        }
    }
}
int doyouwanttoplay()
{
	SetColor(6, 0);
	cout<< "do you want to play ?"<< endl;
	SetColor(2, 0);
	cout<<" <- YES";
	SetColor(4, 0);
	cout<<" NO ->"<<endl;
	while(1) // выбор решени€
	{ 
		Sleep(1);
		if (GetAsyncKeyState(VK_LEFT)) 
		{
			system("cls");
			return 1;
		}
		if (GetAsyncKeyState(VK_RIGHT)) 
		{
			system("cls");
			return 0;
		}
	}
}

main()
{
	int seed=0;
	int L=10;
	int W=10;
	SetColor(6, 0);
    cout<<"enter a seed"<< endl;
    cin>> seed;
    placeSeed(seed);
    system("cls");
    while(doyouwanttoplay()==1)
    {
    	//SetColor(6, 0);
    	//cout <<endl<< "choose Lenght and Wide of field"<<endl;
    	//cin>>L;
    	//cin>>W;
    	ingame(L,W);
	}
}
