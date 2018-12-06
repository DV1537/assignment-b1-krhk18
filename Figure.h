#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include "Polygon.h"

class Figure
{
    private:
        Polygon *polygonPtr;
        int numberOfPolygons;
        int capacity;
    public:
        Figure(Polygon *polygonPtr, int numberOfPolygons);
        ~Figure();
        void addShape(const Polygon &polygon);
        Position* getBoundingBox();
        friend std::ostream &operator<<(std::ostream &out, const Figure &figure);
};

#endif