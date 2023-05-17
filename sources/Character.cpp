#include "Character.hpp"
#include <iostream>

using namespace ariel;

Character::Character(string Name, Point &location, int hit_points) : name(Name), loc(location), hit_points(hit_points){}

bool Character::isAlive() const{
    return (this->hit_points>0);
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

bool Character::IsInTeam(){
    return this->isInTeam;
}

void Character::setIsInTeam(bool set_team){
    this->isInTeam = set_team;
}