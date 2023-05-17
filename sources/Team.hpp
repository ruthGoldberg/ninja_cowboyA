#pragma once
#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <array>

namespace ariel{
    class Team
    {
    private:
        std::array<Character*,10> players;
        Character* leader;
    public:
        Team(Character* leader);
        // ~Team(){
        //     for(size_t i = 0 ; i < 10 ; i++){
        //         delete players.at(i);
        //     }
        // }
        void add(Character* player);
        void attack(Team* against );
        int stillAlive();
        void print();
        Character* getLeader()const;
    };
    
}