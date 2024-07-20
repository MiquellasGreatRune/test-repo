#ifndef TETRA_H
#define TETRA_H
#include <iostream>
#include <curses.h>
#include <fstream>

using namespace std;


class Tetramino { 
protected:
    int x;
    int y;
    WINDOW* gameScreen;
public:
    Tetramino();
    void newtetra(WINDOW* gameScreen,int y,int x);
    void goLeft();
    void goRight();
    void goDown();
    void print();
    int getY();
    int getX();
};
#endif