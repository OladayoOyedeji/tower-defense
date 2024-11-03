#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <cmath>
#include "Path.h"
#include "Constants.h"

class GameObject
{
public:
    GameObject(int, int, int, double, double,
               double, const Color&);
    GameObject(const vec2i&, int, const vec2d&,
               double, const Color&);
    virtual void move();
    virtual void run() = 0;
    void position();
    void radius();
//private:
    vec2i pos_;
    vec2d dir_;
    int radius_;
    double vel_;
    Color color_;
    static Surface * surface_;
};

class Ball : public GameObject
{
public:
    Ball()
    {}

    Ball(Path * path, int r)
        : path_(path), GameObject(path->startx, path->starty, r, (*p)->dx(), (*p)->dy(), 2,  RED)
    {
        
    }
    
    Ball(int x, int y, int r, double dx = 0, double dy = 0)
        : GameObject(x, y, r, dx, dy, 1,  RED)
    {}
    
    // Ball(int r)
    //     : radius_(r), dx(rand() % 5 + 1),
    //       dy(rand() % 5 + 1), x_(path_->startx), y_(path_->starty),
    //       r_(0), b_(200), g_(0), i(0), p(path_->road_.begin()),
    //       color(RED)
    // {}
    void draw()
    {
        surface_->put_circle(x_, y_, radius_, color);
        surface_->put_unfilled_circle(x_, y_, radius_, rand() % 255, rand() % 255, rand() % 255);
    }
    // void move()
    // {
    //     x_ += dx; y_ += dy;
    // }
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
        pos_.set_xy(x, y);
    }
    
    //bool collide(const Ball * ball) const;

    void run();
    static void set_surface(Surface *);
    static void set_path(Path *);
//private:
    // int radius_, x_, y_, r_, b_, g_, dx, dy;
    // Color color;
    Path * path_;
    // static Surface * surface_;
    // int i;
    // std::list< Line * >::iterator p;
};

inline
bool eq(const Color & c1, const Color c2)
{
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}

#endif
