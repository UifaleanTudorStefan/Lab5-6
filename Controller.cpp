//
// Created by tudi1 on 4/5/2019.
//

#include "Controller.h"
#include "Movie.h"

void Controller::addMovieToRepo(const string& title, const string& genre, const int& year, const int& likes,const string& link) {
    Movie m{title,genre,year,likes,link};

    this->repo.add(m);
}

void Controller::deleteMovieFromRepo(const string &title, const string &genre, const int &year, const int &likes,
                                     const string &link) {
    Movie m{title,genre,year,likes,link};
    this->repo.deleteMovie(m);


}

void Controller::updateMovieFromRepo(const string &title, const string &genre, const int &year, const int &likes,
                                     const string &link,const string& link2) {
    Movie m{title,genre,year,likes,link};
    this->repo.updateMovie(link2,m);


}

DynamicVector Controller::getMoviesByGenreCtrl(const string &genre) {
    DynamicVector x=this->repo.getMoviesByGenre(genre);

    return x;
}


