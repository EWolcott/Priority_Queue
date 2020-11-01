#include "Student.h"

//Base empty constructor
Student::Student() : Student("Unknown", "Not Enrolled", 0) {}
//constructor with parameters
Student::Student(std::string name, std::string course, int number)
{
    _name = name;
    _idnumber = number;
    _course = course;
}

std::string Student::getName() //return name
{
    return _name;
}
int Student::getNumber()
{ //return student number
    return _idnumber;
}

void Student::toString() //display student name, course, and number
{
    std::cout << _name << ", Course: " << _course << ", ID Number: " << _idnumber << std::endl;
}

std::string Student::getcourse()
{ //return course
    return _course;
}

void Student::operator=(const Student &s)
{
    this->_course = s._course;
    this->_idnumber = s._idnumber;
    this->_name = s._name;
}
bool operator<(const Student &s, const Student &t)
{

    if (s._course < t._course)
    {
        return true;
    }
    else if (s._course == t._course && s._idnumber < t._idnumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const Student &s, const Student &t)
{

    if (s._course > t._course)
    {
        return true;
    }
    else if (s._course == t._course && s._idnumber > t._idnumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(const Student &s, const Student &t)
{
    return s._idnumber == t._idnumber;
}