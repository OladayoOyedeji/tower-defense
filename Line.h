#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Surface.h"

class Line
{
public:
    Line()
    {}
    Line(int x, int y, double m, double d);
    Line(const vec2i & begin, double m, double d, vec2i & dir)
        : begin_(begin), m_(m), d_(d)
    {
        if (m_ == 0)
        {
            end_.set_y(begin_.y());
            end_.set_x(begin_.x() + dir.x() * d);
        
        }
        else
        {
            int x1_ = begin_.x() + dir.y() * d_ * cos(atan(m_));
            int y1_ = begin_.y() + dir.x() * d_ * sin(atan(m_));
            // std::cout << "y direction: " << dir.y() << ' '
            //           << "x direction: " << dir.x() << '\n';
            end_ = vec2i(x1_, y1_);
        }
    }
    Line(const vec2i & point1, const vec2i & point2)
        : begin_(point1), end_(point2)
    {}
    Line(int x, int y)
        : begin_(x, y), end_(x, y), m_(0), d_(0)
    {}
    Line(const vec2i & v)
        : begin_(v), end_(v)
    {}
    Line(int x0, int y0, int x1, int y1);
    Line(Line & l1, Line & l2);
    int x0() const
    {
        return begin_.x();
    }
    int y0() const
    {
        return begin_.y();
    }
    int x1() const
    {
        return end_.x();
    }
    int y1() const
    {
        return end_.y();
    }
    double m() const
    {
        return m_;
    }
    double d() const
    {
        return d_;
    }
    int dx() const
    {
        return end_.x() - begin_.x();
    }
    int dy() const
    {
        return end_.y() - begin_.y();
    }
    vec2d grad() const
    {
        return vec2d(dx(), dy());
    }
    Line & operator=(const Line & line);

    vec2i begin() const
    {
        return begin_;
    }

    vec2i end() const
    {
        return end_;
    }
    
    void operator()(int x, int y)
    {
        end_.set_x(x);
        end_.set_y(y);
        m_ = double(end_.y() - begin_.y()) / double(end_.x() - begin_.x());
        d_ = sqrt((end_.y() - begin_.y()) * (end_.y() - begin_.y()) + (end_.x() - begin_.x()) * (end_.x() - begin_.x()));
    }
    void operator()(const vec2i & p)
    {
        end_ = p;
    }
    void move(int, int);
    void draw();
    Surface * surface()
    {
        return surface_;
    }
    bool whithin(const vec2i & p)
    {
        //if ()
        return (p.x() >= begin_.x() && p.x() <= end_.x()
                && p.y() >= begin_.y() && p.y() <= end_.y()) ||
            (p.x() <= begin_.x() && p.x() >= end_.x()
                && p.y() <= begin_.y() && p.y() >= end_.y());
    }
    static void set_surface(Surface * surface);
//private:
    vec2i begin_;
    vec2i end_;
    double m_;
    double d_;
    static Surface * surface_;
};

#endif





















































// class Line
// {
// public:
//     Line()
//     {}
//     Line(int x, int y, double m, double d);
//     Line(int x0, int y0, int x1, int y1);
//     Line(Line & l1, Line & l2);
//     void draw();
//     Surface * surface()
//     {
//         return surface_;
//     }
//     static void set_surface(Surface * surface);
    
//     int x0_, y0_, x1_, y1_, xm, ym;
//     double m_;
//     double d_;
//     static Surface * surface_;
// };
