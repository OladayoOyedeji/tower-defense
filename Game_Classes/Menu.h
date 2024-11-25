#ifndef MENU_H
#define MENU_H

#include "Tower.h"

// enum towers
// {
//     RED, BLUE, WHITE, GRAY;
// };


enum towers
{
    BLUE_, RED_, WHITE_, GRAY_
};

// increase the number of poss towers when the size exceeds it
const int NUM_OF_POSSIBLE_TOWERS = 9;

class Menu
{
public:
    Menu(int startx, int starty, int w, int h, bool horizontal = true)
        : startx_(startx), starty_(starty),
          w_(w), h_(h),
          towers({new B_tower, new R_tower, new W_tower, new G_tower})
    {
        double dx = double(w)/NUM_OF_POSSIBLE_TOWERS;
        double x = (startx_ + dx) / 2;
        for (int i = 0; i < towers.size(); ++i)
        {
            std::cout << "starty: " << starty_ << std::endl;
            towers[i]->x_y(x, starty + h/2);
            x += dx;
        }
    }
    ~Menu()
    {
        for (int i = 0; i < towers.size(); ++i)
        {
            delete towers[i];
        }
    }
    vec2i set(int i) const
    {
        return towers[i]->pos();
    }
    void draw(Surface & surface)
    {
        surface.put_rect(startx_, starty_,
                         w_, h_, DARKGRAY);
        for (int i = 0; i < towers.size(); ++i)
        {
            towers[i]->draw();
        }
    }
private:
    int startx_, starty_, w_, h_;
    std::vector<Tower * > towers;
};

#endif
