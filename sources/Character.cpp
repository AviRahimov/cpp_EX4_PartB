#include "Character.hpp"
#include <iostream>

using namespace ariel;

Character::Character(string Name, Point &location) : name(Name), loc(location){}
Character::Character(string Name, Point &location, int hit_points) : name(Name), loc(location), hit_points(hit_points){}
Character::Character(Character& other) : name(other.name), loc(other.loc){

}

// Move constructor
Character::Character(Character&& other) noexcept : loc(other.loc), name(move(other.name))
{
    // Set the other object's location to nullptr to prevent double-free
    other.loc = Point(0, 0);
}

// Move assignment operator
Character& Character::operator=(Character&& other) noexcept
{
    // Check for self-assignment
    if (this == &other)
    {
        return *this;
    }

    // Transfer the other object's resources
    loc = other.loc;
    hit_points = other.hit_points;
    name = std::move(other.name);

    // Set the other object's location to nullptr to prevent double-free
    ;

    return *this;
}


// Character::~Character() = default{
//     // delete;
// }

bool Character::isAlive() const{
    return this->hit_points>0;
}

double Character::distance(Character*other){
    return this->loc.distance(other->getLocation());
}

void Character::hit(int hitting_points){
    if(hitting_points<0){
        throw invalid_argument("hitting points can't be negative");
    }
    this->hit_points-=hitting_points;
}

string Character::getName(){
    return this->name;
}

Point Character::getLocation() const{
    return this->loc;
}

int Character::getHP(){
    return this->hit_points;
}

Character& Character::operator=(const Character& other){
    return *this;
}

bool Character::IsInTeam(){
    return this->isInTeam;
}

void Character::setIsInTeam(bool set_team){
    this->isInTeam = set_team;
}