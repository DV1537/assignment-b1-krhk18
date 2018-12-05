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

std::ostream &operator<<(std::ostream &out, const Figure &figure)
{
    //Print type
    for(int i = 0; i < figure.numberOfPolygons; i++)
    {
        out << figure.polygonPtr[i].getType() << "\n";
    }
    return out;   
}