#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include "Surface.h"
#include "GameObject.h"
#include "Bullet.h"
#include <cmath>

class Tower
{
public:
    Tower()
    {}
    Tower(int cntrx, int cntry)
        : cntr_(cntrx, cntry), target_(cntrx, cntry),
          r_(10), mouth_(cntrx, cntry, double(0), double(r_ + 10)),
          a_(0), da_(-0.05), range_(100), timer_(0), ball_(NULL)
    {}
    
    void rotate();
    void draw();
    void push(Ball * ball)
    {
        if (in_range(ball))
            victims_.push_back(ball);
    }
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
    void x_y(const int x, const int y)
    {
        int dx = x - cntr_.x();
        int dy = y - cntr_.y();
        move(dx, dy);
    }
    Line target(Ball * ball);
    void run()
    {
        for (std::list< Bullet * >::iterator p = amo.begin();
             p != amo.end(); ++p)
        {
            (*p)->run();
            if ((*p)->x() < 0 || (*p)->x() >= W || (*p)->y() >= H || (*p)->x() < 0)
            {
                std::list< Bullet * >::iterator q = p;
                ++p;
                delete (*q);
                amo.erase(q);
                if (p == amo.end())
                {break;}
            }
        }
        
        if (!(victims_.empty()))
        {
            std::list< Ball * >::iterator p = victims_.begin();
            if (in_range(*p) && (*p)->alive_)
                target(*(victims_.begin()));
            else
                victims_.erase(p);    
        }
        if (timer_ % 100 == 0 && victims_.size() != 0)
        {
            shoot();
        }
        ++timer_;
    }
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
    std::unordered_map<Ball *, char> v_;
    //std::stack<>
    Ball * ball_;
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
