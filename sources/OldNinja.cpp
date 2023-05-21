#include "OldNinja.hpp"
using namespace ariel;
/**
@brief Constructs an OldNinja object with the given name and location.
It also sets the initial hit points to 150 and the speed to 8.
@param Name The name of the OldNinja.
@param location The location of the OldNinja.
*/
OldNinja::OldNinja(string Name, Point location): Ninja(Name, location, 150, 8){
}
