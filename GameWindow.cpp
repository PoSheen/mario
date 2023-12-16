#include "GameWindow.h"
#include "global.h"
#include <iostream>

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))



void
GameWindow::game_init()
{
    char buffer[50];

    

    DC->get_Hero().Init();
}



void
GameWindow::game_play()
{
    int msg;

    msg = -1;
    game_begin();

    while(msg != GAME_EXIT)
    {
        msg = game_run();
    }

    show_err_msg(msg);
}

void
GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);
    printf("Game Initializing...\n");
    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / FPS);
    monster_pro = al_create_timer(1.0 / FPS);

    if(timer == NULL || monster_pro == NULL)
        show_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);


    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event


    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    game_init();
}

void
GameWindow::game_begin()
{

    al_start_timer(timer);
}

int
GameWindow::game_run()
{
    int error = GAME_CONTINUE;

    return error;
}

int
GameWindow::game_update()
{
    unsigned int i, j;
    DC->get_Hero().Update();

    return GAME_CONTINUE;
}

void
GameWindow::game_reset()
{
    mute = false;
    redraw = false;


    // stop timer
    al_stop_timer(timer);
}

void
GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    al_destroy_timer(timer);


}

void
GameWindow::draw_running_map()
{
    unsigned int i, j;

    al_clear_to_color(al_map_rgb(100, 100, 100));

    DC->get_Hero().Draw();
    al_flip_display();
    
}
