#include "Line.h"

Surface * Line::surface_ = nullptr;

Line::Line(int x, int y, double m, double d)
    : x0_(x), y0_(y), m_(m), d_(d)
{
    x1_ = d_ * cos(atan(m_));
    y1_ = d_ * sin(atan(m_));
}

Line::Line(int x0, int y0, int x1, int y1)
    : x0_(x0), y0_(y0), x1_(x1), y1_(y1)
{
    m_ = double(y0 - y1) / double(x1 - x0);
    d_ = sqrt((y0 - y1) * (y0 - y1) + (x0 - x1) * (x0 - x1));
}

void Line::draw()
{
    surface_->put_line(x0_, y0_, x1_, y1_, 255, 255, 255);
}

void Line::set_surface(Surface * surface)
{
    surface_ = surface;
}
