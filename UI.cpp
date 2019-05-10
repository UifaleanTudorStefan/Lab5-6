//
// Created by tudi1 on 4/18/2019.
//

#include "UI.h"
#include <string>


using namespace std;

void UI::printMenu()
{   cout<<"0.Exit"<<endl;
    cout<<"1.User mode"<<endl;
    cout<<"2.Admin mode"<<endl;
}
void UI::printUser()
{
    cout<<"0.Go to user menu"<<endl;
    cout<<"1.Add Movie"<<endl;
    cout<<"2.Delete Movie"<<endl;
    cout<<"3.Update movie"<<endl;
    cout<<"4.Play and watch from a certain genre"<<endl;
    cout<<"5.Delete from watchlist"<<endl;
    cout<<"6.Show watch list"<<endl;
}
void UI::printAdmin()
{
    cout<<"0.Go to user menu"<<endl;
    cout<<"1.Add Movie"<<endl;
    cout<<"2.Delete Movie"<<endl;
    cout<<"3.Update movie"<<endl;
    cout<<"4.Show all movies"<<endl;
    cout<<"5.Play and watch from a certain genre"<<endl;
    cout<<"6.Delete from watchlist"<<endl;
    cout<<"7.Show watch list"<<endl;
}
void UI::printAll() {
    DynamicVector v = this->ui.getRepo().getMovies();
    Movie *movies = v.getAllElems();
    if (v.getSize() == NULL)
        return;
    if (v.getSize() == 0)
        return;
    for (int i = 0; i < v.getSize(); i++)
        cout << movies[i].getTitle() << " , " << movies[i].getGenre() << " , " << movies[i].getYear()<<" , "<<movies[i].getLikes()<<" Link:"<<movies[i].getLink()<<endl;
}

    void UI::addMovieUI()
    {
    string title,genre,link;
    int year,likes;

    cout<<"Give a title: "<<endl;
    getline(cin,title);
    cout<<"Give a genre: "<<endl;
    getline(cin,genre);
    cout<<"Give a year: "<<endl;
    cin>>year;
    cout<<"Give the amount of likes: "<<endl;
    cin>>likes;
    cin.ignore();
    cout<<"Give the link: "<<endl;
    getline(cin,link);
    this->ui.addMovieToRepo(title,genre,year,likes,link);

    }
void UI::deleteMovieUI()
{
    string title,genre,link;
    int year,likes;
    cout<<"Give a title: "<<endl;
    getline(cin,title);
    cout<<"Give a genre: "<<endl;
    getline(cin,genre);
    cout<<"Give a year: "<<endl;
    cin>>year;
    likes=0;
    link="";
    this->ui.deleteMovieFromRepo(title,genre,year,likes,link);

}

void UI::playAndAdd() {
    string genre,answer;
    cout<<"Give a genre: "<<endl;
    getline(cin,genre);
    DynamicVector movies=this->ui.getMoviesByGenreCtrl(genre);
    for(int i=0;i<movies.getSize();i++)
    {   cout<<"Movie: "<<movies.getAllElems()[i].getTitle()<<endl<<"Genre: "<<movies.getAllElems()[i].getGenre()<<endl<<"Year of release: " <<movies.getAllElems()[i].getYear()<<endl<<"Likes: "<<movies.getAllElems()[i].getLikes()<<endl;
        cout<<"Playing trailer..."<<endl;
        movies.getAllElems()[i].play();
        cout<<"Would you like to put this movie on your watchlist?"<<endl;
        getline(cin,answer);
        if(answer=="yes" || answer=="Yes")
            if(this->WatchList.findMovie(movies.getAllElems()[i])==false)
                this->WatchList.add(movies.getAllElems()[i]);
        cout<<"Would you like to continue?"<<endl;
        getline(cin,answer);
        if(answer=="no" || answer=="No")
            break;
        if(i==movies.getSize()-1 && answer!="No")
            i=-1;

    }
}

void UI::deleteFromWatchList() {
    string title,genre;
    int year;
    cout<<"Give the title of the movie you want to delete"<<endl;
    getline(cin,title);
    cout<<"Give the genre of the movie you want to delete"<<endl;
    getline(cin,genre);
    cout<<"Give the year of release of the movie you want to delete"<<endl;
    cin>>year;
    cin.ignore();
    Movie m{title,genre,year,0,""};
    this->WatchList.deleteMovie(m);


}

void UI::showWatchList() {
    DynamicVector v = this->WatchList.getMovies();
    Movie *movies = v.getAllElems();
    if (v.getSize() == NULL)
        return;
    if (v.getSize() == 0)
        return;
    for (int i = 0; i < v.getSize(); i++)
        cout << movies[i].getTitle() << " , " << movies[i].getGenre() << " , " << movies[i].getYear()<<" , "<<movies[i].getLikes()<<" Link:"<<movies[i].getLink()<<endl;

}

void UI::updateMovieUI()
{
    string title,genre,link,link2;
    int year,likes;

    cout<<"Give a title: "<<endl;
    getline(cin,title);
    cout<<"Give a genre: "<<endl;
    getline(cin,genre);
    cout<<"Give a year: "<<endl;
    cin>>year;
    cin.ignore();
    likes=0;
    link="";
    cout<<"Give the alternate link: "<<endl;
    getline(cin,link2);
    this->ui.updateMovieFromRepo(title,genre,year,likes,link,link2);

}

    void UI::start() {
    while(true)
    {
        int command={0};
        UI::printMenu();
        cout<<"Give a command: "<<endl;
        cin>>command;
        cin.ignore();
        if(command==0)
            break;
        if(command==1)
            while(true) {
                int command1{0};
                UI::printUser();
                cout << "Give a command: " << endl;
                cin>>command1;
                cin.ignore();
                if(command1==0)
                    break;
                if(command1==1)
                    addMovieUI();

                if(command1==2)
                deleteMovieUI();
                if(command1==3)
                    updateMovieUI();
                if(command1==4)
                    playAndAdd();
                if(command1==5)
                    deleteFromWatchList();
                if(command1==6)
                    showWatchList();
            }

        if(command==2)
            while(true) {
                int command2{0};
                UI::printAdmin();
                cout << "Give a command: " << endl;
                cin>>command2;
                cin.ignore();
                if(command2==0)
                    break;
                if(command2==1)
                    addMovieUI();
                if(command2==2)
                    deleteMovieUI();
                if(command2==3)
                    updateMovieUI();
                if(command2==5)
                    playAndAdd();
                if(command2==4)
                    printAll();
                if(command2==6)
                    deleteFromWatchList();
                if(command2==7)
                    showWatchList();
            }

    }
}


