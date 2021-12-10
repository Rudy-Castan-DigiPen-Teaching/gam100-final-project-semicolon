// Filename : <rain.h>
// Authors : <Hyunjun Lee, Dawoon Jung>
// Course : GAM100F21
// All content © 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once

#include <doodle/doodle.hpp>

#include "player_key.h"

//stage1
#include "first_floor_monster.h"
#include "second_floor_monster.h"
#include "third_floor_monster.h"

//stage2
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "boss_rain.h"

using namespace doodle;

class Rain
{
public:
    double rain_left = { 0.0 };
    double rain_top{ -300.0 };
    double rain_width{ 15.0 };
    double rain_height{ 15.0 };
    double rain_bottom = rain_top + rain_height;
    double rain_right = rain_left + rain_width;

    double rainMP_left{ 30.0 };
    double rainMP_top{ 255.0 };
    double rainMP_width{ 200.0 };
    double rainMP_height{ 20.0 };
    double rainMP_bottom = rainMP_top + rainMP_height;
    double rainMP_right = rainMP_left + rainMP_width;

    void draw_rain()
    {
        if (player.playerHP_width > 300.0 && player.playerMP_width > 200.0)
        {
            if (CheckKeyPressed[4])
            {
                if (rainMP_width > 0.0)
                {
                    rainMP_width -= 0.3;
                    contact_monster();

                    push_settings();
                    no_fill();
                    no_outline();
                    draw_rectangle(rain_left, rain_top, rain_width, rain_height);
                    pop_settings();

                    push_settings();
                    no_outline();
                    set_fill_color(0, 250, 0);
                    draw_rectangle(rain_left - 5.0, rain_top + 7.0, 25, 7);
                    draw_rectangle(rain_left + 4.0, rain_top - 2.0, 7, 25);
                    pop_settings();
                }
            }
            else
            {
                rainMP_width += 0.1;
                if (rainMP_width >= 200.1)
                {
                    rainMP_width = 200.0;
                }
            }
        }

        draw_rectangle(rainMP_left, rainMP_top, rainMP_width, rainMP_height);
    }

    void contact_monster()
    {
        rain_bottom = rain_top + rain_height;
        rain_right = rain_left + rain_width;
        move_rain();
        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

        if (Over(rain_left, rain_right, monster.monster_left, monster.monster_right)
            && Over(rain_top, rain_bottom, monster.monster_top, monster.monster_bottom))
        {
            monster.monsterHP_width -= 20.0;
            rain_left = random(-600.0, 600.0);
            rain_top = random(200.0, 400.0);
        }

        if (Over(rain_left, rain_right, monster2.monster_left2, monster2.monster_right2)
            && Over(rain_top, rain_bottom, monster2.monster_top2, monster2.monster_bottom2))
        {
            monster2.monsterHP_width2 -= 20.0;
            rain_left = random(-600.0, 600.0);
            rain_top = random(200.0, 400.0);
        }

        if (Over(rain_left, rain_right, monster3.monster_left3, monster3.monster_right3)
            && Over(rain_top, rain_bottom, monster3.monster_top3, monster3.monster_bottom3))
        {
            monster3.monsterHP_width3 -= 20.0;
            rain_left = random(-600.0, 600.0);
            rain_top = random(200.0, 400.0);
        }

        if (stage2_monster1.monster1HP_width > 0.0)
        {
            if (Over(rain_left, rain_left + 15, stage2_monster1.monster1_left, stage2_monster1.monster1_left + 50)
                && Over(rain_top, rain_top + 15, stage2_monster1.monster1_top, stage2_monster1.monster1_top + 50))
            {
                stage2_monster1.monster1HP_width -= 10.0;
                rain_left = random(-600.0, 600.0);
                rain_top = random(200.0, 400.0);
            }
        }

        if (stage2_monster2.monster2HP_width > 0.0)
        {
            if (Over(rain_left, rain_left + 15, stage2_monster2.monster2_left, stage2_monster2.monster2_left + 50)
                && Over(rain_top, rain_top + 15, stage2_monster2.monster2_top, stage2_monster2.monster2_top + 50))
            {
                stage2_monster2.monster2HP_width -= 10;
                rain_left = random(-600, 600);
                rain_top = random(200, 400);
            }
        }

        if (stage2_monster3.monster3HP_width > 0.0)
        {
            if (Over(rain_left, rain_left + 15.0, stage2_monster3.monster3_left, stage2_monster3.monster3_left + 50.0)
                && Over(rain_top, rain_top + 15.0, stage2_monster3.monster3_top, stage2_monster3.monster3_top + 50.0))
            {
                stage2_monster3.monster3HP_width -= 10.0;
                rain_left = random(-600.0, 600.0);
                rain_top = random(200.0, 400.0);
            }
        }

        if (stage2_monster4.monster4HP_width > 0.0)
        {
            if (Over(rain_left, rain_left + 15.0, stage2_monster4.monster4_left, stage2_monster4.monster4_left + 50.0)
                && Over(rain_top, rain_top + 15.0, stage2_monster4.monster4_top, stage2_monster4.monster4_top + 50.0))
            {
                stage2_monster4.monster4HP_width -= 10.0;
                rain_left = random(-600.0, 600.0);
                rain_top = random(200.0, 400.0);
            }
        }

        if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width < 1.0)
        {
            if (Over(rain_left, rain_left + 15.0, stage2_boss.boss_left, stage2_boss.boss_left + 60.0)
                && Over(rain_top, rain_top + 15.0, stage2_boss.boss_top, stage2_boss.boss_top + 60.0))
            {
                stage2_boss.bossHP_width -= 10.0;
                rain_left = random(-600.0, 600.0);
                rain_top = random(200.0, 400.0);
            }
        }
    }

    void move_rain(void)
    {
        double rain_move = 200.0 * DeltaTime;

        rain_top -= rain_move;

        if (rain_top < -300.0)
        {
            rain_left = random(-600.0, 600.0);
            rain_top = random(200.0, 400.0);
        }
    }
};
Rain rain;