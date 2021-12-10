//Filename : <Game Menu.h>
//Authors : <Dawoon Jung, Hyunjun Lee>
//Course : GAM100F21
//All content © 2021 DigiPen(USA) Corporation, all rights reserved.


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
    double starting_button_x{ -130.0 };
    double starting_button_y{ 40.0 };
    double starting_button_width{ 350.0 };
    double starting_button_height{ 100.0 };

    double how_to_play_button_x{ -140.0 };
    double how_to_play_button_y{ -300.0 };
    double how_to_play_button_width{ 350.0 };
    double how_to_play_button_height{ 100.0 };

    double Game_Over_button_x{ -700.0 };
    double Game_Over_button_y{ -365.0 };
    double Game_Over_button_width{ 250.0 };
    double Game_Over_button_height{ 100.0 };

    double restart_x{ 470.0 };
    double restart_y{ -365.0 };
    double restart_width{ 250.0 };
    double restart_height{ 100.0 };

    double credit_x{ -80.0 };
    double credit_y{ -135.0 };
    double credit_width{ 250.0 };
    double credit_height{ 100.0 };

    double back_x{ -720.0 };
    double back_y{ -355.0 };
    double back_width{ 200.0 };
    double back_height{ 100.0 };

    double next_x{ -680.0 };
    double next_y{ -330.0 };
    double next_width{ 219.0 };
    double next_height{ 105.0 };

    double next_x2{ 455.0 };
    double next_y2 = next_y;
    double next_width2 = next_width;
    double next_height2 = next_height;

    double quit_x{ 450.0 };
    double quit_y{ 220.0 };
    double quit_width{ 210.0 };
    double quit_height{ 90.0 };

    void back_button() {
        push_settings();
        set_outline_width(10);
        draw_rectangle(back_x, back_y, back_width, back_height);
        pop_settings();

                push_settings();
        set_fill_color(0);
        draw_triangle(-650, -305, -600, -275, -600, -335);
        pop_settings();

    }
    void start_button()
    {
        push_settings();
        set_outline_width(10);
        draw_rectangle(starting_button_x, starting_button_y, starting_button_width, starting_button_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("START", starting_button_x + 115.0, starting_button_y + 20.0);
        pop_settings();

        if (get_mouse_x() > starting_button_x && get_mouse_x() < starting_button_x + 350.0 &&
            get_mouse_y() > starting_button_y  && get_mouse_y() < starting_button_y + 100.0 && MouseIsPressed)
        {
            current_scene = 1;
        }
    }

    void how_to_play_button()
    {
        push_settings();
        set_outline_width(10);
        draw_rectangle(how_to_play_button_x, how_to_play_button_y, how_to_play_button_width, how_to_play_button_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("How To Play", how_to_play_button_x + 57.0, how_to_play_button_y + 20.0);
        pop_settings();

        if (get_mouse_x() > how_to_play_button_x && get_mouse_x() < how_to_play_button_x + 350.0 &&
            get_mouse_y() < how_to_play_button_y + 100.0 && get_mouse_y() > how_to_play_button_y && MouseIsPressed)
        {
            current_scene = 5;
        }
    }

    void credit_button()
    {
        push_settings();
        set_outline_width(10);
        draw_rectangle(credit_x, credit_y, credit_width, credit_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("Credit", credit_x + 67.0, credit_y + 20.0);
        pop_settings();

        if (get_mouse_x() > credit_x && get_mouse_x() < credit_x + 250.0 && get_mouse_y() < credit_y + 100.0 &&
            get_mouse_y() > credit_y && MouseIsPressed)
        {
            current_scene = 8;
        }
    }

    void Game_Over()
    {
        push_settings();
        set_outline_width(10);
        draw_rectangle(Game_Over_button_x, Game_Over_button_y, Game_Over_button_width, Game_Over_button_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("Replay", Game_Over_button_x + 55.0, Game_Over_button_y + 25);
        pop_settings();
        if (get_mouse_x() > Game_Over_button_x && get_mouse_x() < Game_Over_button_x + Game_Over_button_width &&
            get_mouse_y() > Game_Over_button_y && get_mouse_y() < Game_Over_button_y + Game_Over_button_height &&
            MouseIsPressed)
        {
            player.playerMP_width            = 360.0;
            player.armorHP_width             = 0.0;
            player.armor_left                = 0.0;
            player.playerHP_width            = 360.0;
            player.player_left               = -100.0;
            player.player_top                = -300.0;

            rain.rainMP_width = 200.0;

            monster.monsterHP_width            = 120.0;
            monster2.monsterHP_width2          = 100.0;
            monster3.monsterHP_width3          = 100.0;
            monster3.Rightdefense_wall_left3 = 180.0;
            monster3.Rightdefense_wall_height3 = 90.0;
            monster3.Leftdefense_wall_left3    = 0.0;

            stage1_key.stage1_gauge_width = 100.0;
            stage1_key.stage1_key_left    = 300.0;
            stage1_key.stage1_HPrecover_left = 350.0;
            stage1_key.stage1_MPrecover_left = 300.0;

            stage2_monster1.monster1HP_width = 60.0;
            stage2_monster2.monster2HP_width = 60.0;
            stage2_monster3.monster3HP_width = 60.0;
            stage2_monster4.monster4HP_width = 60.0;

            stage2_monster1.m1_swordHP_width = 100.0;
            stage2_monster2.m2_swordHP_width = 100.0;
            stage2_monster3.m3_swordHP_width = 100.0;
            stage2_monster4.m4_swordHP_width = 100.0;

            mini_boss.MbossHP_width            = 40.0;
            mini_boss.MbossHP_width2           = 40.0;
            mini_boss.MbossHP_width3           = 40.0;
            mini_boss.Mb_swordHP_width         = 100.0;
            mini_boss.Mb_swordHP_width2        = 100.0;
            mini_boss.Mb_swordHP_width3        = 100.0;
            mini_boss.Mboss_top                = 100.0;
            mini_boss.Mboss_top2               = 100.0;
            mini_boss.Mboss_top3               = 100.0;

            stage2_boss.bossHP_width         = 800.0;
            stage2_boss.boss_top     = -95.0;
            current_scene                    = 0;
        }
    }

    void restart() {
        push_settings();
        set_outline_width(10);
        draw_rectangle(restart_x, restart_y, restart_width, restart_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("Replay", restart_x + 65.0, restart_y + 22);
        pop_settings();
        if (get_mouse_x() > restart_x && get_mouse_x() < restart_x + restart_width && get_mouse_y() > restart_y &&
            get_mouse_y() < restart_y + restart_height &&
            MouseIsPressed)
        {
            player.playerMP_width = 360.0;
            player.armorHP_width  = 0.0;
            player.armor_left     = 0.0;
            player.playerHP_width = 360.0;
            player.player_left    = -100.0;
            player.player_top     = -300.0;

            rain.rainMP_width = 200.0;

            monster.monsterHP_width            = 120.0;
            monster2.monsterHP_width2          = 100.0;
            monster3.monsterHP_width3          = 100.0;
            monster3.Rightdefense_wall_left3   = 180.0;
            monster3.Rightdefense_wall_height3 = 90.0;
            monster3.Leftdefense_wall_left3    = 0.0;

            stage1_key.stage1_gauge_width    = 100.0;
            stage1_key.stage1_key_left       = 300.0;
            stage1_key.stage1_HPrecover_left = 350.0;
            stage1_key.stage1_MPrecover_left = 300.0;

            stage2_monster1.monster1HP_width = 60.0;
            stage2_monster2.monster2HP_width = 60.0;
            stage2_monster3.monster3HP_width = 60.0;
            stage2_monster4.monster4HP_width = 60.0;

            stage2_monster1.m1_swordHP_width = 100.0;
            stage2_monster2.m2_swordHP_width = 100.0;
            stage2_monster3.m3_swordHP_width = 100.0;
            stage2_monster4.m4_swordHP_width = 100.0;

            mini_boss.MbossHP_width     = 40.0;
            mini_boss.MbossHP_width2    = 40.0;
            mini_boss.MbossHP_width3    = 40.0;
            mini_boss.Mb_swordHP_width  = 100.0;
            mini_boss.Mb_swordHP_width2 = 100.0;
            mini_boss.Mb_swordHP_width3 = 100.0;
            mini_boss.Mboss_top         = 100.0;
            mini_boss.Mboss_top2        = 100.0;
            mini_boss.Mboss_top3        = 100.0;

            stage2_boss.bossHP_width = 800.0;
            stage2_boss.boss_top     = -95.0;
            current_scene            = 0;
        }

    }

    void next_button()
    {
        push_settings();
        set_fill_color(255);
        no_outline();
        draw_rectangle(next_x2, next_y2, next_width2, next_height2);
        pop_settings();
        

        if (get_mouse_x() > next_x && get_mouse_x() < next_x + next_width && get_mouse_y() > next_y &&
            get_mouse_y() < next_y + next_height && MouseIsPressed)
        {
            current_scene = 6;
        }
    }

    void next_button2()
    {

        if (get_mouse_x() > next_x2 && get_mouse_x() < next_x2 + next_width2 && get_mouse_y() > next_y2 &&
            get_mouse_y() < next_y2 + next_height2 && MouseIsPressed)
        {
            current_scene = 7;
        }
    }

    void Quit()
    {
        push_settings();
        set_outline_width(10);
        draw_rectangle(quit_x, quit_y, quit_width, quit_height);
        pop_settings();

        push_settings();
        set_fill_color(0);
        set_font_size(30);
        draw_text("Quit", quit_x + 65.0, quit_y + 22);
        pop_settings();
        if (get_mouse_x() > quit_x && get_mouse_x() < quit_x + quit_width && get_mouse_y() > quit_y &&
            get_mouse_y() < quit_y + quit_height && MouseIsPressed)
        {
            current_scene = 0;
        }
    }
};
Main_screen Game_menu;