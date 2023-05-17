#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string Name, Point location) : Character(Name, location, 110), num_of_bullets(6)
{
}

string Cowboy::print() const{
    string to_print = "";
    to_print += "C(" + this->name + ")";
    if(this->isAlive()){
        to_print += " Hit_points: " + to_string(hit_points);
    }
    to_print += " Location: (" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";
    return to_print;
}

void Cowboy::shoot(Character* enemy){
    if(!(this->isAlive()) || !(enemy->isAlive())){
        throw runtime_error("Cowboy can't attack when he or the enemy is dead");
    }
    if(this == enemy){
        throw runtime_error("Cowboy can't slash himself");
    }
    if(this->hasboolets()){
        enemy->hit(10);
        this->num_of_bullets-=1;
    }
}

bool Cowboy::hasboolets(){
    return (this->num_of_bullets > 0);
}

void Cowboy::reload(){
    if(!(this->isAlive())){
        throw runtime_error("Dead cowboy can't reload");
    }
    this->num_of_bullets = 6;
}

int Cowboy::getBullets(){
    return this->num_of_bullets;
}