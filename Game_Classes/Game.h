#ifndef GAME_H
#define GAME_H

#include "include.h"
#include <stack>

const int num_R_tower = 3;
const int num_B_tower = 3;
const int num_W_tower = 3;
const int num_G_tower = 3;
const int num_bloons = 300;
const int fps = 150;

class Game
{
public:
    Game();
    ~Game();
    void mouse_move();
    void game_input(bool &);
    void bloons_move();
    void run();
    void put_background();
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
    // replacing those stacks
    std::vector< std::stack<Tower *> > mouse_mov_;
    
    Path path_;
    std::list< Bullet * > amo_;
    std::list< Ball * > bloons_;
    //
    Menu menu_;
    int RATE_;
    Mouse mouse_;
    int count_;
    static Image image_;
    bool move;
};

#endif
