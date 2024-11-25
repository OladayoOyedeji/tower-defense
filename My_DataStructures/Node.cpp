#include "Node.h"
#include "Color.h"

void QuadTreeNode::insert(Bullet * bul)
{
    if (!empty())
    {
        for (int i = 0; i < children_.size(); ++i)
        {
            if (children_[i] != NULL && (bul->x() > children_[i]->startx_ &&
                                         bul->x() < children_[i]->endx_ &&
                                         bul->y() > children_[i]->starty_ &&
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
            if (children_[i] != NULL && (bul->x() > children_[i]->startx_ &&
                                         bul->x() < children_[i]->endx_ &&
                                         bul->y() > children_[i]->starty_ &&
                                         bul->y() < children_[i]->endy_))
            {
                std::cout << i << std::endl;
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
        if (children_[i] != NULL && (bul->x() > children_[i]->startx_ &&
                                     bul->x() < children_[i]->endx_ &&
                                     bul->y() > children_[i]->starty_ &&
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
        if (children_[i] != NULL && (bul->x() > children_[i]->startx_ &&
                                     bul->x() < children_[i]->endx_ &&
                                     bul->y() > children_[i]->starty_ &&
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
        delete children_[1];
        children_[1] = NULL;
    }
    if (children_[2] != NULL)
    {
        children_[2]->clear_children();
        delete children_[2];
        children_[2] = NULL;
    }
    if (children_[3] != NULL)
    {
        children_[3]->clear_children();
        delete children_[3];
        children_[3] = NULL;
    }
        
}
void QuadTreeNode::split()
{
    if (empty())
    {
        if (bloons_.size() + amo_.size() > 8)
        {
            std::cout << "split" << std::endl;
            int midx = (endx_ - startx_) / 2 + startx_;
            int midy = (endy_ - starty_) / 2 + starty_;
            children_[0] = (new QuadTreeNode(startx_, starty_, midx, midy, this));
            children_[1] = (new QuadTreeNode(midx, starty_, endx_, midy, this));
            children_[2] = (new QuadTreeNode(startx_, midy, midx, endy_, this));
            children_[3] = (new QuadTreeNode(midx, midy, endx_, endy_, this));
            for (std::list<Bullet *>::iterator p = amo_.begin();
                 p != amo_.end(); ++p)
            {
                if ((*p)->x() > startx_ &&
                    (*p)->x() < endx_ &&
                    (*p)->y() > starty_ &&
                    (*p)->y() < endy_)
                    child_insert(*p);
            }
            
            for (std::list<Ball *>::iterator p = bloons_.begin();
                 p != bloons_.end(); ++p)
            {
                if ((*p)->x() > startx_ &&
                    (*p)->x() < endx_ &&
                    (*p)->y() > starty_ &&
                    (*p)->y() < endy_)
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
            //std::cout << "hello\n";
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
            if ((*p)->alive())
            {
                
                for (std::list<Ball *>::iterator q = bloons_.begin();
                     q != bloons_.end(); ++q)
                {

                    if ((*q)->alive())
                    {
                        //std::cout << "check\n";
                        int r = (*p)->radius() + (*q)->rad();
                        if ((*p)->pos().dist((*q)->pos()) < r)
                        {
                            (*p)->alive() = false;
                            (*q)->alive() = false;
                            break;
                        }
                    }
                    
                }
            }
            else break;
        }
    }
}

void QuadTreeNode::draw(Surface & surface)
{
    // std::cout << "new Node:\n";
    // std::cout << vec2i(startx_, starty_) << "    " << vec2i(endx_, starty_) << std::endl;
    // std::cout << vec2i(startx_, endy_) << "    " << vec2i(endx_, endy_) << std::endl;
    Line l1(vec2i(startx_, starty_), vec2i(startx_, endy_));
    l1.draw();
    
    Line l2(vec2i(startx_, starty_), vec2i(endx_, starty_));
    l2.draw();
    
    Line l3(vec2i(endx_, starty_), vec2i(endx_, endy_));
    l3.draw();
    
    Line l4(vec2i(startx_, endy_), vec2i(endx_, endy_));
    l4.draw();
    // surface.put_line(startx_, starty_, endx_, starty_, WHITE);
    // surface.put_line(startx_, starty_, startx_, endy_, WHITE);
    // surface.put_line(startx_, endy_, endx_, endy_, WHITE);
    // surface.put_line(endx_, starty_, endx_, endy_, WHITE);
    for(int i = 0; i < children_.size(); ++i)
    {
        if (children_[i] != NULL)
        {
            children_[i]->draw(surface);
        }
    }
}
