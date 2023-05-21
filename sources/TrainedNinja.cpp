#include "TrainedNinja.hpp"
using namespace ariel;
/**
@brief Constructs an TrainedNinja object with the given name and location.
It also sets the initial hit points to 120 and the speed to 12.
@param Name The name of the TrainedNinja.
@param location The location of the TrainedNinja.
*/
TrainedNinja::TrainedNinja(string Name, Point location) : Ninja(Name, location, 120, 12)
{
}
