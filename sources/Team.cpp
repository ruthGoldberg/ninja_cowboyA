 #include <iostream>
#include "Team.hpp"
using namespace ariel;
using namespace std;
 
Team ::Team(Character* leader): leader(leader){
    players.fill(leader);
}
void Team ::add(Character* player){
    players.fill(player);
}
void Team ::attack(Team* against ){
    for(size_t i = 0 ; i < 10 ; i++){
        if(players.at(i)->isAlive())
            players.at(i)->hit(10);
    }
}
int Team ::stillAlive(){
    int alive = 0;
    for(size_t i = 0 ; i < 10 ; i++){
        if(players.at(i)->isAlive())
            alive++;
    }
    return alive;
}
void Team ::print(){
    //TODO
}
Character* Team:: getLeader()const{
    return leader;
}