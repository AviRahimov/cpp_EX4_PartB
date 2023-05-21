#include "Point.hpp"
#include "math.h"
#include <iostream>
using namespace ariel;

/**

@brief Initializes a Point object with the given x and y coordinates.
@param new_x The x coordinate of the Point.
@param new_y The y coordinate of the Point.
*/
Point::Point(double new_x, double new_y) : x_axis(new_x), y_axis(new_y)
{
}
/**

@brief Calculates the distance between the current Point and another Point.
@param other The Point object to calculate the distance to.
@return The distance between the current Point and the other Point.
*/
double Point::distance(const Point &other) const
{
    return sqrt(pow((this->x_axis - other.getX()), 2) + pow((this->y_axis - other.getY()), 2));
}
/**

@brief Prints the coordinates of the Point in the format (x,y).
*/
void Point::print() const
{
    std::cout << "(" << this->x_axis << "," << this->y_axis << ")" << std::endl;
}
/**

@brief Moves the current Point towards a destination Point by a specified distance.
@param src The source Point from where the movement starts.
@param dest The destination Point to move towards.
@param dist The maximum distance the Point can move towards the destination.
@return The new Point after moving towards the destination within the specified distance.
@throws std::invalid_argument if the distance is less than 0.
*/
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

/**

@brief Returns the x coordinate of the Point.
@return The x coordinate of the Point.
*/
double Point::getX() const
{
    return this->x_axis;
}
/**

@brief Returns the y coordinate of the Point.
@return The y coordinate of the Point.
*/
double Point::getY() const
{
    return this->y_axis;
}
