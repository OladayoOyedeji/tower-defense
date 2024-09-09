#include "Tower.h"

Surface * Tower::surface_ = NULL;

void Tower::set_surface(Surface * surface)
{
    surface_ = surface;
}



void Tower::rotate()
{
    a_ += da_;
    if (a_ > 3.1414 * 2)
    {
        a_ -= 3.1414 * 2;
    }
    else if (a_ < 0)
    {
        a_ += 3.1414 * 2;
    }
    int endy = mouth_.d_ * sin(a_) + cntr_.y();
    int endx = mouth_.d_ * cos(a_) + cntr_.x();
    mouth_(endx, endy);
}

void Tower::draw()
{
    surface_->put_circle(cntr_, r_, BLUE);
    target_.draw();
    mouth_.draw();
    for (std::list< Bullet * >::iterator p = amo.begin();
         p != amo.end(); ++p)
    {
        (*p)->draw();
    }
    surface_->put_unfilled_circle(cntr_, range_, WHITE);
}

void Tower::target(Ball * ball)
{
    target_(ball->x(), ball->y());
    std::cout << target_.m() << std::endl;
    vec2i dir(1, 1);
    if (ball->x() < target_.x0())
    {
        dir.set_y(-1);
        dir.set_x(-1);
    }
    target_ = Line(target_.begin(), target_.m(), mouth_.d(), dir);
}

void Tower::shoot()
{
    int dir = 1;
    if (target_.x1() < target_.x0())
    {
        dir = -1;
    }
    amo.push_back(new Bullet(target_.end(), target_.m(), dir));
}

void Tower::move(int dx, int dy)
{
    target_.move(dx, dy);
    cntr_.move(dx, dy);
    mouth_.move(dx, dy);
}






















































































/*
Tower::Tower(int x, int y, int r)
    : cntrx(x), cntry(y),
      endx(x + r), endy(y), a_(0), da_(-0.05),
      dx(1), dy(0), r_(r), qdrt(true), w_(10)
{
    int h = w_ * tan(3.1414 / 3) / 2;
    double m = (endy - cntry) / (endx - cntrx);
    double m1 = -(1 / m);
    mx0 = endx;
    my0 = endy;
    mx1 = (w_ / 2) * cos(atan(m1)) + mx0;
    my1 = (w_ / 2) * sin(atan(m1)) + my0;
    mx0 = mx0 - (w_ / 2) * cos(atan(m1));
    my0 = my0 - (w_ / 2) * sin(atan(m1));
}

void Tower::rotate()
{
    // dy = ((-2 * (endx + cntrx)) / (2 * (endy + cntry))) * dx;
    // endx += dx;
    // endy += dy;
    // if (dy != r_ && qdrt)
    // {
    //     dx -= 1;
    //     dy -= 1;
        
    // }
    // else if ()
    // {
    //     dx -= 1;
    //     dy += 1;
    // }
    // else if (dx != r_)
    // {
    //     dx += 1;
    //     dy += 1;
    //     qdrt = false;
    // }
    // else if ()
    // {
    //     dx += 1;
    //     dy -= 1;
    // }
    // endx = cntrx + dx;
    // endy = cntry + dy;
    // static int rot = 1;
    // if (abs(endx - cntrx + dx) > r_)
    // {
    //     dx *= -1;fvw2 
    //     rot *= -1;
    // }
    // endx += dx;
    // std::cout << endx - cntrx << std::endl;
    // endy = cntry + rot * sqrt(r_ * r_ - (endx - cntrx) * (endx - cntrx));
    // std::cout << r_ << std::endl;
    a_ += da_;
    if (a_ > 3.1414 * 2)
    {
        a_ -= 3.1414 * 2;
    }
    else if (a_ < 0)
    {
        a_ += 3.1414 * 2;
    }
    endy = r_ * sin(a_) + cntry;
    endx = r_ * cos(a_) + cntrx;

    double m = (endy - cntry) / double(endx - cntrx);
    std::cout << endx - cntrx << ' ' << endy - cntry << " m: " << m << std::endl;
    double m1 = -1 / m;
    std::cout << m1 << std::endl;
    mx0 = endx;
    my0 = endy;
    mx1 = (w_ / 2) * cos(atan(m1)) + mx0;
    my1 = (w_ / 2) * sin(atan(m1)) + my0;
    mx0 = endx - (w_ / 2) * cos(atan(m1));
    my0 = endy - (w_ / 2) * sin(atan(m1));
}

void Tower::draw()
{
    
    //surface_->put_circle(cntrx, cntry, 100, 255, 255, 255);
    surface_->put_unfilled_circle(cntrx, cntry, r_, rand() % 256, rand() % 256 , rand() % 256);
    surface_->put_line(cntrx, cntry, endx, endy, 0, 0, 200);
    surface_->put_line(mx0, my0, mx1, my1, 0, 0, 200);
    double m = (endy - cntry) / double(endx - cntrx);
    std::cout << endx - cntrx << ' ' << endy - cntry << " m: " << m << std::endl;
    double m1 = -1 / m;
    std::cout << m1 << std::endl;
    int m1x0 = cntrx;
    int m1y0 = cntry;
    int m1x1 = (w_ / 2) * cos(atan(m1)) + m1x0;
    int m1y1 = (w_ / 2) * sin(atan(m1)) + m1y0;
    m1x0 = cntrx - (w_ / 2) * cos(atan(m1));
    m1y0 = cntry - (w_ / 2) * sin(atan(m1));
    surface_->put_line(m1x0, m1y0, m1x1, m1y1, 0, 0, 200);
    surface_->put_line(m1x0, m1y0, mx0, my0, 0, 0, 200);
    surface_->put_line(m1x1, m1y1, mx1, my1, 0, 0, 200);
    surface_->put_circle(cntrx, cntry, r_ - 10, rand() % 256, rand() % 256 , rand() % 256);
    surface_->put_unfilled_circle(cntrx, cntry, r_ - 10, rand() % 256, rand() % 256 , rand() % 256);
}
*/
