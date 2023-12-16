#include "GameWindow.h"
int main(int argc, char *argv[])
{

    GameWindow *MarioGame= new GameWindow();

    MarioGame->game_play();

    delete MarioGame;
    return 0;
}
