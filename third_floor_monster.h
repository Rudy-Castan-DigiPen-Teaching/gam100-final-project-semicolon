#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
using namespace doodle;

class Monster3
{
public:
    int a = 1;
    double monster_left3{ 300.0 };
    double monster_top3{ 150.0 };
    double monster_width3{ 50.0 };
    double monster_height3{ 50.0 };
    double monster_bottom3 = monster_top3 + monster_height3;
    double monster_right3 = monster_left3 + monster_width3;

    double monsterHP_left3{ 275.0 };
    double monsterHP_top3{ 210.0 };
    double monsterHP_width3{ 100.0 };
    double monsterHP_height3{ 10.0 };
    double monsterHP_bottom3 = monsterHP_top3 + monsterHP_height3;
    double monsterHP_right3 = monsterHP_left3 + monsterHP_width3;

    double Rightdefense_wall_left3{ 180.0 };
    double Rightdefense_wall_top3{ 150.0 };
    double Rightdefense_wall_width3{ 20.0 };
    double Rightdefense_wall_height3{ 90.0 };
    double Rightdefense_wall_bottom3 = Rightdefense_wall_top3 + Rightdefense_wall_height3;
    double Rightdefense_wall_right3 = Rightdefense_wall_left3 + Rightdefense_wall_width3;

    double Leftdefense_wall_left3{ 0.0 };
    double Leftdefense_wall_top3{ 150.0 };
    double Leftdefense_wall_width3{ 20.0 };
    double Leftdefense_wall_height3{ 90.0 };
    double Leftdefense_wall_bottom3 = Leftdefense_wall_top3 + Leftdefense_wall_height3;
    double Leftdefense_wall_right3 = Leftdefense_wall_left3 + Leftdefense_wall_width3;

    bool direction3 = true;
    bool defense_move = true;

    void draw_monster_HP_3()
    {
        if (monsterHP_width3 > 0.0)
        {
            monster_HP_move_3();
            draw_rectangle(monster_left3, monster_top3, monster_width3, monster_height3);
            draw_rectangle(monsterHP_left3, monsterHP_top3, monsterHP_width3, monsterHP_height3);
        }

        defense_wall();
    }

    
    void monster_HP_move_3(void)
    {
        monster_bottom3 = monster_top3 + monster_height3;
        monster_right3 = monster_left3 + monster_width3;

        monsterHP_bottom3 = monsterHP_top3 + monsterHP_height3;
        monsterHP_right3 = monsterHP_left3 + monsterHP_width3;

        if (direction3 == true)
        {
            monster_left3 += 0.4;
            monsterHP_left3 += 0.4;
            if (monster_left3 > 400 && monsterHP_left3 > 400)
            {
                direction3 = false;
            }
        }
        else
        {
            monster_left3 -= 0.4;
            monsterHP_left3 -= 0.4;
            if (monster_left3 < 250 && monsterHP_left3 < 250)
            {
                direction3 = true;
            }
        }
    }

    void defense_wall(void)
    {
        if (Leftdefense_wall_left3 < player.player_left && Rightdefense_wall_left3 > player.player_left && player.player_top > 140)
        {
            //draw_right_defense_contact
            if (Rightdefense_wall_height3 > 30)
            {
                Rightdefense_wall_bottom3 = Rightdefense_wall_top3 + Rightdefense_wall_height3;
                Rightdefense_wall_right3 = Rightdefense_wall_left3 + Rightdefense_wall_width3;

                auto Over = [](double aMin, double aMax, double bMin, double bMax)
                {
                    return aMax >= bMin and bMax >= aMin;
                };
                if (Over(Rightdefense_wall_left3, Rightdefense_wall_right3, player.player_left, player.player_right)
                    && Over(Rightdefense_wall_top3, Rightdefense_wall_bottom3, player.player_top, player.player_bottom))
                {
                    player.player_left -= 2;
                    player.playerHP_width -= 1;
                }

                while (player.playerHP_width > 150.0)
                {
                    Rightdefense_wall_height3 += 0.1;

                    if (Rightdefense_wall_height3 > 150.0)
                        break;
                }

                right_defense_move();

                draw_rectangle(Rightdefense_wall_left3, Rightdefense_wall_top3, Rightdefense_wall_width3, Rightdefense_wall_height3);
            }

            //draw_left_defense_contact
            if (Leftdefense_wall_height3 > 30)
            {
                Leftdefense_wall_bottom3 = Leftdefense_wall_top3 + Leftdefense_wall_height3;
                Leftdefense_wall_right3 = Leftdefense_wall_left3 + Leftdefense_wall_width3;


                auto Over = [](double aMin, double aMax, double bMin, double bMax)
                {
                    return aMax >= bMin and bMax >= aMin;
                };

                if (Over(Leftdefense_wall_left3, Leftdefense_wall_right3, player.player_left, player.player_right)
                    && Over(Leftdefense_wall_top3, Leftdefense_wall_bottom3, player.player_top, player.player_bottom))
                {
                    player.player_left += 2;
                    player.playerHP_width -= 1;
                }

                left_defense_move();

                draw_rectangle(Leftdefense_wall_left3, Leftdefense_wall_top3, Leftdefense_wall_width3, Leftdefense_wall_height3);
            }
        }
    }

    void right_defense_move(void)
    {
        if (defense_move == true)
        {
            Rightdefense_wall_left3 -= 0.1;
            if (Rightdefense_wall_left3 < -300)
            {
                defense_move = false;
            }
        }
        else
        {
            Rightdefense_wall_left3 += 0.1;
            if (Rightdefense_wall_left3 > 200)
            {
                defense_move = true;
            }
        }
    }

    void left_defense_move(void)
    {
        if (defense_move == true)
        {
            Leftdefense_wall_left3 -= 0.1;
            if (Leftdefense_wall_left3 < -400)
            {
                defense_move = false;
            }
        }
        else
        {
            Leftdefense_wall_left3 += 0.1;
            if (Leftdefense_wall_left3 > 100)
            {
                defense_move = true;
            }
        }
    }
};
Monster3 monster3;