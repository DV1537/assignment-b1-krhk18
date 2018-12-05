#ifndef FIGURE_H
#define FIGURE_H

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
};

#endif