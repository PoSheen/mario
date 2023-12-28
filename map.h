#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <map>

#include "global.h"
#include "Rectangle.h"


#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))

typedef struct Distance {
    int up, down, right, left;
}Distance;

class Map{
public:
    //Map() {}
    //~Map() {}

    void Init();
    int UpdateCameraPos(int x);
    void Draw();
    void reset();

    int find_down(int x , int y);
    int DownDistant(int x,int y);
    //return x,y 與下方最近的地板距離
    int find_up(int x , int y);
    int UpDistant(int x,int y);

    int find_right(int x, int y);
    int RightDistant(int x,int y);

    int find_left(int x , int y);
    int LeftDistant(int x,int y);
    int get_CameraPos(){return CameraPos;}

    Distance* get_Distance(int x, int y);

private:

    Distance* distance;

    char Blocks[20][30];
    
    int CameraPos=100; 
    //坐左邊座標
    std::map<char, ALLEGRO_BITMAP *> imgData;
};

#endif 