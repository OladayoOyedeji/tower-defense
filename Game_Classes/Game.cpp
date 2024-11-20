#include "Game.h"

const int MENU_WIDTH = 200;
const int PATH_WIDTH = W - MENU_WIDTH;
const int PATH_HEIGHT = H - 1;

Game::Game()
    : surface_(new Surface(W, H)), tower_(num_R_tower + num_B_tower + num_W_tower + num_G_tower),
      path_(5, 5, PATH_WIDTH, PATH_HEIGHT), count_(0), a_timer_(0),
      menu_(PATH_WIDTH, 0, MENU_WIDTH, H),
      RATE_(1000 / 60), bloons_move_(false)
{
    Tower::set_surface(surface_);
    Path::set_surface(surface_);
    GameObject::set_surface(surface_);
        
    path_.generate_path();
        
    for (int i = 0; i < tower_.size(); ++i )
    {
        if (i >= 0 && i < num_B_tower)
        {
            tower_[i] = new B_tower(menu_.Blue());
            B_mouse_mov_.push(tower_[i]);
        }
        else if (i >= num_W_tower && i < num_B_tower + num_R_tower)
        {
            tower_[i] = new R_tower(menu_.Red());
            R_mouse_mov_.push(tower_[i]);
        }
        else if (i >= num_B_tower + num_R_tower && i < num_B_tower + num_R_tower + num_W_tower)
        {
            tower_[i] = new W_tower(menu_.White());
            B_mouse_mov_.push(tower_[i]);
        }
        else
        {
            tower_[i] = new G_tower(menu_.Green());
            G_mouse_mov_.push(tower_[i]);
        }
        
    }
}

Game::~Game()
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
    delete surface_;
        
}

void Game::mouse_move()
{
    static bool R_click = false;
    static bool B_click = false;
    static bool G_click = false;
    static bool W_click = false;
    if (!(R_mouse_mov_.empty()))
    {
        Tower * t = R_mouse_mov_.top();
        if (mouse_.left() && in_ob(mouse_, *t))
        {
            mouse_.update(event_);
            t->x_y(mouse_.x(), mouse_.y());
            R_click = true;
        }
        else if (!(mouse_.left()) && R_click)
        {
            R_mouse_mov_.pop();
            R_click = false;
        }
        else
            mouse_.update(event_);
    }
    if (!(B_mouse_mov_.empty()))
    {
        Tower * t = B_mouse_mov_.top();
        if (mouse_.left() && in_ob(mouse_, *t))
        {
            mouse_.update(event_);
            t->x_y(mouse_.x(), mouse_.y());
            B_click = true;
        }
        else if (!(mouse_.left()) && B_click)
        {
            B_mouse_mov_.pop();
            B_click = false;
        }
        else
            mouse_.update(event_);
    }
    if (!(G_mouse_mov_.empty()))
    {
        Tower * t = G_mouse_mov_.top();
        if (mouse_.left() && in_ob(mouse_, *t))
        {
            mouse_.update(event_);
            t->x_y(mouse_.x(), mouse_.y());
            G_click = true;
        }
        else if (!(mouse_.left()) && G_click)
        {
            G_mouse_mov_.pop();
            G_click = false;
        }
        else
            mouse_.update(event_);
    }
    if (!(W_mouse_mov_.empty()))
    {
        Tower * t = W_mouse_mov_.top();
        if (mouse_.left() && in_ob(mouse_, *t))
        {
            mouse_.update(event_);
            t->x_y(mouse_.x(), mouse_.y());
            W_click = true;
        }
        else if (!(mouse_.left()) && W_click)
        {
            W_mouse_mov_.pop();
            W_click = false;
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
            if ((*p)->x() - (*p)->rad() >= W || (*p)->alive_ == false)
            {
                std::list< Ball * >::iterator q = p;
                ++p;
                delete (*q);
                bloons_.erase(q);
                if (p == bloons_.end())
                {break;}
            }
            else
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
    menu_.draw(*surface_);
    //ball->draw();
    surface_->unlock();
        
    surface_->flip();
}
void Game::shoot(Ball * ball, Tower * tower)
{
    if (a_timer_ % 101 == 0)
    {
        amo_.push_back(new Bullet(tower->target(ball)));
    }
    ++a_timer_;
}
void Game::collision_detection()
{
    QuadTree q(0, 0, W - 1, H - 1, amo_, bloons_);
    //q.draw(*surface_);
}
// void Game::delay()
// {}

void Game::run()
{
    bool s_pressed = false;
    std::cout << W << ' ' << std::endl;
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
            if ((*p)->x() - (*p)->radius() >= W || (*p)->alive_ == false)
            {
                std::list< Bullet * >::iterator q = p;
                ++p;
                delete (*q);
                amo_.erase(q);
                if (p == amo_.end())
                {break;}
            }
            else
            {
                (*p)->run();
            }
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
