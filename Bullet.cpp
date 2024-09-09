#include "Bullet.h"

Surface * Bullet::surface_ = NULL;

void Bullet::set_surface(Surface * surface)
{
    surface_ = surface;
}

Bullet::Bullet()
{}

Bullet::Bullet(int x, int y, double m, int dir)
    : point_(x, y), pointd_(x, y), r_(5), dir_(dir), m_(m),
      vel_(3), dx_(0), dy_(0)
{
    if (m_ == 0)
    {
        dx_ = vel_;
    }
    else
    {
        dx_ = vel_ * cos(atan(m_));
        dy_ = vel_ * sin(atan(m_));
    }
}

Bullet::Bullet(const vec2i & point, double m, int dir)
    : point_(point), pointd_(point.x(), point.y()), r_(5), dir_(dir), m_(m),
      vel_(5), dx_(0), dy_(0)
{
    if (m_ == 0)
    {
        dx_ = vel_;
    }
    else
    {
        dx_ = vel_ * cos(atan(m_));
        dy_ = vel_ * sin(atan(m_));
    }
}

void Bullet::move()
{
    std::cout << "before: " << point_.x() << ' ' << point_.y() << std::endl;
    pointd_.move(dir_ * dx_, dir_ * dy_);
    point_.set_x(pointd_.x());
    point_.set_y(pointd_.y());
    std::cout << "after: " << point_.x() << ' ' << point_.y() << std::endl;
}
void Bullet::run()
{
    move();
}
void Bullet::draw()
{
    surface_->put_circle(point_, r_, YELLOW);
}
