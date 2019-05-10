#include <iostream>
#include "UI.h"

int main() {
    Repository repo;
    Movie movie{"Avengers:Endgame","Superheroes",2019,29252100,"https://www.youtube.com/watch?v=TcMBFSGVi1c"};
    repo.add(movie);
    Movie movie1{"Sonic the Hedgehog","Action",2019,352000,"https://www.youtube.com/watch?v=FvvZaBf9QQI"};
    repo.add(movie1);
    Movie movie2{"The Nun","Thriller",2018,309000,"https://www.youtube.com/watch?v=pzD9zGcUNrw"};
    repo.add(movie2);
    Controller ctrl{repo};
    UI ui{ctrl};

    ui.start();
    return 0;
}