#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "gwindow.h"

class Shape
{
public:
    void setLocation(double x, double y);

    void move(double x, double y);

    void setColor(std::string color);

    virtual void draw(GWindow & gw) = 0;

protected:
    /* The following methods and fields are available to the subclasses */
    Shape(); // Superclass constructor
    std:: string color; // The color of the object
    double x,y; // The coordinates of the object

};

class Line: public Shape{
public:
    Line(double x1, double y1,double x2, double y2);

    /* Prototypes for the overridden virtual methods */
    virtual void draw(GWindow & gw);

private:
    double dx; // Horizontal distance from x1 to x2
    double dy; // Vertical distance from y1 to y2

};

class Rect: public Shape{
public:
    Rect(double x, double y,double width, double height);

    /* Prototypes for the overridden virtual methods */
    virtual void draw(GWindow & gw);

private:
    double width, height; // Dimensions of the rectangle

};

class Oval: public Shape{
public:
    Oval(double x, double y,double width, double height);

    /* Prototypes for the overridden virtual methods */
    virtual void draw(GWindow & gw);

private:
    double width, height; // Dimensions of the rectangle

};













#endif // SHAPE_H
