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
    double sword_left{ -60.0 };
    double sword_top{ -280.0 };
    double sword_width{ 50.0 };
    double sword_height{ 10.0 };
    double sword_bottom = sword_top + sword_height;
    double sword_right = sword_left + sword_width;

    double sword_left2{ -150.0 };
    double sword_top2{ -280.0 };
    double sword_width2{ 50.0 };
    double sword_height2{ 10.0 };
    double sword_bottom2 = sword_top2 + sword_height2;
    double sword_right2 = sword_left2 + sword_width2;
    const  Image image_candy_right{ "asset/candy.png" };
    const  Image image_candy_left{ "asset/candy2.png" };

    const  Image image_sword_right{ "asset/sword.png" };
    const  Image image_sword_left{ "asset/sword2.png" };

    void draw_sword_move()
    {
        //D right
        if (CheckKeyPressed[0])
        {
            if (CheckKeyPressed[2])
            {
                sword_left = player.player_left + 40.0;
                push_settings();
                no_fill();
                no_outline();
                draw_rectangle(sword_left, player.player_top + 20.0, sword_width, sword_height);
                pop_settings();
                if (!(player.armorHP_width > 3.0))
                {
                    draw_image(image_candy_right, sword_left - 3.0, player.player_top + 12.0, sword_width, sword_height+5.0);
                }

                if (player.armorHP_width > 3.0)
                {
                    draw_image(image_sword_right, sword_left - 5.0, player.player_top + 12.0, sword_width, sword_height+13.0);
                }

                if (player.player_left + 50.0 > monster2.monster_left2 && player.player_left + 50.0 < monster2.monster_left2 + 50.0
                    && player.player_top + 50.0 > monster2.monster_top2 && player.player_top + 50.0 < monster2.monster_top2 + 50.0)
                {
                    monster2.monsterHP_width2 -= 2.0;
                }
            }
        }

        //L left
        if (CheckKeyPressed[1])
        {
            if (CheckKeyPressed[2])
            {
                sword_left2 = player.player_left - 40.0;
                push_settings();
                no_fill();
                no_outline();
                draw_rectangle(sword_left2, player.player_top + 20.0, sword_width2, sword_height2);
                pop_settings();

                if (!(player.armorHP_width > 3.0))
                {
                    draw_image(image_candy_left, sword_left2, player.player_top + 12.0, sword_width2, sword_height2+5.0);
                }

                if (player.armorHP_width > 3.0)
                {
                    draw_image(image_sword_left, sword_left2-2.0, player.player_top + 12.0, sword_width2, sword_height2+13.0);
                }
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
        if (CheckKeyPressed[0])
        {
            if (CheckKeyPressed[2])
            {
                if (sword_left + 50.0 > monster.monster_left && sword_left + 50.0 < monster.monster_left + 50.0
                    && sword_top > monster.monster_top && sword_top < monster.monster_top + 50.0)
                {
                    monster.monsterHP_width -= 1.0;
                }
            }
        }
    }
};
Sword sword;