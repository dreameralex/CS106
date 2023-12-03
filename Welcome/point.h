#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
class Point {
public:
    Point();
    Point(int xc, int yc);

    int getX();
    int getY();

    std::string toString();

    /* Friend declaration */
    friend bool operator==(Point p1, Point p2);

    /* Instance variables*/
    int x;
    int y;
};

std::ostream & operator << (std::ostream & os, Point pt);

bool operator==(Point p1, Point p2);

bool operator!=(Point p1, Point p2);
#endif // POINT_H
