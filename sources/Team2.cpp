#include "Team2.hpp"
using namespace ariel;

Team2::Team2(Character *character) : Team(character)
{
}
/**
 * Performs an attack on an enemy team.
 * Throws an exception if the enemy team is null, if the current team has no warriors,
 * if the enemy team has no warriors, or if the enemy team is the same as the current team.
 * @param enemies A pointer to the enemy team to be attacked.
 * run over the war vector in a simple way i.e. without seperating the Ninjas and Cowboys.
 */
void Team2::attack(Team *enemies)
{
    if (enemies == nullptr)
    {
        throw invalid_argument("enemies must be with at least one character");
    }
    if (this->stillAlive() == 0)
    {
        throw std::invalid_argument("Team can't attack with no warriors");
    }
    if (enemies->stillAlive() == 0)
    {
        throw std::runtime_error("Can't attack team with no warriors");
    }
    if (enemies == this)
    {
        throw std::invalid_argument("There is no internal kills");
    }
    // Check if leader is alive
    if (!(this->getLeader()->isAlive()))
    {
        this->getLeader()->setIsInTeam(false);
        this->setLeader(Nearest_to_leader(this, this->getLeader()));
    }
    // Find closest living enemy to leader
    if (!(enemies->getLeader()->isAlive()))
    {
        enemies->getLeader()->setIsInTeam(false);
        enemies->setLeader(Nearest_to_leader(enemies, enemies->getLeader()));
    }
    if ((enemies->getLeader() == nullptr) || (this->getLeader() == nullptr))
    {
        return;
    }
    Character *victim = Nearest_to_leader(enemies, this->getLeader());
    if (!victim)
    {
        return;
    }
    // Attack victim with all living members
    for (auto warrior : this->getWarriors())
    {
        if ((enemies->stillAlive() == 0) || (this->stillAlive() == 0))
        {
            return;
        }
        if (!(warrior->isAlive()))
        {
            continue;
        }
        if (!(victim->isAlive()))
        {
            victim = Nearest_to_leader(enemies, victim);
        }
        if (dynamic_cast<Cowboy *>(warrior) != nullptr && dynamic_cast<Cowboy *>(warrior)->getBullets() > 0)
        {
            // Cowboy with bullets shoots victim
            dynamic_cast<Cowboy *>(warrior)->shoot(victim);
        }
        else if (dynamic_cast<Cowboy *>(warrior) != nullptr)
        {
            // Cowboy without bullets loads gun
            dynamic_cast<Cowboy *>(warrior)->reload();
        }
        else if (dynamic_cast<Ninja *>(warrior) != nullptr && warrior->distance(victim) <= 1)
        {
            // Ninja within 1m of victim kills victim
            dynamic_cast<Ninja *>(warrior)->slash(victim);
        }
        else if (dynamic_cast<Ninja *>(warrior) != nullptr)
        {
            // Ninja further than 1m from victim moves closer
            dynamic_cast<Ninja *>(warrior)->move(victim);
        }
    }
}
/**
 * Counts the number of alive warriors in the team.
 * @return The number of alive warriors in the team.
 */
int Team2::stillAlive()
{
    int num_alive = 0;

    // Traverse the vector in reverse order
    for (auto it = this->getWarriors().rbegin(); it != this->getWarriors().rend(); ++it)
    {
        // Check if the character is alive and if it's a cowboy
        if (*it && (*it)->getHP() > 0)
        {
            num_alive++;
        }
    }

    return num_alive;
}
/**
 * Prints the characters in the team.
 * Characters are printed in the reverse order of their insertion into the team vector.
 */
void Team2::print()
{
    // Traverse the vector in reverse order
    for (auto it = this->getWarriors().rbegin(); it != this->getWarriors().rend(); ++it)
    {
        // Check if the the character is not nullptr and alive
        if ((*it) && (*it)->isAlive())
        {
            cout << (*it)->print() << endl;
        }
    }
}