//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_CHARACTER_HPP
#define CPP_EX4_PARTA_CHARACTER_HPP


#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    protected:
        // Character location
        Point loc;
        int hit_points;
        string name;
        bool isInTeam = false;

    public:
        // Initializer constructor with the name of the Character and his location in the board and
        // number of hit points
        Character(string Name, Point &location, int hit_points);
        // Destructor to free allocated memory must be virtual because there are classes that inherit
        // from this class
        virtual ~Character() = default;
        // Checking if the charcter is still alive or not
        virtual bool isAlive() const;
        // Calculating the distance between the locations of this object and other
        virtual double distance(Character* other);
        // Getting hit from some Character and in result reduce the hit_points
        virtual void hit(int hitting_points);
        virtual string getName();
        virtual Point getLocation() const;
        virtual int getHP();
        virtual string print() const = 0;
        virtual bool IsInTeam();
        virtual void setIsInTeam(bool set_team);
    };
}

#endif // CPP_EX4_PARTA_CHARACTER_HPP
