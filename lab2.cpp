#include "Star.h"
#include "Star.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define TEST_PLANETS 8

using namespace std;

int main(){
    srand(time(NULL));
    cerr << "\n\tTEST #1: Test Star Creation with 0 planets" << endl;
    
    Star sun(TEST_PLANETS);
    assert(sun.getCurrentNumPlanets() == 0);
    assert(sun.getMaxPlanets() == 8);
    
    cerr << "\n\t========================PASS========================\n" << endl;
    
    cerr << "\n\tTEST #2: Test Creating a Planet" << endl;
    //Change the maximum number fo ants to 5
    Planet x(10, 1);
    assert(x.getID() == 1);
    for(int i = 1; i < 720; i++){
        int pos = x.orbit();
        assert(pos == i%360);
    }
    
    cerr << "\n\t========================PASS========================\n" << endl;
    
    cerr << "\n\tTEST #3: Add Planets to a Star" << endl;
    
    for(int i = 0; i < TEST_PLANETS; i++){
        if(i < 20){
            assert(sun.addPlanet());
            assert(sun.getCurrentNumPlanets() == i+1);
        }
        else{
            assert(!sun.addPlanet());
            assert(sun.getCurrentNumPlanets() == TEST_PLANETS);
        }
        assert(sun.getMaxPlanets() == TEST_PLANETS);
        Planet temp = sun.getFurthest();
        int count = 0;
        for(int j = 0; j < sun.getCurrentNumPlanets(); j++){
            if(temp.getID() == sun.planets[j].getID())
                count++;
            assert(temp.getDistance() >= sun.planets[j].getDistance());
        }
        
        assert(count == 1);
    }
    
    cerr << "\n\t========================PASS========================\n" << endl;
    
    cerr << "\n\tTEST #4: Test Star orbit" << endl;
    
    int pos[TEST_PLANETS];
    for(int i = 0; i < sun.getCurrentNumPlanets(); i++){
        pos[i] = sun.planets[i].getPos();
    }
    sun.orbit();
    
    for(int i = 0; i < sun.getCurrentNumPlanets(); i++){
        assert(pos[i] + 1 == sun.planets[i].getPos());
    }
    
    cerr << "\n\t========================PASS========================\n" << endl;
    
    cerr << "\n\tTEST #5: Print Star Information" << endl;
    
    sun.printStarInfo();
    
    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tAll Tests Passed.\nDont forget to run with Valgrind and push to Github!\n" << endl;
    return 0;
}
