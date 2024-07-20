#include <iostream>
#include "curses.h"
#include "fstream"
#include "Main_Menu.hpp"
#include "Scoreboard.hpp"
#include "Game.hpp"
using  namespace std;

Main_Menu::Main_Menu(WINDOW* win){
    this->screen = win;
    this->name = newwin(3,16,getmaxy(stdscr)/2-8,getmaxx(stdscr)/2-8);
    this->options = newwin(7,14,getmaxy(stdscr)/2-3,getmaxx(stdscr)/2-7);
}
void Main_Menu::print_case(int highlight){
    if (highlight == 1){
        wattr_on(options,A_REVERSE,0);
        mvwprintw(options,highlight,2,"start");
        wattr_off(options,A_REVERSE,0);
        mvwprintw(options,highlight+2,2,"scoreboard");
        mvwprintw(options,highlight+4,2,"exit");
        wrefresh(options);
    } 
    else if (highlight == 3){
        wattr_on(options,A_REVERSE,0);
        mvwprintw(options,highlight,2,"scoreboard");
        wattr_off(options,A_REVERSE,0);
        mvwprintw(options,highlight-2,2,"start");
        mvwprintw(options,highlight+2,2,"exit");
        wrefresh(options);
    } 
    else if (highlight == 5){
        wattr_on(options,A_REVERSE,0);
        mvwprintw(options,highlight,2,"exit");
        wattr_off(options,A_REVERSE,0);
        mvwprintw(options,highlight-4,2,"start");
        mvwprintw(options,highlight-2,2,"scoreboard");
        wrefresh(options);
    }
}
void Main_Menu::pressed_enter(int selected){
    if (selected == 1){ 
        wclear(name);
        wclear(options);
        wrefresh(name);
        wrefresh(options);
        delwin(name);
        delwin(options);
        Game game = Game(screen);
        game.initGame();
    } else if ( selected == 3){
        wclear(name);
        wclear(options);
        wrefresh(name);
        wrefresh(options);
        delwin(name);
        delwin(options);
        Scoreboard scoreboard = Scoreboard(screen);
        scoreboard.initScoreboard();        
    }  else if (selected == 5){
        exit(0);
    }
}
void Main_Menu::initMenu(){
    box(screen,0,0);
    box(name,0,0);
    box(options,0,0);
    wrefresh(screen);
    wrefresh(name);
    wrefresh(options);
    wrefresh(name);
    wrefresh(options);
    mvwprintw(name,1,1,"NCURSES TETRIS");
    mvwprintw(options,1,1,"-start");
    mvwprintw(options,3,1,"-scoreboard");
    mvwprintw(options,5,1,"-exit");
    wrefresh(name);
    keypad(options,true);
    wrefresh(options);

    int key;
    int highlight = 1;

    
    wattr_on(options,A_REVERSE,0);
    mvwprintw(options,highlight,2,"start");
    wattr_off(options,A_REVERSE,0);
    wrefresh(options);
    while (true){
        key = wgetch(options);
        if (key == (int)KEY_UP){
            highlight = highlight-2;
            if (highlight < 1){
                highlight = 5;
            }
            print_case(highlight);              
        }
        else if (key == KEY_DOWN){
            highlight = highlight+2;
            if (highlight > 5){
                highlight = 1;
            }
            print_case(highlight);
        }
        else if (key == 10 ){
            pressed_enter(highlight);
            break;
        } 
    }    
}
