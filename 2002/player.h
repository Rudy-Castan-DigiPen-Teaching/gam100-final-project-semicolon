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
    // player_left = 0 550
    double player_left{ 0.0 };
    //player_top = -300  150
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

    double Jplayer_left{ 50.0 };
    double Jplayer_top{ 20.0 };
    double Jplayer_width{ 110.0 };
    double Jplayer_height{ 20.0 };
    double Jplayer_bottom = Jplayer_top + Jplayer_height;
    double Jplayer_right = Jplayer_left + Jplayer_width;

    double armorHP_left{ -450.0 };
    double armorHP_top{ 280.0 };
    double armorHP_width{ 0.0 };
    double armorHP_height{ 30.0 };

    double armor_left{ 0.0 };
    double armor_top{ -267.0 };
    double armor_width{ 30.0 };
    double armor_height{ 30.0 };

    double& anotoer_PlayerMPleft = playerMP_left;

    const  Image santa_right{ "asset/santa.png" };
    const  Image santa_left{ "asset/santa2.png" };
    const  Image warrior_right{ "asset/warrior.png" };
    const  Image warrior_left{ "asset/warrior2.png" };

    void draw_player()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(player_left, player_top, player_width, player_height);
        pop_settings();

            draw_image(santa_right, player_left, player_top, 40.0, 45.0);
            if (armorHP_width > 3.0)
            {
                draw_image(warrior_right, player_left - 1.0, player_top, 45.0, 45.0);
            }

    }

    void draw_playerHP()
    {
        push_settings();
        no_outline();
        set_font_size(25);
        draw_text("HP", -505, 270);
        set_fill_color(HexColor{ 0xff0000ff });
        draw_rectangle(playerHP_left, playerHP_top, playerHP_width, playerHP_bottom);
        set_fill_color(0);
        draw_text("HP", -505, 270);
        pop_settings();

        //HP automatic recovery
        if (playerHP_width < 360.0)
        {
            playerHP_width += 0.01;
        }
        else if (playerHP_width > 360.0)
        {
            playerHP_width = 360.0;
        }

        //end
        if (playerHP_width < 0.0)
        {
            current_scene = gameover;
        }
        if (armorHP_width < 0.5)
        {
            push_settings();
            set_font_size(20);
            draw_text("360 / " + to_string(playerHP_width), -380, 278);
            pop_settings();
        }
    }

    void armor()
    {        //armor
        if (armorHP_width < 0.0)
        {
            armorHP_width = -0.1;
        }
        if (armorHP_width > 250.0)
        {
            armorHP_width = 250.0;
        }
        if (armor_top + 30.0 > player_top && armor_top < player_top + 40.0 && armor_left < player_left + 40.0 && armor_left + 30.0 > player_left)
        {
            armor_left = 3000.0;
            armorHP_width = 300.0;
        }

        if (armorHP_width < 0.5)
        {
            push_settings();
            set_font_size(20);
            draw_text("360 / " + to_string(playerHP_width), -380, 278);
            pop_settings();
        }

        draw_rectangle(armorHP_left, armorHP_top, armorHP_width, armorHP_height);

        push_settings();
        set_fill_color(120.0);

        draw_rectangle(armor_left, armor_top, armor_width, armor_height);
        pop_settings();
        if (armorHP_width > 1.0)
        {
            push_settings();
            set_font_size(20);
            draw_text("300 / " + to_string(armorHP_width), -380, 278);
            pop_settings();
        }
    }

    void draw_playerMP()
    {
        push_settings();
        no_outline();
        set_font_size(25);
        set_fill_color(HexColor{ 0xA0F1FF });
        draw_rectangle(anotoer_PlayerMPleft, playerMP_top, playerMP_width, playerMP_bottom);
        set_fill_color(0);
        draw_text("MP", -30, 270);
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
            const double player_move = 1.2;
            player_left += player_move;
        }

        if (CheckKeyPressed[1])
        {
                draw_image(santa_left, player_left, player_top, 40.0, 45.0);
                if (armorHP_width > 3.0)
                {
                    draw_image(warrior_left, player_left - 4.0, player_top, 45.0, 45.0);
                }
            const double player_move = 1.2;
            player_left -= player_move;
        }
    }

    void jump()
    {
        Jplayer_width += 1.5;
        if (Jplayer_width < 0.0)
        {
            Jplayer_width = 0.0;
        }
        else if (Jplayer_width > 100.0)
        {
            Jplayer_width = 100.0;
        }

        if (Jplayer_width > 0.0)
        {
            if (CheckKeyPressed[5])
            {
                Jplayer_width -= 4.0;
                player_top += 6.0;
            }
        }

        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(Jplayer_left, Jplayer_top, Jplayer_width, Jplayer_height);
        pop_settings();
    }

    void player_falling()
    {
        player_top -= 3.0;
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
            player_top = -350.0;
            current_scene = stage2;
        }
    }
};
Player player;