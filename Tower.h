#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include "Surface.h"
#include "GameObject.h"
#include <cmath>

class Tower
{
public:
    Tower(int cntrx, int cntry)
        : cntr_(cntrx, cntry), target_(cntrx, cntry),
          r_(20), mouth_(cntrx, cntry, double(0), double(r_ + 20)),
          a_(0), da_(-0.05)
    {}
    void rotate();
    void draw();
    void move();
    void target(Ball * ball);
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
    static void set_surface(Surface *);

private:
    double a_;
    double da_;
    Line target_;
    vec2i cntr_;
    int r_;
    Line mouth_;
    static Surface * surface_;
};

#endif














































/*
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
*/
