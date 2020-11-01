#include "Turtle.h"

//Base empty constructor
Turtle::Turtle() : Turtle("Unknown", 0) {}
//constructor with parameters
Turtle::Turtle(std::string shell, int hits)
{
    _hitpoints = hits;
    _shell = shell;
}

std::string Turtle::getshell() //return shell color
{
    return _shell;
}
int Turtle::getHitPoints()
{ //return Hit Points
    return _hitpoints;
}

void Turtle::toString() //display turtle shell color and hit points
{
    std::cout << "This Turtle's Shell color is: " << _shell << ", and it has " << _hitpoints << " hitpoints left." << std::endl;
}

void Turtle::operator=(const Turtle &s)
{
    this->_hitpoints = s._hitpoints;
    this->_shell = s._shell;
}
bool operator<(const Turtle &s, const Turtle &t)
{

    if (s._shell < t._shell)
    {
        return true;
    }
    else if (s._shell == t._shell && s._hitpoints < t._hitpoints)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const Turtle &s, const Turtle &t)
{

    if (s._shell > t._shell)
    {
        return true;
    }
    else if (s._shell == t._shell && s._hitpoints > t._hitpoints)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(const Turtle &s, const Turtle &t)
{
    return s._shell == t._shell;
}