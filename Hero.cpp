#include "Hero.h"
#include "DataCenter.h"


const char direction_name[][10] = {"left", "right", "front", "back"};
int draw_frequency = 10;
void Hero::Init(){
    imgCount[HeroState::LEFT] = 2;
    imgCount[HeroState::RIGHT] = 2;
    imgCount[HeroState::FRONT] = 2;
    imgCount[HeroState::BACK] = 2;

    CameraPos=DC->get_map().get_CameraPos();

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
    y = 100;
}

void Hero::Update(){
    counter = (counter + 1) % draw_frequency;
    if(counter == 0)
        sprite_pos = (sprite_pos + 1) % imgCount[direction];

    Distance *distance= DC->get_map().get_Distance(x,y);
    cout << speed << ' ' << v0 << ' ' << x << ' '<< y << ' '<< distance->right <<' '<< distance->left << ' ' << distance->up << ' ' << distance->down << endl ;
    
    if(0 < distance->down-unit*2){
        v0+=gravity/15;
    }else if(v0>0){v0=0;}


    if( key_state[ALLEGRO_KEY_SPACE] ){
        if(distance->down==2*unit){
            v0 -= gravity;    
        }
    }
    //在地上按space會跳起來


    if( key_state[ALLEGRO_KEY_W] ){
        
        direction = HeroState::BACK;
    }else if( key_state[ALLEGRO_KEY_S] ){
        v0 += gravity/5;
        direction = HeroState::FRONT;
    }
    if( key_state[ALLEGRO_KEY_A] ){
        if(speed >= -1*MaxSpeed){
            speed -= MaxSpeed/5;
        }
        if(!distance->left)speed =0;
        direction = HeroState::LEFT;
    }else{
        if(speed<0){
            speed += MaxSpeed/5;
        }
    }
    if( key_state[ALLEGRO_KEY_D] ){
        if(speed <= MaxSpeed){
            speed += MaxSpeed/5;
        } 
        direction = HeroState::RIGHT;
    }else{
        if(speed>0){
            speed -= MaxSpeed/5;
        }
    }


    if(speed > distance->right-unit && speed >0){
        x+=distance->right-unit;
        speed =0;
    }
    else if(speed < distance->left*(-1)+unit && speed<0){
        x+=distance->left*(-1)+unit;
        speed =0;
    }
    x+=speed;
    
    if(v0){
        if(v0 > distance->down-2*unit && v0 >0){
            y+=distance->down-2*unit;
            v0=0;
        }
        else if(v0 <= distance->up*(-1)){
            y+=distance->up*(-1)+1;
            v0=0;
        }
        y+=v0;
    }
    
    CameraPos = DC->get_map().UpdateCameraPos(x);
    if(y>window_height){
        Hero::reset();
        DC->get_map().reset();
    }
    
}

void Hero::Draw(){

    al_draw_scaled_bitmap(imgData[direction][sprite_pos], 0, 0,al_get_bitmap_width(imgData[direction][sprite_pos]), al_get_bitmap_height(imgData[direction][sprite_pos]),x - CameraPos,y,unit,2*unit,0);
}

void Hero::reset(){
    x=100;
    y=100;
    return;
}