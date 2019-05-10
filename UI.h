//
// Created by tudi1 on 4/18/2019.
//

#ifndef UNTITLED3_UI_H
#define UNTITLED3_UI_H

#endif //UNTITLED3_UI_H

#include "Controller.h"

class UI
{
private:
    Controller ui;
    Repository WatchList;
public:
    UI(Controller ui): ui(ui){}
    void start();

private:
    void printMenu();
    void printAdmin();
    void printUser();
    void printAll();
    void addMovieUI();
    void deleteMovieUI();
    void updateMovieUI();
    void playAndAdd();
    void deleteFromWatchList();
    void showWatchList();
};