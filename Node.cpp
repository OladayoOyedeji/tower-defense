#include "Node.h"

void QuadtreeNode::insert(Bullet * bul)
{
    if (!empty())
    {
        for (int i = 0; i < children_.size(); ++i)
        {
        
            if (children_[i] != NULL)
            {
                if (bul->x() < children_[i]->startx_ && ball->x() < children_[i]->endx_
                    && bul->y() < children_[i]->starty_ && ball->y() < children_[i]->endy_)
                {
                    children_[i]->amo_.push_back(bul);
                }
            }
        }
    }
}
void QuadtreeNode::insert(Ball * bul)
{
    if (!empty())
    {
        for (int i = 0; i < children_.size(); ++i)
        {
        
            if (children_[i] != NULL)
            {
                if (bul->x() < children_[i]->startx_ && ball->x() < children_[i]->endx_
                    && bul->y() < children_[i]->starty_ && ball->y() < children_[i]->endy_)
                {
                    children_[i]->bloons_.push_back(bul);
                }
            }
        }
    }
}
bool empty()
{
    for (int i = 0; i < children_.size(); ++i)
    {
        if (children_[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
void QuadtreeNode::split()
{
    if (empty())
    {
        if (bloons_.size() + amo_.size() > 4)
        {
            // start
            int midx = (endx_ - startx_) / 2 + startx_;
            int midy = (endy_ - starty_) / 2 + starty_;
            children_[0] = (new QuadTreeNode(startx_, starty_, midx_, midy_));
            children_[1] = (new QuadTreeNode(midx_, starty_, endx_, midy_));
            children_[2] = (new QuadTreeNode(startx_, midy_, midx_, endy_));
            children_[3] = (new QuadTreeNode(midx_, midy_, endy_, endx_));
        }
        for (std::list<Bullet *>::iterator p = amo_.begin();
             p != amo_.end(); ++p)
        {
            insert(*p);
        }
    
        for (std::list<Ball *>::iterator p = amo_.begin();
             p != amo_.end(); ++p)
        {
            insert(*p);
        }
    }
}
void QuadtreeNode::collision();
