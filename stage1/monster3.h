#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "sword.h"

using namespace doodle;

class MONSTER3
{
public:
    double monster3_left{ -400.0 };
    double monster3_top{ 98.0 };
    double monster3_width{ 50.0 };
    double monster3_height{ 50.0 };

    double monster3HP_left{ -405.0 }; //-465 ~ -360
    double monster3HP_top{  154.0 };
    double monster3HP_width{ 60.0 };
    double monster3HP_height{ 10.0 };

    bool speed3 = true;

    void draw_monster3()
    {
        if (monster3HP_width > 0.0)
        {
            contact_player_monster3();
            draw_rectangle(monster3_left, monster3_top, monster3_width, monster3_height);
            draw_rectangle(monster3HP_left, monster3HP_top, monster3HP_width, monster3HP_height);
        }
    }

    void monster3_move(void)
    {
        if (speed3 == true)
        {
            monster3_left -= 0.4;
            monster3HP_left -= 0.4;
            if (monster3_left < -460.0 && monster3HP_left < -465.0)
            {
                speed3 = false;
            }
        }
        else
        {
            monster3_left += 0.4;
            monster3HP_left += 0.4;
            if (monster3_left > -355.0 && monster3HP_left > -360.0)
            {
                speed3 = true;
            }
        }
    }

    void contact_player_monster3(void)
    {
        if (player.player_left + 40 >= monster3_left && player.player_left + 40 <= monster3_left + 40
            && player.player_top + 40 <= monster3_top + 40 && player.player_top + 40 >= monster3_top)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();

            player.player_left -= 3;
            player.playerHP_width -= 2;
        }
        if (player.player_left > monster3_left && player.player_left <= monster3_left + 40
            && player.player_top + 40 <= monster3_top + 40 && player.player_top + 40 >= monster3_top)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();

            player.player_left += 3;
            player.playerHP_width -= 2;
        }
    }
};
MONSTER3 stage2_monster3;