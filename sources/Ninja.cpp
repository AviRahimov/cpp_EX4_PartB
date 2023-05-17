#include "Ninja.hpp"
using namespace ariel;

Ninja::Ninja(string Name, Point location) : Character(Name, location){

}
Ninja::Ninja(string Name, Point location, int hit_points, int speed) : Character(Name, location, hit_points), speed(speed){

}
string Ninja::print() const{
    string to_print = "";
    to_print += "N(" + this->name + ")";
    if(this->isAlive()){
        to_print += " Hit_points: " + to_string(hit_points);
    }
    to_print += " Location: (" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";
    return to_print;
}

void Ninja::slash(Character* enemy){
    if(!(this->isAlive()) || !(enemy->isAlive())){
        throw runtime_error("Ninja can't attack when he or the enemy is dead");
    }
    if(this == enemy){
        throw runtime_error("Ninja can't slash himself");
    }
    if((this->distance(enemy) <= 1)){
        enemy->hit(40);
    }
}

void Ninja::move(Character* enemy){
    this->loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
}