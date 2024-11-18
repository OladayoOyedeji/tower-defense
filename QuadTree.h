#ifndef QUADTREE_H
#define QUADTREE_H

#include "Node.h"

class QuadTree
{
  public:
    QuadTree(int startx, int starty, int endx, int endy, std::list< Bullet * > amo_,
             std::list< Ball * > bloons_)
    {
        root_->split();
    }
  private:
    QuadTreeNode * root_;
};

#endif
