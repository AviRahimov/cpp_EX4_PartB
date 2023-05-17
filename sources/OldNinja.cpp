#include "OldNinja.hpp"
using namespace ariel;

OldNinja::OldNinja(string Name, Point location): Ninja(Name, location, 150, 8){
}

// void OldNinja::move(Character* enemy){
//     this->loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
// }