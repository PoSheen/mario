#include "map.h"

void Map::Init(){
    al_init_image_addon();
    FILE *file;
    file = fopen("Map.txt","r");

    imgData = {
        {'G', al_load_bitmap("./img/ground.png")},
        {'Q', al_load_bitmap("./img/qmark.png")}

    };

    for(int i=0;i<20;i++)for(int j=0;j<30;j++){
        fscanf(file, "%c" , &Blocks[i][j]);
    }

    fclose(file);
    return;
}

int Map::UpdateCameraPos(int x){
    if(x-CameraPos > window_width*4/5)CameraPos=x-window_width*4/5;
    else if(x-CameraPos < window_width/5)CameraPos=x-window_width/5;
    if(x<0)x=0;
    return CameraPos;
}

void Map::Draw(){
    for(int i=0;i<20;i++)for(int j=0;j<30;j++){
        switch(Blocks[i][j]){
            case 'G':
                al_draw_scaled_bitmap(imgData['G'], 0, 0,al_get_bitmap_width(imgData['G']), al_get_bitmap_height(imgData['G']),unit*j-CameraPos,unit*i,unit,unit,0);
                //al_draw_bitmap(imgData['G'])
                //al_draw_filled_rectangle(unit*j-CameraPos,unit*i,unit*j+unit-CameraPos,unit*i+unit,al_map_rgb(255,0,255));
                break;
            case 'Q':
                al_draw_scaled_bitmap(imgData['Q'], 0, 0,al_get_bitmap_width(imgData['Q']), al_get_bitmap_height(imgData['Q']),unit*j-CameraPos,unit*i,unit,unit,0);
            default:
                break;

        }

    }
}

void Map::reset(){
    CameraPos=100;
    return;
}

int Map::find_down(int x,int y){
    int p=y/unit;
    for(int i=p; i<20; i++){
        if(Blocks[i][x/unit]!=' ')
            if((unit*i-y)>=0)return unit*i-y;
    }
    return 999;
}
int Map::DownDistant(int x,int y){
    int left = x, right = x+unit-1;
    return min(find_down(left,y),find_down(right,y));

}

int Map::find_up(int x,int y){
    int p=y/unit;
    for(int i=p; i>0; i--){
        if(Blocks[i][x/unit]!=' ')
            if((y-unit*i)>=0) return y-unit*i;
    }
    return 999;
}
int Map::UpDistant(int x,int y){
    int left = x, right = x+unit-1;
    return min(find_up(left,y),find_up(right,y));

}

int Map::find_right(int x,int y){
    int p=x/unit;
    for(int i=p; i<30; i++){
        if(Blocks[y/unit][i]!=' ')
            if((unit*i - x) >0)return unit*i - x;
    }
    return 999;
}
int Map::RightDistant(int x,int y){
    int up = y, mid = y+unit, down = y+2*unit-1;
    return min(find_right(x,mid),(find_right(x,up),find_right(x,down)));

}

int Map::find_left(int x,int y){
    int p=x/unit;
    for(int i=p; i>-1; i--){
        if(Blocks[y/unit][i]!=' ')
            return x - unit*i;
    }
    return 999;
}
int Map::LeftDistant(int x,int y){
    int up = y, mid = y+unit, down = y+2*unit-1;
    return min(find_left(x,mid),(find_left(x,up),find_left(x,down)));

}



Distance* Map::get_Distance(int x, int y){
    distance = new Distance;
    distance->up = Map::UpDistant(x,y);
    distance->down = Map::DownDistant(x,y);
    distance->left = Map::LeftDistant(x,y);
    distance->right = Map::RightDistant(x,y);
    return distance;
}