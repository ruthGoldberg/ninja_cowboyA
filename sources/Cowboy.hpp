#pragma once
#include "Character.hpp"
namespace ariel{
    class Cowboy : public Character
    {
    private:
        int bullets;
    public:
        Cowboy(string name, Point location);
        //~Cowboy();
        void shoot(Character* enemy);
        bool hasboolets();
        void reload();
        int getBullets()const;
        string print();
        
    };
}

