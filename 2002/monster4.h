#pragma once

#include <doodle/doodle.hpp>
#include "player.h"
#include "sword.h"

using namespace doodle;

class MONSTER4
{
public:
    double monster4_left{ 380.0 };
    double monster4_top{ 98.0 };
    double monster4_width{ 50.0 };
    double monster4_height{ 50.0 };

    double monster4HP_left{ 375.0 };
    double monster4HP_top{ 154.0 };
    double monster4HP_width{ 60.0 }; //60
    double monster4HP_height{ 10.0 };

    double warm4_left = { 150.0 };
    double warm4_top = { -60 };
    double warm4_width = { 460.0 };
    double warm4_height = { 230.0 };

    double m4_sword_left = { 320.0 };
    double m4_sword_top = { 118.0 };
    double m4_sword_width = { 60.0 };
    double m4_sword_height = { 10.0 };

    double m4_swordHP_left = { 0.0 };
    double m4_swordHP_top = { 0.0 };
    double m4_swordHP_width = { 100.0 };
    double m4_swordHP_height = { 10.0 };

    const  Image image_monster_right4{ "asset/bossvirus.png" };
    const  Image image_monster_left4{ "asset/bossvirus2.png" };
    const  Image image_monsterSword_right4{ "asset/knife.png" };
    const  Image image_monsterSword_left4{ "asset/knife2.png" };

    bool speed4 = true;

