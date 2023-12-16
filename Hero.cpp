
#include "Hero.h"
#include "DataCenter.h"


const char direction_name[][10] = {"left", "right", "front", "back"};
int draw_frequency = 10;
void Hero::Init(){
    imgCount[HeroState::LEFT] = 2;
    imgCount[HeroState::RIGHT] = 2;
    imgCount[HeroState::FRONT] = 2;
    imgCount[HeroState::BACK] = 2;

    char buffer[50];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < imgCount[ static_cast<HeroState>(i) ]; j++)
        {
            ALLEGRO_BITMAP *img;
            sprintf(buffer, "./Hero/dragonite_%s_%d.png", direction_name[i], j+1);
            img = al_load_bitmap(buffer);
            if(img){
                imgData[static_cast<HeroState>(i)].push_back(img), printf("[Hero] image loaded!!\n");
            }else{
                printf("[Hero] image not loaded!!\n");
            }
        }
    }
    x = 100;
    y = 1;
    floor = DC->get_map().CurentFloorHeight(x,y/20);
}
void Hero::Update(){
    bool walled = false;

    counter = (counter + 1) % draw_frequency;
    if(counter == 0)
        sprite_pos = (sprite_pos + 1) % imgCount[direction];



    if(y<floor-60){
        v0+=gravity/15;
    }else if(y>floor-60 && x+20 > DC->get_map().CurentWall(x/20,y)){
        walled =true;
        v0=0;
    }else{
        y=floor-60;
        v0=0;
    }
    if( key_state[ALLEGRO_KEY_SPACE] ){
        if(y==floor-60){
            v0 -= gravity;    
        }
    }
    //在地上按space會跳起來


    if( key_state[ALLEGRO_KEY_W] ){
        
        direction = HeroState::BACK;
    }else if( key_state[ALLEGRO_KEY_S] ){
        v0 += gravity/5;
        direction = HeroState::FRONT;
    }if( key_state[ALLEGRO_KEY_A] ){
        if(speed >= -1*MaxSpeed){
            speed -= MaxSpeed/5;
        }
        x += speed;
        floor = DC->get_map().CurentFloorHeight(x,y/20);
        direction = HeroState::LEFT;
    }else if( key_state[ALLEGRO_KEY_D] ){
        if(speed <= MaxSpeed){
            speed += MaxSpeed/5;
        }
        x += speed;
    
        floor = DC->get_map().CurentFloorHeight(x,y/20);
        direction = HeroState::RIGHT;
    }
    cout << DC->get_map().CurentWall(x/20,y) << ' ' << x << ' ' << y << endl;

    if(walled&&speed > 0){
        x-=speed;
        speed =0;
    }
    y+=v0;
    
}

void Hero::Draw(){

    al_draw_bitmap(imgData[direction][sprite_pos], x, y, 0);
}


