#pragma once

#include <doodle/doodle.hpp>
using namespace doodle;

#include "player.h"
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "monster4.h"

class BOSS_RAIN
{
public:
    double B_rain_left = { 0.0 };
    double B_rain_top{ -300.0 };
    double B_rain_width{ 25.0 };
    double B_rain_height{ 25.0 };

    const  Image Virus { "asset/mini_virus.png" };

    void draw_BossRain()
    {
        if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width < 1.0)
        {
            contact_rain_player();
            b_move_rain();

            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(B_rain_left, B_rain_top, B_rain_width, B_rain_height);
            pop_settings();

            draw_image(Virus, B_rain_left, B_rain_top, B_rain_width, B_rain_height);

        }
    }

    void b_move_rain(void)
    {
        double b_rain_move = 200.0 * DeltaTime;

        B_rain_top -= b_rain_move;

        if (B_rain_top < -360.0)
        {
            B_rain_left = random(-600.0, 600.0);
            B_rain_top = random(200.0, 500.0);
        }
    }

    void contact_rain_player(void)
    {
        if (B_rain_top < player.player_top + 40.0 && B_rain_top > player.player_top
            && B_rain_left < player.player_left + 40.0 && B_rain_left + 25.0 > player.player_left)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();
            B_rain_left = random(-600.0, 600.0);
            B_rain_top = random(200.0, 500.0);
            player.armorHP_width -= 10.0;
            if (player.armorHP_width < 0.0)
            {
                player.playerHP_width -= 5.0;
            }
        }
    }


};
BOSS_RAIN boss_rain;