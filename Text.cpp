#include "Text.h"

Text::Text(){
    rect_.x = 0;
    rect_.y = 0;
    text_color_.r = 255;
    text_color_.g = 255;
    text_color_.b = 255;
}
Text::~Text(){

}
void Text::SetColor(const int& type){
    if(type == RED){
        text_color_ = {255,0,0};
    }
    else if(type == WHITE){
        text_color_ = {255,255,255};
    }
    else if(type == BLACK){
        text_color_ = {0,0,0};
    }
}
void Text::loadText_showText(TTF_Font* font,SDL_Renderer* screen){
    Clean();
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text_.c_str(), text_color_ );
	if( textSurface != NULL ){
        object_ = SDL_CreateTextureFromSurface( screen, textSurface );
        if(object_ != NULL){
            rect_.w = textSurface->w;
            rect_.h = textSurface->h;
        }
		SDL_FreeSurface( textSurface );
	}

    Render(screen);
}
