// Filename : <monster2.h>
// Authors : <Hyunjun Lee, Dawoon Jung>
// Course : GAM100F21
// All content © 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "sword.h"

using namespace doodle;

class MONSTER2
{
public:
    double monster2_left{ -460.0 }; //-460 ~ -355 
    double monster2_top{ -202.0 };
    double monster2_width{ 50.0 };
    double monster2_height{ 50.0 };

    double monster2HP_left{ -465.0 }; //-465 ~ -360
    double monster2HP_top{ -145.0 };
    double monster2HP_width{ 60.0 }; //60
    double monster2HP_height{ 10.0 };

    double warm2_left = { -560.0 };
    double warm2_top = { -350 };
    double warm2_width = { 400.0 };
    double warm2_height = { 350.0 };

    double m2_sword_left = { -520.0 };
    double m2_sword_top = { -182.0 };
    double m2_sword_width = { 60.0 };
    double m2_sword_height = { 10.0 };

    double m2_swordHP_left = { 375.0 };
    double m2_swordHP_top = { -460.0 };
    double m2_swordHP_width = { 100.0 };
    double m2_swordHP_height = { 10.0 };

    const  Image image_monster_right2{ "asset/bossvirus.png" };
    const  Image image_monster_left2{ "asset/bossvirus2.png" };
    const  Image image_monsterSword_right2{ "asset/knife.png" };
    const  Image image_monsterSword_left2{ "asset/knife2.png" };

    bool speed2 = true;

