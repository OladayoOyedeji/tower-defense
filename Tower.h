#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include "Surface.h"
#include "GameObject.h"
#include "Bullet.h"
#include <cmath>

const int TOWER_RADIUS = 10;
const int TOWER_RANGE = 100;

/*the blue towers priority is the balls faster
 the reds priority is is the slower balls
 the whites priority is the bigger balls
 and the grey priority is the slower balls

 so i need to create a priority queue of all theses
 condition*/

class Tower: public GameObject
{
public:
    Tower()
    {}
    Tower(const vec2i&, const Color&);
    Tower(int cntrx, int cntry);
    
    void rotate();
    void draw();
    void push(Ball * ball)
    void move(int , int);
    int x()
    {
        return cntr_.x();
    }
    int y()
    {
        return cntr_.y();
    }
    int rad()
    {
        return r_;
    }
    int range()
    {
        return range_;
    }
    void x_y(const int x, const int y);
    Line target(Ball * ball);
    void run();
    bool in_range(const Ball * ball)
    {
        int r = ball->pos().dist(cntr_);
        
        return r < range_;
    }
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
    void shoot();
    static void set_surface(Surface *);

private:
    double a_;
    double da_;
    Line target_;
    vec2i cntr_;
    int r_, timer_;

    int range_;
    Line mouth_;
    static Surface * surface_;
    std::list< Bullet * > amo;
    std::list< Ball * > victims_;
    //std::stack<>
    Ball * ball_;
};

class B_tower : public Tower
{
public:
    B_tower(const vec2i & v)
        : Tower(v, BLUE)
    {}
};

class R_tower : public Tower
{
public:
    R_tower(const vec2i & v)
        : Tower(v, RED)
    {}
};

class W_tower : public Tower
{
public:
    W_tower(const vec2i & v)
        : Tower(v, WHITE)
    {}
};

class G_tower : public Tower
{
public:
    G_tower(const vec2i & v)
        : Tower(v, GREY)
    {}
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
