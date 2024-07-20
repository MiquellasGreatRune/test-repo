#include <iostream>
#include "curses.h"
#include "fstream"
#include "Game.hpp"
#include "Tetramino.hpp"
#include "Cube.hpp"
using namespace std;


Tetramino::Tetramino(){
    this->gameScreen = nullptr;
    this->x = -1;
    this->y = -1;
}
void Tetramino::newtetra(WINDOW* gameScreen,int y,int x){
    this->gameScreen = gameScreen;
    this->y = y;
    this->x = x;
}
void Tetramino::goLeft(){
    mvwprintw(gameScreen,y,x," ");
    x = -1;
    print();
}
void Tetramino::goRight(){
    mvwprintw(gameScreen,y,x," ");
    x = +1;
    print();
}
void Tetramino::goDown(){
    mvwprintw(gameScreen,y,x," ");
    y=y-1;
    print();
}
void Tetramino::print(){
    mvwprintw(gameScreen,y,x,"0");
    wrefresh(gameScreen);
}
int Tetramino::getX(){
    return this->x;
}
int Tetramino::getY(){
    return this->y;
}
