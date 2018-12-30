#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include "Polygon.h"
#include "BoundingBox.h"

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
        BoundingBox getTotalBoundingBox();
        friend std::ostream &operator<<(std::ostream &out, const Figure &figure);
};

#endif