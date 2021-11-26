#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "sword.h"

using namespace doodle;

class MONSTER2
{
public:
    double monster2_left{ -460.0 }; //-460 ~ -355 
    double monster2_top{ -202.0 };
    double monster2_width{ 50.0 };
    double monster2_height{ 50.0 };

    double monster2HP_left{ -465.0 }; //-465 ~ -360
    double monster2HP_top{ -145.0 };
    double monster2HP_width{ 60.0 };
    double monster2HP_height{ 10.0 };

    double warm2_left = { -560.0 };
    double warm2_top = { -350 };
    double warm2_width = { 400.0 };
    double warm2_height = { 350.0 };

    bool speed2 = true;

    void draw_monster2()
    {
        if (monster2HP_width > 0.0)
        {
            monster2_move();
            draw_rectangle(monster2_left, monster2_top, monster2_width, monster2_height);
            draw_rectangle(monster2HP_left, monster2HP_top, monster2HP_width, monster2HP_height);

            //warm
            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(warm2_left, warm2_top, warm2_width, warm2_height);
            pop_settings();
            if (player.player_left < warm2_left + warm2_width && player.player_left + 40 > warm2_left
                && player.player_top < warm2_top + warm2_height && player.player_top + 40 > warm2_top)
            {
                push_settings();
                no_outline();
                set_fill_color(HexColor{ 0xFFD56E });
                draw_ellipse(monster2_left - 20, monster2_top + 50, 9);
                draw_rectangle(monster2_left - 24, monster2_top + 60, 8, 50);
                pop_settings();
            }
        }
    }

    void monster2_move(void)
    {
        if (speed2 == true)
        {
            monster2_left -= 0.4;
            monster2HP_left -= 0.4;
            if (monster2_left < -460.0 && monster2HP_left < -465.0)
            {
                speed2 = false;
            }
        }
        else
        {
            monster2_left += 0.4;
            monster2HP_left += 0.4;
            if (monster2_left > -355.0 && monster2HP_left > -360.0)
            {
                speed2 = true;
            }
        }
    }

    void contact_player_monster2()
    {
        if (player.player_left + 40 >= monster2_left && player.player_left + 40 <= monster2_left + 40
            && player.player_top + 40 <= monster2_top + 40 && player.player_top + 40 >= monster2_top)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();

            player.player_left -= 3;
            player.playerHP_width -= 2;
        }
        if (player.player_left > monster2_left && player.player_left <= monster2_left + 40
            && player.player_top + 40 <= monster2_top + 40 && player.player_top + 40 >= monster2_top)
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
MONSTER2 stage2_monster2;