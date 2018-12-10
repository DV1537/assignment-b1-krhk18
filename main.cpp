#include <iostream>
#include <fstream>
#include <sstream>
#include "Position.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Figure.h"

/*
I interpreted the assignment like this:
1. Read in all the shapes in the program and store them
2. Create another shape (of choice) to add to the already stored shapes from file (by using addShape function)
3. Calculate boundingbox coordinates from figure of shapes from file + created shape in program

OBS! This means I'm printing the boundingBox of the shapes in the file + one added shape in the program!

(Maybe I could have used "addShape" to add the shapes presented in file to Figure.
This is not how I have interpreted the assignment though).
*/

int main(int argc, const char * argv[])
{
    int capacityNumbers = 1;
    double *numbersPtr = new double[capacityNumbers];
    Position *positionPtr = nullptr;
    std::string type = "";
    std::ifstream inputFile;
    std::stringstream myStringStream;
    std::string line;
    int numberOfCoordinates = 0;
    int numberOfElements;
    int capacityPolygons = 1;
    Polygon *polygonPtr = new Polygon[capacityPolygons];
    int numberOfShapes;

    inputFile.open(argv[1]);

    //Check if file reads in successfully
    if(!inputFile)
    {
        std::cout << "Error opening file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        //Read in file
        while(!inputFile.eof())
        {
            //Read one line into a string
            myStringStream.clear();
            std::getline(inputFile, line);
            myStringStream << line;

            //read each element in the string and store in numbersPtr (+ count number of elements)
            while(myStringStream >> numbersPtr[numberOfElements])           //Read in and store
            {           
                numberOfElements++;
                if(numberOfElements >= capacityNumbers)       //If full: expand
                {
                    capacityNumbers += 1;
                    double *tempPtr = new double[capacityNumbers];  //Create new, bigger
                    for(int i = 0; i < capacityNumbers - 1; i++)      //move
                    {
                        tempPtr[i] = numbersPtr[i];
                    }
                    delete []numbersPtr;                //delete old content
                    numbersPtr = tempPtr;               //make pointer point to new array
                    tempPtr = nullptr;
                }
            }

            //Check if line is empty, contains non-numberical values or has an odd number of values
            if(numberOfElements == 0 || !myStringStream.eof())
            {
                std::cout << "Line number " << numberOfShapes + 1 << " is empty or contains non-numerical values\n";
                exit(EXIT_FAILURE);
            }
            else if(numberOfElements % 2 == 1)
            {
                std::cout << "Line number " << numberOfShapes + 1 << " contains an odd number of values\n";
                exit(EXIT_FAILURE);
            }
            else
            {
                //Store numbers as positions (x, y) in positionPtr
                numberOfCoordinates = numberOfElements / 2;
                positionPtr = new Position[numberOfCoordinates];
                for(int i = 0; i < numberOfCoordinates; i++)
                {
                    positionPtr[i].xCoord = numbersPtr[2 * i];
                    positionPtr[i].yCoord = numbersPtr[2 * i + 1];
                }

                //Create polygon object
                Polygon myPolygonObject(positionPtr, numberOfCoordinates);

                //Store polygon object in polygonPtr (by first increasing the size if needed)
                if(numberOfShapes >= capacityPolygons)
                {
                    capacityPolygons += 1;
                    Polygon *tempPtr = new Polygon[capacityPolygons];  //Create new, bigger
                    for(int i = 0; i < capacityPolygons - 1; i++)      //move
                    {
                        tempPtr[i] = polygonPtr[i];
                    }
                    delete []polygonPtr;                //delete old content
                    polygonPtr = tempPtr;               //make pointer point to new array
                    tempPtr = nullptr;
                }
                polygonPtr[numberOfShapes] = myPolygonObject;
                numberOfShapes++;

                numberOfElements = 0;
            }
            //Start over with next line in file
        }
    }

    inputFile.close();

    //Create Figure
    Figure myFigure(polygonPtr, numberOfShapes);

    //Create polygon and add to figure
    Position positionOne(2, 3), positionTwo(2, 5);
    Position positionArray[2] = {positionOne, positionTwo};

    Polygon polyToAdd(positionArray, 2);
    myFigure.addShape(polyToAdd);

    //Call boundingBox and store returned pointer to positions
    Position *boundingBoxPtr;
    boundingBoxPtr = myFigure.getBoundingBox();

    //Round to 3 decimal digits and print boundingbox corners coordinates
    for(int i = 0; i < 2; i++)
    {
        double xCoord = roundf(boundingBoxPtr[i].xCoord * 1000) / 1000;
        double yCoord = roundf(boundingBoxPtr[i].yCoord * 1000) / 1000;
        std::cout << xCoord << " " << yCoord << " ";
    }
    std::cout << std::endl;

    //Free memory
    delete []boundingBoxPtr;
    boundingBoxPtr = nullptr;

    delete []numbersPtr;
    numbersPtr = nullptr;
    
    delete []positionPtr;
    positionPtr = nullptr;
    
    delete []polygonPtr;
    polygonPtr = nullptr;

    //Pause program
    std::getchar();

    return 0;
}