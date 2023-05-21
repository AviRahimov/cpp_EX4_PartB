#include "Team.hpp"
using namespace ariel;
/**

Constructor for the Team class.
Creates a new team with the given character as the leader.
@param character A pointer to the character to be set as the leader of the team.
@throws runtime_error if the leader character is already in another team.
*/
Team::Team(Character *character) : leader(character)
{
    this->war.clear();
    this->war.push_back(leader);
    if (this->leader->IsInTeam())
    {
        throw runtime_error("This leader is already in another team");
    }
    this->leader->setIsInTeam(true);
}

/**
 * Destructor for the Team class.
 * Deletes all the character objects stored in the war vector.
 */
Team::~Team()
{
    for (size_t i = 0; i < war.size(); i++)
    {
        delete war.at(i);
    }
}

/**
 * Adds a warrior to the team.
 * Throws an exception if the warrior is already in another team or if the team is already full.
 * @param warrior A pointer to the warrior to be added.
 */
void Team::add(Character *warrior)
{
    if (warrior->IsInTeam())
    {
        throw runtime_error("The warrior is in another team");
    }
    if (this->war.size() >= 10)
    {
        throw runtime_error("The team is full");
    }
    warrior->setIsInTeam(true);
    this->war.push_back(warrior);
}

/**
 * Performs an attack on an enemy team.
 * Throws an exception if the enemy team is null, if the current team has no warriors,
 * if the enemy team has no warriors, or if the enemy team is the same as the current team.
 * @param enemies A pointer to the enemy team to be attacked.
 * run over all Cowboys and then over all the Ninjas.
 */
void Team::attack(Team *enemies)
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
    if (!(leader->isAlive()))
    {
        leader->setIsInTeam(false);
        this->setLeader(Nearest_to_leader(this, leader));
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
    Character *victim = Nearest_to_leader(enemies, this->leader);
    if (!victim)
    {
        return;
    }
    // Attack victim with all living members
    for (auto warrior : war)
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
        if ((dynamic_cast<Cowboy *>(warrior) != nullptr) && (dynamic_cast<Cowboy *>(warrior)->hasboolets()))
        {
            // Cowboy with bullets shoots victim
            dynamic_cast<Cowboy *>(warrior)->shoot(victim);
        }
        else if (dynamic_cast<Cowboy *>(warrior) != nullptr)
        {
            // Cowboy without bullets loads gun
            dynamic_cast<Cowboy *>(warrior)->reload();
        }
    }
    for (auto warrior : war)
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
        if (dynamic_cast<Ninja *>(warrior) != nullptr && warrior->distance(victim) <= 1)
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
 * Finds the nearest character to the leader in a given team.
 * @param team A pointer to the team to search in.
 * @param leader A pointer to the leader character.
 * @return A pointer to the nearest character to the leader.
 */
Character *Team::Nearest_to_leader(Team *team, Character *leader)
{
    // Find closest living character to dead leader
    Character *closest = nullptr;
    double min_dist = INFINITY;
    for (auto warrior : team->getWarriors())
    {
        if ((warrior->isAlive()) && (warrior != leader))
        {
            double dist = leader->distance(warrior);
            if (dist < min_dist)
            {
                closest = warrior;
                min_dist = dist;
            }
        }
    }
    return closest;
}

/**
 * Counts the number of alive warriors in the team.
 * @return The number of alive warriors in the team.
 */
int Team::stillAlive()
{
    int num_alive = 0;

    // Traverse the vector in reverse order
    for (auto it = war.rbegin(); it != war.rend(); ++it)
    {
        // Check if the character is alive and if it's a cowboy
        if (*it && (*it)->getHP() > 0 && dynamic_cast<Cowboy *>(*it))
        {
            num_alive++;
        }
    }

    // Traverse the vector in reverse order again
    for (auto it = war.rbegin(); it != war.rend(); ++it)
    {
        // Check if the character is alive and if it's a ninja
        if (*it && (*it)->getHP() > 0 && dynamic_cast<Ninja *>(*it))
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
void Team::print()
{
    // Traverse the vector in reverse order
    for (auto it = war.rbegin(); it != war.rend(); ++it)
    {
        // Check if the character is alive and if it's a cowboy
        if (dynamic_cast<Cowboy *>(*it))
        {
            cout << (*it)->print() << endl;
        }
    }

    // Traverse the vector in reverse order again
    for (auto it = war.rbegin(); it != war.rend(); ++it)
    {
        // Check if the character is alive and if it's a ninja
        if (dynamic_cast<Ninja *>(*it))
        {
            cout << (*it)->print() << endl;
        }
    }
}

/**
 * Retrieves the vector of warriors in the team.
 * @return A reference to the vector of warriors in the team.
 */
vector<Character *> &Team::getWarriors()
{
    return this->war;
}

/**
 * Retrieves the leader character of the team.
 * @return A pointer to the leader character.
 */
Character *Team::getLeader()
{
    return this->leader;
}

/**
 * Sets a new leader character for the team.
 * @param new_leader A pointer to the new leader character.
 */
void Team::setLeader(Character *new_leader)
{
    this->leader = new_leader;
}
