#ifndef GIFT_OBJECT_H_
#define GIFT_OBJECT_H_

#include "common.h"
#include "base.h"

#define GIFT_WIDTH 49
#define GIFT_HEIGHT 58
#define WIDTH_LEVEL_UP 49
#define HEIGHT_LEVEL_UP 41
#define GIFT_SPEED 3

class Gift : public base{
public:
    Gift();
    ~Gift();

    void set_x_val(const int& Xval){x_val_ = Xval;}
    void set_y_val(const int& Yval){y_val_ = Yval;}
    int get_x_val()const{return x_val_;}
    int get_y_val()const{return y_val_;}

    void set_gift_type(const int& GiftType){gift_type_ = GiftType;}
    int get_gift_type()const{return gift_type_;}
    void set_come_back(const bool& comeback){come_back_ = comeback;}
    bool get_come_back()const{return come_back_;}

    void Show(SDL_Renderer* screen);
    void Move(const int& x_border,const int& y_border);
    void loadImgGift(SDL_Renderer* screen);

    void set_clip();
    SDL_Rect GetRectFrame();
    int random_gift()const;
private:
    int x_val_;
    int y_val_;

    int gift_type_;
    bool come_back_;

    int frame_;
    SDL_Rect clip_[25];
};



















#endif
