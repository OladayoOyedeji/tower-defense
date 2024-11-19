#ifndef QUADTREE_H
#define QUADTREE_H

#include "Node.h"

class QuadTree
{
  public:
    QuadTree(int startx, int starty, int endx, int endy,
             std::list< Bullet * > & amo, std::list< Ball * > & bloons)
        : root_(new QuadTreeNode(startx, starty, endx, endy, amo, bloons))
    {
        root_->split();
    }
    ~QuadTree()
    {
        root_->clear_children();
        delete root_;
    }
    void draw(Surface &surface)
    {
        root_->draw(surface);
    }
  private:
    QuadTreeNode * root_;
};

#endif