    void draw_monster2()
    {
        if (monster2HP_width > 0.5)
        {
            contact_player_monster2_swordVSsword();
            contact_player_m2sword();
            monster2_move();

            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(monster2_left, monster2_top, monster2_width, monster2_height);
            pop_settings();

            push_settings();
            no_outline();
            set_fill_color(255, 0, 0);
            draw_rectangle(monster2HP_left, monster2HP_top, monster2HP_width, monster2HP_height);
            pop_settings();

            //warm
            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(warm2_left, warm2_top, warm2_width, warm2_height);
            pop_settings();
            if (player.player_left < warm2_left + warm2_width && player.player_left + 40.0 > warm2_left
                && player.player_top < warm2_top + warm2_height && player.player_top + 40.0 > warm2_top)
            {
                push_settings();
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.05;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.03;
                    }
                }
                no_outline();
                set_fill_color(HexColor{ 0xFFD56E });
                draw_ellipse(monster2_left - 20, monster2_top + 50, 9);
                draw_rectangle(monster2_left - 24, monster2_top + 60, 8, 50);
                pop_settings();
            }
        }
    }

    void monster2_move(void)
    {
        if (speed2 == true)
        {
            draw_image(image_monster_left2, monster2_left, monster2_top, monster2_width, monster2_height);
            if (m2_swordHP_width > 0.0)
            {
                draw_image(image_monsterSword_left2, m2_sword_left + 5.0, m2_sword_top - 5.0, m2_sword_width, m2_sword_height);
            }
            m2_sword_left -= 0.4;
            monster2_left -= 0.4;
            monster2HP_left -= 0.4;
            if (monster2_left < -460.0 && monster2HP_left < -465.0)
            {
                speed2 = false;
            }
        }
        else
        {
                draw_image(image_monster_right2, monster2_left, monster2_top, monster2_width, monster2_height);
                if (m2_swordHP_width > 0.0)
                {
                    draw_image(image_monsterSword_right2, m2_sword_left + 105.0, m2_sword_top - 5.0, m2_sword_width, m2_sword_height);
                }
            m2_sword_left += 0.4;
            monster2_left += 0.4;
            monster2HP_left += 0.4;
            if (monster2_left > -355.0 && monster2HP_left > -360.0)
            {
                speed2 = true;
            }
        }
    }

    void contact_player_m2sword(void)
    {
        if (m2_swordHP_width > 0.0)
        {
            if (player.player_left + 40.0 > m2_sword_left && player.player_left < m2_sword_left + 60.0
                && m2_sword_top < player.player_top + 40.0 && m2_sword_top + 10.0 > player.player_top)
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
                draw_Lm2sword();
                draw_image(image_monsterSword_left2, m2_sword_left, m2_sword_top, m2_sword_width, m2_sword_height);
                draw_image(image_monster_left2, monster2_left, monster2_top, monster2_width, monster2_height);
            }

            if (player.player_left < m2_sword_left + 170.0 && player.player_left > m2_sword_left + 110.0
                && m2_sword_top < player.player_top + 40.0 && m2_sword_top + 10.0 > player.player_top)
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
                draw_Rm2sword();
                draw_image(image_monsterSword_right2, m2_sword_left+110.0, m2_sword_top, m2_sword_width, m2_sword_height);
            }
        }
    }

    void draw_Lm2sword(void)
    {
        push_settings();
        no_outline();
        no_fill();
        draw_rectangle(m2_sword_left, m2_sword_top, m2_sword_width, m2_sword_height);
        pop_settings();
    }

    void draw_Rm2sword(void)
    {
        push_settings();
        no_outline();
        no_fill();
        draw_rectangle(m2_sword_left + 110.0, m2_sword_top, m2_sword_width, m2_sword_height);
        pop_settings();
    }

    void contact_player_monster2_swordVSsword(void)
    {
        if (player.player_left + 40.0 >= monster2_left && player.player_left + 40.0 <= monster2_left + 40.0
            && player.player_top + 40.0 <= monster2_top + 40.0 && player.player_top + 40.0 >= monster2_top)
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
        if (player.player_left > monster2_left && player.player_left <= monster2_left + 40.0
            && player.player_top + 40.0 <= monster2_top + 40.0 && player.player_top + 40.0 >= monster2_top)
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
                if (player.player_left + 90.0 > monster2_left && player.player_left + 90.0 < monster2_left + 50.0
                    && player.player_top + 10.0 > monster2_top && player.player_top < monster2_top + 50.0)
                {
                    monster2HP_width -= 1.0;
                }

                //When the monster and the player's sword come into contact
                if (m2_swordHP_width > 0.0)
                {
                    if (player.player_left + 50.0 > m2_sword_left && player.player_left + 60.0 < m2_sword_left + 60.0
                        && player.player_top + 10.0 > monster2_top && player.player_top < monster2_top + 50.0)
                    {
                        push_settings();
                        no_fill();
                        no_outline();
                        draw_rectangle(m2_sword_left, m2_sword_top, m2_sword_width, m2_sword_height);
                        pop_settings();
                        draw_image(image_monsterSword_left2, m2_sword_left, m2_sword_top, m2_sword_width, m2_sword_height);
                        player.player_left -= 3.0;
                        m2_swordHP_width -= 1.0;
                    }
                }
            }
        }
        if (CheckKeyPressed[1])
        {
            if (CheckKeyPressed[2])
            {
                //When the player's sword touches the monster,
                if (player.player_left - 50.0 < monster2_left + 50.0 && player.player_left - 50.0 > monster2_left
                    && player.player_top + 10.0 > monster2_top && player.player_top < monster2_top + 50.0)
                {
                    monster2HP_width -= 1.0;
                }

                //When the monster and the player's sword come into contact
                if (m2_swordHP_width > 0.0)
                {
                    if (player.player_left - 50.0 > m2_sword_left + 110.0 && player.player_left - 50.0 < m2_sword_left + 150.0
                        && player.player_top + 10.0 > monster2_top && player.player_top < monster2_top + 50.0)
                    {
                        push_settings();
                        no_fill();
                        no_outline();
                        draw_rectangle(m2_sword_left + 110.0, m2_sword_top, m2_sword_width, m2_sword_height);
                        pop_settings();

                        draw_image(image_monsterSword_right2, m2_sword_left + 110.0, m2_sword_top, m2_sword_width, m2_sword_height);
                        player.player_left += 3.0;
                        m2_swordHP_width -= 1.0;
                    }
                }
            }
        }
        push_settings();
        no_outline();
        set_fill_color(70, 50, 225);
        draw_rectangle(monster2_left - 25.0, monster2_top + 70.0, m2_swordHP_width, m2_swordHP_height);
        pop_settings();
    }
};
MONSTER2 stage2_monster2;