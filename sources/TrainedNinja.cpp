#include "TrainedNinja.hpp"
using namespace ariel;

TrainedNinja::TrainedNinja(string Name, Point location): Ninja(Name, location, 120, 12){
}

// void TrainedNinja::move(Character* enemy){
//     this->loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
// }