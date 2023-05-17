#pragma once
#include "Ninja.hpp"
namespace ariel{
    class OldNinja : public Ninja
    {
    private:
        /* data */
    public:
        OldNinja(string name , Point location);
        //~OldNinja();
        void move(Character* enemy);
        void slash(Character* enemy);
        string print();
    };
    
}
    