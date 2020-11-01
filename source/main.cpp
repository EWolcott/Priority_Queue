#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "heap.h"
#include "pqueue.h"
#include "Student.h"
#include "Turtle.h"

std::string getShell()
{
    std::vector<std::string> _shells;
    _shells = {"Red", "Blue", "Yellow", "Green", "Purple"};
    std::string shell = _shells[rand() % 5];
    return shell;
}

std::string getname()
{
    std::vector<std::string> _firstNames;
    std::vector<std::string> _lastNames;

    _firstNames = {"Roy", "Wyatt", "Owen", "Herschel", "Bill", "Florencio", "Guy", "Renato", "Octavio", "Alexis",
                   "Gaylord", "Kyle", "Danny", "Aurelio", "Wilfredo", "Mel", "Rosario", "Clay", "Max", "Dino", "Elvin",
                   "Donnell", "Darrell", "Seymour", "Chong", "Lionel", "Noel", "Victor", "Marc", "Trevor", "Rusty", "Russ",
                   "Jonathan", "Chris", "Chauncey", "Emmitt", "Antony", "Deandre", "Anthony", "Raymond", "Eliseo", "Kris",
                   "Travis", "Felton", "Britt", "Pierre", "Patrick", "Mauro", "Erwin", "Gregorio"};
    _lastNames = {"Parrish", "Garner", "Blackwell", "Valentine", "Guerra", "Cox", "Kirk", "Clements", "Pratt",
                  "Coffey", "Romero", "Mayo", "Patel", "Page", "Oneal", "Bowen", "Chapman", "Buchanan", "Schmitt", "Mckee",
                  "Foster", "Collier", "Shea", "Velez", "Booth"};

    std::string first = _firstNames[rand() % 50];
    std::string last = _lastNames[rand() % 25];
    std::string name = first + " " + last;
    return name;
}

std::string getcourse()
{
    std::vector<std::string> _courses;
    _courses = {"Philosophy", "Business", "Computer Science", "English", "Biology"};
    std::string course = _courses[rand() % 5];
    return course;
}

int getid()
{
    int id = ((rand() % 9999999) + 1000);
    return id;
}

//Pete Tucker's Person class
class Person
{
private:
    std::string _name;
    int _age;

public:
    Person(std::string name, int age) : _name(name), _age(age) {}
    std::string getName() const { return _name; }
    int getAge() const { return _age; }
    bool operator<(const Person &other) const
    {
        if (_name < other._name)
        {
            return true;
        }
        else if (_name == other._name && _age < other._age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//Pete Tucker's overloaded operator
std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.getName() << " (" << p.getAge() << ")";
    return os;
}

int main()
{
    std::string names[] = {"Amy", "Ben", "Catherine", "Daniel", "Emily", "Fred"};
    cs273::priority_queue<Person> pq;
    srand(time(NULL));
    while (pq.size() < 15)
    {
        Person p = Person(names[rand() % 6], rand() % 75 + 25);
        pq.push(p);
    }

    while (!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    cs273::priority_queue<Student> stq;

    while (stq.size() < 15)
    {
        Student s = Student(getname(), getcourse(), getid());
        stq.push(s);
    }

    Student tmp;
    while (!stq.empty())
    {
        tmp = stq.top();
        tmp.toString();
        stq.pop();
    }

    cs273::priority_queue<Turtle> tq;

    while (tq.size() < 15)
    {
        Turtle s = Turtle(getShell(), getid());
        tq.push(s);
    }

    Turtle temp;
    while (!tq.empty())
    {
        temp = tq.top();
        temp.toString();
        tq.pop();
    }
}