//NAME : Semicolon
//ASSIGNMENT : Game Snapshot
//COURSE : CS120
//TERM & YEAR : Fall 2021

#pragma once

#include <doodle/doodle.hpp>

#include "player_key.h"
#include "player.h"
#include "first_floor_monster.h"
#include "second_floor_monster.h"

using namespace doodle;

class Sword
{
public:
    double sword_left{ 40.0 };
    double sword_top{ -280.0 };
    double sword_width{ 50.0 };
    double sword_height{ 10.0 };
    double sword_bottom = sword_top + sword_height;
    double sword_right = sword_left + sword_width;

    double sword_left2{ -40.0 };
    double sword_top2{ -280.0 };
    double sword_width2{ 50.0 };
    double sword_height2{ 10.0 };
    double sword_bottom2 = sword_top2 + sword_height2;
    double sword_right2 = sword_left2 + sword_width2;

    void draw_sword_monster_attach()
    {
        //D right
        if (CheckKeyPressed[0])
        {
            const double player_move = 2.0 * DeltaTime;
            sword_left += player_move * 100;
            if (CheckKeyPressed[2])
            {
                sword_bottom = sword_top + sword_height;
                sword_right = sword_left + sword_width;

                auto Over = [](double aMin, double aMax, double bMin, double bMax)
                {
                    return aMax >= bMin and bMax >= aMin;
                };

                if (Over(sword_left, sword_right, monster.monster_left, monster.monster_right)
                    && Over(sword_top, sword_bottom, monster.monster_top, monster.monster_bottom))
                {
                    monster.monsterHP_width -= 2;
                }

                if (Over(sword_left, sword_right, monster2.monster_left2, monster2.monster_right2)
                    && Over(sword_top, sword_bottom, monster2.monster_top2, monster2.monster_bottom2))
                {
                    monster2.monsterHP_width2 -= 2;
                }
                
                push_settings();
                set_fill_color(0, 250, 0);
                draw_rectangle(player.player_left + 40, player.player_top + 15, sword_width, sword_height);
                pop_settings();
            }
        }
        //A left
        if (CheckKeyPressed[1])
        {
            const double player_move2 = 2.0 * DeltaTime;
            sword_left2 -= player_move2 * 100;
            if (CheckKeyPressed[2])
            {
                sword_bottom2 = sword_top2 + sword_height2;
                sword_right2 = sword_left2 + sword_width2;

                auto Over = [](double aMin, double aMax, double bMin, double bMax)
                {
                    return aMax >= bMin and bMax >= aMin;
                };             

                if (Over(sword_left2, sword_right2, monster.monster_left, monster.monster_right)
                    && Over(sword_top2, sword_bottom2, monster.monster_top, monster.monster_bottom))
                {
                    monster.monsterHP_width -= 2;
                }

                push_settings();
                set_fill_color(250,0,0);
                draw_rectangle(player.player_left-40, player.player_top + 15, sword_width2, sword_height2);
                pop_settings();
            }
        }

        //follow player_x
        //right
        if (CheckKeyPressed[1])
        {
            const double player_move = 2.0 * DeltaTime;
            sword_left -= player_move * 100;
        }

        //left
        if (CheckKeyPressed[0])
        {
            const double player_moves = 2.0 * DeltaTime;
            sword_left2 += player_moves * 100;
        }
    }
};
Sword sword;
