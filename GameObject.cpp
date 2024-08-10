#include "GameObject.h"

Surface * Ball::surface_ = NULL;
Path * Ball::path_ = NULL;

bool Ball::collide(const Ball * ball) const
{
    int distx = abs(ball->x() - x_);
    int disty = abs(ball->y() - y_);
    int dist = sqrt(distx * distx + disty * disty);
    return dist <= ball->rad() + radius_;
}

void Ball::run()
{
    if (p != path_->road_.end())
    {
        if (i % 2 == 0)
        {
            dx = 1;
            dy = 0;
        }
        else
        {
            int in = 1;
            if ((*p)->y1() - (*p)->y0() < 0)
            {
                in = -1;
            }
            dy = 1 * in;
            dx = 0;
        }
        move();
        if (x_ >= (*p)->x1() && y_ == (*p)->y1())
        {
            x_ = (*p)->x1();
            y_ = (*p)->y1();
            ++p;
            ++i;
        }
    }
    else
    {
        move();
    }
}

void Ball::set_surface(Surface * surface)
{
    surface_ = surface;
}

void Ball::set_path(Path * path)
{
    path_ = path;
}
