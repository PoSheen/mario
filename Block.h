#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "Rectangle.h"

class Block{
public:
    Block(){}
    ~Block(){}

    void Draw();

    int getX() {return recrangle->x;}
    int getY() {return recrangle->y;}
    int getDX() {return recrangle->dx;}
    int getDY() {return recrangle->dy;}

    Rectangle* getRectangle() const{ return recrangle;}

protected:
    Rectangle *recrangle;

};


#endif