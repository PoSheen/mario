
#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <map>
#include <vector>
#include <allegro5/allegro.h>
#include "global.h"
#include <iostream>
#include "Rectangle.h"

using namespace std;

enum class HeroState{
    LEFT,
    RIGHT,
    FRONT,
    BACK,
    ATTACK
};

class Hero{

public:
    void Init(); // put in GameWindow init
    void Update(); // put in GameWindow game_update
    void Draw(); // put in GameWindow draw running map
    void reset();
private:
    int x, y;
    int floor;
    int counter = 0;
    int sprite_pos = 0;
    int speed = 0;
    const int MaxSpeed = 5;
    const int gravity = 15;
    int v0 = 0;
    int CameraPos;
    HeroState direction = HeroState::FRONT;
    std::map<HeroState, std::vector<ALLEGRO_BITMAP *> > imgData;
    std::map<HeroState, int > imgCount;
};


#endif
