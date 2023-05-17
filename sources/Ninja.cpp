#include <iostream>
#include "Ninja.hpp"
using namespace ariel;
using namespace std;

Ninja :: Ninja(string name , Point location , int speed , int points):
Character(location , name , points) , speed(speed){}

void Ninja :: move(Character* enemy){
    Point::moveTowards(this->location ,enemy->getLocation() ,speed);
}
void Ninja ::slash(Character* enemy){
    if(location.distance(enemy->getLocation()) < 1){
        enemy->hit(40);
    }
}
int Ninja :: getSpeed()const{
    return speed;
}
string Ninja:: print(){
     string output = "N ("+name+") location: "+ location.print();
    if(isAlive()){
        output +=" points: "+to_string(points);
    }
    return output;
}