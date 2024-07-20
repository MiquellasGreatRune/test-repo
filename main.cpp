#include <iostream>
#include "curses.h"
#include "fstream"
#include "Main_Menu.hpp"
using  namespace std;
//standard terminal window is 30ymax 120xmax
//stdscr è lo schermo iniziale del terminale
//newwin(altezza,larghezza,inizio y,inizio x)
//wborder = (sx,dx,top,bottom,topsxcorner,topdxcorner,bottomsxcorner,bottomdxcorner)

int main(int argc,char ** argv) {
   
    initscr();
    noecho();
    cbreak();
    int x,y,max_Y,max_X;
    getbegyx(stdscr,y,x);
    getmaxyx(stdscr,max_Y,max_X);
    WINDOW* screen = newwin(32,32,max_Y/2-16,max_X/2-16);
    leaveok(screen,true);
    Main_Menu menu = Main_Menu(screen);
    menu.initMenu();
    ///////////
    endwin();
    return 0;
    
}
