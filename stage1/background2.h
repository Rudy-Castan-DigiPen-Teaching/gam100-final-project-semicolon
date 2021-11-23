#pragma once

#include <doodle/doodle.hpp>
#include "player.h"

using namespace doodle;

class WallS
{
public:
    double under_wall_left{ -580.0 };
    double under_wall_top{ -370.0 };
    double under_wall_width{ 1200.0 };
    double under_wall_height{ 10.0 };
    double under_wall_right = under_wall_left + under_wall_width;
    double under_wall_bottom = under_wall_top + under_wall_height;

    double left_wall_left{ -580.0 };
    double left_wall_top{ -370.0 };
    double left_wall_width{ 10.0 };
    double left_wall_height{ 610.0 };
    double left_wall_right = left_wall_left + left_wall_width;
    double left_wall_bottom = left_wall_top + left_wall_height;

    double right_wall_left{ 620.0 };
    double right_wall_top{ -370.0 };
    double right_wall_width{ 10.0 };
    double right_wall_height{ 610.0 };
    double right_wall_right = right_wall_left + right_wall_width;
    double right_wall_bottom = right_wall_top + right_wall_height;

    double upside_wall_left{ -580.0 };
    double upside_wall_top{ 240.0 };
    double upside_wall_width{ 1210.0 };
    double upside_wall_height{ 10.0 };
    double upside_wall_right = upside_wall_left + upside_wall_width;
    double upside_wall_bottom = upside_wall_top + upside_wall_height;

    double floor1_left{ 80.0 };
    double floor1_top{ -270.0 };
    double floor1_width{ 100.0 };
    double floor1_height{ 10.0 };
    double floor1_right = floor1_left + floor1_width;
    double floor1_bottom = floor1_top + floor1_height;

    double floor2_left{ 80.0 };
    double floor2_top{ -170.0 };
    double floor2_width{ 100.0 };
    double floor2_height{ 10.0 };
    double floor2_right = floor2_left + floor2_width;
    double floor2_bottom = floor2_top + floor2_height;

    void draw_stage2_floors()
    {
        if (player.player_left > floor1_left && player.player_left < floor1_right
            && player.player_top > floor1_top && player.player_top < floor1_bottom)
        {
            player.player_top += 3;
        }

        draw_rectangle(floor1_left, floor1_top, floor1_width, floor1_height);
        if (player.player_left > floor2_left && player.player_left < floor2_right
            && player.player_top > floor2_top && player.player_top < floor2_bottom)
        {
            player.player_top += 3;
        }
        draw_rectangle(floor2_left, floor2_top, floor2_width, floor2_height);
    }

    void draw_walls()
    {
        udner_update();
        left_update();
        right_update();
        upsdie_update();
        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

        if (Over(under_wall_left, under_wall_right, player.player_left, player.player_right)
            && Over(under_wall_top, under_wall_bottom, player.player_top, player.player_bottom))
        {
            udner_update();
            player.player_top += 3.0;
        }

        if (Over(left_wall_left, left_wall_right, player.player_left, player.player_right)
            && Over(left_wall_top, left_wall_bottom, player.player_top, player.player_bottom))
        {
            left_update();
            player.player_left += 3.0;
        }

        if (player.player_left > 580.0)
        {
            right_update();
            player.player_left -= 3.0;
        }

        if (player.player_top + 50 > upside_wall_bottom)
        {
            upsdie_update();
            player.player_top -= 3.0;
        }

        push_settings();
        no_outline();
        set_fill_color(0);
        draw_rectangle(-580, -60, 1200, 300);
        draw_rectangle(-580, -60, 1200, -300);
        pop_settings();

        push_settings();
        no_outline();
        set_fill_color(250, 0, 0);
        draw_rectangle(under_wall_left, under_wall_top, under_wall_width, under_wall_height);
        draw_rectangle(left_wall_left, left_wall_top, left_wall_width, left_wall_height);
        draw_rectangle(right_wall_left, right_wall_top, right_wall_width, right_wall_height);
        draw_rectangle(upside_wall_left, upside_wall_top, upside_wall_width, upside_wall_height);
        pop_settings();
    }

    void udner_update(void)
    {
        under_wall_right = under_wall_left + under_wall_width;
        under_wall_bottom = under_wall_top + under_wall_height;
    }

    void left_update(void)
    {
        left_wall_right = left_wall_left + left_wall_width;
        left_wall_bottom = left_wall_top + left_wall_height;
    }

    void right_update(void)
    {
        right_wall_right = right_wall_left + right_wall_width;
        right_wall_bottom = right_wall_top + right_wall_height;
    }

    void upsdie_update(void)
    {
        upside_wall_right = upside_wall_left + upside_wall_width;
        upside_wall_bottom = upside_wall_top + upside_wall_height;
    }
};
WallS walls;