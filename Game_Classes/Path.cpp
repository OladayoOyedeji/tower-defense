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
    int y = (endy - starty) / 2 + starty;
    int i = 0;
    int d = w;
    while (x < endx-1 && y < endy && y > starty)
    {
        vec2i start(x, y);
        vec2i end;
        if (dir_ == HORIZONTAL)
        {
            if (endx - x < w / 4)
            {
                
                end(endx - 1, y);
                x = end.x(); y = end.y();
                road_.push_back(new Line(start, end));
                std::cout << "1 " << start << ' ' << end << std::endl;
                return;
            }
            else
            {
                int midx = (endx - x) / 2 + x;
                end(rand() % (midx - x - 10) + x, y);
                x = end.x(); y = end.y();
                road_.push_back(new Line(start, end));
                // std::cout << "2" << start << ' ' << end << std::endl;
                dir_ = VERTICAL;
            }
        }
        else
        {
            int d = rand() % 2;
            if (y - starty < 30)
            {
                d = 1;
            }
            if (d == 0)
            {
                int new_y = rand() % (y - starty - 1) + starty;
                std::cout << "new_y:" << new_y << " starty: " << starty << std::endl;
                end(x, new_y);
                road_.push_back(new Line(start, end));
                
                x = end.x(); y = end.y();
                std::cout << "new vector: " << end << std::endl;
                dir_ = HORIZONTAL;
            }
            else
            {
                end(x, rand() % (endy - y) + y);
                road_.push_back(new Line(start, end));
                // std::cout << "4" << start << ' ' << end << std::endl;
                x = end.x(); y = end.y();
                dir_ = HORIZONTAL;
            }
        }
        std::cout << "3 " << start << ' ' << end << std::endl;
        
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
    Line::set_surface(surface);
    surface_ = surface;
}
