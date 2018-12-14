#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include "Polygon.h"

class Figure
{
    private:
        Polygon *polygonPtr;
        int numberOfShapes;
        int capacity;
    public:
        Figure();
        ~Figure();
        void addShape(Polygon *polygon);
        Position* getTotalBoundingBox();
        friend std::ostream &operator<<(std::ostream &out, const Figure &figure);
};

#endif