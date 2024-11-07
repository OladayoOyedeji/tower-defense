#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <list>
#include "Line.h"

class Path
{
public:
    Path()
    {}
    Path(const int w_, const int h_, const int startx_, const int starty_)
        : w(w_), h(h_), startx(startx_), starty(starty_)
    {
        //generate_path();
    }
    ~Path();
    void clear();
    void generate_path();
    void draw();
    vec2i start() const
    {
        std::list<Line *>::const_iterator p = road_.begin();
        return (*p)->begin();
    }
    vec2d vector() const
    {
        std::list<Line *>::const_iterator p = road_.begin();
        return (*p)->grad();
    }
    std::list<Line *>::iterator begin()
    {
        return road_.begin();
    }
    std::list<Line *>::iterator end()
    {
        return road_.end();
    }
    static void set_surface(Surface * surface);
//private:
    std::list< Line * > road_;
    int startx, starty;
    int endx, endy;
    int w;
    int h;
    static Surface * surface_;
};

#endif
