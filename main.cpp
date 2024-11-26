#include "Game.h"

int main(int argc, char* argv[])
{
    srand((unsigned int) time(NULL));
    Game game;
    game.run();
    const int FONTSIZE = 24;
    Surface surface(640, 480);
    Event event;
    //Font font("fonts/FreeSans.ttf", FONTSIZE);
    Mouse mouse;

    int x = 100, y = 100, w = 100, h = 100;
    bool move = false; // true iff the square is moving with the mouse

    // std::stringstream out;
    // out << "drag-n-drop sim: click on mouse to pick up/put down";
    Color c = {255, 255, 255};
    //Image helpimage(font.render(out.str().c_str(), c));
    //Rect helprect = helpimage.getRect();
    
	while (1)
	{
            std::stringstream out;
	    if (event.poll())
            { 
                if (event.type() == QUIT) break;
                else if (event.type() == MOUSEMOTION)
                {
                    std::cout << "move\n";
                    mouse.update(event);
                    if (move)
                    {
                        x = mouse.x();
                        y = mouse.y();
                    }
                }
                else if (event.type() == MOUSEBUTTONDOWN)
                {
                    std::cout << "mouse down\n";
                    // do nothing ... pick up and put down
                    // happens only when the button is released
                }
                else if (event.type() == MOUSEBUTTONUP)
                {
                    std::cout << "mouse up\n";
                    mouse.update(event);
                    int mousex = mouse.x();
                    int mousey = mouse.y();
                    if (x <= mousex && mousex <= x + w
                        && y <= mousey && mousey <= y + h)
                    {
                        move = !move;
                        std::cout << move << std::endl;
                    }
                }
            }

        surface.lock();
        surface.fill(BLACK);
        if (move)
        {            
            surface.put_rect(x, y, w, h, 100, 100, 100);
        }
        else
        {
            surface.put_rect(x, y, w, h, 255, 255, 255);
        }
        //surface.put_image(helpimage, helprect);
        surface.unlock();
        surface.flip();

        delay(10);
    }

    return 0;
}
