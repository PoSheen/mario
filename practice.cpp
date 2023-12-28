#include <stdio.h>
#include "practice.h"


int main(int argc, char *argv[]){
    int msg =0;

    srand(time(NULL));

    game_init();
    game_begin();
    while(msg != GAME_TERMINATE){
        msg = game_run();
    }
    game_destroy();
    return 0;

}

void game_init(){

    al_init();
    al_init_image_addon();

    event_queue = al_create_event_queue();
    display = al_create_display(window_width,window_height);
    timer = al_create_timer(1.0/FPS);

    //if(timer == NULL)
        //show_err_msg(-1);
    al_install_keyboard();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_set_window_position(display,0,0);
    DC->get_map().Init();
    DC->get_Hero().Init();
}

int game_run(){
    int error =0;

    if(!al_is_event_queue_empty(event_queue)){
        error = process_event();
    }

    
    return error;
}

int process_event(){
    al_wait_for_event(event_queue, &event);
    keyboard_event();
    int error = game_update();
    game_draw();
    return error;
}

int keyboard_event(){
    //if(event.type == ALLEGRO_EVENT_TIMER){
        //if(event.timer.source == timer){

    if( event.type == ALLEGRO_EVENT_KEY_DOWN){
        key_state[event.keyboard.keycode] = true;

    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
         key_state[event.keyboard.keycode] = false;
    }
    return 0;
}

int game_update(){
    if( key_state[ALLEGRO_KEY_ESCAPE] ){
        return GAME_TERMINATE;
    }
    DC->get_Hero().Update();
    return 0;
}

void game_begin(){
    al_clear_to_color( al_map_rgb(255,0,0) );
    al_flip_display();
    al_start_timer(timer);    
}

void game_draw(){
    
    al_clear_to_color(al_map_rgb(0,0,0));
    DC->get_map().Draw();
    DC->get_Hero().Draw();
    al_flip_display();
}


void game_destroy(){
    al_destroy_timer(timer);
    al_destroy_display(display);
}