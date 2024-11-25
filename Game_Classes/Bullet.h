#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class Bullet: public GameObject
{
public:
    Bullet(const Line & target)
        : GameObject(target.begin(), 4, target.grad(), 5.5, RED),
          pointd_(target.x0(), target.y0())
    {}
    virtual void move()
    {
        pointd_.move(dir_.x(), dir_.y());
        pos_.set_x(pointd_.x());
        pos_.set_y(pointd_.y());
    }
    virtual void run()
    {
        move();
    }
    int x()
    {
        return pos_.x();
    }
    int y()
    {
        return pos_.y();
    }
private:
    vec2d pointd_;
};

#endif
