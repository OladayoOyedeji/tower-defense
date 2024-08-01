#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Event.h"
#include "Path.h"
#include "GameObject.h"

int main(int argc, char* argv[])
{
    srand((unsigned int) time(NULL));
    Surface surface(W, H);
    Event event;
    Line().set_surface(&surface);
    Ball().set_surface(&surface);
    std::cout << W << std::endl;
    Path p(W - 1, H, 0, H / 2);
    Ball().set_path(&p);
    std::list< Ball * > ball;
    p.set_surface(&surface);
    int RATE = 1000 / 60;
    bool s_pressed = false;
    
    while(1)
    {
        if (event.poll() && event.type() == QUIT) break;
        
        int start = getTicks();
        KeyPressed keypressed = get_keypressed();
        // if (!s_pressed && keypressed[SPACE])
        // {
        //     p.generate_path();
        //     s_pressed = true;
        // }
        // if (!keypressed[SPACE])
        // {
        //     s_pressed = false;
        // }

        if (!s_pressed && keypressed[SPACE])
        {
            ball.push_back(new Ball(rand() % 30 + 10));
            s_pressed = true;
        }
        if (!keypressed[SPACE])
        {
            s_pressed = false;
        }
        //ball->run();
        for (std::list< Ball * >::iterator p = ball.begin();
             p != ball.end(); ++p)
        {
            (*p)->run();
            
            if ((*p)->x() - (*p)->rad() >= W)
            {
                std::list< Ball * >::iterator q = p;
                ++p;
                delete (*q);
                ball.erase(q);
                if (p == ball.end())
                {break;}
            }

        }
        surface.lock();
        surface.fill(BLACK);
        p.draw();
        for (std::list< Ball * >::iterator p = ball.begin();
             p != ball.end(); ++p)
        {
            (*p)->draw();
        }
        //ball->draw();
        surface.unlock();
        surface.flip();
        int end = getTicks();
        int dt = RATE - end + start;
        if (dt > 0) delay(dt);
    }

    for (std::list< Ball * >::iterator p = ball.begin();
         p != ball.end(); ++p)
    {
        delete (*p);
    }
    return 0;
}
