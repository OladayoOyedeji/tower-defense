#ifndef MENU_H
#define MENU_H

#include "Tower.h"

class Menu
{
  public:
    Menu(int startx, int starty, int w, int h)
        : startx_(startx), starty_(starty), w_(w), h_(h),
        red_(vec2i(startx+w/4, starty + h/8)),
        blue_(vec2i(startx + 3 * w/4, starty + h/8)),
        white_((vec2i(startx+w/4, starty + h/4))),
        green_(vec2i(startx + 3 * w/4, starty + h/4))
    {}
    vec2i Red() const
    {
        return red_.pos_;
    }
    vec2i Blue() const
    {
        return blue_.pos_;
    }
    
    vec2i White() const
    {
        return white_.pos_;
    }
    
    vec2i Green() const
    {
        return green_.pos_;
    }
    void draw(Surface & surface)
    {
        surface.put_rect(startx_, starty_, w_, h_, DARKGRAY);
        red_.draw();
        blue_.draw();
        white_.draw();
        green_.draw();
    }
  private:
    int startx_, starty_, w_, h_;
    R_tower red_;
    B_tower blue_;
    W_tower white_;
    G_tower green_;
    
};

#endif
