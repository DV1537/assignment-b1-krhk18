#include "Figure.h"

Figure::Figure(Polygon *pPtr, int numberOfPolygons)
{
    this->numberOfPolygons = numberOfPolygons;
    capacity = numberOfPolygons;
    
    polygonPtr = new Polygon[capacity];
    for(int i = 0; i < numberOfPolygons; i++)
    {
        polygonPtr[i] = pPtr[i];
    }
}

Figure::~Figure()
{
    if(polygonPtr)
    {
        delete[] polygonPtr;
        polygonPtr = nullptr;
    }
}