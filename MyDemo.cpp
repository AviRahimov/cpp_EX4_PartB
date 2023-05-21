#include <iostream>
#include "sources/Team.hpp"

using namespace ariel;
using namespace std;

auto multi_attack = [](int n, Team &attacker, Team &defender)
{
    for (int i = 0; i < n; i++)
    {
        if (defender.stillAlive())
        {
            attacker.attack(&defender);
        }
    }
};

int main()
{
    // Create character locations
    Point p1(10.5, 7.2);
    Point p2(15.8, 12.1);
    Point p3(20.3, 9.6);
    Point p4(5.2, 3.9);
    Point p5(31.7, 50);
    try
    {
        // Create characters
        Character *leader = new Cowboy("John", p1);
        Character *warrior1 = new TrainedNinja("Sam", p2);
        Character *warrior2 = new Cowboy("Mike", p3);
        Character *warrior3 = new OldNinja("Emily", p4);
        Character *warrior4 = new YoungNinja("Trainee", p5);
        // Create a team and add characters to it
        Team team(leader);
        team.add(warrior1);
        team.add(warrior2);
        team.add(warrior3);
        team.add(warrior4);
        // Print the initial team
        cout << "Initial Team:" << endl;
        team.print();

        // Move the leader character
        Point newLocation(12.8, 9.1);
        leader->getLocation().moveTowards(leader->getLocation(), newLocation, 2.5);

        // Attack another team
        Team enemyTeam(new Cowboy("Booker", Point(5.6, 7.1)));
        enemyTeam.add(new YoungNinja("Jake", Point(8.7, 5.4)));
        enemyTeam.add(new Cowboy("Sarah", Point(17.2, 13.5)));

        cout << "Attacking Enemy Team..." << endl;
        team.attack(&enemyTeam);

        // Print the updated teams
        cout << "Updated Team:" << endl;
        team.print();

        cout << "Enemy Team:" << endl;
        enemyTeam.print();

        // team attack enemyTeam 3 times
        multi_attack(3, team, enemyTeam);
        // Print the updated teams
        cout << "Updated Team:" << endl;
        team.print();

        cout << "Enemy Team:" << endl;
        enemyTeam.print();

        // Check if enemy characters are alive
        cout << "Checking if enemy characters are alive..." << endl;
        for (auto enemy : enemyTeam.getWarriors())
        {
            if (enemy->isAlive())
            {
                cout << enemy->getName() << " is alive." << endl;
            }
            else
            {
                cout << enemy->getName() << " is dead." << endl;
            }
        }
    }
    catch (const exception &e)
    {
        cout << "An exception occurred: " << e.what() << endl;
    }

    return 0;
}
