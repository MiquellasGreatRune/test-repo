#include <iostream>
#include <cstdlib>
#include <ctime>
#include "curses.h"
#include "fstream"
#include "Main_Menu.hpp"
#include "Scoreboard.hpp"
#include "Game.hpp"
#include "Cube.hpp"
#include "Tetramino.hpp"
using namespace std;
//wborder = (sx,dx,top,bottom,topsxcorner,topdxcorner,bottomsxcorner,bottomdxcorner)

Game::Game(WINDOW* win){
        this->screen = win;
        this->gameScreen = newwin(22,12,getmaxy(stdscr)/2-11,getmaxx(stdscr)/2-6);
        this->scoreScreen = newwin(10,20,getmaxy(stdscr)/2-16,getmaxx(stdscr)/2+18);
        for (int i=0;i<10;i++){
            for (int j=0;j<20;j++){
                map->occupied[j][i] = false;
                map->y[j][i] = j+1;
                map->x[j][i] = i+1;
            }
        }
        Score=0;
        n_lines=0;
        lost = false;
        //this->SpawnY = getmaxy(gameScreen)/2-10;
        //this->SpawnX = getmaxx(gameScreen)/2;
        this->SpawnX = 1;
        this->SpawnY = 1;
}
void Game::initGame(){
    box(screen,0,0);
    box(scoreScreen,0,0);
    //wborder(gameScreen,0,0,' ',0,' ',' ',0,0);
    box(gameScreen,0,0);
    mvwprintw(scoreScreen,1,1,"SCORE: %d",Score);
    mvwprintw(scoreScreen,3,1,"LINES: %d",n_lines);
    leaveok(gameScreen,true);
    leaveok(scoreScreen,true);
    wrefresh(screen);
    wrefresh(scoreScreen);
    wrefresh(gameScreen);
    
    startGame();
}
void Game::startGame(){
    int key,type;
    keypad(gameScreen,true);
    wrefresh(gameScreen);
    while (lost == false){
        type = 1;//rand()%1+1;
        if (type == 1){
            Cube piece = Cube(gameScreen,SpawnY,SpawnY,map);
            piece.Spawncube();
            wrefresh(gameScreen);
            while(!piece.isStopped()){
                halfdelay(7);
                key = wgetch(gameScreen);
                if (key == KEY_LEFT){
                    piece.MoveLeft();
                } else if (key == KEY_RIGHT){
                    piece.MoveRight();
                } else if (key == KEY_ENTER){
                    break;
                }
                //piece.MoveDown(); 
            }  
        } 
    }
    Main_Menu menu = Main_Menu(screen);
    menu.initMenu();
}
void Game::updatescore(int points){
    this->Score = this->Score + points;
    mvwprintw(scoreScreen,1,1,"SCORE: %d",Score);
    wrefresh(scoreScreen);
}
void Game::updatelines(int lines){
    this->n_lines = n_lines + lines;
    mvwprintw(scoreScreen,3,1,"LINES: %d",n_lines);
    wrefresh(scoreScreen);
}