#include <iostream>
#include "Figure.h"

Figure::Figure() : polygonPtr(nullptr), numberOfShapes(0), capacity(0)
{
}

Figure::~Figure()
{
    if(polygonPtr)
    {
        delete[] polygonPtr;
        polygonPtr = nullptr;
    }
}

void Figure::addShape(Polygon *polygon)
{
    if(numberOfShapes >= capacity)
    {
        capacity += 1;
        Polygon *tempPtr = new Polygon[capacity];
        for(int i = 0; i < numberOfShapes; i++)
        {
            tempPtr[i] = polygonPtr[i];
        }
        delete[] polygonPtr;
        polygonPtr = tempPtr;
        tempPtr = nullptr;
    }
    polygonPtr[numberOfShapes] = *polygon;
    numberOfShapes++;
}

// Gets boundingbox top left and bottom right positions
Position* Figure::getTotalBoundingBox()
{
    double xMin = 0.0;
    double yMin = 0.0;
    double xMax = 0.0;
    double yMax = 0.0;

    //Loop through Polygons in the Figure.
    for(int i = 0; i < numberOfShapes; i++)
    {
        Position *tempPosPtr;
        tempPosPtr = polygonPtr[i].getBoundingBox();
        
        if(tempPosPtr[0].xCoord < xMin)
        {
            xMin = tempPosPtr[0].xCoord;    //xMin
        }
        if(tempPosPtr[0].yCoord > yMax)
        {
            yMax = tempPosPtr[0].yCoord;    //yMax
        }
        if(tempPosPtr[1].xCoord > xMax)
        {
           xMax = tempPosPtr[1].xCoord;     //xMax 
        }
        if(tempPosPtr[1].yCoord < yMin)
        {
            tempPosPtr[1].yCoord;           //yMin
        }
                
        //Free memory
        delete []tempPosPtr;
        tempPosPtr = nullptr;
    }

    //Make position top left corner (xMin, yMax) and bottom right corner (xMax, yMin)
    Position topLeft(xMin, yMax);
    Position bottomRight(xMax, yMin);
    
    Position *cornerPtr = new Position[2];
    cornerPtr[0] = topLeft;
    cornerPtr[1] = bottomRight;

    return cornerPtr;
}

//This is for being able to print the types of the shapes (polygons) stored in "Figure".
//(Used for debugging)
std::ostream &operator<<(std::ostream &out, const Figure &figure)
{
    //Print type
    for(int i = 0; i < figure.numberOfShapes; i++)
    {
        out << figure.polygonPtr[i].getType() << "\n";
    }
    return out;   
}