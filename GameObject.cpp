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
            //std::cout << "\n";
        }
        else
        {
            int in = 1;
            if ((*p)->y1_ - (*p)->y0_ < 0)
            {
                in = -1;
            }
            //std::cout << (*p)->y1_ - (*p)->y0_ << std::endl;
            dy = 1 * in;
            dx = 0;
            //std::cout << "vertical\n";
        }
        move();
        if (x_ >= (*p)->x1_ && y_ == (*p)->y1_)
        {
            x_ = (*p)->x1_;
            y_ = (*p)->y1_;
            ++p;
            ++i;
        }
    }
    else
    {
    // if (x_ >= path_->endx && y_ == path_->endy)
    // {
    //     x_ = path_->endx;
    //     y_ = path_->endy;
    // }
    move();
    }
    //std::cout << i << std::endl;
    // if (x_ < 0 || x_ > W || y_ < 0 || y_ > H)
    // {
    //     if (x_ < 0)
    //     {
    //         x_ = 0;
    //         dx *= -1;
    //     }
    //     if (x_ > W)
    //     {
    //         x_ = W;
    //         dx *= -1;
    //     }
    //     if (y_ < 0)
    //     {
    //         y_ = 0;
    //         dy *= -1;
    //     }
    //     if (y_ > H)
    //     {
    //         y_ = H;
    //         dy *= -1;
    //     }
    //     if (eq(color, BLUE))
    //     {
    //         color = RED;
    //     }
    //     else
    //     {
    //         color = BLUE;
    //     }
    //     //std::cout << color.r << std::endl;
    //}
}

void Ball::set_surface(Surface * surface)
{
    surface_ = surface;
}

void Ball::set_path(Path * path)
{
    path_ = path;
}
