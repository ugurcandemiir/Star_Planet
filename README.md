### CS 240 - Spring 2019
# Lab 2 - Separate Compilation and Basic C++
## Due Date: 11:59 p.m., February 6th, 2019

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab2.cpp
    * Star.h
    * Star.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make clean
    * Sample Output (with our test case):
        ```shell
            ./lab2
    	TEST #1: Test Star Creation with 0 planets
    	========================PASS========================
    	TEST #2: Test Creating a Planet
    	========================PASS========================
    	TEST #3: Add Planets to a Star
    	========================PASS========================
    	TEST #4: Test Star orbit
    	========================PASS========================
    	TEST #5: Print Star Information
        The star currently has 8 planets.
        The star can support up to 8 planets.
        Planets:
        	Planet 0 is 654 million miles away at position 1 around the star.
        	Planet 1 is 966 million miles away at position 1 around the star.
        	Planet 2 is 2896 million miles away at position 1 around the star.
        	Planet 3 is 2168 million miles away at position 1 around the star.
        	Planet 4 is 2193 million miles away at position 1 around the star.
        	Planet 5 is 262 million miles away at position 1 around the star.
        	Planet 6 is 1594 million miles away at position 1 around the star.
        	Planet 7 is 1962 million miles away at position 1 around the star.
    	========================PASS========================
    	All Tests Passed.
        Dont forget to run with Valgrind and push to Github!
        ```

### Grading Rubric
**_TOTAL: 15 points_**
* **Part A: 3 points**
    * header file contains include guards [3 points]
* **Part B: 12 points**
    * Passes test #1 [1 point]
    * Passes test #2 [2 points]
    * Passes test #3 [2 points]
    * Passes test #4 [2 points]
    * Passes test #5 [1 point]
    * Makefile contains an 'all' target that _only_ compiles the code [1 point]
    * Makefile contains an 'run' target that executes and only compiles if necessary [1 point]
    * Makefile contains an 'clean' target that removes object files and the executable [1 point]
    * Makefile contains variables as described [1 point]
* **Part C:**
    * Repository includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk)[-3 points]
    * Your submission will not be accepted if:
        * Does not follow requested project structure and submission format
        * Does not compile

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

The goal of Lab 2 is to familiarize you with the few basic C++ features and aspects that we have discussed in the first weeks of class. In particular, you will implement multiple classes with various methods; you will use iostream to produce formatted output; you will do just a bit more separate compilation by building two separate object (i.e. _.o_) files, and then separately link them into a single executable.

## Part A: Star Program

You should implement two classes, Star and Planet. Both these classes are already defined in a Star.h file and should be implemented in the Star.cpp file. All methods you write must be external.

### Planet
The Planet class has two constructors. One that creates a Planet and initializes the id to -1, and another that takes a distance and an #id number as a parameter. Your planet class should have the following interface:
* _public_:
    * Planet(); //already implemented for you
        * A default constructor so you can allocate memory for an empty array. This is for utility purposes only and should be considered an invalid object.
    * Planet(int distance, int id); //already implemented for you
        * A value constructor that sets the Planet’s `id` to a unique value and its `distance` to a random number between 0 to 3000 (in millions of miles).
        * The `pos` should be set to 0
    * int orbit();
        * Moves the planet +1 unit around the Star.
            * Your position should always be in the range 0-359.
        * Returns the planet's current position
    * int getID();
        * returns the Planet’s ID number
    * int getDistance();
        * returns the Planet's distance from the Star
    * int getPosition();
        * returns the Planet's position relative to the Star

:bulb: Notice I only gave you the public interface. Although I wrote the private interface for you in this lab, normally the private interface will be up to you.

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

__You may continue to work on the remainder of the lab on your own time or in lab__

### Star
The Star class will have a constructor that takes a random number of planets it is allowed to hold as a parameter, between 0 and 20. You will also need an array of Planet objects. For now, the Planet array is allocated to buffer size of 20. We will make this more dynamic in a later lab. Below is the expected interface for your Star class.
* _public_:
    * Planet planets[20];
       * An array of Planets. We will make this more dynamic in a later lab.
    * Star(int);
        * A constructor that takes the maximum number of Planets as a parameter
    * bool addPlanet(Planet p);
        * Adds a new Planet object to the Star with a unique id and a random distance. The new planet is only added if the maximum number of planets the Star can support has not yet been reached.
        * Return true on success and false on failure.
    * Planet getFurthest();
        * Returns the furthest planet form the Star.
    * void orbit();
        * calls orbit on all planets orbiting the Star
    * void printStarInfo();
        * Prints the Star information. (See sample output above)
    * int getCurrentNumPlanets();
        * returns the current number of planets
    * int getMaxPlanets();
        * returns the maximum number of planets

## Part B: Testing and Running Your Code
### Make
You are going to be using separate compilation to build your program. This means you will need to create two object files. One from the provided lab2.cpp file, and one from your Star.cpp file. The header file, or .h file, contains your class declarations. You never compile header files. They are always included in other files that get compiled and should be dependencies for a target, never a target themselves. Often, they will be included in multiple files and as multiple dependencies.

For this class we are going to be using `make` and makefiles to compile our code. Write a makefile that compiles lab2.cpp and Star.cpp to separate object files. Then link them as shown in class. Your makefile will need to have the following targets (in addition to the compile and linking targets).
* __all__
   * This will compile your code to an executable, and should have your executable target as a dependency
* __run__
   * This target has ‘all’ as a dependency, then runs your executable
* __clean__
   * removes object files and the executable. Be careful not to delete your source code.
* :bulb: You may add any additional targets you feel are useful
    * For example, I always add a `submit` target that first cleans, then adds all files, commits, and pushes to github.
    
[Click here for more information on makefiles](http://mrbook.org/blog/tutorials/make/)

You must use variables in your makefile to accomplish the following:
* A compiler flag variable that will easily allow you to switch compiler flags
   * example compiler flags I recommend:
      * `-Wall -Wextra -DDEBUG -g -std=c++14`
* A project name variable that you can use throughout your makefile

### Constraints

The above public methods for your classes are the minimum interface requirements. You may add additional methods or instance variables to your classes if you feel they are needed. For full credit, please adhere to the following constraints, in addition to what is described above:
* You may not use any __global variables__. The only exception to this is constant values, and they should be declared in all uppercase.        
* Your lab must build from 2 different C++ source files (See expected structure below).
    * Your ‘Star’ /’Planet’ classes should be defined in a header file, and implemented in a separate implementation (.cpp) file.
    * The C++ file that contains the main() is provided below. You must use the provided driver code since it contains tests you must pass.
    * _lab2.cpp_ and _Star.cpp_ should build into .o files called _lab2.o_ and _Star.o_, respectively, and should then link into an executable called _lab2_. Therefore, after building your program with make, we should be able to type `./lab2` to run it.

## Part C : Code Organization and Submission
* Required code organization:
   * lab2.cpp (driver code - You must include this file in your submission)
   * Star.h
   * Star.cpp
   * makefile
      * executable should be called: lab2
         * _do not add a .exe extension_

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

_These commands all presume that your current working directory is within the directory tracked by `git`._

You will need to do the following when your submission is ready for grading.
```shell
git commit -am "final commit"
git push
```

To complete your submission, you must copy and paste the commit hash into MyCourses. Go to MyCourses, select CS110, and then assignments. Select Lab 2, and where it says text submission, paste your commit hash. You can get your latest commit hash with the following command:

```shell
git rev-parse HEAD
```

:warning: Remember, you __MUST__ make a submission on mycourses before the deadline to be considered on time.
