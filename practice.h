#ifndef PRACTICE_H_INCLUDED
#define PRACTICE_H_INCLUDED

#include <queue>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>    
#include <vector>
#include <list>        
#include <time.h>
#include "DataCenter.h"
#include "global.h"

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

const float FPS = 60;

void game_init();
void game_begin();
void game_destroy();
int game_run();
int process_event();
int game_update();
void game_draw();
int keyboard_event();
int pos_x=300, pos_y=400;



ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT event ;
ALLEGRO_TIMER *timer = NULL;

#endif 