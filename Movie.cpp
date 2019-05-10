//
// Created by tudi1 on 4/5/2019.
//

#include "Movie.h"

using namespace std;


Movie::Movie(const string& title, const string& genre, const int& year, const int& likes,const string& link)
{
    this->title=title;
    this->genre=genre;
    this->year=year;
    this->likes=likes;
    this->link=link;
}

void Movie::play()
{
    ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

