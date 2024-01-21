#include "shape.h"
#include <string>
#include "gwindow.h"
using namespace  std;
Shape::Shape()
{
    setColor("BLUE");
}

void Shape::setLocation(double x, double y){
    this->x = x;
    this->y = y;
}


void Shape::move(double dx, double dy){
    x += dx;
    y += dy;
}

void Shape::setColor(string color){
    this->color = color;
}

/*
 * Implementation notes: Line class
*/
Line::Line(double x1, double y1, double x2, double y2){
    this->x = x1;
    this->y = y1;
    this->dx = x2 - x1;
    this->dy = y2 - y1;
}

void Line::draw(GWindow &gw){
    gw.setColor(color);
    gw.drawLine(x,y,x+dx,y+dy);
}

/*
 * Implementation notes: Rect and Oval classes
*/
Rect::Rect(double x, double y, double width, double height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rect::draw(GWindow &gw){
    gw.setColor(color);
    gw.fillRect(x,y,width,height);
}

Oval::Oval(double x, double y, double width, double height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Oval::draw(GWindow &gw){
    gw.setColor(color);
    gw.fillOval(x,y,width,height);
}

/*
 * Implementation notes: Circle
*/
Circle::Circle(double x, double y, double r): Oval(x-r,y-r,2*r,2*r){
    /* Empty */
}





















