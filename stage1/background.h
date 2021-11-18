//NAME : Semicolon
//ASSIGNMENT : Game Snapshot
//COURSE : CS120
//TERM & YEAR : Fall 2021

#pragma once

#include <doodle/doodle.hpp>
using namespace doodle;

class Background
{
public:
    double floor_left{ -700.0 };
    double floor_top1{ -110.0 };
    double floor_top2{ 120.0 };
    double floor_top3{ -330.0 };
    double floor_width{ 1400.0 };
    double floor_height{ 30.0 };

    void draw_stage1()
    {
        push_settings();
        set_fill_color(0);
        draw_rectangle(floor_left, floor_top1, floor_width, floor_height);
        draw_rectangle(floor_left, floor_top2, floor_width, floor_height);
        draw_rectangle(floor_left, floor_top3, floor_width, floor_height);
        pop_settings();
    }
};
Background background;
