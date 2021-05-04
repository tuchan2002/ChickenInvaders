#include "Boss.h"

Boss::Boss(){
    rect_.x = SCREEN_WIDTH;
    rect_.y = SCREEN_HEIGHT / 2;
    x_val_ = 0;
    y_val_ = 0;
    status_.turn_down = 0;
    status_.turn_up = 0;
    status_.turn_left = 1;
    status_.turn_right = 0;
    frame_ =0;
    heart_ = 0;
}
Boss::~Boss(){

}
SDL_Rect Boss::GetRectFrame(){
    SDL_Rect rect;
        rect.x = rect_.x;
        rect.y = rect_.y;
        rect.w = WIDTH_BOSS;
        rect.h = HEIGHT_BOSS;
    return rect;
}
void Boss::set_clips(){
        for(int i=0;i<10;i++){
            clip_[i].x = i * WIDTH_BOSS;
            clip_[i].y = 0;
            clip_[i].w = WIDTH_BOSS;
            clip_[i].h = HEIGHT_BOSS;
        }
}
void Boss::Show(SDL_Renderer* screen){
    frame_++;
    if(frame_/5 >= 10){
        frame_ = 0;
    }
    SDL_Rect renderQuad = {rect_.x,rect_.y,WIDTH_BOSS,HEIGHT_BOSS};
    SDL_RenderCopy(screen,object_,&clip_[frame_/5],&renderQuad);
}
void Boss::MakeBullet(SDL_Renderer* screen){
    for(int i=0;i<bullet_list_.size();i++){
        bullet* p_bullet = bullet_list_.at(i);
        if(p_bullet){
            if(p_bullet->get_is_move()){
                p_bullet->Render(screen);
                p_bullet->HandleMoveBossBullet(SCREEN_WIDTH,SCREEN_HEIGHT+this->rect_.y);
            }
            else{
                p_bullet->SetRect(this->rect_.x + WIDTH_BOSS / 2 - p_bullet->GetRect().w / 2,this->rect_.y + HEIGHT_BOSS);
                p_bullet->set_is_move(true);
            }
        }
    }
}
void Boss::InitBullet(bullet* p_bullet,SDL_Renderer* screen){
    if(p_bullet != NULL){
        if(p_bullet->loadImg("image//egg_boss.png",screen)){
            p_bullet->set_is_move(true);
            p_bullet->SetRect(this->rect_.x + WIDTH_BOSS / 2 - p_bullet->GetRect().w / 2,this->rect_.y + HEIGHT_BOSS);
            p_bullet->set_y_val(BOSS_BULLET_SPEED);
            bullet_list_.push_back(p_bullet);
        }
    }
}
void Boss::Move(){
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

        if(rect_.y > SCREEN_HEIGHT - HEIGHT_BOSS){
            status_.turn_up = 1;
            status_.turn_down = 0;
        }
        else if(rect_.y < 0){
            status_.turn_down = 1;
            status_.turn_up = 0;
        }
        if(rect_.x <= 0){
            status_.turn_right = 1;
            status_.turn_left = 0;
        }
        else if(rect_.x >= SCREEN_WIDTH - WIDTH_BOSS){
            status_.turn_left = 1;
            status_.turn_right = 0;
        }
}
void Boss::show_heart_boss(SDL_Renderer* screen,int x,int y,int w,int h){
    SDL_Rect fill_rect = {x,y,w,h};
    SDL_SetRenderDrawColor(screen,255,0,0,255);
    SDL_RenderFillRect(screen,&fill_rect);
}





