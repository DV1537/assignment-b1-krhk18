#include "Figure.h"

Figure::Figure(Shape *sPtr, int numberOfShapes)
{
    this->numberOfShapes = numberOfShapes;
    capacity = numberOfShapes;
    
    shapePtr = new Position[capacity];
    for(int i = 0; i < numberOfShapes; i++)
    {
        shapePtr[i] = sPtr[i];
    }
}

Figure::~Figure()
{
    if(shapePtr)
    {
        delete[] shapePtr;
        shapePtr = nullptr;
    }
}