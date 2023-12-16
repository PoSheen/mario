#include "Rectangle.h"


bool
Rectangle::isOverlap(Rectangle *R1, Rectangle *R2){
    int left,right,up,down,dx,dy;
    if(R1->x > R2->x){
        left = R1->x; 
        right = R2->x;
        dx=R1->dx;
    }else if (R1->x < R2->x){
        left = R2->x;
        right = R1->x;
        dx=R2->dx;
    }else{
        return true;
    }
    if(R1->y > R2->y){
        down = R1->y; 
        up = R2->y;
        dy=R2->dy;
    }else if (R1->y < R2->y){
        down = R2->y;
        up = R1->y;
        dy=R1->dy;
    }else{
        return true;
    }

    if(left+dx > right || up+dy > down){
        return true;
    }
    return false;
}