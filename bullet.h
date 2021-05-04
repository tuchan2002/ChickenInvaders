#ifndef BULLET_H_
#define BULLET_H_

#include "base.h"
#include "common.h"

class bullet : public base{
public:
    bullet();
    ~bullet();

    void set_x_val(const int& xVal){x_val_ = xVal;}
    void set_y_val(const int& yVal){y_val_ = yVal;}
    int get_x_val()const{return x_val_;}
    int get_y_val()const{return y_val_;}
    void set_is_move(const bool& isMove){is_move_ = isMove;}
    bool get_is_move()const{return is_move_;}
    void set_bullet_type(const int& bulletType){bullet_type_ = bulletType;}
    int get_bullet_type()const{return bullet_type_;}

    void HandleMoveSpaceShipBullet();
    void HandleMoveChickenBullet();
    void HandleMoveBossBullet(const int& x_border,const int& y_border);
    void loadImgBullet(SDL_Renderer* screen,int bullet_level);
private:
    int x_val_;
    int y_val_;
    bool is_move_;
    int bullet_type_;
};












#endif

