#include "Game.h"

void Game::mouse_move()
{
    static bool click = false;
    if (!(mouse_mov_.empty()))
    {
        std::cout << "hello" << std::endl;
        Tower * t = mouse_mov_.top();
        if (mouse_.left() && in_ob(mouse_, *t))
        {
            mouse_.update(event_);
            t->x_y(mouse_.x(), mouse_.y());
            click = true;
        }
        else if (!(mouse_.left()) && click)
        {
            mouse_mov_.pop();
            click = false;
        }
        else
            mouse_.update(event_);
    }
}
void Game::bloons_move()
{
    static int nums = 0;
    if (count_ % 60 == 0 && nums != num_bloons)
    {
        nums++;
        bloons_.push_back(new Ball(&path_, rand() % 30 + 10, rand() / RAND_MAX + 2));
    }
    count_++;
    for (std::list< Ball * >::iterator p = bloons_.begin();
         p != bloons_.end(); ++p)
    {
        (*p)->run();
        // int r = sqrt(((*p)->x() - t.x()) * ((*p)->x() - t.x()) + ((*p)->y() - t.y()) * ((*p)->y() - t.y()));
        // if (r < t.range())
        // {
        //     //t.push((*p));
        //     shoot((*p));
        // }
            
        if ((*p)->x() - (*p)->rad() >= W)
        {
            std::list< Ball * >::iterator q = p;
            ++p;
            delete (*q);
            bloons_.erase(q);
            if (p == bloons_.end())
            {break;}
        }

    }
}
void Game::draw()
{
    surface_->lock();
    surface_->fill(BLACK);
    path_.draw();
    for (std::list< Ball * >::iterator p = bloons_.begin();
         p != bloons_.end(); ++p)
    {
        (*p)->draw();
    }
    for (int i = 0; i < tower_.size(); ++i)
    {
        tower_[i]->draw();
    }
    //ball->draw();
    surface_->unlock();
        
    surface_->flip();
}
// void Game::shoot()
// {
//     for (int i = 0; i < num_tower; ++i)
//     {
        
//         amo_.push_back(new Bullet(tower _[i]->target()));
//     }
// }
void Game::collision_detection()
{}
// void Game::delay()
// {}

void Game::run()
{
    bool s_pressed = false;
    while (1)
    {
        if (event_.poll() && event_.type() == QUIT) break;
        int start = getTicks();
        mouse_move();
        bloons_move();
        //shoot();
        collision_detection();
        draw();
        //delay();
        int end = getTicks();
        int dt = RATE_ - end + start;
        if (dt > 0)
        {delay(dt);}
    }
}
