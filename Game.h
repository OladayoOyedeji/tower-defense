#ifndef GAME_H
#define GAME_H

#include "include.h"
#include <stack>

const int num_tower = 3;
const int num_bloons = 50;
const int fps = 60;

class Game
{
public:
    Game(Surface * surface)
        : surface_(surface), tower_(num_tower),
          path_(W, H, 0, H/2), count_(0),
          RATE_(1000 / 60)
    {
        path_.set_surface(surface_);
        path_.generate_path();
        GameObject().set_surface(surface_);
        for (int i = 0; i < num_tower; ++i)
        {
            tower_[i]->set_surface(surface);
            tower_[i] = new Tower(0 + 10, 0 + 10);
            mouse_mov_.push(tower_[i]);
        }
    }
    ~Game()
    {
        for (int i = 0; i < tower_.size(); ++i)
        {
            delete tower_[i];
            tower_[i] = NULL;
        }
        for (std::list<Ball*>::iterator p = bloons_.begin(); p != bloons_.end();
            ++p)
        {
            delete *p;
            *p = NULL;
        }
    }
    void mouse_move();
    void bloons_move();
    void run();
    void draw();
    void shoot();
    void collision_detection();
    //void delay();
private:
    Surface * surface_;
    Event event_;
    std::vector<Tower *> tower_;
    std::stack<Tower *> mouse_mov_;
    Path path_;
    std::list< Bullet * > amo_;
    std::list< Ball * > bloons_;
    //
    int RATE_;
    Mouse mouse_;
    int count_;
    
};

#endif
