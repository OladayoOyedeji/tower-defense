#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include "Surface.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Priority.h"
#include <cmath>

const int TOWER_RADIUS = 10;
const int TOWER_RANGE = 100;

/*the blue towers priority is the balls faster
 the reds priority is is the slower balls
 the whites priority is the bigger balls
 and the grey priority is the smaller balls

 so i need to create a priority queue of all theses
 condition*/

bool big_p(Ball * ball1, Ball * ball2);
bool smal_p(Ball * ball1, Ball * ball2);
bool fast_p(Ball * ball1, Ball * ball2);
bool slow_p(Ball * ball1, Ball * ball2);

class Tower: public GameObject
{
public:
    Tower()
    {}
    Tower(const vec2i& c, const Color& color, bool (*comp)(Ball *, Ball *))
        : GameObject(c, TOWER_RADIUS, color), target_(c),
          victims_(comp), range_(TOWER_RANGE), mouth_(c)
    {}
    Tower(int cntrx, int cntry);
    
    virtual void draw();
    //virtual void move(int , int);
    int x()
    {
        return pos_.x();
    }
    int y()
    {
        return pos_.y();
    }
    int rad()
    {
        return radius_;
    }
    int range()
    {
        return range_;
    }
    void x_y(const int x, const int y);
    Line target(Ball * ball);
    Line target()
    {
        return target_;
    }
    virtual void run();
    void push(Ball * ball);
    bool in_range(const Ball * ball)
    {
        int r = ball->pos().dist(pos_);
        
        return r < range_;
    }
    //void shoot();
    static void set_surface(Surface *);
private:
    Line target_;
    int timer_;
    int range_;
    Line mouth_;
    static Surface * surface_;

    PriorityQueue< Ball * > victims_;
};

class B_tower : public Tower
{
public:
    B_tower(const vec2i & v = vec2i())
        : Tower(v, BLUE, &big_p)
    {}
};

class R_tower : public Tower
{
public:
    
    R_tower(const vec2i & v = vec2i())
        : Tower(v, RED, &smal_p)
    {}
};

class W_tower : public Tower
{
public:
    W_tower(const vec2i & v = vec2i())
        : Tower(v, WHITE, &fast_p)
    {}
};

class G_tower : public Tower
{
public:
    G_tower(const vec2i & v = vec2i())
        : Tower(v, GRAY, &slow_p)
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
