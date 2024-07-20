#ifndef CUBE_H
#define CUBE_H
#include <iostream>
#include <curses.h>
#include <fstream>
#include "Game.hpp"
using namespace std;

class Tetramino;

class Cube{
protected:
    Tetramino* topleft;
    Tetramino* topright;
    Tetramino* bottomleft;
    Tetramino* bottomright;
    Map* map;
    bool stopped;
public:
    Cube(WINDOW* win,int spawnX,int spawnY,Map* map);
    void Spawncube();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    bool isStopped();
};

#endif