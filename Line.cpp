#include "Line.h"

Surface * Line::surface_ = nullptr;

Line::Line(int x, int y, double m, double d)
    : m_(m), d_(d),
      begin_(x, y)
{
    if (m_ == 0)
    {
        end_.set_y(y);
        end_.set_x(x + d);
        //std::cout << end_.y() << std::endl;
        
    }
    else
    {
    int x1_ = d_ * cos(atan(m_)) + x;
    int y1_ = d_ * sin(atan(m_)) + y;
    end_ = vec2i(x1_, y1_);
    }
}

Line::Line(int x0, int y0, int x1, int y1)
    : begin_(x0, y0), end_(x1, y1)
{
    m_ = double(y0 - y1) / double(x1 - x0);
    d_ = sqrt((y0 - y1) * (y0 - y1) + (x0 - x1) * (x0 - x1));
}

void Line::move(int dx, int dy)
{
    begin_.move(dx, dy);
    end_.move(dx, dy);
}

void Line::draw()
{
    surface_->put_line(begin_, end_, 255, 255, 255);
}

Line & Line::operator=(const Line & line_)
{
    begin_ = line_.begin();
    end_ = line_.end();
    m_ = line_.m();
    d_ = line_.d();
    return *this;
}

void Line::set_surface(Surface * surface)
{
    surface_ = surface;
}

