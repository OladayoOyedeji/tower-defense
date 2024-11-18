//Oyedeji Oladayo
#include "Path.h"

Surface * Path::surface_ = nullptr;

Path::~Path()
{
    clear();
}

void Path::clear()
{
    std::list< Line * >::iterator p = road_.end();
    --p;
    int size = road_.size();
    for (int i = 0; i < size ; ++i)
    {
        delete (*p);
        p--;
        road_.pop_back();
    }
}

void Path::generate_path()
{
    clear();
    
    int x = startx;
    int y = starty;
    int i = 0;
    int d = w;
    while (x < endx-1 || y < endy || y > 0)
    {
        if (dir_ == HORIZONTAL)
        {
            if (endx - x < w / 4)
            {
                vec2i start(x, y);
                vec2i end(endx - 1, y);
                x = end.x(); y = end.y();
                road_.push_back(new Line(start, end));
                // std::cout << "1" << start << ' ' << end << std::endl;
                return;
            }
            else
            {
                vec2i start(x, y);
                int midx = (endx - x) / 2 + x;
                vec2i end(rand() % (midx - x - 10) + x, y);
                x = end.x(); y = end.y();
                road_.push_back(new Line(start, end));
                // std::cout << "2" << start << ' ' << end << std::endl;
                dir_ = VERTICAL;
            }
        }
        else
        {
            int d = rand() % 2;
            if (d == 0)
            {
                vec2i start(x, y);
                int new_y = rand() % (y - starty - 1) + 10;
                vec2i end(x, new_y);
                road_.push_back(new Line(start, end));
                std::cout << "3" << start << ' ' << end << std::endl;
                x = end.x(); y = end.y();
                dir_ = HORIZONTAL;
            }
            else
            {
                vec2i start(x, y);
                vec2i end(x, rand() % (endy - y) + 10);
                road_.push_back(new Line(start, end));
                // std::cout << "4" << start << ' ' << end << std::endl;
                x = end.x(); y = end.y();
                dir_ = HORIZONTAL;
            }
        }
        
    }
}

void Path::draw()
{
    for (std::list< Line * >::iterator p = road_.begin();
         p != road_.end(); ++p)
    {
        //std::cout << (*p)->surface() << std::endl;
        (*p)->draw();
    }
}

void Path::set_surface(Surface * surface)
{
    Line().set_surface(surface);
    surface_ = surface;
}
