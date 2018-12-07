#include <iostream>
#include "Figure.h"

Figure::Figure(Shape *sPtr, int numberOfShapes)
{
    this->numberOfShapes = numberOfShapes;
    capacity = numberOfShapes;
    
    //Since the program is only making polygons, and no other shapes will be created,
    //I have assumed it is OK to make shapePtr point to Polygons.
    shapePtr = new Polygon[capacity];
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

void Figure::addShape(const Shape &shape)
{
    if(numberOfShapes >= capacity)
    {
        capacity += 1;
        Shape *tempPtr = new Polygon[capacity];
        for(int i = 0; i < numberOfShapes; i++)
        {
            tempPtr[i] = shapePtr[i];
        }
        delete[] shapePtr;
        shapePtr = tempPtr;
        tempPtr = nullptr;
    }
    shapePtr[numberOfShapes] = shape;
    numberOfShapes++;
}

/* Gets boundingbox top left and bottom right positions by
looping trough the polygons in the figure and comparing
the x- and y-coords to find the highest and lowest of each.
top left = (lowest x-coord, highest y-coord)
bottom right = (highest x-coord, lowest y-coord) */
Position* Figure::getBoundingBox()
{
    double xMin = 0.0;
    double yMin = 0.0;
    double xMax = 0.0;
    double yMax = 0.0;

    //Loop through Polygons in the Figure.
    for(int i = 0; i < numberOfShapes; i++)
    {
        //Create new pointer for positions in current polygon
        int numberOfPositions = shapePtr[i].getNrOfPositions();
        Position *tempPositionPtr = new Position[numberOfPositions];
        //Get positions of current polygon
        shapePtr[i].getPositions(tempPositionPtr);

        //Find min- and max- values of x and y
        if(i == 0)
        {
            xMin = xMax = tempPositionPtr[0].xCoord;
            yMin = yMax = tempPositionPtr[0].yCoord;
        }
        for(int j = 0; j < numberOfPositions; j++)
        {
            if(xMin > tempPositionPtr[j].xCoord)
            {
                xMin = tempPositionPtr[j].xCoord;
            }
            if(xMax < tempPositionPtr[j].xCoord)
            {
                xMax = tempPositionPtr[j].xCoord;
            }
            if(yMin > tempPositionPtr[j].yCoord)
            {
                yMin = tempPositionPtr[j].yCoord;
            }
            if(yMax < tempPositionPtr[j].yCoord)
            {
                yMax = tempPositionPtr[j].yCoord;
            }
        }
        
        //Free memory
        delete []tempPositionPtr;
        tempPositionPtr = nullptr;
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
        out << figure.shapePtr[i].getType() << "\n";
    }
    return out;   
}