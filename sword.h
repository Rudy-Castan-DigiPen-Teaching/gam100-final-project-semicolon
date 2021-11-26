#pragma once

#include <doodle/doodle.hpp>

#include "background.h"
#include "player_key.h"
#include "player.h"
#include "first_floor_monster.h"
#include "second_floor_monster.h"

using namespace doodle;

class Sword
{
public:
    double sword_left{ -60 };
    double sword_top{ -280.0 };
    double sword_width{ 50.0 };
    double sword_height{ 10.0 };
    double sword_bottom = sword_top + sword_height;
    double sword_right = sword_left + sword_width;

    double sword_left2{ -150 };
    double sword_top2{ -280.0 };
    double sword_width2{ 50.0 };
    double sword_height2{ 10.0 };
    double sword_bottom2 = sword_top2 + sword_height2;
    double sword_right2 = sword_left2 + sword_width2;

    void draw_sword_move()
    {
        //D right
        if (CheckKeyPressed[0])
        {
            if (CheckKeyPressed[2])
            {
                sword_left = player.player_left + 40;
                push_settings();
                set_fill_color(0, 150, 0);
                draw_rectangle(sword_left, player.player_top+20, sword_width, sword_height);
                pop_settings();
            }
        }

        //L left
        if (CheckKeyPressed[1])
        {
            if (CheckKeyPressed[2])
            {
                sword_left2 = player.player_left - 40;
                push_settings();
                set_fill_color(250, 0, 0);
                draw_rectangle(sword_left2, player.player_top+20, sword_width2, sword_height2);
                pop_settings();
            }
        }

        if (CheckKeyPressed[0])
        {
            const double player_move = 1.2;
            sword_left += player_move;
            sword_left2 += player_move;
        }

        if (CheckKeyPressed[1])
        {
            const double player_move = 1.2;
            sword_left -= player_move;
            sword_left2 -= player_move;
        }
    }

    void stage1_mosters()
    {
        if (sword_left + 50 > monster.monster_left && sword_left + 50 < monster.monster_left + 50
            && sword_top > monster.monster_top && sword_top < monster.monster_top + 50)
        {
            monster.monsterHP_width -= 2;
        }
    }
};
Sword sword;