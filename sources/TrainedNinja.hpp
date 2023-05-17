#pragma once
#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja : public Ninja
    {
    private:
        /* data */
    public:
        TrainedNinja(string name , Point location);
        //~TrainedNinja();
       string print();
       
    };
    
}