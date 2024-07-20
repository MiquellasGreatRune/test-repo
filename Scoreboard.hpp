#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <curses.h>
#include <fstream>
using namespace std;
class Scoreboard {
protected:
    WINDOW* screen;
    WINDOW* score;
    WINDOW* SCname;
    fstream scoreFile;
public:
    Scoreboard(WINDOW* win);
    void initScoreboard();
    void printscores();
};
#endif