#include "Game.h"

int main(int argc, char* argv[])
{
    srand((unsigned int) time(NULL));
    Game game;
    game.run();

    // Surface surface(W, H);
    // Line::set_surface(&surface);
    // Event event_;
    // int startx_ = 0;
    // int starty_ = 0;
    // int endx_ = W - 1;
    // int endy_ = H - 1;
    
    // while (1)
    // {
    //     // endx_ = (endx_ - startx_) / 2 + startx_;
    //     // endy_ = (endy_ - starty_) / 2 + starty_;
    //     Line l1(vec2i(startx_, starty_), vec2i(startx_, endy_));
    
    //     Line l2(vec2i(startx_, starty_), vec2i(endx_, starty_));
    
    //     Line l3(vec2i(endx_, starty_), vec2i(endx_, endy_));
    
    //     Line l4(vec2i(startx_, endy_), vec2i(endx_, endy_));
    //     if (event_.poll() && event_.type() == QUIT) break;
    //     surface.lock();
    //     surface.fill(BLACK);
    //     l1.draw();
    //     l2.draw();
    //     l3.draw();
    //     l4.draw();
    //     surface.unlock();
        
    //     surface.flip();
    // }
    
    return 0;
}
