#include "point.h"
#include "strlib.h"
#include <iostream>
using namespace std;

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int xc, int yc){
    x = xc;
    y = yc;
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

string Point::toString(){
    return "(" + integerToString(x) + "," + integerToString(y) + ")";
}

bool operator==(Point p1, Point p2){
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator != (Point p1, Point p2){
    return !(p1 == p2);
}

ostream & operator << (ostream & os, Point pt){
    return os << pt.toString();
}


