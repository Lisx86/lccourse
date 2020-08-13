#include <ncurses.h>
#include <iostream>
#include <math.h>
#include <unistd.h>
using namespace std;

int main()
{
    initscr();
    /*if(has_colors()==false)
    {
        printw("This terminal does not support colors");
        getch();
        endwin();
        return -1;
    }*/

    int h,w;
    getmaxyx(stdscr, h, w);
    printw("%d,%d",h,w);
    refresh();
    move(h/2,w/2);
    refresh();
    int x = 0;
    int y = 0;
    float angle = 0.0f;
    int a = 2, b = 2;
    int maxPoints=1000;
    int adaptw=1,adapth=1;
    if(w>h)
    {
        adapth=(w+h/2)/h;
    }

    if(h>w)
    {
        adaptw=(h+w/2)/w;
    }

    //start_color();
    //init_color(1,129,50,253);
    for (float i = 0; i < maxPoints; i=i+0.01)
    {
        angle = 0.3 * i;
        x = (a + b * angle/adapth) * cos(angle);
        y = (a + b * angle/adaptw) * sin(angle);

        //attron(COLOR_PAIR(1));
        refresh();
        if(h/2+x>h-3 or w/2+y>w-3)
        {
            refresh();
            getch();
            endwin();
            return 0;
        }
        move(h/2+x,w/2+y);
        refresh();
        addch(ACS_CKBOARD);
        refresh();
        //attroff(COLOR_PAIR(1));
        refresh();
        //usleep(50000);
    }   
    refresh();
    getch();
    endwin();
}