//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_TEAM2_HPP
#define CPP_EX4_PARTA_TEAM2_HPP

#include "Team.hpp"
#include <vector>

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *character);
        ~Team2() = default;
        void attack(Team *enemies) override;
        int stillAlive() override;
        void print() override;
    };
}

#endif // CPP_EX4_PARTA_TEAM2_HPP
