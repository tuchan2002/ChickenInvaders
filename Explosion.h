#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "base.h"
#include "common.h"

#define WIDTH_FRAME_EXP 150
#define HEIGHT_FRAME_EXP 165
#define NUMBER_OF_FRAME 8

class Explosion : public base{
public:
    Explosion();
    ~Explosion();

    void set_clip();
    void Show(SDL_Renderer* screen);

    void set_frame(const int& Frame){frame_ = Frame;}
    int get_frame()const{return frame_;}
private:
    int frame_;
    SDL_Rect clip_[NUMBER_OF_CHICKEN];
};



#endif
