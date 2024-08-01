#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include "Surface.h"
#include <cmath>

class Tower
{
public:
    Tower(int x, int y, int r);
    void anticlock()
    {
        da_ = abs(da_) * -1;
        rotate();
    }
    void clock()
    {
        da_ = abs(da_);
        rotate();
    }
    void rotate();
    void draw();
    static void set_surface(Surface * surface);
//private:
    int cntrx, cntry;
    int endx, endy;
    int mx0, my0, mx1, my1;
    double dx; double dy;
    int r_;
    double a_;
    double da_;
    bool qdrt;
    int w_;
    static Surface * surface_;
    
};


#endif
