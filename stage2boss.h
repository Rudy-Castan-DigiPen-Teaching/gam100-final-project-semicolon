#pragma once

#include <doodle/doodle.hpp>

using namespace doodle;

class STAGE2_BOSS
{
public:
    double boss_left { -10.0 };
    double boss_top{ -95.0 };
    double boss_width{ 50.0 };
    double boss_height{ 50.0 };
    double boss_bottom = boss_top + boss_height;
    double boss_right = boss_left + boss_width;

    void draw_boss()
    {
        boss_move();
        contact_floor();
        draw_rectangle(boss_left, boss_top, boss_width, boss_height);
    }

    void boss_HP()
    {

    }

    void boss_move(void)
    {
        boss_top -= 3;
    }

    void contact_floor(void)
    {
        if (boss_left + 50 > walls.Dprison_left && boss_left < walls.Dprison_right
            && boss_top > walls.Dprison_top && boss_top < walls.Dprison_bottom)
        {
            boss_top += 3;
        }

        if (boss_left + 50 > walls.under_wall_left && boss_left < walls.under_wall_right
            && boss_top > walls.under_wall_top && boss_top < walls.under_wall_bottom)
        {
            boss_top += 3;
        }
    }
};
STAGE2_BOSS stage2_boss;