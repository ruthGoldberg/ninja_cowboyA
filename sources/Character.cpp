#include <iostream>
#include "Character.hpp"
using namespace ariel;
using namespace std;

Character :: Character(Point local , string name , int points):
location(local),name(name),points(points){}
bool Character :: isAlive(){
    return points > 0;
}
double Character :: distance(Character& other){
    return location.distance(other.location);
}
void Character ::hit(int points){
    if(this->points < points){
        this->points = 0;
    }else{
        this->points-=points;
    }
}
string Character ::getName()const{
    return name;
}
Point Character ::getLocation()const{
    return location;
}

int Character:: getPoints()const{
    return points;
}
