#include "Ninja.hpp"
using namespace ariel;
/**

@brief Constructs a Ninja object with the given name and location.
The initial hit points and speed are set to default values.
@param Name The name of the Ninja.
@param location The location of the Ninja.
@param hit_points The initial hitting points of the Ninja
@param speed The speed of the Ninja
*/
Ninja::Ninja(string Name, Point location, int hit_points, int speed) : Character(Name, location, hit_points), speed(speed){

}
/**

@brief Prints the Ninja's information.
@return A string representing the Ninja's information.
*/
string Ninja::print() const{
    string to_print = "";
    to_print += "N(" + this->name + ")";
    if(this->isAlive()){
        to_print += " Hit_points: " + to_string(hit_points);
    }
    to_print += " Location: (" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";
    return to_print;
}
/**

@brief Performs a slash attack on the enemy Character.
@param enemy A pointer to the enemy Character.
@throws std::runtime_error if the Ninja or the enemy is dead, or if the Ninja tries to attack himself.
*/
void Ninja::slash(Character* enemy){
    if(!(this->isAlive())){
        throw runtime_error("NInja can't attack when he is dead");
    }
    if(!(enemy->isAlive())){
        throw runtime_error("NInja can't attack when the enemy is dead");
    }
    if(this == enemy){
        throw runtime_error("Ninja can't slash himself");
    }
    if((this->distance(enemy) <= 1)){
        enemy->hit(40);
    }
}
/**

@brief Moves the Ninja towards the enemy Character based on the Ninja's speed.
@param enemy A pointer to the enemy Character.
*/
void Ninja::move(Character* enemy){
    this->loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
}
