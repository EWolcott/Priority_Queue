#ifndef TURTLE_H
#define TURTLE_H

#include <string>
#include <iostream>
#include <typeinfo>
//Turtle class
class Turtle
{
public:
    int _hitpoints;     //track number
    std::string _shell; //track course

    //Base empty constructor
    Turtle();
    //constructor with parameters
    Turtle(std::string shell, int hits);

    int getHitPoints();     //return hit points
    void toString();        //display turtle info
    std::string getshell(); //display shell
    void operator=(const Turtle &);
    friend bool operator<(const Turtle &, const Turtle &);
    friend bool operator>(const Turtle &, const Turtle &);
    friend bool operator==(const Turtle &, const Turtle &);
};

#endif