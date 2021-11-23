#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "Stage1_Key.h"
using namespace doodle;

class Monster2
{
public:
    double monster_left2{ 300.0 };
    double monster_top2{ -80.0 };
    double monster_width2{ 50.0 };
    double monster_height2{ 50.0 };
    double monster_bottom2 = monster_top2 + monster_height2;
    double monster_right2 = monster_left2 + monster_width2;

    double monsterHP_left2{ 275.0 };
    double monsterHP_top2{ -20.0 };
    double monsterHP_width2{ 100.0 };
    double monsterHP_height2{ 10.0 };
    double monsterHP_bottom2 = monsterHP_top2 + monsterHP_height2;
    double monsterHP_right2 = monsterHP_left2 + monsterHP_width2;

    bool direction2 = true;

    void draw_monster_HP_2()
    {
        if (monsterHP_width2 > 0.0)
        {
            draw_rectangle(monster_left2, monster_top2, monster_width2, monster_height2);
            draw_rectangle(monsterHP_left2, monsterHP_top2, monsterHP_width2, monsterHP_height2);

            monster_attack_range_2();
            draw_monster_HP_move_2();

            //warm
            if (monster_left2 - 300 < player.player_left && player.player_left < monster_left2 + 300
                && player.player_top >= -100 && player.player_bottom <= 100)
            {
                push_settings();
                no_outline();
                set_fill_color(HexColor{ 0xFFD56E });
                draw_ellipse(monster_left2 - 40, -20, 9);
                draw_rectangle(monster_left2 - 44, -10, 8, 50);
                pop_settings();
            }
        }
        else
        {
            stage1_key.draw_stage1_key_monster2();
        }
    }

    void draw_monster_HP_move_2(void)
    {
        update2();
        if (direction2 == true)
        {
            monster_left2 += 0.8;
            monsterHP_left2 += 0.8;
            if (monster_left2 > 400 && monsterHP_left2 > 400)
            {
                direction2 = false;
            }
        }
        else
        {
            monster_left2 -= 4;
            monsterHP_left2 -= 4;
            if (monster_left2 < 0 && monsterHP_left2 < 0)
            {
                direction2 = true;
            }
        }
    }

    void monster_attack_range_2(void)
    {
        update2();

        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

        if (Over(player.player_left, player.player_right, monster_left2, monster_right2)
            && Over(player.player_top, player.player_bottom, monster_top2, monster_bottom2))
        {
            player.playerHP_width -= 2;
            if (player.player_left > monster_left2)
            {
                player.player_left = monster_left2 - 50;
            }
        }
    }

    void update2(void)
    {
        monster_bottom2 = monster_top2 + monster_height2;
        monster_right2 = monster_left2 + monster_width2;

        monsterHP_bottom2 = monsterHP_top2 + monsterHP_height2;
        monsterHP_right2 = monsterHP_left2 + monsterHP_width2;
    }
};
Monster2 monster2;