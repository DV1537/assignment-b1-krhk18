#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
    private:
        Shape *shapePtr;
        int numberOfShapes;
        int capacity;
    public:
        Figure(Shape *shapePtr, int numberOfShapes);
        ~Figure();
};

#endif