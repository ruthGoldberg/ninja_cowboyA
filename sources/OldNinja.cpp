#include <iostream>
#include "OldNinja.hpp"
using namespace ariel;
using namespace std;

OldNinja :: OldNinja(string name , Point location):
Ninja(name , location ,8 ,150){}
void OldNinja :: move(Character* enemy){}
void OldNinja :: slash(Character* enemy){}
string OldNinja:: print(){
    return "old";
}