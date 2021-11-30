#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "player_key.h"
#include "first_floor_monster.h"
#include "second_floor_monster.h"
#include "third_floor_monster.h"

using namespace doodle;

class Alcohol
{
public:
    double alcohol_left = player.player_left;
    double alcohol_top{ -300.0 };
    double alcohol_width{ 15.0 };
    double alcohol_height{ 15.0 };
    double alcohol_bottom = alcohol_top + alcohol_height;
    double alcohol_right = alcohol_left + alcohol_width;

    double alcohol_left2 = player.player_left;
    double alcohol_top2{ -300.0 };
    double alcohol_width2{ 15.0 };
    double alcohol_height2{ 15.0 };
    double alcohol_bottom2 = alcohol_top2 + alcohol_height2;
    double alcohol_right2 = alcohol_left2 + alcohol_width2;

        void alcohol_RightKey_K()
        {
            if (CheckKeyPressed[0])
            {
                if (CheckKeyPressed[3] && player.playerMP_width >=5.0)
                {
                    alcohol_left = player.player_left;   
                    player.playerMP_width -= 5.0;
                }
            }
        }
        void draw_alcohol_RightMove(void)
        {
            alcohol_left++;
            draw_rectangle(alcohol_left, player.player_top + 15.0, alcohol_width, alcohol_height);
        }

        void alcohol_LeftKey_K()
        {
            if (CheckKeyPressed[1])
            {
                if (CheckKeyPressed[3] && player.playerMP_width >= 5.0)
                {
                    alcohol_left2 = player.player_left;
                    player.playerMP_width -= 5.0;
                }
            }
        }
        void draw_alcohol_LeftMove(void)
        {
            alcohol_left2--;
            draw_rectangle(alcohol_left2, player.player_top + 15.0, alcohol_width2, alcohol_height2);
        }

    void monster_attach()
    {
        alcohol_bottom = alcohol_top + alcohol_height;
        alcohol_right = alcohol_left + alcohol_width;

        alcohol_bottom2 = alcohol_top2 + alcohol_height2;
        alcohol_right2 = alcohol_left2 + alcohol_width2;

        auto Over = [](double aMin, double aMax, double bMin, double bMax)
        {
            return aMax >= bMin and bMax >= aMin;
        };

                                        //first_floor_monster

        if (Over(alcohol_left, alcohol_right, monster.monster_left, monster.monster_right)
            && Over(alcohol_top, alcohol_bottom, monster.monster_top, monster.monster_bottom))
        {
            alcohol_left = player.player_left + 1000.0;
            alcohol_top = player.player_top;
            monster.monsterHP_width -= 40.0;
        }

                                        //second_floor_monster
        //right
        if (Over(alcohol_left, alcohol_right, monster2.monster_left2, monster2.monster_right2)
            && Over(alcohol_top, alcohol_bottom, monster2.monster_top2, monster2.monster_bottom2))
        {
            alcohol_left = player.player_left + 1000.0;
            alcohol_top = player.player_top;
            monster2.monsterHP_width2 -= 50.0;
        }

                                         //third_floor_monster
        //right
        if (Over(alcohol_left, alcohol_right, monster3.monster_left3, monster3.monster_right3)
            && Over(alcohol_top, alcohol_bottom, monster3.monster_top3, monster3.monster_bottom3))
        {
            alcohol_left = player.player_left + 1000.0;
            alcohol_top = player.player_top;
            monster3.monsterHP_width3 -= 20.0;
        }
        //left
        if (Over(alcohol_left2, alcohol_right2, monster3.monster_left3, monster3.monster_right3)
            && Over(alcohol_top2, alcohol_bottom2, monster3.monster_top3, monster3.monster_bottom3))
        {
            alcohol_left2 = player.player_left - 1000.0;
            alcohol_top2 = player.player_top;
            monster3.monsterHP_width3 -= 20.0;
        }

                                          //defense
        //right
        if (Over(alcohol_left, alcohol_right, monster3.Rightdefense_wall_left3, monster3.Rightdefense_wall_right3)
            && Over(alcohol_top, alcohol_bottom, monster3.Rightdefense_wall_top3, monster3.Rightdefense_wall_bottom3))
        {
            alcohol_left = player.player_left + 1000.0;
            alcohol_top = player.player_top;
            monster3.Rightdefense_wall_height3 -= 30;
        }
        //left
        if (Over(alcohol_left2, alcohol_right2, monster3.Leftdefense_wall_left3, monster3.Leftdefense_wall_right3)
            && Over(alcohol_top2, alcohol_bottom2, monster3.Leftdefense_wall_top3, monster3.Leftdefense_wall_bottom3))
        {
            alcohol_left = player.player_left + 1000.0;
            alcohol_top = player.player_top;
            monster3.Leftdefense_wall_height3 -= 30;
        }
    }
};
Alcohol alcohol;