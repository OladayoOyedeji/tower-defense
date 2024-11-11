#ifndef QUADTREENODE_H
#define QUADTREENODE_H

class QuadTreeNode
{
public:
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
    void split();
    void collision();
        
private:
    std::list< Bullet * > amo_;
    std::list< Ball * > bloons_;
    int startx_, starty_;
    int endx_, endy_;
    QuadTreeNode * parent_;
    std::vector<QuadTreeNode *> children_;
};

#endif
