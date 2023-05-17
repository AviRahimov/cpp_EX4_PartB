#include "Point.hpp"
#include "math.h"
#include <iostream>
using namespace ariel;

// Initiallize the x and y coordinates
Point::Point(double new_x, double new_y) : x_axis(new_x), y_axis(new_y)
{
}

// Calculating the distance between the class Point and some other Point passed as argument
double Point::distance(const Point &other) const
{
    return sqrt(pow((this->x_axis - other.getX()), 2) + pow((this->y_axis - other.getY()), 2));
}

// Printing the point in that form: (x,y)
void Point::print() const
{
    std::cout << "(" << this->x_axis << "," << this->y_axis << ")" << std::endl;
}

// Return the closet Point to the destination Point that is with distance no longer than dist from the
// the source Point
Point Point::moveTowards(const Point &src, const Point &dest, double dist)
{
    if (dist < 0)
    {
        throw std::invalid_argument("Distance can't be less than 0");
    }
    // Calculate the distance between the source and destination points
    double distance = src.distance(dest);

    // If the distance is less than or equal to the given distance, return the destination point
    if (distance <= dist)
    {
        return dest;
    }

    // Calculate the ratio between the given distance and the distance between the source and destination points
    double ratio = dist / distance;

    // Calculate the new x and y coordinates based on the ratio
    double new_x = src.getX() + (ratio * (dest.getX() - src.getX()));
    double new_y = src.getY() + (ratio * (dest.getY() - src.getY()));

    // Return a new point with the new x and y coordinates
    return Point(new_x, new_y);
}

double Point::getX() const
{
    return this->x_axis;
}

double Point::getY() const
{
    return this->y_axis;
}