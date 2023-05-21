#include "Character.hpp"
#include <iostream>

using namespace ariel;
/**

@brief Constructs a Character object with the given name and location.
@param Name The name of the Character.
@param location The location of the Character.
*/
Character::Character(string Name, Point &location, int hit_points) : name(Name), loc(location), hit_points(hit_points){}
/**

@brief Checks if the Character is alive.
@return True if the Character's hit points are greater than 0, false otherwise.
*/
bool Character::isAlive() const{
    return (this->hit_points>0);
}
/**

@brief Calculates the distance between the current Character and another Character.
@param other A pointer to the other Character.
@return The distance between the current Character and the other Character.
*/
double Character::distance(Character*other){
    return this->loc.distance(other->getLocation());
}
/**

@brief Reduces the hit points of the Character by a specified amount.
@param hitting_points The number of hit points to subtract.
@throws std::invalid_argument if hitting_points is negative.
*/
void Character::hit(int hitting_points){
    if(hitting_points<0){
        throw invalid_argument("hitting points can't be negative");
    }
    this->hit_points-=hitting_points;
}
/**

@brief Gets the name of the Character.
@return The name of the Character.
*/
string Character::getName(){
    return this->name;
}
/**

@brief Gets the location of the Character.
@return The location of the Character.
*/
Point Character::getLocation() const{
    return this->loc;
}
/**

@brief Gets the hit points of the Character.
@return The hit points of the Character.
*/
int Character::getHP(){
    return this->hit_points;
}
/**

@brief Checks if the Character is in a team.
@return True if the Character is in a team, false otherwise.
*/
bool Character::IsInTeam(){
    return this->isInTeam;
}
/**

@brief Sets whether the Character is in a team or not.
@param set_team True to set the Character in a team, false otherwise.
*/
void Character::setIsInTeam(bool set_team){
    this->isInTeam = set_team;
}
