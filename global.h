#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <allegro5/allegro_font.h>

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 1600
#define window_height 1200
#define field_width 600
#define field_height 600
#define unit 60

#define NumOfGrid (field_width / grid_width) * (field_height / grid_height)


extern bool key_state[ALLEGRO_KEY_MAX];


#endif // GLOBAL_H_INCLUDED
