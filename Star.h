#ifndef STAR_H
#define STAR_H
class Planet{
private:
    int id;
    int pos;
    int distance;
public:
    Planet(){this->id=-1;};
    Planet(int,int);
    int orbit();
    int getID();
    int getDistance();
    int getPos();
    //you may add any additional methods you may need.
};

class Star{
private:
    int max_planets;
    int current_planets;
    int next_id;
public:
    Planet planets[20];
    Star(int);
    bool addPlanet();
    Planet getFurthest();
    void orbit();
    void printStarInfo();
    int getCurrentNumPlanets();
    int getMaxPlanets();
    //you may add any additional methodas you may need.
};
#endif
