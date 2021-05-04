#ifndef TEXT_H_
#define TEXT_H_

#include "base.h"
#include "common.h"

class Text : public base{
public:
    Text();
    ~Text();

    enum TEXT_COLOR{
        RED = 5,
        WHITE = 6,
        BLACK = 7,
    };

    void SetText(const std::string& text){text_ = text;}
    void SetColor(const int& type);
    void loadText_showText(TTF_Font* font,SDL_Renderer* screen);
private:
    std::string text_;
    SDL_Color text_color_;
};






#endif
