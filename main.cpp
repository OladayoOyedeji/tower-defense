#include "Game.h"

int main(int argc, char* argv[])
{
    srand((unsigned int) time(NULL));
    Surface surface(W, H);
    std::cout << &surface << std::endl;
    Game game(&surface);
    game.run();
    // Event event;
    // GameObject().set_surface(&surface);
    // Path().set_surface(&surface);
    // Tower().set_surface(&surface);
    
    // Tower t(W / 2, H / 2);
    // std::cout << W << std::endl;
    // Path p(W - 60, H - 50, 50, H / 2);
    
    // std::list< Ball * > ball;
    // // p.set_surface(&surface);
    // int RATE = 1000 / 60;
    // bool s_pressed = false;
    // Mouse mouse;
    
    // while(1)
    // {
    //     if (event.poll() && event.type() == QUIT) break;
        
    //     int start = getTicks();
    //     KeyPressed keypressed = get_keypressed();
        // if (!s_pressed && keypressed[SPACE])
        // {
        //     p.generate_path();
        //     s_pressed = true;
        // }
        // if (!keypressed[SPACE])
        // {
        //     s_pressed = false;
        // }

        // if (!s_pressed && keypressed[SPACE])
    //     {
    //         ball.push_back(new Ball(&p, rand() % 30 + 10));
    //         s_pressed = true;
    //     }
    //     if (!keypressed[SPACE])
    //     {
    //         s_pressed = false;
    //     }
    //     if (mouse.left() && in_ob(mouse, t))
    //     {
    //         mouse.update(event);
    //         t.x_y(mouse.x(), mouse.y());
    //     }
    //     else
    //     {
    //         mouse.update(event);
    //     }
    //     //ball->run();
    //     for (std::list< Ball * >::iterator p = ball.begin();
    //          p != ball.end(); ++p)
    //     {
    //         (*p)->run();
    //         int r = sqrt(((*p)->x() - t.x()) * ((*p)->x() - t.x()) + ((*p)->y() - t.y()) * ((*p)->y() - t.y()));
    //         if (r < t.range())
    //         {
    //             t.push((*p));
    //         }
            
    //         if ((*p)->x() - (*p)->rad() >= W)
    //         {
    //             std::list< Ball * >::iterator q = p;
    //             ++p;
    //             delete (*q);
    //             ball.erase(q);
    //             if (p == ball.end())
    //             {break;}
    //         }

    //     }
    //     t.run();
    //     surface.lock();
    //     surface.fill(BLACK);
    //     p.draw();
    //     for (std::list< Ball * >::iterator p = ball.begin();
    //          p != ball.end(); ++p)
    //     {
    //         (*p)->draw();
    //     }
    //     t.draw();
    //     //ball->draw();
    //     surface.unlock();
        
    //     surface.flip();
    //     int end = getTicks();
    //     int dt = RATE - end + start;
    //     if (dt > 0) delay(dt);
    // }

    // for (std::list< Ball * >::iterator p = ball.begin();
    //      p != ball.end(); ++p)
    // {
    //     delete (*p);
    // }
    return 0;
}
