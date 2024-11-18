#include "Game.h"

void Game::mouse_move()
{
    static bool click = false;
    if (!(mouse_mov_.empty()))
    {
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
    if (bloons_move_)
    {
        static int nums = 0;
        if (count_ % 30 == 0 && nums != num_bloons)
        {
            nums++;
            bloons_.push_back(new Ball(&path_, rand() % 30 + 10, (rand() / RAND_MAX * 4) + 1));
        }
        count_++;
        for (std::list< Ball * >::iterator p = bloons_.begin();
             p != bloons_.end(); ++p)
        {
            (*p)->run();
            for (int i = 0; i < tower_.size(); ++i)
            {
                tower_[i]->push((*p));
                tower_[i]->run();
                int r = sqrt(((*p)->x() - tower_[i]->x()) * ((*p)->x() - tower_[i]->x()) + ((*p)->y() - tower_[i]->y()) * ((*p)->y() - tower_[i]->y()));
                if (r < tower_[i]->range())
                {
                    //tower_[i]->push((*p));
                    shoot((*p), tower_[i]);
                }
            }
            
            
            if ((*p)->x() - (*p)->rad() >= W || (*p)->alive_ == false)
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
}
void Game::game_input(bool & s_pressed)
{
    if (!bloons_move_)
    {
        KeyPressed keypressed = get_keypressed();
        if (!s_pressed && keypressed[SPACE])
        {
            bloons_move_ = true;
            s_pressed = true;
        }
        if (!keypressed[SPACE])
        {
            s_pressed = false;
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
        //std::cout << i + 1 << std::endl;
    }
    for (std::list< Bullet * >::iterator p = amo_.begin();
         p != amo_.end(); ++p)
    {
        (*p)->draw();
    }
    //ball->draw();
    surface_->unlock();
        
    surface_->flip();
}
void Game::shoot(Ball * ball, Tower * tower)
{
    if (a_timer_ % 101 == 0)
    {
        amo_.push_back(new Bullet(tower->target()));
    }
    ++a_timer_;
}
void Game::collision_detection()
{
    //Quadtree(amo_, bloons_);
}
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
        game_input(s_pressed);
        bloons_move();
        //shoot();
        for (std::list< Bullet * >::iterator p = amo_.begin();
             p != amo_.end(); ++p)
        {
            (*p)->run();
        }
        collision_detection();
        draw();
        //delay();
        int end = getTicks();
        int dt = RATE_ - end + start;
        if (dt > 0)
        {delay(dt);}
    }
}
