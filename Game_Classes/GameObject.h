#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <cmath>
#include "Path.h"
#include "Constants.h"

class GameObject
{
public:
    GameObject()
    {}
    GameObject(const vec2i & pos)
        : pos_(pos)
    {}
    GameObject(int, int, int, double, double,
               double, const Color&);
    GameObject(const vec2i&, int, const vec2d&,
               double, const Color&);
    // towers constructor
    GameObject(const vec2i& pos, int radius, const Color& color)
        : pos_(pos), radius_(radius), vel_(0),
          color_(color), alive_(true)
    {}
    virtual void move()
    {
        pos_ += dir_;
    }
    double vel() const
    {
        return vel_;
    }
    virtual void draw()
    {
        surface_->put_circle(pos_, radius_, color_);
    }
    virtual void run()
    {
        if (alive_)
            move();
    }
    bool alive() const
    {
        return alive_;
    }
    int radius() const
    {
        return radius_;
    }
    bool & alive()
    {
        return alive_;
    }
    vec2i pos() const
    {
        return pos_;
    }
    static void set_surface(Surface *);
    vec2i pos_;
    vec2d dir_;
    int radius_;
    double vel_;
    Color color_;
    bool alive_;
    static Surface * surface_;
    
};

class Ball: public GameObject
{
public:
    Ball(Path * path, int r, double vel)
        : path_(path), GameObject(path->start(), r,
                                  path->vector(), rand()/RAND_MAX * 2 + rand() % 2 + 1,
                                  RED), p(path_->begin())
    {
        
    }
    
    Ball(int x, int y, int r,
         double dx = 0, double dy = 0)
        : GameObject(x, y, r, dx, dy, 1,  RED)
    {}
    
    virtual void draw()
    {
        surface_->put_circle(pos_, radius_, color_);
        surface_->put_unfilled_circle(pos_, radius_,
                                      rand() % 255, rand() % 255,
                                      rand() % 255);
    }
    int x() const
    {
        return pos_.x();
    }
    int y() const
    {
        return pos_.y();
    }
    int rad() const
    {
        return radius_;
    }

    void x_y(const int x, const int y)
    {
        pos_.set_x(x);
        pos_.set_y(y);
    }
    
    virtual void run();
    
    Path * path_;
    std::list< Line * >::iterator p;
};

inline
bool eq(const Color & c1, const Color c2)
{
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}

#endif
