#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "sword.h"
#include "monster4.h"
using namespace doodle;

class MONSTER3
{
public:
    double monster3_left{ -400.0 };
    double monster3_top{ 98.0 };
    double monster3_width{ 50.0 };
    double monster3_height{ 50.0 };

    double monster3HP_left{ -405.0 };
    double monster3HP_top{ 154.0 };
    double monster3HP_width{ 60.0 }; //60
    double monster3HP_height{ 10.0 };

    double warm3_left = { -560.0 };
    double warm3_top = { -60 };
    double warm3_width = { 400.0 };
    double warm3_height = { 270.0 };

    double m3_sword_left = { -460.0 };
    double m3_sword_top = { 118.0 };
    double m3_sword_width = { 60.0 };
    double m3_sword_height = { 10.0 };

    double m3_swordHP_left = { 375.0 };
    double m3_swordHP_top = { -460.0 };
    double m3_swordHP_width = { 100.0 };
    double m3_swordHP_height = { 10.0 };

    const  Image image_monster_right3{ "asset/bossvirus.png" };
    const  Image image_monster_left3{ "asset/bossvirus2.png" };
    const  Image image_monsterSword_right3{ "asset/knife.png" };
    const  Image image_monsterSword_left3{ "asset/knife2.png" };

    bool speed3 = true;

