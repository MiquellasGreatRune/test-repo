#include <iostream>
#include <curses.h>
#include <fstream>
#include "Scoreboard.hpp"
#include "Main_Menu.hpp"
using namespace std;
Scoreboard::Scoreboard(WINDOW* win){
    this->screen = win;
    this->SCname = newwin(3,14,getmaxy(stdscr)/2-8,getmaxx(stdscr)/2-7);
    this->score = newwin(14,14,getmaxy(stdscr)/2-3,getmaxx(stdscr)/2-7);   
}
void Scoreboard::initScoreboard(){
    box(screen,0,0);
    box(score,0,0);
    box(SCname,0,0);
    wrefresh(screen);
    wrefresh(score);
    wrefresh(SCname);
    keypad(score,true);
    mvwprintw(SCname,1,1,"HIGH SCORES!");
    wrefresh(SCname);
    printscores();
    int key;
    while (true){
        key = wgetch(score);
        if (key = KEY_ENTER){
            wclear(score);
            wclear(SCname);
            wrefresh(score);
            wrefresh(SCname);
            delwin(score);
            delwin(SCname);
            Main_Menu menu = Main_Menu(screen);
            menu.initMenu();
        }
    }
}
void Scoreboard::printscores(){
    this->scoreFile.open("Score.txt");
    char ch[50];
    if (scoreFile.is_open()){
        for (int i=0;i<50;i++){
            scoreFile >> ch[i];
            if (scoreFile.fail()){
                break;
            }else if (scoreFile.eof()){
                break;
            }
        }
    }
    int j = -1;
    for (int l=0;l<50;l++){
        if (l%10 == 0){
            j=j+2;
        }
        mvwprintw(score,j,l%10+1,"%c",ch[l]);
    }
    scoreFile.close();
    mvwprintw(score,12,1,"-");
    wattr_on(score,A_REVERSE,0);
    mvwprintw(score,12,2,"back");
    wattr_off(score,A_REVERSE,0);
    wrefresh(score);
}