    void draw_monster4()
    {
        if (monster4HP_width > 0.5)
        {
            contact_player_monster4_swordVSsword();
            monster4_move();
            contact_player_m4sword();

            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(monster4_left, monster4_top, monster4_width, monster4_height);
            pop_settings();

            push_settings();
            set_fill_color(255, 0, 0);
            draw_rectangle(monster4HP_left, monster4HP_top, monster4HP_width, monster4HP_height);
            pop_settings();

            //warm
            push_settings();
            no_outline();
            no_fill();
            draw_rectangle(warm4_left, warm4_top, warm4_width, warm4_height);
            pop_settings();
            if (player.player_left < warm4_left + warm4_width && player.player_left + 40.0 > warm4_left
                && player.player_top < warm4_top + warm4_height && player.player_top + 40.0 > warm4_top)
            {
                push_settings();
                no_outline();
                set_fill_color(HexColor{ 0xFFD56E });
                draw_ellipse(monster4_left - 20.0, monster4_top + 50.0, 9);
                draw_rectangle(monster4_left - 24.0, monster4_top + 60.0, 8, 50);
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

    void monster4_move(void)
    {
        if (speed4 == true)
        {
            draw_image(image_monster_left4, monster4_left, monster4_top, monster4_width, monster4_height);
            m4_sword_left -= 0.25;
            monster4_left -= 0.25;
            monster4HP_left -= 0.25;
            if (monster4_left < 330.0 && monster4HP_left < 335.0)
            {
                speed4 = false;
            }
        }
        else
        {
            draw_image(image_monster_right4, monster4_left, monster4_top, monster4_width, monster4_height);
            m4_sword_left += 0.25;
            monster4_left += 0.25;
            monster4HP_left += 0.25;
            if (monster4_left > 440.0 && monster4HP_left > 445.0)
            {
                speed4 = true;
            }
        }
    }

    void contact_player_m4sword(void)
    {
        if (m4_swordHP_width > 0.0)
        {
            if (player.player_left + 40.0 > m4_sword_left && player.player_left < m4_sword_left + 60.0
                && m4_sword_top < player.player_top + 40.0 && m4_sword_top + 10.0 > player.player_top)
            {
                push_settings();
                set_fill_color(155, 30, 30);
                draw_rectangle(-570, -359, 1190, 600);
                pop_settings();

                player.player_left -= 3;
                player.armorHP_width -= 1.0;
                if (player.armorHP_width < 0.0)
                {
                    player.playerHP_width -= 2.0;
                }
                draw_Lm4sword();
            }

            if (player.player_left < m4_sword_left + 170.0 && player.player_left > m4_sword_left + 110.0
                && m4_sword_top < player.player_top + 40.0 && m4_sword_top + 10.0 > player.player_top)
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
                draw_Rm4sword();
            }
        }
    }

    void contact_player_monster4_swordVSsword(void)
    {
        if (player.player_left + 40.0 >= monster4_left && player.player_left + 40.0 <= monster4_left + 40.0
            && player.player_top + 40.0 <= monster4_top + 40.0 && player.player_top + 40.0 >= monster4_top)
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
        if (player.player_left > monster4_left && player.player_left <= monster4_left + 40.0
            && player.player_top + 40.0 <= monster4_top + 40.0 && player.player_top + 40.0 >= monster4_top)
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
                if (player.player_left + 50.0 > monster4_left && player.player_left + 50.0 < monster4_left + 50.0
                    && player.player_top + 10.0 > monster4_top && player.player_top < monster4_top + 50.0)
                {
                    monster4HP_width -= 1.0;
                }

                //When the monster and the player's sword come into contact
                if (m4_swordHP_width > 0.0)
                {
                    if (player.player_left + 50.0 > m4_sword_left && player.player_left + 60.0 < m4_sword_left + 60.0
                        && player.player_top + 10.0 > monster4_top && player.player_top < monster4_top + 50.0)
                    {
                        push_settings();
                        no_fill();
                        no_outline();
                        draw_rectangle(m4_sword_left, m4_sword_top, m4_sword_width, m4_sword_height);
                        pop_settings();

                        draw_image(image_monsterSword_left4, m4_sword_left, m4_sword_top, m4_sword_width, m4_sword_height);

                        player.player_left -= 3.0;
                        m4_swordHP_width -= 1.0;
                    }
                }
            }
        }
        if (CheckKeyPressed[1])
        {
            if (CheckKeyPressed[2])
            {
                //When the player's sword touches the monster,
                if (player.player_left - 50.0 < monster4_left + 50.0 && player.player_left - 50.0 > monster4_left
                    && player.player_top + 10.0 > monster4_top && player.player_top < monster4_top + 50.0)
                {
                    monster4HP_width -= 1.0;
                }

                //When the monster and the player's sword come into contact
                if (m4_swordHP_width > 0.0)
                {
                    if (player.player_left - 50.0 > m4_sword_left + 110.0 && player.player_left - 50.0 < m4_sword_left + 150.0
                        && player.player_top + 10.0 > monster4_top && player.player_top < monster4_top + 50.0)
                    {
                        push_settings();
                        no_fill();
                        no_outline();
                        draw_rectangle(m4_sword_left + 110.0, m4_sword_top, m4_sword_width, m4_sword_height);
                        pop_settings();

                        draw_image(image_monsterSword_right4, m4_sword_left + 110.0, m4_sword_top, m4_sword_width, m4_sword_height);
                        player.player_left += 3.0;
                        m4_swordHP_width -= 1.0;
                    }
                }
            }
        }
        push_settings();
        no_outline();
        set_fill_color(70, 50, 225);
        draw_rectangle(monster4_left - 25.0, monster4_top + 70.0, m4_swordHP_width, m4_swordHP_height);
        pop_settings();
    }

    void draw_Lm4sword(void)
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(m4_sword_left, m4_sword_top, m4_sword_width, m4_sword_height);
        pop_settings();
        draw_image(image_monsterSword_left4, m4_sword_left, m4_sword_top, m4_sword_width, m4_sword_height);
    }

    void draw_Rm4sword(void)
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(m4_sword_left + 110.0, m4_sword_top, m4_sword_width, m4_sword_height);
        pop_settings();
        draw_image(image_monsterSword_right4, m4_sword_left + 110.0, m4_sword_top, m4_sword_width, m4_sword_height);
    }
};
MONSTER4 stage2_monster4;