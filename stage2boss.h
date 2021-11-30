#pragma once

#include <doodle/doodle.hpp>
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "monster4.h"
#include "player.h"
#include "stage2_mini_boss.h"

using namespace doodle;

class STAGE2_BOSS
{
public:
    double boss_left{ -10.0 };
    double boss_top{ -95.0 };
    double boss_width{ 60.0 };
    double boss_height{ 60.0 };
    double boss_bottom = boss_top + boss_height;
    double boss_right = boss_left + boss_width;

    double bossHP_left{ -370.0 };
    double bossHP_top{ 150.0 };
    double bossHP_width{ 800.0 }; //800
    double bossHP_height{ 30.0 };

    double bossFly_left{ -470.0 };
    double bossFly_top{ 100.0 };
    double bossFly_width{ 1000.0 };
    double bossFly_height{ 30.0 };

    bool bossmove = true;


    void draw_boss()
    {
        if (bossHP_width > 1.0)
        {
            boss_top -= 3;
            if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width < 1.0)
            {
                contact_playersword();
                contact_player();
                boss_HP();
                boss_move();
                bossHP_skill();
            }
            contact_floor();
            draw_rectangle(boss_left, boss_top, boss_width, boss_height);
        }
    }

    void boss_HP(void)
    {
        draw_rectangle(bossHP_left, bossHP_top, bossHP_width, bossHP_height);
        
        push_settings();
        no_outline();
        set_font_size(25);
        draw_text("BOSS HP", -30, 175);
        set_fill_color(HexColor{ 0xA0F1FF });
        pop_settings();
    }

    void boss_move(void)
    {
        if (!(bossHP_width < 620.0 && bossHP_width > 570.0 || bossHP_width < 430.0 && bossHP_width > 380.0 || bossHP_width < 220.0 && bossHP_width > 170.0))
        {
            if (bossmove == true)
            {
                boss_left -= 0.5;
                if (boss_left < -170.0)
                {
                    bossmove = false;
                }
            }
            else
            {
                boss_left += 0.5;
                if (boss_left > 140.0)
                {
                    bossmove = true;
                }
            }
        }
    }

    void bossHP_skill(void)
    {
        //570 ~ 620
        draw_line(250, 180, 250, 150);
        draw_line(200, 180, 200, 150);
        //380~410
        draw_line(10, 180, 10, 150);
        draw_line(60, 180, 60, 150);
        //170~220
        draw_line(-150, 180, -150, 150);
        draw_line(-200, 180, -200, 150);

        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(bossFly_left, bossFly_top, bossFly_width, bossFly_height);
        pop_settings();

        if (bossHP_width < 620.0 && bossHP_width > 570.0)
        {
            if (mini_boss.MbossHP_width + mini_boss.MbossHP_width2 + mini_boss.MbossHP_width3 < 3.0)
            {
                bossHP_width = 569.0;
            }
            boss_top += 6.0;
            mini_boss.draw_Mboss();
        }

        if (bossHP_width < 430.0 && bossHP_width > 380.0)
        {
            bossHP_width -= 0.05;
            boss_top += 6.0;
        }

        if (bossHP_width < 220.0 && bossHP_width > 170.0)
        {
            bossHP_width -= 0.05;
            boss_top += 6.0;
        }

        if (boss_top + 60.0 < bossFly_top + 30 && boss_top + 60.0 > bossFly_top
            && boss_left < bossFly_left + 1000.0 && boss_left + 60.0 > bossFly_left)
        {
            boss_top -= 3.0;
        }
    }

    void boss_skill()
    {
    }

    void contact_player(void)
    {
        if (player.player_left < boss_left + 60.0 && player.player_left > boss_left
            && player.player_top + 40.0 > boss_top && player.player_top < boss_top + 60.0)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();
            player.player_left += 3.0;
            player.armorHP_width -= 3.0;
            if (player.armorHP_width < 0.0)
            {
                player.playerHP_width -= 3.0;
            }
        }
        if (player.player_left + 40 > boss_left && player.player_left + 40.0 < boss_left + 60.0
            && player.player_top + 40.0 > boss_top && player.player_top < boss_top + 60.0)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();
            player.player_left -= 3.0;
            player.armorHP_width -= 3.0;
            if (player.armorHP_width < 0.0)
            {
                player.playerHP_width -= 3.0;
            }
        }
    }

    void contact_playersword(void)
    {
        if (CheckKeyPressed[0])
        {
            if (CheckKeyPressed[2])
            {
                //When the player's sword touches the monster
                if (player.player_left + 100.0 > boss_left && player.player_left + 100.0 < boss_left + 60.0
                    && player.player_top + 10.0 > boss_top && player.player_top < boss_top + 60.0)
                {
                    bossHP_width -= 1.3; //0.3
                }
            }
        }
        if (CheckKeyPressed[1])
        {
            if (CheckKeyPressed[2])
            {
                //When the player's sword touches the monster,
                if (player.player_left - 50.0 < boss_left + 60.0 && player.player_left - 50.0 > boss_left
                    && player.player_top + 10.0 > boss_top && player.player_top < boss_top + 60.0)
                {
                    bossHP_width -= 1.3; //0.3
                }
            }
        }
    }

    void contact_floor(void)
    {
        if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width > 1.0)
        {
            if (boss_left + 50 > walls.Dprison_left && boss_left < walls.Dprison_right
                && boss_top > walls.Dprison_top && boss_top < walls.Dprison_bottom)
            {
                boss_top += 3;
            }
        }
        
        if (boss_left + 50 > walls.floor1_left && boss_left < walls.floor1_right
            && boss_top > walls.floor1_top && boss_top < walls.floor1_bottom)
        {
            boss_top += 3;
        }
    }
};
STAGE2_BOSS stage2_boss;