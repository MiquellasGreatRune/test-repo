#include <iostream>
#include <cstdlib>
#include <ctime>
#include "curses.h"
#include "fstream"
#include "Game.hpp"
#include "Tetramino.hpp"
#include "Cube.hpp"
using namespace std;
Cube::Cube(WINDOW* gameScreen,int spawnX,int spawnY,Map* map){
    topleft = new Tetramino();
    topright = new Tetramino();
    bottomleft = new Tetramino();
    bottomright = new Tetramino();
    topleft->newtetra(gameScreen,spawnY,spawnX);
    topright->newtetra(gameScreen,spawnY,spawnX+1);
    bottomleft->newtetra(gameScreen,spawnY+1,spawnX);
    bottomright->newtetra(gameScreen,spawnY+1,spawnX+1);
    this->map = map;
    this->stopped = false;
}
void Cube::Spawncube(){
    topleft->print();
    topright->print();
    bottomleft->print();
    bottomright->print();
}
void Cube::MoveLeft(){
    if (topleft->getY()!= 1){
        topleft->goLeft();
        bottomleft->goLeft();
        topright->goLeft();
        bottomright->goLeft();
    }
}
void Cube::MoveRight(){
    if (topright->getY()!= 10){
        topright->goRight();
        bottomright->goRight();
        topleft->goRight();
        bottomleft->goRight();
        
    }
}
void Cube::MoveDown(){
    if (bottomleft->getY()!=20){
        bottomleft->goDown();
        bottomright->goDown();
        topleft->goDown();
        topright->goDown();
    } else if (bottomleft->getY()==20){
        stopped = true;
    }
}
bool Cube::isStopped(){
    return this->stopped;
}