#include "YoungNinja.hpp"
using namespace ariel;
/**
@brief Constructs an YoungNinja object with the given name and location.
It also sets the initial hit points to 100 and the speed to 14.
@param Name The name of the YoungNinja.
@param location The location of the YoungNinja.
*/
YoungNinja::YoungNinja(string Name, Point location) : Ninja(Name, location, 100, 14)
{
}
