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

    const  Image image_monster3_right{ "asset/wizard.png" };
    const  Image image_monster3_left{ "asset/wizard2.png" };
    const  Image image_monster3_attack{ "asset/lightning.png" };
    const  Image CANE { "asset/cane2.png" };

    bool direction3 = true;
    bool defense_move = true;

    void draw_monster_HP_3()
    {
        if (monsterHP_width3 > 0.0)
        {
            monster_HP_move_3();
            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(monster_left3, monster_top3, monster_width3, monster_height3);
            pop_settings();

            push_settings();
            set_fill_color(255, 0, 0);
            no_outline();
            draw_rectangle(monsterHP_left3, monsterHP_top3, monsterHP_width3, monsterHP_height3);
            pop_settings();
            if (player.player_left + 40.0 > monster_left3 && player.player_left + 40.0 < monster_left3 + 50.0
                && player.player_top + 40.0 < monster_top3 + 50.0 && player.player_top + 40.0 > monster_top3)
            {
                player.player_left -= 3.0;
                player.playerHP_width -= 2.0;
            }
            if (CheckKeyPressed[0])
            {
                if (CheckKeyPressed[2])
                {
                    if (player.player_left + 80.0 > monster_left3 && player.player_left + 80.0 < monster_left3 + 50.0
                        && player.player_top + 40.0 < monster_top3 + 50.0 && player.player_top + 40.0 > monster_top3)
                    {
                        monsterHP_width3 -= 0.5;
                    }
                }
            }
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
            draw_image(image_monster3_right, monster_left3, monster_top3, monster_width3, monster_height3);
            draw_image(CANE, monster_left3 + 45.0, monster_top3, 20, 60);
            monster_left3 += 0.4;
            monsterHP_left3 += 0.4;
            if (monster_left3 > 400.0 && monsterHP_left3 > 400.0)
            {
                direction3 = false;
            }
        }
        else
        {
            monster_left3 -= 0.4;
            monsterHP_left3 -= 0.4;
            draw_image(image_monster3_left, monster_left3, monster_top3, monster_width3, monster_height3);
            draw_image(CANE, monster_left3-15.0, monster_top3, 20, 60);
            if (monster_left3 < 250.0 && monsterHP_left3 < 250.0)
            {
                direction3 = true;
            }
        }
    }

    void defense_wall(void)
    {
        if (Leftdefense_wall_left3 < player.player_left && Rightdefense_wall_left3 > player.player_left && player.player_top > 140.0)
        {
            //draw_right_defense_contact
            if (Rightdefense_wall_height3 > 30.0)
            {
                Rightdefense_wall_bottom3 = Rightdefense_wall_top3 + Rightdefense_wall_height3;
                Rightdefense_wall_right3 = Rightdefense_wall_left3 + Rightdefense_wall_width3;
                if (CheckKeyPressed[0])
                {
                    if (CheckKeyPressed[2])
                    {
                        if (player.player_left + 40.0 < Rightdefense_wall_left3 && player.player_left + 80.0 > Rightdefense_wall_width3 + 20.0
                            && player.player_top <= Rightdefense_wall_top3)
                        {
                            Rightdefense_wall_height3 -= 5.0;
                        }
                    }
                }

                auto Over = [](double aMin, double aMax, double bMin, double bMax)
                {
                    return aMax >= bMin and bMax >= aMin;
                };
                if (Over(Rightdefense_wall_left3, Rightdefense_wall_right3, player.player_left, player.player_right)
                    && Over(Rightdefense_wall_top3, Rightdefense_wall_bottom3, player.player_top, player.player_bottom))
                {
                    player.player_left -= 2.0;
                    player.playerHP_width -= 1.0;
                }

                while (player.playerHP_width > 150.0)
                {
                    Rightdefense_wall_height3 += 0.1;

                    if (Rightdefense_wall_height3 > 150.0)
                        break;
                }

                right_defense_move();

                push_settings();
                no_fill();
                no_outline();
                draw_rectangle(Rightdefense_wall_left3, Rightdefense_wall_top3, Rightdefense_wall_width3, Rightdefense_wall_height3);
                pop_settings();

                draw_image(image_monster3_attack, Rightdefense_wall_left3, Rightdefense_wall_top3, Rightdefense_wall_width3, Rightdefense_wall_height3);
            }

            //draw_left_defense_contact
            if (Leftdefense_wall_height3 > 30.0)
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
                    player.player_left += 2.0;
                    player.playerHP_width -= 1.0;
                }

                left_defense_move();

                push_settings();
                no_fill();
                no_outline();
                draw_rectangle(Leftdefense_wall_left3, Leftdefense_wall_top3, Leftdefense_wall_width3, Leftdefense_wall_height3);
                pop_settings();

                draw_image(image_monster3_attack, Leftdefense_wall_left3, Leftdefense_wall_top3, Leftdefense_wall_width3, Leftdefense_wall_height3);
            }
        }
    }

    void right_defense_move(void)
    {
        if (defense_move == true)
        {
            Rightdefense_wall_left3 -= 0.1;
            if (Rightdefense_wall_left3 < -300.0)
            {
                defense_move = false;
            }
        }
        else
        {
            Rightdefense_wall_left3 += 0.1;
            if (Rightdefense_wall_left3 > 200.0)
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
            if (Leftdefense_wall_left3 < -400.0)
            {
                defense_move = false;
            }
        }
        else
        {
            Leftdefense_wall_left3 += 0.1;
            if (Leftdefense_wall_left3 > 100.0)
            {
                defense_move = true;
            }
        }
    }
};
Monster3 monster3;