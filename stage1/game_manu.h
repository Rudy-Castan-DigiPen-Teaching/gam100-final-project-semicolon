#pragma once

#include <doodle/doodle.hpp>

using namespace doodle;

class main
{
public:
    double starting_botton_x{ -300 };
    double starting_botton_y{ 200 };
    double starting_botton_width{ 200 };
    double starting_botton_height{ 100 };

    double how_to_play_botton_x{ -300 };
    double how_to_play_botton_y{ -200 };
    double how_to_play_botton_width{ 200 };
    double how_to_play_botton_height{ 100 };

    void start_botton()
    {
        push_settings();
        draw_rectangle(starting_botton_x, starting_botton_y, starting_botton_width, starting_botton_height);
        set_font_size(25);
        set_fill_color(0);
        draw_text("start botton", starting_botton_x, starting_botton_y + 30);
        pop_settings();
        if (get_mouse_x() > starting_botton_x && get_mouse_x() < starting_botton_x + starting_botton_width &&
            get_mouse_y() > starting_botton_y && get_mouse_y() < starting_botton_y + starting_botton_height
            && MouseIsPressed)
        {
            current_scene = 1;
        }
    }

    void how_to_play_botton() 
    {
        push_settings();
        draw_rectangle(how_to_play_botton_x, how_to_play_botton_y, how_to_play_botton_width, how_to_play_botton_height);
        set_font_size(25);
        set_fill_color(0);
        draw_text("How To Play", how_to_play_botton_x, how_to_play_botton_y + 30);
        pop_settings();
        if (get_mouse_x() > how_to_play_botton_x && get_mouse_x() < how_to_play_botton_x + how_to_play_botton_width &&
            get_mouse_y() > how_to_play_botton_y && get_mouse_y() < how_to_play_botton_y + how_to_play_botton_height &&
            MouseIsPressed)
        {
            current_scene = 4;
        }
    }
};
main Main;