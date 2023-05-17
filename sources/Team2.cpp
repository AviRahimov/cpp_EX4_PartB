#include "Team2.hpp"
using namespace ariel;

Team2::Team2(Character* character) : Team(character){

}

// Team2::~Team2(){

// }

void Team2::attack(Team* enemies){
    if(enemies == nullptr){
        throw invalid_argument("enemies must be with at least one character");
    }
    // Check if leader is alive
    if (this->getLeader()->getHP() <= 0)
    {
        this->getLeader()->setIsInTeam(false);
        // Find closest living character to dead leader
        Character* closest = nullptr;
        double min_dist = INFINITY;
        for (auto warrior : this->getWarriors())
        {
            if (warrior->getHP() > 0)
            {
                double dist = this->getLeader()->distance(warrior);
                if (dist < min_dist)
                {
                    closest = warrior;
                    min_dist = dist;
                }
            }
        }
        this->setLeader(closest);
    }
    // Find closest living enemy to leader
    Character* victim = nullptr;
    double min_dist = INFINITY;
    for (auto enemy : enemies->getWarriors())
    {
        if (enemy->getHP() > 0)
        {
            double dist = this->getLeader()->distance(enemy);
            if (dist < min_dist)
            {
                victim = enemy;
                min_dist = dist;
            }
        }
    }
    // Attack victim with all living members
    for (auto warrior : this->getWarriors())
    {
        if (warrior->getHP() <= 0)
        {
            continue;
        }
        if (dynamic_cast<Cowboy*>(warrior) != nullptr && dynamic_cast<Cowboy*>(warrior)->getBullets() > 0)
        {
            // Cowboy with bullets shoots victim
            dynamic_cast<Cowboy*>(warrior)->shoot(victim);
        }
        else if (dynamic_cast<Cowboy*>(warrior) != nullptr)
        {
            // Cowboy without bullets loads gun
            dynamic_cast<Cowboy*>(warrior)->reload();
        }
        else if (dynamic_cast<Ninja*>(warrior) != nullptr && warrior->distance(victim) <= 1)
        {
            // Ninja within 1m of victim kills victim
            dynamic_cast<Ninja*>(warrior)->slash(victim);
        }
        else if (dynamic_cast<Ninja*>(warrior) != nullptr)
        {
            // Ninja further than 1m from victim moves closer
            dynamic_cast<Ninja*>(warrior)->move(victim);
        }
    }
    // Check if victim is dead
    if (victim->getHP() <= 0)
    {
        // Find new victim
        victim = nullptr;
        min_dist = INFINITY;
        for (auto enemy : enemies->getWarriors())
        {
            if (enemy->getHP() > 0)
            {
                double dist = this->getLeader()->distance(enemy);
                if (dist < min_dist)
                {
                    victim = enemy;
                    min_dist = dist;
                }
            }
        }
    }
    // // Recursive call to attack if still alive enemies and attackers
    // if (stillAlive() > 0 && enemies->stillAlive() > 0)
    // {
    //     attack(enemies);
    // }
}

int Team2::stillAlive(){
    int num_alive = 0;

    // Traverse the vector in reverse order
    for (auto it = this->getWarriors().rbegin(); it != this->getWarriors().rend(); ++it) {
        // Check if the character is alive and if it's a cowboy
        if (*it && (*it)->getHP() > 0) {
            num_alive++;
        }
    }

    return num_alive;
}

void Team2::print(){
    // Traverse the vector in reverse order
    for (auto it = this->getWarriors().rbegin(); it != this->getWarriors().rend(); ++it) {
        // Check if the the character is not nullptr and alive
        if((*it) && (*it)->isAlive()){
            cout << (*it)->print() << endl;
        }
    }
}