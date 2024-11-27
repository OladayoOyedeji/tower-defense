#include "Game.h"

int main(int argc, char* argv[])
{
    srand((unsigned int) time(NULL));
    Game game;
    game.run();
    
    return 0;
}
