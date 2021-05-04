#ifndef GAME_MANAGEMENT_H_
#define GAME_MANAGEMENT_H_

#include "Common.h"
#include "base.h"
#include "space_ship.h"
#include "Chicken.h"
#include "Explosion.h"
#include "Gift.h"
#include "Text.h"
#include "Boss.h"

class game_management{
public:
    game_management();
    ~game_management();

    void init(std::string title);
    void handle_event();
    void handle_boss();
    void handle_chicken();
    void handle_game();
    void clean();
    void menu(const std::string& item);
    void reset_game();
    bool get_running(){return isRunning;}
    bool check_collision(const SDL_Rect& object1,const SDL_Rect& object2);
    bool check_mouse_vs_item(const int& x,const int& y,const SDL_Rect& rect);
private:
    bool isRunning;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event gEvent;
    Mix_Chunk* g_sound_bullet[3];
    Mix_Chunk* g_sound_exp[3];
    Mix_Chunk* g_sound_chicken_hit[3];
    Mix_Chunk* g_sound_level_up;
    Mix_Music* g_music_start;
    TTF_Font* g_font_text;
    TTF_Font* g_font_menu;
    TTF_Font* g_font_end_game;

    base background;
    space_ship spaceship;
    Explosion exp;
    Explosion exp_boss;
    Gift gift;
    Text kill_text;
    base support;
    Text heart_text;
    Text lighting_text;
    Text hint;
    Text end_game;
    Boss boss;
    int bullet_level;
    int kill;
    float scrolling;
    int time_end_game;
    int count_num_exp;
    int menu_number;
    std::vector<Chicken*> p_chicken_list;

};
#endif
