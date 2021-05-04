#include "chicken.h"

Chicken::Chicken(){
    rect_.x = SCREEN_WIDTH;
    rect_.y = SCREEN_HEIGHT / 2;
    x_val_ = 0;
    y_val_ = 0;
    status_.turn_down = 0;
    status_.turn_up = 0;
    status_.turn_left = 0;
    status_.turn_right = 1;
    frame_ =0;
    heart_ = 0;
    come_back_ = true;
}
Chicken::~Chicken(){

}
SDL_Rect Chicken::GetRectFrame(){
    SDL_Rect rect;
        rect.x = rect_.x;
        rect.y = rect_.y;
        rect.w = WIDTH_CHICKEN;
        rect.h = HEIGHT_CHICKEN;
    return rect;
}
void Chicken::set_clips(){
        for(int i=0;i<18;i++){
            clip_[i].x = i * WIDTH_CHICKEN;
            clip_[i].y = 0;
            clip_[i].w = WIDTH_CHICKEN;
            clip_[i].h = HEIGHT_CHICKEN;
        }
}
void Chicken::Show(SDL_Renderer* screen){
    if(come_back_ == true){
        frame_++;
        if(frame_/5 >= 18){
            frame_ = 0;
        }
        SDL_Rect renderQuad = {rect_.x,rect_.y,WIDTH_CHICKEN,HEIGHT_CHICKEN};
        SDL_RenderCopy(screen,object_,&clip_[frame_/5],&renderQuad);
    }
}
void Chicken::HandleBullet(SDL_Renderer* screen){

        for(int i=0;i<bullet_list_.size();i++){
            bullet* p_bullet = bullet_list_.at(i);
            if(p_bullet){
                if(p_bullet->get_is_move()){
                    p_bullet->Render(screen);
                    p_bullet->HandleMoveChickenBullet();
                }
                else{
                    p_bullet->SetRect(this->rect_.x + WIDTH_CHICKEN / 2 - p_bullet->GetRect().w / 2,this->rect_.y + HEIGHT_CHICKEN);
                    p_bullet->set_is_move(true);
                }
            }
        }
}
void Chicken::InitBullet(bullet* p_bullet,SDL_Renderer* screen){
    if(p_bullet != NULL){
        if(p_bullet->loadImg("image//egg.png",screen)){
            p_bullet->set_is_move(true);
            p_bullet->SetRect(this->rect_.x + WIDTH_CHICKEN / 2 - p_bullet->GetRect().w / 2,this->rect_.y + HEIGHT_CHICKEN);
            p_bullet->set_y_val(CHICKEN_BULLET_SPEED);
            bullet_list_.push_back(p_bullet);
        }
    }
}
void Chicken::Move(){
    if(come_back_==true){
        rect_.y += y_val_;
        if(status_.turn_left){
            rect_.x -= x_val_;
        }
        if(status_.turn_right){
            rect_.x += x_val_;
        }
        if(status_.turn_up){
            rect_.y -= 2 * y_val_;
        }

        if(rect_.y > SCREEN_HEIGHT ){
            status_.turn_up = 1;
            status_.turn_down = 0;
        }
        else if(rect_.y + HEIGHT_CHICKEN< 0){
            status_.turn_down = 1;
            status_.turn_up = 0;
        }
        if(rect_.x <= - WIDTH_CHICKEN*3){
            status_.turn_right = 1;
            status_.turn_left = 0;
        }
        else if(rect_.x >= SCREEN_WIDTH + 3*WIDTH_CHICKEN){
            status_.turn_left = 1;
            status_.turn_right = 0;
        }
    }
}
void Chicken::RemoveBullet(const int& idx){
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
void Chicken::set_status_right(){
    status_.turn_down = 0;
    status_.turn_up = 0;
    status_.turn_left = 0;
    status_.turn_right = 1;
}




