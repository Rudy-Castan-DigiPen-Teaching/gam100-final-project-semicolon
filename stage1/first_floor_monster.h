//NAME : Semicolon
//ASSIGNMENT : Game Snapshot
//COURSE : CS120
//TERM & YEAR : Fall 2021

#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "Stage1_Key.h"

using namespace doodle;

class Monster
{
public:
    double monster_left{ 300.0 };
    double monster_top{ -300.0 };
    double monster_width{ 50.0 };
    double monster_height{ 50.0 };
    double monster_bottom = monster_top + monster_height;
    double monster_right = monster_left + monster_width;

    double monsterHP_left{ 260.0 };
    double monsterHP_top{ -240.0 };
    double monsterHP_width{ 120.0 };
    double monsterHP_height{ 10.0 };
    double monsterHP_bottom = monsterHP_top + monsterHP_height;
    double monsterHP_right = monsterHP_left + monsterHP_width;

    double monster_sword_left{ 250.0 };
    double monster_sword_top{ -280.0 };
    double monster_sword_width{ 50.0 };
    double monster_sword_height{ 10.0 };
    double monster_sword_bottom = monster_sword_top + monster_sword_height;
    double monster_sword_right = monster_sword_left + monster_sword_width;

    bool direction = true;

    void draw_monster_and_HP()
    {
        if (monsterHP_width > 0.0)
        {
            push_settings();
            draw_rectangle(monster_left, monster_top, monster_width, monster_height);
            set_fill_color(255, 0, 0);
            draw_rectangle(monsterHP_left, monsterHP_top, monsterHP_width, monsterHP_height);
            pop_settings();

            monster_player_contact();
            draw_monster_HP_move();
            monster_attack_range();
;       }
        else 
        {
            stage1_key.DropItem_monster1();
        }
    }

    //The code where the monster moves left and right.
    void draw_monster_HP_move(void)
    {
        update();

        if (direction == true)
        {
            monster_sword_left += 0.3;
            monster_left += 0.3;
            monsterHP_left +=0.3;
            if (monster_left > 400 && monsterHP_left > 400)
            {
                direction = false;
            }
        }
        else
        {
            monster_sword_left -= 0.3;
            monster_left -= 0.3;
            monsterHP_left -=0.3;
            if (monster_left <200 && monsterHP_left<200)
            {
                direction = true;
            }
        }
    }

    void monster_attack_range(void)
    {
        //moster sword
        update();
        if (monster_left - 100 < player.player_left && player.player_left < monster_left + 100
            && player.player_top <= monster_top)
        {
            draw_rectangle(monster_sword_left, monster_sword_top, monster_sword_width, monster_sword_height);
        }

        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

        if (Over(player.player_left, player.player_right, monster_sword_left, monster_sword_right)
            && Over(player.player_top, player.player_bottom, monster_sword_top, monster_sword_bottom))
        {
            player.playerHP_width -= 0.8;
        }

        //warm
        if (monster_left - 200 < player.player_left && player.player_left < monster_left + 200
            && player.player_top <= monster_top)
        {
            push_settings();
            no_outline();
            set_fill_color(HexColor{ 0xFFD56E });
            draw_ellipse(monster_left - 60, -250, 9);
            draw_rectangle(monster_left - 64, -240, 8, 50);
            pop_settings();
        }        
    }

    void monster_player_contact(void)
    {
        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };
        if (Over(player.player_left, player.player_right, monster_left, monster_right)
            && Over(player.player_top, player.player_bottom, monster_top, monster_bottom))
        {
            player.player_left = monster_left - 50;
        }

    }

    void update(void)
    {
        monster_bottom = monster_top + monster_height;
        monster_right = monster_left + monster_width;

        monsterHP_bottom = monsterHP_top + monsterHP_height;
        monsterHP_right = monsterHP_left + monsterHP_width;

        monster_sword_bottom = monster_sword_top + monster_sword_height;
        monster_sword_right = monster_sword_left + monster_sword_width;
    }
};
Monster monster;
