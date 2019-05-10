//
// Created by tudi1 on 4/5/2019.
//

#ifndef UNTITLED3_CONTROLLER_H
#define UNTITLED3_CONTROLLER_H

#endif //UNTITLED3_CONTROLLER_H
#pragma once

#include "Repository.h"
#include <iostream>

using namespace std;

class Controller
{
private:
    Repository repo;
public:
    Controller(const Repository& repo): repo(repo) {}
    Repository getRepo() const {return this->repo;}
    void deleteMovieFromRepo(const string& title, const string& genre, const int& year, const int& likes, const string& link);
    void addMovieToRepo(const string& title, const string& genre, const int& year, const int& likes, const string& link);
    void updateMovieFromRepo(const string &title, const string &genre, const int &year, const int &likes,
                                         const string &link,const string& link2);
    DynamicVector getMoviesByGenreCtrl(const string &genre);
};