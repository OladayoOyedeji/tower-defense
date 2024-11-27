#include "Game.h"
#include <string>

const int STATUS_BAR_HEIGHT = 50;
const int MENU_HEIGHT = 100;
const int PATH_WIDTH = W - 50;
const int PATH_HEIGHT = H - MENU_HEIGHT - 50;

Image Game::image_ = "images/BackGround.jpg";

Game::Game()
    : surface_(new Surface(W, H)),
      tower_(num_R_tower + num_B_tower + num_W_tower + num_G_tower),
      path_(5, STATUS_BAR_HEIGHT, PATH_WIDTH, PATH_HEIGHT), count_(1), a_timer_(0),
      menu_(0, 50 + PATH_HEIGHT, W, MENU_HEIGHT),
      RATE_(1000 / fps), bloons_move_(false)
{
    Tower::set_surface(surface_);
    Path::set_surface(surface_);
    GameObject::set_surface(surface_);
        
    path_.generate_path();
    mouse_mov_.resize(menu_.size());
        
    for (int i = 0; i < tower_.size(); ++i )
    {
        if (i >= 0 && i < num_B_tower)
        {
            tower_[i] = new B_tower(menu_.set(BLUE_));
            mouse_mov_[BLUE_].push(tower_[i]);
        }
        else if (i >= num_W_tower && i < num_B_tower + num_R_tower)
        {
            tower_[i] = new R_tower(menu_.set(RED_));
            mouse_mov_[RED_].push(tower_[i]);
        }
        else if (i >= num_B_tower + num_R_tower &&
                 i < num_B_tower + num_R_tower + num_W_tower)
        {
            tower_[i] = new W_tower(menu_.set(WHITE_));
            mouse_mov_[WHITE_].push(tower_[i]);
        }
        else
        {
            tower_[i] = new G_tower(menu_.set(GRAY_));
            mouse_mov_[GRAY_].push(tower_[i]);
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
    static std::vector<bool> move(mouse_mov_.size(), false);
    for (int i = 0; i < mouse_mov_.size(); ++i)
    {
        if (!(mouse_mov_[i].empty()))
        {
            Tower * t = mouse_mov_[i].top();
            if (event_.type() == MOUSEMOTION)
            {
                //std::cout << "move\n";
                mouse_.update(event_);
                if (move[i])
                {
                    t->x_y(mouse_.x(), mouse_.y());
                    break;
                }
            }
            else if (event_.type() == MOUSEBUTTONDOWN)
            {
                // std::cout << "event poll: " << event_.poll() << "mouse down\n";
                // do nothing ... pick up and put down
                // happens only when the button is released
            }
            else if (event_.type() == MOUSEBUTTONUP)
            {
                // std::cout << "mouse up\n";
                mouse_.update(event_);
                if (in_ob(mouse_, *t))
                {
                    t->show_range();
                    move[i] = !move[i];
                    // std::cout << move[i] << std::endl;
                    if (!move[i])
                    {
                        mouse_mov_[i].pop();
                        break;
                    }
                }
            }
        }
    }
}
void Game::bloons_move()
{
    if (bloons_move_)
    {
        static int nums = 0;
        double vel = 1.5;
        if (count_ % 45 == 0 && nums != num_bloons)
        {
            nums++;
            if (count_ % 300 == 0) vel = 3.5;
            bloons_.push_back(new Ball(&path_, rand() % 20 + 10, vel));
        }
        count_++;
        for (std::list< Ball * >::iterator p = bloons_.begin();
             p != bloons_.end(); ++p)
        {
            if ((*p)->x() - (*p)->rad() >= W || (*p)->alive_ == false)
            {
                std::list< Ball * >::iterator q = p;
                --p;
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
                    int r = sqrt(((*p)->x() - tower_[i]->x()) *
                                 ((*p)->x() - tower_[i]->x()) +
                                 ((*p)->y() - tower_[i]->y()) *
                                 ((*p)->y() - tower_[i]->y()));
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


void Game::put_background()
{
    Rect rect(0, 0, W, H);
    surface_->put_image(image_, rect);
}

void Game::draw()
{
    surface_->lock();
    surface_->fill(BLACK);
    put_background();
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
    if (a_timer_ % 50 == 0)
    {
        amo_.push_back(new Bullet(tower->target(ball)));
    }
    ++a_timer_;
}
void Game::collision_detection()
{
    QuadTree q(0, 0, W - 1, H - 1, amo_, bloons_);
    q.draw(*surface_);
}
// void Game::delay()
// {}

void Game::run()
{
    bool s_pressed = false;
    // std::cout << W << ' ' << std::endl;
    
    while (1)
    {
        if (event_.poll())
        {
            if (event_.type() == QUIT) break;
            mouse_move();
        }
        int start = getTicks();
        game_input(s_pressed);
        
        // if (event_.poll())
        // {
        //std::cout << "robert is awesome" << std::endl;
        //mouse_move();
            //}
        bloons_move();
        //shoot();
        for (std::list< Bullet * >::iterator p = amo_.begin();
             p != amo_.end(); ++p)
        {
            if ((*p)->x() - (*p)->radius() >= W || (*p)->alive_ == false)
            {
                std::list< Bullet * >::iterator q = p;
                --p;
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
        draw();
        collision_detection();
        //delay();
        int end = getTicks();
        int dt = RATE_ - end + start;
        if (dt > 0)
        {delay(dt);}
    }
}
