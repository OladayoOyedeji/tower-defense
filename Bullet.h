#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class Bullet
{
public:
    Bullet();
    Bullet(int, int, double, int);
    Bullet(const vec2i &, double, int);
    void move();
    void run();
    void draw();
    int x()
    {
        return point_.x();
    }
    int y()
    {
        return point_.y();
    }
    static void set_surface(Surface * surface);
private:
    vec2i point_;
    vec2d pointd_;
    double dx_, dy_;
    int vel_;
    int r_;
    int dir_;
    double m_;
    static Surface * surface_;
};

#endif
