#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <list>
#include "Line.h"

class Path
{
public:
    Path(const int w_, const int h_, const int startx_, const int starty_)
        : w(w_), h(h_), startx(startx_), starty(starty_)
    {
        generate_path();
    }
    ~Path();
    void clear();
    void generate_path();
    void draw();
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
