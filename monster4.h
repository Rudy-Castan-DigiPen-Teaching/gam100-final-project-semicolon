#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "sword.h"

using namespace doodle;

class MONSTER4
{
public:
    double monster4_left{ 380.0 };
    double monster4_top{ 98.0 };
    double monster4_width{ 50.0 };
    double monster4_height{ 50.0 };

    double monster4HP_left{ 375.0 };
    double monster4HP_top{ 154.0 };
    double monster4HP_width{ 60.0 };
    double monster4HP_height{ 10.0 };

    bool speed4 = true;

    void draw_monster4()
    {
        if (monster4HP_width > 0.0)
        {
            contact_player_monster4();
            draw_rectangle(monster4_left, monster4_top, monster4_width, monster4_height);
            draw_rectangle(monster4HP_left, monster4HP_top, monster4HP_width, monster4HP_height);
        }
    }

    void monster4_move(void)
    {
        if (speed4 == true)
        {
            monster4_left -= 0.4;
            monster4HP_left -= 0.4;
            if (monster4_left < -460.0 && monster4HP_left < -465.0)
            {
                speed4 = false;
            }
        }
        else
        {
            monster4_left += 0.4;
            monster4HP_left += 0.4;
            if (monster4_left > -355.0 && monster4HP_left > -360.0)
            {
                speed4 = true;
            }
        }
    }

    void contact_player_monster4(void)
    {
        if (player.player_left + 40 >= monster4_left && player.player_left + 40 <= monster4_left + 40
            && player.player_top + 40 <= monster4_top + 40 && player.player_top + 40 >= monster4_top)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();

            player.player_left -= 3;
            player.playerHP_width -= 2;
        }
        if (player.player_left > monster4_left && player.player_left <= monster4_left + 40
            && player.player_top + 40 <= monster4_top + 40 && player.player_top + 40 >= monster4_top)
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
MONSTER4 stage2_monster4;