#pragma once

#include <doodle/doodle.hpp>
using namespace doodle;
class first_door
{
public:
    double under_door_left{ 570.0 };
    double under_door_top{ -300.0 };
    double under_door_width{ 20.0 };
    double under_door_height{ 100.0 };
    double under_door_right = under_door_left + under_door_width;
    double under_door_bottom = under_door_top + under_door_height;

    void draw_first_door()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(under_door_left, under_door_top, under_door_width, under_door_height);
        pop_settings();
    }
};
first_door first;

class second_door
{
public:
    double left_middle_door_left{ -590.0 };
    double left_middle_door_top{ -80.0 };
    double left_middle_door_width{ 20.0 };
    double left_middle_door_height{ 100.0 };
    double left_middle_door_right = left_middle_door_left + left_middle_door_width;
    double left_middle_door_bottom = left_middle_door_top + left_middle_door_height;

    void draw_second_door()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(left_middle_door_left, left_middle_door_top, left_middle_door_width, left_middle_door_height);
        pop_settings();
    }
};
second_door second;

class third_door
{
public:
    double right_middle_door_left{ 570.0 };
    double right_middle_door_top{ -80.0 };
    double right_middle_door_width{ 20.0 };
    double right_middle_door_height{ 100.0 };
    double right_middle_door_right = right_middle_door_left + right_middle_door_width;
    double right_middle_door_bottom = right_middle_door_top + right_middle_door_height;

    void draw_third_door()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(right_middle_door_left, right_middle_door_top, right_middle_door_width, right_middle_door_height);
        pop_settings();
    }
};
third_door third;

class fourth_door
{
public:
    double left_top_door_left{ -590.0 };
    double left_top_door_top{ 150.0 };
    double left_top_door_width{ 20.0 };
    double left_top_door_height{ 100.0 };
    double left_top_door_right = left_top_door_left + left_top_door_width;
    double left_top_door_bottom = left_top_door_top + left_top_door_height;

    void draw_fourth_door()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(left_top_door_left, left_top_door_top, left_top_door_width, left_top_door_height);
        pop_settings();
    }
};
fourth_door fourth;

class five_door
{
public:
    double right_top_door_left{ 570.0 };
    double right_top_door_top{ 150.0 };
    double right_top_door_width{ 20.0 };
    double right_top_door_height{ 100.0 };
    double right_top_door_right = right_top_door_left + right_top_door_width;
    double right_top_door_bottom = right_top_door_top + right_top_door_height;

    void draw_five_door(void)
    {
            push_settings();
            //no_fill();
            draw_rectangle(right_top_door_left, right_top_door_top, right_top_door_width, right_top_door_height);
            pop_settings();  
    }
};
five_door five;