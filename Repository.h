//
// Created by tudi1 on 4/5/2019.
//

#ifndef UNTITLED3_REPOSITORY_H
#define UNTITLED3_REPOSITORY_H

#endif //UNTITLED3_REPOSITORY_H

#pragma once

#include "DynamicVector.h"


class Repository{
private:
    DynamicVector movies;
public:
    Repository(){}
    void add(const Movie& movie);
    void deleteMovie(const Movie& movie);
    void updateMovie(const string &link,const Movie &movie);
    DynamicVector getMovies() const {return this->movies;}
    DynamicVector getMoviesByGenre(const string& genre);
    bool findMovie(const Movie& movie);

};