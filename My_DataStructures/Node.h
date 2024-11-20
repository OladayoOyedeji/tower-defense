#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <list>
#include <vector>
#include "Bullet.h"
#include "Surface.h"


class QuadTreeNode
{
public:
    QuadTreeNode(int startx, int starty, int endx, int endy,
                 std::list< Bullet * > & amo, std::list< Ball * > & bloons)
        : startx_(startx), starty_(starty), children_(4),
          endx_(endx), endy_(endy), parent_(NULL), amo_(amo),
          bloons_(bloons)
    {
        for (int i = 0; i < children_.size(); ++i)
        {
            children_[i] = NULL;
        }
    }
    QuadTreeNode(int startx, int starty, int endx, int endy,
                 QuadTreeNode * parent = NULL)
        : startx_(startx), starty_(starty), children_(4),
          endx_(endx), endy_(endy), parent_(parent)
    {
        for (int i = 0; i < 4; ++i)
        {
            children_[i] = NULL;
        }
    }
    void insert(Bullet * bul);
    void insert(Ball * bul);
    
    void child_insert(Bullet * bul);
    void child_insert(Ball * bul);
    
    void split();
    void collision();
    bool empty();
    void clear_children();

    void draw(Surface & surface);
        
private:
    std::list< Bullet * > amo_;
    std::list< Ball * > bloons_;
    int startx_, starty_;
    int endx_, endy_;
    QuadTreeNode * parent_;
    std::vector<QuadTreeNode *> children_;
};

#endif
