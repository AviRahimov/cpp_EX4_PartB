//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_TEAM_HPP
#define CPP_EX4_PARTA_TEAM_HPP

#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
#include <cmath>
namespace ariel
{
    class Team
    {
    private:
        Character *leader;
        vector<Character *> war;

    public:
        // Constructor
        Team(Character *character);
        virtual ~Team();
        void add(Character *warrior);
        virtual void attack(Team *enemies);
        virtual int stillAlive();
        virtual void print();
        vector<Character *> &getWarriors();
        Character *getLeader();
        void setLeader(Character *new_leader);
        Character *Nearest_to_leader(Team *team, Character *leader);
    };
}

#endif // CPP_EX4_PARTA_TEAM_HPP
