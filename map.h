#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "Rectangle.h"


#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))

class Map{
public:
    //Map() {}
    //~Map() {}

    void Init();

    void Draw();

    int find_top(int x , int y);

    int CurentFloorHeight(int x,int y);
    //return x,y 下方最近的地板高度

    int find_right(int x, int y);

    int CurentWall(int x,int y);


private:

    const int width=30;

    const int height=20;

    char Blocks[20][30];
    
    int CameraPos; 
    //坐左邊座標
};

#endif 