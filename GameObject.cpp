#include "GameObject.h"

GameObject::GameObject(int x, int y, int radius,
                       double dx, double dy, double vel,
                       const Color & col)
    : pos_(x, y), radius_(radius), vel_(vel),
      dir_(dx, dy), color_(col)
{
    dir_.unit();
    dir_ *= vel;
}

virtual void GameObject::move()
{
    pos_ += dir_;
}


GameObject::GameObject(const vec2i & pos, int radius,
                       const vec2d & dir, const Color & color)
    : pos_(pos), radius_(radius), dir_(dir), color_(color)
{}

Surface * GameObject::surface_ = NULL;
//Path * Ball::path_ = NULL;

// bool Ball::collide(const Ball * ball) const
// {
//     int distx = abs(ball->x() - x_);
//     int disty = abs(ball->y() - y_);
//     int dist = sqrt(distx * distx + disty * disty);
//     return dist <= ball->rad() + radius_;
// }

void Ball::run()
{
    static std::list< Line * >::iterator p = path_->begin();
    
    if (!((*p)->whithin(pos)))
    {
        p++;
        pos_ = vec2i((*p)->x0(), (*p)->y0());
        dir_.set_xy((*p)->dx(), (*p)->dy());
        dir.unit();
        dir *= vel_;
    }
    else
    {
        move();
    }
    // if (p != path_->end())
    // {
    //     if (i % 2 == 0)
    //     {
    //         dx = 1;
    //         dy = 0;
    //     }
    //     else
    //     {
    //         int in = 1;
    //         if ((*p)->y1() - (*p)->y0() < 0)
    //         {
    //             in = -1;
    //         }
    //         dy = 1 * in;
    //         dx = 0;
    //     }
    //     move();
    //     if (x_ >= (*p)->x1() && y_ == (*p)->y1())
    //     {
    //         x_ = (*p)->x1();
    //         y_ = (*p)->y1();
    //         ++p;
    //         ++i;
    //     }
    // }
    // else
    // {
    //     move();
    // }
}

void Ball::set_surface(Surface * surface)
{
    surface_ = surface;
}

void Ball::set_path(Path * path)
{
    path_ = path;
}
