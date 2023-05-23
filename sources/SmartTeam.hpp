//
// Created by avi on 30/04/2023.
//
//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_SmartTeam_HPP
#define CPP_EX4_PARTA_SmartTeam_HPP
#ifndef CPP_EX4_PARTA_SmartTeam_HPP
#define CPP_EX4_PARTA_SmartTeam_HPP

#include "Team.hpp"
#include <vector>
#include "Team.hpp"
#include <vector>

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *character);
        ~SmartTeam() = default;
        void attack(Team *enemies) override;
        vector<Character*> findClosestCharacters(Team* attackerTeam, Team* enemyTeam);
    };
}

#endif // CPP_EX4_PARTA_SmartTeam_HPP
#endif // CPP_EX4_PARTA_SmartTeam_HPP
