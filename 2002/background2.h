#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "monster4.h"
#include "stage2boss.h"
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

    double Lprison_left{ -70.0 };
    double Lprison_top{ -100.0 };
    double Lprison_width{ 20.0 };
    double Lprison_height{ 100.0 };
    double Lprison_right = Lprison_left + Lprison_width;
    double Lprison_bottom = Lprison_top + Lprison_height;

    double Rprison_left{ 80.0 };
    double Rprison_top{ -100.0 };
    double Rprison_width{ 20.0 };
    double Rprison_height{ 100.0 };
    double Rprison_right = Rprison_left + Rprison_width;
    double Rprison_bottom = Rprison_top + Rprison_height;

    double Uprison_left{ -50.0 };
    double Uprison_top{ 0.0 };
    double Uprison_width{ 130.0 };
    double Uprison_height{ 20.0 };
    double Uprison_right = Uprison_left + Uprison_width;
    double Uprison_bottom = Uprison_top + Uprison_height;

    double Dprison_left{ -50.0 };
    double Dprison_top{ -120.0 };
    double Dprison_width{ 130.0 };
    double Dprison_height{ 20.0 };
    double Dprison_right = Dprison_left + Dprison_width;
    double Dprison_bottom = Dprison_top + Dprison_height;

    //FLOOR
    double floor1_left{ -232.0 };
    double floor1_top{ -280.0 };
    double floor1_width{ 500.0 };
    double floor1_height{ 10.0 };
    double floor1_right = floor1_left + floor1_width;
    double floor1_bottom = floor1_top + floor1_height;

    double floor2_left{ -195.0 };
    double floor2_top{ 70.0 };
    double floor2_width{ 415.0 };
    double floor2_height{ 10.0 };
    double floor2_right = floor2_left + floor2_width;
    double floor2_bottom = floor2_top + floor2_height;

    double floor3_left{ -495.0 };
    double floor3_top{ -215.0 };
    double floor3_width{ 200.0 };
    double floor3_height{ 10.0 };
    double floor3_right = floor3_left + floor3_width;
    double floor3_bottom = floor3_top + floor3_height;

    double floor4_left{ -495.0 };
    double floor4_top{ -245.0 };
    double floor4_width{ 20.0 };
    double floor4_height{ 30.0 };
    double floor4_right = floor4_left + floor4_width;
    double floor4_bottom = floor4_top + floor4_height;

    double floor5_left{ -570.0 };
    double floor5_top{ -145.0 };
    double floor5_width{ 90.0 };
    double floor5_height{ 15.0 };
    double floor5_right = floor5_left + floor5_width;
    double floor5_bottom = floor5_top + floor5_height;

    double floor6_left{ -475.0 };
    double floor6_top{ 85.0 };
    double floor6_width{ 200.0 };
    double floor6_height{ 10.0 };
    double floor6_right = floor6_left + floor6_width;
    double floor6_bottom = floor6_top + floor6_height;

    double floor7_left{ -450.0 };
    double floor7_top{ -60.0 };
    double floor7_width{ 150.0 };
    double floor7_height{ 20.0 };
    double floor7_right = floor7_left + floor7_width;
    double floor7_bottom = floor7_top + floor7_height;

    double floor8_left{ -570.0 };
    double floor8_top{ 0.0 };
    double floor8_width{ 60.0 };
    double floor8_height{ 10.0 };
    double floor8_right = floor8_left + floor8_width;
    double floor8_bottom = floor8_top + floor8_height;

    double floor9_left{ -240.0 };
    double floor9_top{ -150.0 };
    double floor9_width{ 40.0 };
    double floor9_height{ 10.0 };
    double floor9_right = floor9_left + floor9_width;
    double floor9_bottom = floor9_top + floor9_height;

    void draw_stage2_floors()
    {
        push_settings();
        set_fill_color(0,0,0);
        no_outline();
        if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
        {
            draw_rectangle(Lprison_left, Lprison_top, Lprison_width, Lprison_height);
            draw_rectangle(Rprison_left, Rprison_top, Rprison_width, Rprison_height);
            draw_rectangle(Uprison_left, Uprison_top, Uprison_width, Uprison_height);
            draw_rectangle(Dprison_left, Dprison_top, Dprison_width, Dprison_height);

            //floor2
            if (player.player_left + 40.0 > floor2_left && player.player_left < floor2_right
                && player.player_top + 40.0 > floor2_top && player.player_top + 40.0 < floor2_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top -= 3.0;
                }
            }
            if (player.player_left + 40.0 > floor2_left && player.player_left < floor2_right
                && player.player_top > floor2_top && player.player_top < floor2_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top += 3.0;
                }
            }
            draw_rectangle(floor2_left, floor2_top, floor2_width, floor2_height);

            //floor6
            if (player.player_left + 40.0 > floor6_left && player.player_left < floor6_right
                && player.player_top + 40 > floor6_top && player.player_top < floor6_top + 10.0)
            {
                player.player_top += 3.0;
            }
            if (player.player_left + 40.0 > floor6_left && player.player_left < floor6_right
                && player.player_top + 40.0 > floor6_top && player.player_top + 40.0 < floor6_top + 10.0)
            {
                player.player_top -= 3.0;
            }
            draw_rectangle(floor6_left, floor6_top, floor6_width, floor6_height);

            if (player.player_left + 40.0 > floor6_left + 782.0 && player.player_left < floor6_right + 782.0
                && player.player_top > floor6_top && player.player_top < floor6_top + 10.0)
            {
                player.player_top += 3.0;
            }
            if (player.player_left + 40.0 > floor6_left + 782.0 && player.player_left < floor6_right + 782.0
                && player.player_top + 40.0 > floor6_top && player.player_top + 40.0 < floor6_top + 10.0)
            {
                player.player_top -= 3.0;
            }
            draw_rectangle(floor6_left + 782.0, floor6_top, floor6_width, floor6_height);

            //floor7
            if (player.player_left + 40.0 > floor7_left && player.player_left < floor7_right
                && player.player_top > floor7_top && player.player_top < floor7_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top += 3.0;
                }
            }
            if (player.player_left + 40.0 > floor7_left && player.player_left < floor7_right
                && player.player_top + 40.0 > floor7_top && player.player_top + 40.0 < floor7_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top += 3.0;
                }
            }
            draw_rectangle(floor7_left, floor7_top, floor7_width, floor7_height);

            if (player.player_left + 40.0 > floor7_left + 790.0 && player.player_left < floor7_right + 790.0
                && player.player_top > floor7_top && player.player_top < floor7_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top += 3.0;
                }
            }
            if (player.player_left + 40.0 > floor7_left + 790.0 && player.player_left < floor7_right + 790.0
                && player.player_top + 40.0 > floor7_top && player.player_top + 40.0 < floor7_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top += 3.0;
                }
            }
            draw_rectangle(floor7_left + 790.0, floor7_top, floor7_width, floor7_height);

            //floor 8
            if (player.player_left + 40.0 > floor8_left && player.player_left < floor8_right
                && player.player_top > floor8_top && player.player_top < floor8_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top += 3.0;
                }
            }
            if (player.player_left + 40.0 > floor8_left && player.player_left < floor8_right
                && player.player_top + 40.0 > floor8_top && player.player_top + 40.0 < floor8_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top -= 3.0;
                }
            }
            draw_rectangle(floor8_left, floor8_top, floor8_width, floor8_height);

            if (player.player_left + 40.0 > floor8_left + 1130.0 && player.player_left < floor8_right + 1130.0
                && player.player_top > floor8_top && player.player_top < floor8_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top += 3.0;
                }
            }
            if (player.player_left + 40.0 > floor8_left + 1130.0 && player.player_left < floor8_right + 1130.0
                && player.player_top + 40.0> floor8_top && player.player_top + 40.0 < floor8_bottom)
            {
                if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
                {
                    player.player_top -= 3.0;
                }
            }
            draw_rectangle(floor8_left + 1130.0, floor8_top, floor8_width, floor8_height);
        }

        //floor1
        if (player.player_left + 40.0 > floor1_left && player.player_left < floor1_right
            && player.player_top > floor1_top && player.player_top < floor1_bottom)
        {
            player.player_top += 3.0;
        }
        if (player.player_left + 40.0 > floor1_left && player.player_left < floor1_right
            && player.player_top + 40.0 > floor1_top && player.player_top + 40.0 < floor1_bottom)
        {
            player.player_top -= 3.0;
        }
        draw_rectangle(floor1_left, floor1_top, floor1_width, floor1_height);

        //floor3
        if (player.player_left + 40.0 > floor3_left && player.player_left < floor3_right
            && player.player_top + 40.0 > floor3_top && player.player_top + 40.0 < floor3_bottom)
        {
            player.player_top -= 3.0;
        }
        if (player.player_left + 40.0 > floor3_left && player.player_left < floor3_right
            && player.player_top > floor3_top && player.player_top < floor3_bottom)
        {
            player.player_top += 3.0;
        }
        draw_rectangle(floor3_left, floor3_top, floor3_width, floor3_height);

        if (player.player_left + 40.0 > floor3_left + 825.0 && player.player_left < floor3_right + 825.0
            && player.player_top + 40.0 > floor3_top && player.player_top + 40.0 < floor3_bottom)
        {
            player.player_top -= 3.0;
        }
        if (player.player_left + 40.0 > floor3_left + 825.0 && player.player_left < floor3_right + 825.0
            && player.player_top > floor3_top && player.player_top < floor3_bottom)
        {
            player.player_top += 3.0;
        }
        draw_rectangle(floor3_left + 825.0, floor3_top, floor3_width, floor3_height);

        //floor4
        if (player.player_left + 40.0 > floor4_left && player.player_left < floor4_right
            && player.player_top + 40.0 > floor4_top && player.player_top + 40.0 < floor4_bottom)
        {
            player.player_top -= 3.0;
        }
        draw_rectangle(floor4_left, floor4_top, floor4_width, floor4_height);

        if (player.player_left + 40.0 > floor4_left + 180.0 && player.player_left < floor4_right + 180.0
            && player.player_top + 40.0 > floor4_top && player.player_top + 40.0 < floor4_bottom)
        {
            player.player_top -= 3.0;
        }
        draw_rectangle(floor4_left + 180.0, floor4_top, floor4_width, floor4_height);

        if (player.player_left + 40.0 > floor4_left + 825.0 && player.player_left < floor4_right + 825.0
            && player.player_top + 40.0 > floor4_top && player.player_top + 40.0 < floor4_bottom)
        {
            player.player_top -= 3.0;
        }
        draw_rectangle(floor4_left + 825.0, floor4_top, floor4_width, floor4_height);

        if (player.player_left + 40.0 > floor4_left + 1005.0 && player.player_left < floor4_right + 1005.0
            && player.player_top + 40.0 > floor4_top && player.player_top + 40.0 < floor4_bottom)
        {
            player.player_top -= 3.0;
        }
        draw_rectangle(floor4_left + 1005.0, floor4_top, floor4_width, floor4_height);

        //floor5
        if (player.player_left < floor5_right && player.player_top + 40 > floor5_top && player.player_top + 40 < floor5_bottom)
        {
            player.player_top -= 3.0;
        }
        if (player.player_left < floor5_right && player.player_top > floor5_top && player.player_top < floor5_bottom)
        {
            player.player_top += 3.0;
        }
        draw_rectangle(floor5_left, floor5_top, floor5_width, floor5_height);

        if (player.player_left + 40.0 > floor5_left + 1100.0 && player.player_top + 40.0 > floor5_top && player.player_top + 40.0 < floor5_bottom)
        {
            player.player_top -= 3.0;
        }
        if (player.player_left + 40 > floor5_left + 1100.0 && player.player_top > floor5_top && player.player_top < floor5_bottom)
        {
            player.player_top += 3.0;
        }
        draw_rectangle(floor5_left + 1100, floor5_top, floor5_width, floor5_height);

        //floor 9 
        if (player.player_left + 40.0 > floor9_left && player.player_left < floor9_right
            && player.player_top > floor9_top && player.player_top < floor9_bottom)
        {
            player.player_top += 3.0;
            if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
            {
                player.playerHP_width += 1.0;
            }
            else
            {
                player.playerHP_width += 0.5;
            }

        }
        if (player.player_left + 40.0 > floor9_left && player.player_left < floor9_right
            && player.player_top + 40.0 > floor9_top && player.player_top + 40.0 < floor9_bottom)
        {
            player.player_top -= 3.0;
        }
        push_settings();
        set_fill_color(250, 0, 0);
        draw_rectangle(floor9_left, floor9_top, floor9_width, floor9_height);
        pop_settings();

        if (player.player_left + 40.0 > floor9_left + 470.0 && player.player_left < floor9_right + 470.0
            && player.player_top > floor9_top && player.player_top < floor9_bottom)
        {
            player.player_top += 3.0;
            if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
            {
                player.playerMP_width += 1.0;
            }
            else
            {
                player.playerMP_width += 0.5;
            }

        }
        if (player.player_left + 40.0 > floor9_left + 470.0 && player.player_left < floor9_right + 470.0
            && player.player_top + 40.0 > floor9_top && player.player_top + 40.0 < floor9_bottom)
        {
            player.player_top -= 3.0;
        }
        push_settings();
        set_fill_color(0, 0, 250);
        draw_rectangle(floor9_left + 470.0, floor9_top, floor9_width, floor9_height);
        pop_settings();



        pop_settings();
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