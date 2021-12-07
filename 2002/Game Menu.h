#pragma once

#include "first_floor_monster.h"
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "monster4.h"
#include "player.h"
#include "second_floor_monster.h"
#include "stage2_mini_boss.h"
#include "stage2boss.h"
#include "third_floor_monster.h"
#include <doodle/doodle.hpp>

using namespace doodle;

class Main_screen
{
public:
    double starting_botton_x{ -160.0 };
    double starting_botton_y{ 100.0 };
    double starting_botton_width{ 350.0 };
    double starting_botton_height{ 100.0 };

    double how_to_play_botton_x{ -160.0 };
    double how_to_play_botton_y{ -200.0 };
    double how_to_play_botton_width{ 350.0 };
    double how_to_play_botton_height{ 100.0 };

    double Game_Over_botton_x{ 0.0 };
    double Game_Over_botton_y{ -200.0 };
    double Game_Over_botton_width{ 200.0 };
    double Game_Over_botton_height{ 100.0 };

        const Image warrior{ "asset/warrior.png" };

    void start_botton()
    {
        push_settings();
        set_outline_width(10);
        draw_rectangle(starting_botton_x, starting_botton_y, starting_botton_width, starting_botton_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("START", starting_botton_x + 115.0, starting_botton_y + 20.0);
        pop_settings();

        if (get_mouse_x() > starting_botton_x && get_mouse_x() < starting_botton_x + 350.0 &&
            get_mouse_y() > starting_botton_y  && get_mouse_y() < starting_botton_y + 100.0 && MouseIsPressed)
        {
            current_scene = 1;
        }

        draw_image(warrior, -600.0, -300.0, 300.0, 500.0);
    }

    void how_to_play_botton()
    {
        push_settings();
        set_outline_width(10);
        draw_rectangle(how_to_play_botton_x, how_to_play_botton_y, how_to_play_botton_width, how_to_play_botton_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("How To Play", how_to_play_botton_x + 57.0, how_to_play_botton_y + 20.0);
        pop_settings();

        if (get_mouse_x() > how_to_play_botton_x && get_mouse_x() < how_to_play_botton_x + 350.0 &&
            get_mouse_y() < how_to_play_botton_y + 100.0 && get_mouse_y() > how_to_play_botton_y && MouseIsPressed)
        {
            current_scene = 4;
        }
    }
    void Game_Over()
    {
        push_settings();

        draw_rectangle(Game_Over_botton_x, Game_Over_botton_y, Game_Over_botton_width, Game_Over_botton_height);
        set_font_size(25);
        draw_text("Replay", Game_Over_botton_x + 35, Game_Over_botton_y + 25);
        pop_settings();
        if (get_mouse_x() > Game_Over_botton_x && get_mouse_x() < Game_Over_botton_x + Game_Over_botton_width &&
            get_mouse_y() > Game_Over_botton_y && get_mouse_y() < Game_Over_botton_y + Game_Over_botton_height &&
            MouseIsPressed)
        {
            monster.monsterHP_width          = 120;
            monster2.monsterHP_width2        = 100;
            monster3.monsterHP_width3        = 100;
            stage2_monster1.monster1HP_width = 60;
            stage2_monster2.monster2HP_width = 60;
            stage2_monster3.monster3HP_width = 60;
            stage2_monster4.monster4HP_width = 60;
            mini_boss.MbossHP_width          = 40;
            mini_boss.MbossHP_width2         = 40;
            mini_boss.MbossHP_width3         = 40;
            stage2_boss.bossHP_width         = 800;
            player.playerHP_width            = 360;
            player.player_left               = -100;
            player.player_top                = -300;
            stage2_monster1.m1_swordHP_width = 100;
            stage2_monster2.m2_swordHP_width = 100;
            stage2_monster3.m3_swordHP_width = 100;
            stage2_monster4.m4_swordHP_width = 100;
            current_scene                    = 1;
        }
    }
};
Main_screen Game_menu;