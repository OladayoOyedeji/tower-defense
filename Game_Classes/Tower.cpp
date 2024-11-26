#include "Tower.h"

bool big_p(Ball * ball1, Ball * ball2)
{
    return ball1->rad() > ball2->rad();
}
bool smal_p(Ball * ball1, Ball * ball2)
{
    return ball1->rad() < ball2->rad();
}
bool fast_p(Ball * ball1, Ball * ball2)
{
    return ball1->vel() > ball2->vel();
}
bool slow_p(Ball * ball1, Ball * ball2)
{
    return ball1->vel() < ball2->vel();
}

Surface * Tower::surface_ = NULL;

void Tower::set_surface(Surface * surface)
{
    surface_ = surface;
}

void Tower::push(Ball * ball)
{
    if (in_range(ball))
        victims_.insert(ball);
}

void Tower::x_y(const int x, const int y)
{
    int dx = x - pos_.x();
    int dy = y - pos_.y();
    dir_(double(dx), double(dy));
    move();
}
void Tower::run()
{       
    if (!(victims_.is_empty()))
    {
        target(victims_.max());
        victims_.clear();
    }
    ++timer_;
}
void Tower::draw()
{
    surface_->put_circle(pos_, radius_, color_);
    mouth_.draw();
    if (range_show_)
    {
        surface_->put_unfilled_circle(pos_, range_, WHITE);
    }
}

Line Tower::target(Ball * ball)
{
    target_ = Line(pos(), ball->pos());
    return target_;
}