    void draw_monster3()
    {
        if (monster3HP_width > 0.5)
        {
            contact_player_monster3_swordVSsword();
            contact_player_m3sword();
            monster3_move();
            
            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(monster3_left, monster3_top, monster3_width, monster3_height);
            pop_settings();

            push_settings();
            set_fill_color(255,0,0);
            draw_rectangle(monster3HP_left, monster3HP_top, monster3HP_width, monster3HP_height);
            pop_settings();

            //warm
            push_settings();
            no_outline();
            no_fill();
            draw_rectangle(warm3_left, warm3_top, warm3_width, warm3_height);
            pop_settings();
            if (player.player_left < warm3_left + warm3_width && player.player_left + 40.0 > warm3_left
                && player.player_top < warm3_top + warm3_height && player.player_top + 40.0 > warm3_top)
            {
                push_settings();
                no_outline();
                set_fill_color(HexColor{ 0xFFD56E });
                draw_ellipse(monster3_left - 20.0, monster3_top + 50.0, 9);
                draw_rectangle(monster3_left - 24.0, monster3_top + 60.0, 8, 50);
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.05;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.03;
                    }
                }
                pop_settings();
            }
        }
    }

    void monster3_move(void)
    {
        if (speed3 == true)
        {
            draw_image(image_monster_left3, monster3_left, monster3_top, monster3_width, monster3_height);
            m3_sword_left -= 0.5;
            monster3_left -= 0.5;
            monster3HP_left -= 0.5;
            if (monster3_left < -460.0 && monster3HP_left < -465.0)
            {
                speed3 = false;
            }
        }
        else
        {
            draw_image(image_monster_right3, monster3_left, monster3_top, monster3_width, monster3_height);
            m3_sword_left += 0.4;
            monster3_left += 0.4;
            monster3HP_left += 0.4;
            if (monster3_left > -355.0 && monster3HP_left > -360.0)
            {
                speed3 = true;
            }
        }
    }

    void contact_player_m3sword(void)
    {
        if (m3_swordHP_width > 0.0)
        {
            if (player.player_left + 40.0 > m3_sword_left && player.player_left < m3_sword_left + 60.0
                && m3_sword_top < player.player_top + 40.0 && m3_sword_top + 10.0 > player.player_top)
            {
                push_settings();
                set_fill_color(155, 30, 30);
                draw_rectangle(-570, -359, 1190, 600);
                pop_settings();

                player.player_left -= 3.0;
                player.armorHP_width -= 1.0;
                if (player.armorHP_width < 0.0)
                {
                    player.playerHP_width -= 2.0;
                }
                draw_Lm3sword();
            }

            if (player.player_left < m3_sword_left + 170.0 && player.player_left > m3_sword_left + 110.0
                && m3_sword_top < player.player_top + 40.0 && m3_sword_top + 10.0 > player.player_top)
            {
                push_settings();
                set_fill_color(155, 30, 30);
                draw_rectangle(-570, -359, 1190, 600);
                pop_settings();

                player.player_left += 3.0;
                player.armorHP_width -= 1.0;
                if (player.armorHP_width < 0.0)
                {
                    player.playerHP_width -= 2.0;
                }
                draw_Rm3sword();
            }
        }
    }

    void contact_player_monster3_swordVSsword(void)
    {
        if (player.player_left + 40.0 >= monster3_left && player.player_left + 40.0 <= monster3_left + 40.0
            && player.player_top + 40.0 <= monster3_top + 40.0 && player.player_top + 40.0 >= monster3_top)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();

            player.player_left -= 3.0;
            player.armorHP_width -= 1.0;
            if (player.armorHP_width < 0.0)
            {
                player.playerHP_width -= 2.0;
            }
        }
        if (player.player_left > monster3_left && player.player_left <= monster3_left + 40.0
            && player.player_top + 40.0 <= monster3_top + 40.0 && player.player_top + 40.0 >= monster3_top)
        {
            push_settings();
            set_fill_color(155, 30, 30);
            draw_rectangle(-570, -359, 1190, 600);
            pop_settings();

            player.player_left += 3.0;
            player.armorHP_width -= 1.0;
            if (player.armorHP_width < 0.0)
            {
                player.playerHP_width -= 2.0;
            }
        }

        if (CheckKeyPressed[0])
        {
            if (CheckKeyPressed[2])
            {
                //When the player's sword touches the monster
                if (player.player_left + 50.0 > monster3_left && player.player_left + 50.0 < monster3_left + 50.0
                    && player.player_top + 10.0 > monster3_top && player.player_top < monster3_top + 50.0)
                {
                    monster3HP_width -= 1.0;
                }

                //When the monster and the player's sword come into contact
                if (m3_swordHP_width > 0.0)
                {
                    if (player.player_left + 50.0 > m3_sword_left && player.player_left + 60.0 < m3_sword_left + 60.0
                        && player.player_top + 10.0 > monster3_top && player.player_top < monster3_top + 50.0)
                    {
                        push_settings();
                        no_outline();
                        no_fill();
                        draw_rectangle(m3_sword_left, m3_sword_top, m3_sword_width, m3_sword_height);
                        pop_settings();
                        draw_image(image_monsterSword_left3, m3_sword_left, m3_sword_top, m3_sword_width, m3_sword_height);
                        player.player_left -= 3.0;
                        m3_swordHP_width -= 1.0;
                    }
                }
            }
        }
        if (CheckKeyPressed[1])
        {
            if (CheckKeyPressed[2])
            {
                //When the player's sword touches the monster,
                if (player.player_left - 50.0 < monster3_left + 50.0 && player.player_left - 50.0 > monster3_left
                    && player.player_top + 10.0 > monster3_top && player.player_top < monster3_top + 50.0)
                {
                    monster3HP_width -= 1.0;
                }

                //When the monster and the player's sword come into contact
                if (m3_swordHP_width > 0.0)
                {
                    if (player.player_left - 50.0 > m3_sword_left + 110.0 && player.player_left - 50.0 < m3_sword_left + 150.0
                        && player.player_top + 10.0 > monster3_top && player.player_top < monster3_top + 50.0)
                    {
                        push_settings();
                        no_outline();
                        no_fill();
                        draw_rectangle(m3_sword_left + 110.0, m3_sword_top, m3_sword_width, m3_sword_height);
                        pop_settings();

                        draw_image(image_monsterSword_right3, m3_sword_left+110.0, m3_sword_top, m3_sword_width, m3_sword_height);
                        player.player_left += 3.0;
                        m3_swordHP_width -= 1.0;
                    }
                }
            }
        }
        push_settings();
        no_outline();
        set_fill_color(70, 50, 225);
        draw_rectangle(monster3_left - 25.0, monster3_top + 70.0, m3_swordHP_width, m3_swordHP_height);
        pop_settings();
    }


    void draw_Lm3sword(void)
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(m3_sword_left, m3_sword_top, m3_sword_width, m3_sword_height);
        pop_settings();
        draw_image(image_monsterSword_left3, m3_sword_left, m3_sword_top, m3_sword_width, m3_sword_height);
    }

    void draw_Rm3sword(void)
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(m3_sword_left + 110.0, m3_sword_top, m3_sword_width, m3_sword_height);
        pop_settings();

        draw_image(image_monsterSword_right3, m3_sword_left + 110.0, m3_sword_top, m3_sword_width, m3_sword_height);
    }
};
MONSTER3 stage2_monster3;