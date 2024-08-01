#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Surface.h"

class Line
{
public:
    Line()
    {}
    Line(int x, int y, double m, double d);
    Line(int x0, int y0, int x1, int y1);
    Line(Line & l1, Line & l2);
    void draw();
    Surface * surface()
    {
        return surface_;
    }
    static void set_surface(Surface * surface);
    
    int x0_, y0_, x1_, y1_, xm, ym;
    double m_;
    double d_;
    static Surface * surface_;
};

#endif
