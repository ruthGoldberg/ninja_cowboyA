#include "doctest.h"
#include "sources/Team.hpp"
using namespace ariel;

TEST_CASE("Initialize Characters"){
    Cowboy bob("bob",Point(1,1));
    YoungNinja alice("alice", Point(10,10));
    TrainedNinja fredy("fredy", Point(8,5));
    OldNinja david("david" , Point(-3,6));  

    CHECK_EQ(bob.getName(), "bob");
    CHECK_EQ(alice.getName(), "alice");
    CHECK_EQ(fredy.getName(), "fredy");
    CHECK_EQ(david.getName(), "david");  

    CHECK_EQ(bob.getLocation().print() , "(1,1)");
    CHECK_EQ(alice.getLocation().print() , "(10,10)");
    CHECK_EQ(fredy.getLocation().print() , "(8,5)");
    CHECK_EQ(david.getLocation().print() , "(-3,6)");

    CHECK_EQ(bob.isAlive() ,1);
    CHECK_EQ(alice.isAlive() ,1);
    CHECK_EQ(fredy.isAlive() ,1);
    CHECK_EQ(david.isAlive() ,1);

    CHECK_EQ(bob.getPoints() ,110);
    CHECK_EQ(alice.getPoints() ,100);
    CHECK_EQ(fredy.getPoints() ,120 );
    CHECK_EQ(david.getPoints() ,150);
    
}

TEST_CASE("hit"){
    Cowboy bob("bob",Point(1,1));
    YoungNinja alice("alice", Point(10,10));
    TrainedNinja fredy("fredy", Point(8,5));
    OldNinja david("david" , Point(-3,6)); 

    bob.hit(5);
    CHECK_EQ(bob.getPoints() ,105);
    alice.hit(40);
    CHECK_EQ(alice.getPoints() ,60);
    fredy.hit(30);
    CHECK_EQ(fredy.getPoints() ,90 );
    david.hit(180);
    CHECK_EQ(david.getPoints() ,0);
}

TEST_CASE("moveTowards"){
    Point a(1,1) , b(1,-9);
    double distance =a.distance(b);
    CHECK_THROWS(Point::moveTowards(a,b,-5));
    Point c = Point::moveTowards(a,b,distance/2);
    CHECK_LE(c.distance(b) ,distance/2);
}

TEST_CASE("distance"){
    Cowboy bob("bob",Point(1,1));
    YoungNinja alice("alice", Point(10,10));
    TrainedNinja fredy("fredy", Point(8,5));
    OldNinja david("david" , Point(-3,6)); 
    CHECK_EQ(bob.distance(alice) , alice.distance(bob));
    CHECK_EQ(bob.distance(fredy) , fredy.distance(bob));
    CHECK_EQ(david.distance(alice) ,alice.distance(david));
}
TEST_SUITE("Cowboy") {
    Cowboy bob("bob",Point(1,1));
    YoungNinja alice("alice", Point(10,10));

    TEST_CASE("shoot function"){
        while(bob.getBullets()){
            CHECK_NOTHROW( bob.shoot(&alice));
        }
        CHECK_THROWS(bob.shoot(&alice));
        CHECK_EQ(alice.getPoints(),40);
    }

    TEST_CASE("Hashboolets and reload"){
        CHECK_EQ(bob.hasboolets() , 0);
        bob.reload();
        CHECK_EQ(bob.hasboolets() , 1);
        CHECK_EQ(bob.getBullets(), 6);
        CHECK_EQ(bob.print() , "C (bob) location: (1,1) points: 110");
    }
}
TEST_SUITE("Ninja"){
        YoungNinja alice("alice", Point(10,10));
        TrainedNinja fredy("fredy", Point(8,5));
        OldNinja david("david" , Point(-3,6));

    TEST_CASE("move and speed"){
        

        double AFdistance = alice.distance(fredy);
        double ADdistance = alice.distance(david);
        double FDdistance = fredy.distance(david);

        alice.move(&fredy);
        david.move(&alice);
        fredy.move(&david);

        CHECK_LE( alice.distance(fredy) , AFdistance - 14);
        CHECK_LE( alice.distance(david) , AFdistance - 8);
        CHECK_LE( david.distance(fredy) , AFdistance - 12);

        CHECK_EQ(alice.getSpeed() , 14);
        CHECK_EQ(fredy.getSpeed() , 12);
        CHECK_EQ(david.getSpeed() , 8);

    }

    TEST_CASE("slash"){
        Cowboy bob("bob",Point(1,1));
        YoungNinja shon("shon" ,Point(0.5,0.5));
        shon.slash(&bob);
        CHECK_EQ(bob.getPoints() , 70);
        shon.slash(&fredy);
        CHECK_EQ(fredy.getPoints() , 120);
        CHECK_EQ(shon.print() , "N (shon) location: (0.5,0.5) points: 100");
    }

}

TEST_SUITE("Team"){
    TEST_CASE("Initailize"){
        Cowboy bob("bob",Point(1,1));
        Team team(&bob);
        CHECK_EQ(team.getLeader()->getName() , "bob");
    }
}

