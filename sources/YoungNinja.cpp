#include "YoungNinja.hpp"
using namespace ariel;

YoungNinja::YoungNinja(string Name, Point location) : Ninja(Name, location, 100, 14){
}

// void YoungNinja::move(Character* enemy){
//     this->loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);    
// }