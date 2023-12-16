#include "map.h"

void Map::Init(){
    FILE *file;
    file = fopen("Map.txt","r");

    for(int i=0;i<20;i++)for(int j=0;j<30;j++){
        fscanf(file, "%c" , &Blocks[i][j]);
    }

    fclose(file);
    return;
}

void Map::Draw(){
    for(int i=0;i<20;i++)for(int j=0;j<30;j++){
        switch(Blocks[i][j]){
            case 'G':
                al_draw_filled_rectangle(20*j,20*i,20*j+20,20*i+20,al_map_rgb(255,0,255));
                break;
            default:
                break;

        }

    }
}

int Map::find_top(int x,int y){
    for(int i=y; i<20; i++){
        if(Blocks[i][x]=='G')
            return 20*i;
    }
    return 999;
}

int Map::CurentFloorHeight(int x,int y){
    int left = (x-10)/20, right = (x+10)/20;

    return min(find_top(left,y),find_top(right,y));

}

int Map::find_right(int x,int y){
    for(int i=x; i<30; i++){
        if(Blocks[y][i]=='G')
            return 20*i;
    }
    return 999;
}

int Map::CurentWall(int x,int y){
    int up = y/20, down = (y+50)/20;

    return min(find_right(x,up),find_right(x,down));

}
