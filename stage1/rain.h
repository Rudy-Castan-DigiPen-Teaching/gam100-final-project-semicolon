#pragma once

#include <doodle/doodle.hpp>

#include "player_key.h"
#include "first_floor_monster.h"
#include "second_floor_monster.h"
#include "third_floor_monster.h"

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
                    draw_rectangle(rain_left, rain_top, rain_width, rain_height);
                }
            }
            else
            {
                rainMP_width += 0.1;
                if (rainMP_width >= 200.1)
                {
                    rainMP_width = 200;
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
            monster.monsterHP_width -= 20;
            rain_left = random(-600, 600);
            rain_top = random(200, 400);
        }

        if (Over(rain_left, rain_right, monster2.monster_left2, monster2.monster_right2)
            && Over(rain_top, rain_bottom, monster2.monster_top2, monster2.monster_bottom2))
        {
            monster2.monsterHP_width2 -= 20;
            rain_left = random(-600, 600);
            rain_top = random(200, 400);
        }

        if (Over(rain_left, rain_right, monster3.monster_left3, monster3.monster_right3)
            && Over(rain_top, rain_bottom, monster3.monster_top3, monster3.monster_bottom3))
        {
            monster3.monsterHP_width3 -= 20;
            rain_left = random(-600, 600);
            rain_top = random(200, 400);
        }
    }

    void move_rain(void)
    {
        double rain_move = 200 * DeltaTime;

        rain_top -= rain_move;

        if (rain_top < -300.0)
        {
            rain_left = random(-600, 600);
            rain_top = random(200, 400);
        }
    }
};
Rain rain;