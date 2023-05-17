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
const unsigned int NUM_WARRIORS = 10;
namespace ariel
{
    class Team
    {
    private:
        Character *leader;
        vector<Character *> war{NUM_WARRIORS};

    public:
        // Constructor
        Team(Character *character);
        // Copy constructor
        Team(Team &other);
        // Move constructor
        Team(Team &&other) noexcept;
        // Move assignment operator
        Team &operator=(Team &&other) noexcept;
        // Copy assignment operator
        Team &operator=(const Team &other);
        ~Team() = default;
        void add(Character *warrior);
        virtual void attack(Team *enemies);
        virtual int stillAlive();
        virtual void print();
        vector<Character *> &getWarriors();        
        Character *getLeader();
        void setLeader(Character *new_leader);
        Character* Nearest_to_leader(Team* team, Character* leader);
    };
}

#endif // CPP_EX4_PARTA_TEAM_HPP
