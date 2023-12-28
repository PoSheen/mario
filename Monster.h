#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "Rectangle.h"

class Monster{
public:
    Monster(){}
    ~Monster(){}

    virtual void Draw()=0;
    bool TouchedHero();

    Rectangle* getRectangle() const { return rectangle; }
private:
    Rectangle *rectangle;



};




#endif