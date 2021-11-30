#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "doors.h"

using namespace doodle;

class Stage1_Key
{
public:
    double stage1_key_left{ 300.0 };
    double stage1_key_top{ -80.0 };
    double stage1_key_width{ 20.0 };
    double stage1_key_height{ 20.0 };
    double stage1_key_bottom = stage1_key_top + stage1_key_height;
    double stage1_key_right = stage1_key_left + stage1_key_width;

    double stage1_gauge_left{ 0.0 };
    double stage1_gauge_top{0.0 };
    double stage1_gauge_width{ 100.0 };
    double stage1_gauge_height{ 10.0 };
    double stage1_gauge_bottom = stage1_gauge_top + stage1_gauge_height;
    double stage1_gauge_right = stage1_gauge_left + stage1_gauge_width;

    double stage1_HPrecover_left{ 350.0 };
    double stage1_HPrecover_top{ -80.0 };
    double stage1_HPrecover_width{ 20.0 };
    double stage1_HPrecover_height{ 20.0 };
    double stage1_HPrecover_bottom = stage1_HPrecover_top + stage1_HPrecover_height;
    double stage1_HPrecover_right = stage1_HPrecover_left + stage1_HPrecover_width;

    double stage1_MPrecover_left{ 300.0 };
    double stage1_MPrecover_top{ -300.0 };
    double stage1_MPrecover_width{ 20.0 };
    double stage1_MPrecover_height{ 20.0 };
    double stage1_MPrecover_bottom = stage1_MPrecover_top + stage1_MPrecover_height;
    double stage1_MPrecover_right = stage1_MPrecover_left + stage1_MPrecover_width;



    void draw_stage1_key_monster2(void)
    {
        //KEY
        player_stage1_key_contact_HP();
        draw_rectangle(stage1_key_left, stage1_key_top, stage1_key_width, stage1_key_height);

        //HP 
        push_settings();
        set_fill_color(120, 0, 0);
        draw_rectangle(stage1_HPrecover_left, stage1_HPrecover_top, stage1_HPrecover_width, stage1_HPrecover_height);
        pop_settings();
    }

    void DropItem_monster1()
    {
        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

        //recover MP
        if (Over(player.player_left, player.player_right, stage1_MPrecover_left, stage1_HPrecover_right)
            && Over(player.player_top, player.player_bottom, stage1_MPrecover_top, stage1_MPrecover_bottom))
        {
            stage1_MPrecover_left = 3000.0;
            player.playerMP_width += 360.0;
        }

        //MP
        draw_rectangle(stage1_MPrecover_left, stage1_MPrecover_top, stage1_MPrecover_width, stage1_MPrecover_height);
    }

    void stage1_guage_draw_door()
    {
        push_settings();
        no_fill();
        no_outline();
;       draw_rectangle(stage1_gauge_left, stage1_gauge_top, stage1_gauge_width, stage1_gauge_height);
        pop_settings();

        if (stage1_gauge_width < 0.0)
        {
            five.draw_five_door();
        }
    }

    void player_stage1_key_contact_HP(void)
    {
        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

        //key
        if (Over(player.player_left, player.player_right, stage1_key_left, stage1_key_right)
            && Over(player.player_top, player.player_bottom, stage1_key_top, stage1_key_bottom))
        {
            stage1_key_left = 3000.0;
            stage1_gauge_width -= 200.0;
        }

        //recover HP
        if (Over(player.player_left, player.player_right, stage1_HPrecover_left, stage1_MPrecover_right)
            && Over(player.player_top, player.player_bottom, stage1_HPrecover_top, stage1_HPrecover_bottom))
        {
            stage1_HPrecover_left = 3000.0;
            player.playerHP_width += 360.0;
        }
    }
};
Stage1_Key stage1_key;