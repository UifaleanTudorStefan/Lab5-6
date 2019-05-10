//
// Created by tudi1 on 4/5/2019.
//

#include "Repository.h"

void Repository::add(const Movie& movie)
{
    this->movies.add(movie);
}

void Repository::deleteMovie(const Movie &movie) {
    DynamicVector v=this->movies;
    DynamicVector v2;
    for(int i=0;i<this->movies.getSize();i++)
        if(this->movies.getAllElems()[i].getTitle()==movie.getTitle() && this->movies.getAllElems()[i].getGenre()==movie.getGenre() && this->movies.getAllElems()[i].getYear()==movie.getYear())
        {

            for(int j=0;j<v.getSize();j++) {
                if(j!=i)
                v2.add(v.getAllElems()[j]);
            }

        }


    this->movies=v2;

}

void Repository::updateMovie(const string &link,const Movie &movie)
{for(int i=0;i<this->movies.getSize();i++)
        if(this->movies.getAllElems()[i].getTitle()==movie.getTitle() && this->movies.getAllElems()[i].getGenre()==movie.getGenre() && this->movies.getAllElems()[i].getYear()==movie.getYear()) {
            this->movies.getAllElems()[i].setLink(link);
        }

}

DynamicVector Repository::getMoviesByGenre(const string& genre)
{
    DynamicVector tot=this->getMovies();
    DynamicVector genres;
    for(int i=0;i<tot.getSize();i++)
    {
        if(tot.getAllElems()[i].getGenre()==genre)
            genres.add(tot.getAllElems()[i]);
    }

    if(genres.getSize()!=0 || genres.getSize()!=NULL)
        return genres;
    else
        return tot;
}

bool Repository::findMovie(const Movie &movie) {
    DynamicVector res=this->getMovies();
    for(int i=0;i<res.getSize();i++)
    {
        if(movie.getTitle()==res.getAllElems()[i].getTitle() && movie.getGenre()==res.getAllElems()[i].getGenre() && movie.getYear()==res.getAllElems()[i].getYear())
            return true;
    }
    return false;
}

