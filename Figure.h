#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include "Polygon.h"

class Figure
{
    private:
        Shape *shapePtr;
        int numberOfShapes;
        int capacity;
    public:
        Figure();
        ~Figure();
        void addShape(const Shape &shape);
        Position* getBoundingBox();
        friend std::ostream &operator<<(std::ostream &out, const Figure &figure);
};

#endif