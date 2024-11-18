#include "Node.h"

void QuadTreeNode::insert(Bullet * bul)
{
    if (!empty())
    {
        for (int i = 0; i < children_.size(); ++i)
        {
            if (children_[i] != NULL && (bul->x() < children_[i]->startx_ &&
                                         bul->x() < children_[i]->endx_ &&
                                         bul->y() < children_[i]->starty_ &&
                                         bul->y() < children_[i]->endy_))
            {
                children_[i]->insert(bul);
                break;
            }
        }
    }
    else
    {
        amo_.push_back(bul);
    }
}
void QuadTreeNode::insert(Ball * bul)
{
    if (!empty())
    {
        for (int i = 0; i < children_.size(); ++i)
        {
            if (children_[i] != NULL && (bul->x() < children_[i]->startx_ &&
                                         bul->x() < children_[i]->endx_ &&
                                         bul->y() < children_[i]->starty_ &&
                                         bul->y() < children_[i]->endy_))
            {
                
                children_[i]->insert(bul);
                break;
            }
        }
    }
    else
    {
        bloons_.push_back(bul);
    }
}

void QuadTreeNode::child_insert(Bullet * bul)
{  
    for (int i = 0; i < children_.size(); ++i)
    {
        if (children_[i] != NULL && (bul->x() < children_[i]->startx_ &&
                                     bul->x() < children_[i]->endx_ &&
                                     bul->y() < children_[i]->starty_ &&
                                     bul->y() < children_[i]->endy_))
        {
                
            children_[i]->insert(bul);
            break;
        }
    }
}
void QuadTreeNode::child_insert(Ball * bul)
{  
    for (int i = 0; i < children_.size(); ++i)
    {
        if (children_[i] != NULL && (bul->x() < children_[i]->startx_ &&
                                     bul->x() < children_[i]->endx_ &&
                                     bul->y() < children_[i]->starty_ &&
                                     bul->y() < children_[i]->endy_))
        {
                
            children_[i]->insert(bul);
            break;
        }
    }
}
void child_insert(Ball * bul);

bool QuadTreeNode::empty()
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
void QuadTreeNode::clear_children()
{
    if (children_[0] != NULL)
    {
        children_[0]->clear_children();
        delete children_[0];
        children_[0] = NULL;
    }
    if (children_[1] != NULL)
    {
        children_[1]->clear_children();
        delete children_[0];
        children_[1] = NULL;
    }
    if (children_[2] != NULL)
    {
        children_[2]->clear_children();
        delete children_[0];
        children_[2] = NULL;
    }
    if (children_[3] != NULL)
    {
        children_[3]->clear_children();
        delete children_[0];
        children_[3] = NULL;
    }
        
}
void QuadTreeNode::split()
{
    if (empty())
    {
        if (bloons_.size() + amo_.size() > 8)
        {
            int midx = (endx_ - startx_) / 2 + startx_;
            int midy = (endy_ - starty_) / 2 + starty_;
            children_[0] = (new QuadTreeNode(startx_, starty_, midx, midy));
            children_[1] = (new QuadTreeNode(midx, starty_, endx_, midy));
            children_[2] = (new QuadTreeNode(startx_, midy, midx, endy_));
            children_[3] = (new QuadTreeNode(midx, midy, endy_, endx_));
            for (std::list<Bullet *>::iterator p = amo_.begin();
                 p != amo_.end(); ++p)
            {
                child_insert(*p);
            }

            int i = 0;
            for (std::list<Ball *>::iterator p = bloons_.begin();
                 p != bloons_.end(); ++p)
            {
                //std::cout << bloons_.size() << ' ' << i++ << std::endl;
                child_insert(*p);
            }
            for (int i = 0; i < 4; ++i)
            {
                if (children_[i] != NULL)
                {
                    children_[i]->split();
                }
            }
        }
        else
        {
            std::cout << "hello\n";
            collision();
        }
    }
}
void QuadTreeNode::collision()
{
    if (empty())
    {
        for (std::list<Bullet *>::iterator p = amo_.begin();
             p != amo_.end(); ++p)
        {
            std::cout << "check2\n";
            if ((*p)->alive() == true)
            {
                std::cout << "check\n";
                for (std::list<Ball *>::iterator q = bloons_.begin();
                     q != bloons_.end(); ++q)
                {
                    int r = (*p)->radius() + (*q)->rad();
                    if ((*p)->pos().dist((*p)->pos()) < r)
                    {
                        (*p)->alive() = false;
                        (*q)->alive() = false;
                        break;
                    }
                }
            }
            else break;
        }
    }
}
