#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <curses.h>
using namespace std;
class Main_Menu {
protected:
    WINDOW* screen;
    WINDOW* name;
    WINDOW* options;
public:
    Main_Menu(WINDOW* win);
    void initMenu();
    void print_case(int highlight);
    void pressed_enter(int selected);
    };

#endif