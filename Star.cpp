

#include "Star.h"
#include <stdio.h>
#include <cstdlib>

Planet::Planet(int distance, int id){
    this->id = id;
    this->distance = distance;
    this->pos = 0;
}
int Planet::orbit(){
    if (this->pos < 359){
        this->pos += 1;
    }else{
        this->pos = 0 ;
    }
    return this->pos;
}

int Planet::getID(){
    return this->id;
}
int Planet::getDistance(){
    return this->distance;
}
int Planet::getPos(){
    return this->pos;
}

Star::Star(int max_planets){
    this->max_planets = max_planets;
    this->current_planets =  0;
    this->next_id = 0;
}

bool Star::addPlanet(){
    if(this->current_planets < this->max_planets){
        planets[current_planets] = Planet(rand() % 3000 ,next_id++);
        current_planets +=1;
        return true;
    }else{
        return false;
    }
}
Planet Star:: getFurthest(){
    int maxDistance=0;
    Planet temp_planets = planets[0];
    for(int i =0 ; i <current_planets; i++) {
        if (planets[i].getDistance() > maxDistance) {
            maxDistance=planets[i].getDistance();
            temp_planets = planets[i] ;
        }
    }
    return temp_planets;
}



void Star::orbit(){
    for (int i = 0 ; i<= current_planets; i++){
        planets[i].orbit();
    }
}

void Star::printStarInfo(){
    
    printf("The star currently has %d planets.\n" , current_planets );
    printf("The star can support up %d to planets.\n", current_planets ) ;
    printf("Planets: \n");
    for (int i = 0; i < 8; i++) {
        planets[i].getDistance();
        printf("\tPlanet %d is %d million miles away at position 1 around the star.\n",i, planets[i].getDistance() );
    }
}
int Star::getCurrentNumPlanets(){
    return this->current_planets;
}
int Star::getMaxPlanets(){
    return this->max_planets;
}
