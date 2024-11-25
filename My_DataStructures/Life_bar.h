#ifndef LIFE_BAR_H
#define LIFE_BAR_H

#include "GameObject.h"

class Life_bar: public GameObject
{
  public:
    Life(vec2i & v, int red_c)
        : GameObject(v), life_(10), reducing_factor_(life_ / red_c)
    {}
    void reduce()
    {
        life_ -= reducing_factor_;
    }
    double red() const
    {
        return reducing_factor_;
    }
    double life() const
    {
        return life_;
    }
    virtual void draw()
    {
        surface_->put_rect(pos_, 8, 2, RED);
        surface_->put_rect(pos_.x() - 1, pos().y() - 1, 10, 2, RED);
    }
  private:
    double life_;
    double reducing_factor_;
};

#endif
