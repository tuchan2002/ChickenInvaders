#include "Gift.h"

Gift::Gift(){
    gift_type_ = 0;
    come_back_ = false;
    frame_ = 0;
}
Gift::~Gift(){

}
void Gift::Show(SDL_Renderer* screen){
    if(gift_type_ == 3){
        if(come_back_== true){
            frame_++;
            if(frame_/3 >= 25){
                frame_ = 0;
            }
            SDL_Rect renderQuad = {rect_.x,rect_.y,WIDTH_LEVEL_UP,HEIGHT_LEVEL_UP};
            SDL_RenderCopy(screen,object_,&clip_[frame_/3],&renderQuad);
        }
    }
    else if(gift_type_ < 3){
        if(come_back_ == true){
            Render(screen);
        }
    }
}
void Gift::Move(const int& x_border,const int& y_border){
    if(come_back_ == true){
        rect_.y += y_val_;
        if(rect_.y > y_border ){
            come_back_ = false;
            rect_.x = - GIFT_WIDTH;
            rect_.y = - GIFT_HEIGHT;
        }
    }
}
void Gift::loadImgGift(SDL_Renderer* screen){
    if(gift_type_ == BLASTER){
        loadImg("image//gift1.png",screen);
    }
    else if(gift_type_ == NEUTRON){
        loadImg("image//gift2.png",screen);
    }
    else if(gift_type_ == BORON){
        loadImg("image//gift3.png",screen);
    }
    else if(gift_type_ == LEVEL_UP){
        loadImg("image//level_up_1225.png",screen);
    }
}
void Gift::set_clip(){
    for(int i=0;i<25;i++){
        clip_[i].x = i * WIDTH_LEVEL_UP;
        clip_[i].y = 0;
        clip_[i].w = WIDTH_LEVEL_UP;
        clip_[i].h = HEIGHT_LEVEL_UP;
    }
}
SDL_Rect Gift::GetRectFrame(){
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = WIDTH_LEVEL_UP;
    rect.h = HEIGHT_LEVEL_UP;

    return rect;
}
int Gift::random_gift()const{
    int rand_gift_type = rand()%5;
    rand_gift_type = rand_gift_type < 3 ? rand_gift_type : 3;
    return rand_gift_type;
}

