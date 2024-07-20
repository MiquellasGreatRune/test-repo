#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <curses.h>
#include <fstream>
struct Map {
    bool occupied[20][10];
    int y[20][10];
    int x[20][10];
};

class Game {
protected:
    WINDOW* screen;
    WINDOW* gameScreen;
    WINDOW* scoreScreen;
    int Score;
    int n_lines;
    bool lost;
    int SpawnY;
    int SpawnX;
    Map* map;
public:
   Game(WINDOW* win);
   void initGame();
   void startGame();
   void updatescore(int points);
   void updatelines(int lines);
    
};
#endif