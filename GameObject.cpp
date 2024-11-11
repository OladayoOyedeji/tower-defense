#include "GameObject.h"


Surface * GameObject::surface_ = NULL;

void GameObject::set_surface(Surface * surface)
{
    surface_ = surface;
}

GameObject::GameObject(int x, int y, int radius,
                       double dx, double dy, double vel,
                       const Color & col)
    : pos_(x, y), radius_(radius), vel_(vel),
      dir_(dx, dy), color_(col), alive_(true)
{
    dir_.unit();
    dir_ *= vel;
}

GameObject::GameObject(const vec2i & pos, int radius,
                       const vec2d & dir, double vel,
                       const Color & color)
    : pos_(pos), radius_(radius), vel_(vel),
      dir_(dir), color_(color), alive_(true)
{
    dir_.unit();
    dir_ *= vel;
}

void Ball::run()
{

    if (p != path_->end())
    {
        if (!((*p)->whithin(pos_)))
        {
            pos_ = vec2i((*p)->end());
            p++;
            if (p != path_->end())
            {
                dir_ = (*p)->grad();
                dir_.unit();
                dir_ *= vel_;
            }
            move();
        }
        else
        {
            move();
        }
    }
}
