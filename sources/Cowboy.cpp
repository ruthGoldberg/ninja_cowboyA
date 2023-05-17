#include <iostream>
#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy :: Cowboy(string name, Point location):
Character(location,name,110) ,bullets(6){}

void Cowboy:: shoot(Character* enemy){
    if(isAlive() && hasboolets()){
        enemy->hit(10);
        bullets--;
    }else{
        throw runtime_error("Cowboy is not Alive or does not left any bullents");
    }
}
bool Cowboy:: hasboolets(){
    return bullets > 0;
}
void Cowboy:: reload(){
    bullets += 6;
}
int Cowboy :: getBullets()const{
    return bullets;
}
//TODO: print function
string Cowboy ::print(){
    string output = "C ("+name+") location: "+ location.print();
    if(isAlive()){
        output +=" points: "+to_string(points);
    }
    return output;
}