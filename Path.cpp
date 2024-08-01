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
    //std::cout << road_.size() << std::endl;
}

void Path::generate_path()
{
    clear();
    int x = startx;
    int y = starty;
    int i = 0;
    int d = w;
    while (x != startx + w && y != 0 && y != h)
    {
        if (i % 2 == 0)
        {
            int x1 = 0;
            if ((startx + w) - x > 20)
            {
                x1 = rand() % (w - (x + 25) + 1  ) + x + 25;
                //std::cout << x1 << std::endl;
                // 10 + x <----> W
                // 
                // rand() %  + 10 + x
                
            }
            else
            {
                x1 = startx + w;
            }
            
            
            if (x1 > startx + w)
            {
                x1 = startx + w;
            }
            
            //ystd::cout << "x0: " << x << " x1: " << x1 << std::endl;
            road_.push_back(new Line(x, y, x1, y));
            x = x1;
            endx = x;
            endy = y;
        }
        else
        {
            int y1 = rand() %  h;
            road_.push_back(new Line(x, y, x, y1));
            y = y1;
            endx = x;
            endy = y;
        }
        ++i;
        // std::cout << i << std::endl;
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
    surface_ = surface;
}
