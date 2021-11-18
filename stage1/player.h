//NAME : Semicolon
//ASSIGNMENT : Game Snapshot
//COURSE : CS120
//TERM & YEAR : Fall 2021

#pragma once

#include <doodle/doodle.hpp>
#include <string>

#include "doors.h"
#include "player_key.h"
#include "Screen.h"
using namespace doodle;
using namespace std;

class Player
{
public:
    double player_left{ 0.0 };
    double player_top{ -300.0 };
    double player_width{ 40.0 };
    double player_height{ 40.0 };
    double player_bottom = player_top + player_height;
    double player_right = player_left + player_width;

    double playerHP_left{ -450.0 };
    double playerHP_top{ 280.0 };
    double playerHP_width{ 360.0 };
    double playerHP_height{ -250.0 };
    double playerHP_bottom = playerHP_top + playerHP_height;
    double playerHP_right = playerHP_left + playerHP_width;

    double playerMP_left{ 30.0 };
    double playerMP_top{ 280.0 };
    double playerMP_width{ 360.0 };
    double playerMP_height{ -250.0 };
    double playerMP_bottom = playerMP_top + playerMP_height;
    double playerMP_right = playerMP_left + playerMP_width;
    
    double& anotoer_PlayerMPleft = playerMP_left;

    void draw_player()
    {
        draw_rectangle(player_left, player_top, player_width, player_height);
    }

    void draw_playerHP()
    {
        push_settings();
        no_outline();
        set_font_size(25);
        draw_text("HP", -505, 270);
        set_fill_color(HexColor{ 0xff0000ff });
        draw_rectangle(playerHP_left, playerHP_top, playerHP_width, playerHP_bottom);
        pop_settings();

        //HP automatic recovery
        if (playerHP_width < 360.0)
        {
            playerHP_width += 0.01;
        }
        else if(playerHP_width > 360.0)
        {
            playerHP_width = 360.0;
        }

        //end
        if (playerHP_width < 0.0)
        {
            current_scene = gameover;
        }

        push_settings();
        set_font_size(20);
        draw_text("360 / " + to_string(playerHP_width), -380, 278);
        pop_settings();
    }

    void draw_playerMP()
    {
        push_settings();
        no_outline();
        set_font_size(25);
        draw_text("MP", -30, 270);
        set_fill_color(HexColor{ 0xA0F1FF });
        draw_rectangle(anotoer_PlayerMPleft, playerMP_top, playerMP_width, playerMP_bottom);
        pop_settings();

        //The code that charges up when the mana is used up.
        if (playerMP_width < 360.0)
        {
            playerMP_width += 0.05;
        }
        if (playerMP_width > 360.0)
        {
            playerMP_width = 360;
        }

        //The code so that Mana doesn't get negative.
        if (playerMP_width < 0.0)
        {
            playerMP_width = 0.0;
        }

        push_settings();
        set_font_size(20);
        draw_text("360 / " + to_string(playerMP_width), 100, 278);
        pop_settings();
    }

    void player_keyboard_A_D()
    {
        //moving key
        if (CheckKeyPressed[0])
        {
            const double player_move = 2.0 * DeltaTime;
            player_left += player_move * 100;
        }

        if (CheckKeyPressed[1])
        {
            const double player_move = 2.0 * DeltaTime;
            player_left -= player_move * 100;
        }
    }

    void contact_door()
    {
        player_bottom = player_top + player_height;
        player_right = player_left + player_width;

        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

        //From the first floor to the second floor.
        if (Over(player_left, player_right, first.under_door_left, first.under_door_right)
            && Over(player_top, player_bottom, first.under_door_top, first.under_door_bottom))
        {
            player_left = -500.0;
            player_top = -80.0;
        }
        //From the second floor to the firtst floor.
        if (Over(player_left, player_right, second.left_middle_door_left, second.left_middle_door_right)
            && Over(player_top, player_bottom, second.left_middle_door_top, second.left_middle_door_bottom))
        {
            player_left = 500.0;
            player_top = -300.0;
        }
        //From the second floor to the third floor.
        if (Over(player_left, player_right, third.right_middle_door_left, third.right_middle_door_right)
            && Over(player_top, player_bottom, third.right_middle_door_top, third.right_middle_door_bottom))
        {
            player_left = -500.0;
            player_top = 150.0;
        }
        //From the third floor to the second floor.
        if (Over(player_left, player_right, fourth.left_top_door_left, fourth.left_top_door_right)
            && Over(player_top, player_bottom, fourth.left_top_door_top, fourth.left_top_door_bottom))
        {
            player_left = 500.0;
            player_top = -80.0;
        }
        //go 2stage
        if (Over(player_left, player_right, five.right_top_door_left, five.right_top_door_right)
            && Over(player_top, player_bottom, five.right_top_door_top, five.right_top_door_bottom))
        {
            player_left = 0.0;
            player_top = -300.0;
            current_scene = stage2;
        }
    }
};
Player player;
