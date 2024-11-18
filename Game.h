#ifndef GAME_H
#define GAME_H

#include "include.h"
#include <stack>

const int num_R_tower = 3;
const int num_B_tower = 3;
const int num_W_tower = 3;
const int num_G_tower = 3;
const int num_bloons = 1000;
const int fps = 60;

class Game
{
public:
    Game(Surface * surface)
        : surface_(surface), tower_(num_R_tower + num_B_tower + num_W_tower + num_G_tower),
          path_(W, H, 0, H/2), count_(0), a_timer_(0),
          RATE_(1000 / 60), bloons_move_(false)
    {
        path_.set_surface(surface_);
        path_.generate_path();
        GameObject().set_surface(surface_);
        for (int i = 0; i < tower_.size(); ++i )
        {
            tower_[i]->set_surface(surface);
            if (i >= 0 && i < num_B_tower)
                tower_[i] = new B_tower(vec2i(0 + 10, 0 + 10));
            else if (i >= num_W_tower && i < num_B_tower + num_R_tower)
                tower_[i] = new R_tower(vec2i(0 + 20, 0 + 20));
            else if (i >= num_B_tower + num_R_tower && i < num_B_tower + num_R_tower + num_W_tower)
                tower_[i] = new W_tower(vec2i(0 + 10, 0 + 20));
            else
                tower_[i] = new G_tower(vec2i(0 + 10, 0 + 20));
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
        for (std::list<Ball *>::iterator p = bloons_.begin(); p != bloons_.end();
            ++p)
        {
            delete *p;
            *p = NULL;
        }
        for (std::list<Bullet *>::iterator p = amo_.begin(); p != amo_.end();
            ++p)
        {
            delete *p;
            *p = NULL;
        }
        
    }
    void mouse_move();
    void game_input(bool &);
    void bloons_move();
    void run();
    void draw();
    void shoot(Ball * ball, Tower * tower);
    void collision_detection();
    bool bloons_move_;
    int a_timer_;
    
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
