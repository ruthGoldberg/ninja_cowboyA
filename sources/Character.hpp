#pragma once
#include <string>
#include "Point.hpp"
using namespace std;
namespace ariel{
class Character
{
    public:
        Point location;
        int points;
        string name;
        Character(Point local , string name ,  int points);
        bool isAlive();
        double distance(Character& other);
        void hit(int points);
        string getName()const;
        Point getLocation()const;
        virtual string print() = 0;
        int getPoints()const;
    };
}


