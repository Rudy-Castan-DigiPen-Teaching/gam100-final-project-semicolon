#pragma once

#include <doodle/doodle.hpp>
using namespace doodle;

class BOSS_RAIN
{
public:
    double rain_left = { 0.0 };
    double rain_top{ -300.0 };
    double rain_width{ 15.0 };
    double rain_height{ 15.0 };
    double rain_bottom = rain_top + rain_height;
    double rain_right = rain_left + rain_width;

    void draw_BossRain()
    {
        draw_rectangle(rain_left, rain_top, rain_width, rain_height);
    }
};