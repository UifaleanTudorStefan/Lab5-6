//
// Created by tudi1 on 4/5/2019.
//

#ifndef UNTITLED3_MOVIE_H
#define UNTITLED3_MOVIE_H

#endif //UNTITLED3_MOVIE_H

#pragma once
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

using namespace std;

class Movie
{
private:
    string title;
    string genre;
    int year;
    int likes;
    string link;

public:
    Movie(): title(" "), genre(" "), year(0), likes(0), link(" "){}
    Movie(const string& title, const string& genre, const int& year, const int& likes,const string& link);
    string getTitle() const { return title; }
    string getGenre() const { return genre; }
    int getYear() const { return year; }
    int getLikes() const { return likes; }
    string getLink() const { return link; }
    void setLink(const string &link){this->link=link;}
    void play();


};