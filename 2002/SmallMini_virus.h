// Filename : <SmallMini_virus.h>
// Authors : <Hyunjun Lee, Dawoon Jung>
// Course : GAM100F21
// All content © 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once

#include <doodle/doodle.hpp>
using namespace doodle;

class Mini_Virus
{
public:
    double minivirus_left{ -19.0 };
    double minivirus_left2{ 120.0 };
    double minivirus_left3{ -160.0 };
    double minivirus_left4{ 250.0 };
    double minivirus_left5{ -290.0 };
    double minivirus_left6{ 380.0 };
    double minivirus_left7{ -420.0 };
    double minivirus_left8{ 510.0 };
    double minivirus_left9{ -550.0 };

    double minivirus_top{ -20.0 };
    double minivirus_width{ 60.0 };
    double minivirus_height{ 60.0 };
    const  Image Viruses{ "asset/mini_virus.png" };
    void draw_minivirus()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(minivirus_left, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left2, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left3, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left4, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left5, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left6, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left7, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left8, minivirus_top, minivirus_width, minivirus_height);
        draw_rectangle(minivirus_left9, minivirus_top, minivirus_width, minivirus_height);
        pop_settings();

        draw_image(Viruses, minivirus_left, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left2, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left3, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left4, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left5, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left6, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left7, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left8, minivirus_top, minivirus_width, minivirus_height);
        draw_image(Viruses, minivirus_left9, minivirus_top, minivirus_width, minivirus_height);

        move_minivirus();
    }

    void move_minivirus(void)
    {
        double b_mini_move = 200.0 * DeltaTime;

        minivirus_top -= b_mini_move;

        if (minivirus_top < -360.0)
        {
            minivirus_top = random(-19.0, 40.0);
        }
    }
};
Mini_Virus mini;
