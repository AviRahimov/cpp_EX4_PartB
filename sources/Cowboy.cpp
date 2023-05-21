#include "Cowboy.hpp"
using namespace ariel;
/**
@brief Constructs a Cowboy object with the given name and location.
It also sets the initial hit points to 110 and the number of bullets to 6.
@param Name The name of the Cowboy.
@param location The location of the Cowboy.
*/
Cowboy::Cowboy(string Name, Point location) : Character(Name, location, 110), num_of_bullets(6)
{
}
/**

@brief Prints the Cowboy's information.
@return A string representing the Cowboy's information.
*/
string Cowboy::print() const
{
    string to_print = "";
    to_print += "C(" + this->name + ")";
    if (this->isAlive())
    {
        to_print += " Hit_points: " + to_string(hit_points);
    }
    to_print += " Location: (" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";
    return to_print;
}
/**

@brief Shoots the enemy Character.
@param enemy A pointer to the enemy Character.
@throws std::runtime_error if the Cowboy or the enemy is dead, or if the Cowboy tries to shoot himself.
*/
void Cowboy::shoot(Character *enemy)
{
    if (!(this->isAlive()))
    {
        throw runtime_error("Cowboy can't attack when he is dead");
    }
    if (!(enemy->isAlive()))
    {
        throw runtime_error("Cowboy can't attack when the enemy is dead");
    }
    if (this == enemy)
    {
        throw runtime_error("Cowboy can't slash himself");
    }
    if (this->hasboolets())
    {
        enemy->hit(10);
        this->num_of_bullets -= 1;
    }
}
/**

@brief Checks if the Cowboy has bullets.
@return True if the Cowboy has bullets, false otherwise.
*/
bool Cowboy::hasboolets() const
{
    return (this->num_of_bullets > 0);
}
/**

@brief Reloads the Cowboy's bullets.
@throws std::runtime_error if the Cowboy is dead.
*/
void Cowboy::reload()
{
    if (!(this->isAlive()))
    {
        throw runtime_error("Dead cowboy can't reload");
    }
    this->num_of_bullets = 6;
}
/**

@brief Gets the number of bullets the Cowboy has.
@return The number of bullets.
*/
int Cowboy::getBullets() const
{
    return this->num_of_bullets;
}
