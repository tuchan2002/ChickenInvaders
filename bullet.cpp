#include "bullet.h"

bullet::bullet(){
    x_val_ =0;
    y_val_ =0;
    is_move_ = false;
    bullet_type_ = BLASTER;
}
bullet::~bullet(){

}

void bullet::loadImgBullet(SDL_Renderer* screen,int bullet_level){
    if(bullet_type_ == BLASTER){
        std::string blaster_str = "image//blaster" + std::to_string(bullet_level) + ".png";
        loadImg(blaster_str,screen);
    }
    else if(bullet_type_ == NEUTRON){
        std::string neutron_str = "image//neutron" + std::to_string(bullet_level) + ".png";
        loadImg(neutron_str,screen);
    }
    else if(bullet_type_ == BORON){
        std::string boron_str = "image//boron" + std::to_string(bullet_level) + ".png";
        loadImg(boron_str,screen);
    }
}

void bullet::HandleMoveSpaceShipBullet(){
    rect_.y += y_val_;
    if(rect_.y < -rect_.h){
        is_move_ = false;
    }
}
void bullet::HandleMoveChickenBullet(){
    rect_.y += y_val_;
    if(rect_.y > SCREEN_HEIGHT){
        is_move_ = false;
    }
}
void bullet::HandleMoveBossBullet(const int& x_border,const int& y_border){
    rect_.y += y_val_;
    if(rect_.y > y_border){
        is_move_ = false;
    }
}
