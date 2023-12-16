#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "Rectangle.h"

class Object {
public:
    Object() {}
    ~Object() {}

    // pure function for drawing object
    virtual void Draw() = 0;

    int getX() { return rectangle->x; }
    int getY() { return rectangle->y; }
    int getWidth() { return rectangle->dx; }
    int getHeight() { return rectangle->dy; }

    Rectangle* getRectangle() const { return rectangle; }

protected:
    Rectangle *rectangle;

};

#endif // OBJECT_H_INCLUDED
