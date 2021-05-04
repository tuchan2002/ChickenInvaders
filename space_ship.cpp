#include "space_ship.h"

space_ship::space_ship(){
    rect_.x = SCREEN_WIDTH/2;
    rect_.y = SCREEN_HEIGHT - HEIGHT_MAIN;
    rect_.w = WIDTH_MAIN;
    rect_.h = HEIGHT_MAIN;

    x_val_ = 0;
    y_val_ = 0;

    bullet_type_ = BLASTER;
    status_ = true ;
    bullet_damage_ = 0;
    heart_ = MAIN_HEART;
}
space_ship::~space_ship(){

}
void space_ship::Control(SDL_Event event,SDL_Renderer* screen,Mix_Chunk* bullet_sound[4],int bullet_level,Mix_Chunk* g_sound_level_up){
        if(event.type== SDL_KEYDOWN && event.key.repeat == 0){
            switch(event.key.keysym.sym){
            case SDLK_w:
            y_val_ -= MAIN_SPEED;
            break;
            case SDLK_s:
            y_val_ += MAIN_SPEED;
            break;
            case SDLK_d:
            x_val_ += MAIN_SPEED;
            break;
            case SDLK_a:
            x_val_ -= MAIN_SPEED;
            break;
            }
        }
        else if(event.type == SDL_KEYUP && event.key.repeat == 0){
            switch(event.key.keysym.sym){
            case SDLK_w:
            y_val_ += MAIN_SPEED;
            break;
            case SDLK_s:
            y_val_ -= MAIN_SPEED;
            break;
            case SDLK_d:
            x_val_ -= MAIN_SPEED;
            break;
            case SDLK_a:
            x_val_ += MAIN_SPEED;
            break;
            }
        }
        if(event.type== SDL_KEYDOWN && event.key.repeat == 0){
            if(event.key.keysym.sym == SDLK_SPACE){
                if(status_==true){
                    bullet* p_bullet = new bullet();
                    p_bullet->set_bullet_type(bullet_type_);

                    if(bullet_type_ == BLASTER){
                        Mix_PlayChannel(-1,bullet_sound[0],0);
                        p_bullet->set_y_val(-BLASTER_SPEED);
                        bullet_damage_ = 2;
                    }
                    else if(bullet_type_ == NEUTRON){
                        Mix_PlayChannel(-1,bullet_sound[1],0);
                        p_bullet->set_y_val(-NEUTRON_SPEED);
                        bullet_damage_ = 2.5;
                    }
                    else if(bullet_type_ == BORON){
                        Mix_PlayChannel(-1,bullet_sound[2],0);
                        p_bullet->set_y_val(-BORON_SPEED);
                        bullet_damage_ = 1.5;
                    }

                    p_bullet->loadImgBullet(screen,bullet_level);
                    p_bullet->SetRect(this->rect_.x + this->rect_.w / 2 - p_bullet->GetRect().w / 2,this->rect_.y - p_bullet->GetRect().h);
                    p_bullet->set_is_move(true);
                    bullet_list_.push_back(p_bullet);
                }
            }
            if(event.key.keysym.sym == SDLK_RETURN){
                if(heart_>0){
                    if(status_==false){
                        Mix_PlayChannel(-1,g_sound_level_up,0);
                        status_ = true;
                        rect_.x = SCREEN_WIDTH/2;
                        rect_.y = SCREEN_HEIGHT - HEIGHT_MAIN;
                    }
                }
            }
        }
}
void space_ship::Show(SDL_Renderer* screen){
    if(status_==true){
        Render(screen);
    }
}
void space_ship::Move(){
    if(status_==true){
        rect_.x += x_val_;
        if(rect_.x < 0 || rect_.x + WIDTH_MAIN > SCREEN_WIDTH){
            rect_.x -= x_val_;
        }
        rect_.y += y_val_;
        if(rect_.y < 0 || rect_.y + HEIGHT_MAIN > SCREEN_HEIGHT){
            rect_.y -= y_val_;
        }
    }
}
void space_ship::HandleBullet(SDL_Renderer* screen){
    for(int i=0;i<bullet_list_.size();i++){
        bullet* p_bullet = bullet_list_.at(i);
        if(p_bullet != NULL){
            if(p_bullet->get_is_move()){
                p_bullet->Render(screen);
                p_bullet->HandleMoveSpaceShipBullet();
            }
            else{
                if(p_bullet != NULL){
                    bullet_list_.erase(bullet_list_.begin()+i);

                    delete p_bullet;
                    p_bullet = NULL;
                }
            }
        }
    }
}
void space_ship::RemoveBullet(const int& idx){
    for(int i=0;i < bullet_list_.size();i++){
        if(idx < bullet_list_.size()){
            bullet* p_bullet = bullet_list_.at(idx);
            bullet_list_.erase(bullet_list_.begin() + idx);

            if(p_bullet != NULL){
                delete p_bullet;
                p_bullet = NULL;
            }
        }
    }
}
