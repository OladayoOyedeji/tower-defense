#include "Bullet.h"

// Bullet::Bullet(int x, int y, double m, int dir)
//     : point_(x, y), pointd_(x, y), r_(5), dir_(dir), m_(m),
//       vel_(3), dx_(0), dy_(0)
// {
//     if (m_ == 0)
//     {
//         dx_ = vel_;
//     }
//     else
//     {
//         dx_ = vel_ * cos(atan(m_));
//         dy_ = vel_ * sin(atan(m_));
//     }
// }

// Bullet::Bullet(const vec2i & point, double m, int dir)
//     : point_(point), pointd_(point.x(), point.y()), r_(5), dir_(dir), m_(m),
//       vel_(5), dx_(0), dy_(0)
// {
//     if (m_ == 0)
//     {
//         dx_ = vel_;
//     }
//     else
//     {
//         dx_ = vel_ * cos(atan(m_));
//         dy_ = vel_ * sin(atan(m_));
//     }
// }

// Bullet::Bullet(const Line & target)
//     : Game(target.begin(), r, target.grad(), 3, RED)
// {}

// virtual void Bullet::move()
// {
//     std::cout << "before: " << pos_.x() << ' ' << pos_.y() << std::endl;
//     pointd_.move(dir_.x(), dir_.y());
//     pos_ = pointd_;
//     std::cout << "after: " << pos_.x() << ' ' << pos_.y() << std::endl;
// }

// virtual void Bullet::run()
// {
//     move();
// }
