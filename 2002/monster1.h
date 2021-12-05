#pragma once
#include <doodle/doodle.hpp>
#include "player.h"
#include "sword.h"
using namespace doodle;

class MONSTER1
{
public:
    double monster1_left{ 325.0 }; //move 330~460
    double monster1_top{ -202.0 };
    double monster1_width{ 50.0 };
    double monster1_height{ 50.0 };

    double monster1HP_left{ 320.0 };
    double monster1HP_top{ -145.0 };
    double monster1HP_width{ 60.0 }; //60
    double monster1HP_height{ 10.0 };

    double warm1_left = { 200.0 };
    double warm1_top = { -350 };
    double warm1_width = { 400.0 };
    double warm1_height = { 350.0 };

    double m1_sword_left = { 265.0 };
    double m1_sword_top = { -182.0 };
    double m1_sword_width = { 60.0 };
    double m1_sword_height = { 10.0 };

    double m1_swordHP_left = { 375.0 };
    double m1_swordHP_top = { -232.0 };
    double m1_swordHP_width = { 100.0 };
    double m1_swordHP_height = { 10.0 };

    const  Image image_monster_right1{ "asset/bossvirus.png" };
    const  Image image_monster_left1{ "asset/bossvirus2.png" };
    const  Image image_monsterSword_right1{ "asset/knife.png" };
    const  Image image_monsterSword_left1{ "asset/knife2.png" };


    bool speed1 = true;

    void draw_monster1()
    {
        if (monster1HP_width > 0.5)
        {
            //rain_contact1();
            contact_player_m1Lsword();
            contact_player_monster1_swordVSsword();

            push_settings();
            no_outline();
            no_fill();
;            draw_rectangle(monster1_left, monster1_top, monster1_width, monster1_height);
            pop_settings();

            monster1_move();

            push_settings();
            set_fill_color(255, 0, 0);
            no_outline();
            draw_rectangle(monster1HP_left, monster1HP_top, monster1HP_width, monster1HP_height);
            pop_settings();

            //warm
            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(warm1_left, warm1_top, warm1_width, warm1_height);
            pop_settings();
            if (player.player_left < warm1_left + warm1_width && player.player_left + 40.0 > warm1_left
                && player.player_top < warm1_top + warm1_height && player.player_top + 40.0 > warm1_top)
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
                draw_ellipse(monster1_left - 20.0, monster1_top + 50, 9);
                draw_rectangle(monster1_left - 24.0, monster1_top + 60, 8, 50);
                pop_settings();
            }
        }
    }

    void contact_player_m1Lsword(void)
    {
        //When the monster sword touches the player
        if (m1_swordHP_width > 0.0)
        {
            if (player.player_left + 40.0 > m1_sword_left && player.player_left < m1_sword_left + 60.0
                && m1_sword_top < player.player_top + 40.0 && m1_sword_top + 10.0 > player.player_top)
            {
                push_settings();
                set_fill_color(155, 30, 30);
                draw_rectangle(-570, -359, 1190, 600);
                pop_settings();
                draw_image(image_monster_left1, monster1_left, monster1_top, monster1_width, monster1_height);

                player.player_left -= 3.0;
                player.armorHP_width -= 1.0;
                if (player.armorHP_width < 0.0)
                {
                    player.playerHP_width -= 2.0;
                }
                draw_Lm1sword();
            }

            if (player.player_left < m1_sword_left + 170.0 && player.player_left > m1_sword_left + 110.0
                && m1_sword_top < player.player_top + 40.0 && m1_sword_top + 10.0 > player.player_top)
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
                draw_Rm1sword();
            }
        }
    }

    void draw_Lm1sword(void)
    {
        push_settings();
        no_outline();
        no_fill();
        draw_rectangle(m1_sword_left, m1_sword_top, m1_sword_width, m1_sword_height);
        pop_settings();
        draw_image(image_monsterSword_left1, m1_sword_left+3.0, m1_sword_top-5.0, m1_sword_width, m1_sword_height);
    }

    void draw_Rm1sword(void)
    {
        push_settings();
        no_outline();
        no_fill();
        draw_rectangle(m1_sword_left + 110.0, m1_sword_top, m1_sword_width, m1_sword_height);
        pop_settings();
        draw_image(image_monsterSword_right1, m1_sword_left + 110.0, m1_sword_top - 5.0, m1_sword_width, m1_sword_height);
    }


    void monster1_move(void)
    {
        if (speed1 == true)
        {
            if (!(player.player_left + 40.0 > m1_sword_left && player.player_left < m1_sword_left + 60.0
                && m1_sword_top < player.player_top + 40.0 && m1_sword_top + 10.0 > player.player_top))
            {
                draw_image(image_monster_right1, monster1_left, monster1_top, monster1_width, monster1_height);
            }
            m1_sword_left += 0.2;
            monster1_left += 0.2;
            monster1HP_left += 0.2;
            if (monster1_left > 460.0 && monster1HP_left > 460.0)
            {
                speed1 = false;
            }
        }
        else
        {
            draw_image(image_monster_left1, monster1_left, monster1_top, monster1_width, monster1_height);
            m1_sword_left -= 0.2;
            monster1_left -= 0.2;
            monster1HP_left -= 0.2;
            if (monster1_left < 330.0 && monster1HP_left < 330.0)
            {
                speed1 = true;
            }
        }
    }

    void contact_player_monster1_swordVSsword(void)
    {
        //When the monster contacts the player
        if (player.player_left + 40.0 >= monster1_left && player.player_left + 40.0 <= monster1_left + 40.0
            && player.player_top + 40.0 <= monster1_top + 40.0 && player.player_top + 40.0 >= monster1_top)
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
        if (player.player_left > monster1_left && player.player_left <= monster1_left + 40.0
            && player.player_top + 40.0 <= monster1_top + 40.0 && player.player_top + 40.0 >= monster1_top)
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
                if (player.player_left + 90.0 > monster1_left && player.player_left + 90.0 < monster1_left + 50.0
                    && player.player_top + 10.0 > monster1_top && player.player_top < monster1_top + 50.0)
                {
                    monster1HP_width -= 1.0;
                }

                //When the monster and the player's sword come into contact
                if (m1_swordHP_width > 0.0)
                {
                    if (player.player_left + 50.0 > m1_sword_left && player.player_left + 60.0 < m1_sword_left + 60.0
                        && player.player_top + 10.0 > monster1_top && player.player_top < monster1_top + 50.0)
                    {
                        push_settings();
                        no_fill();
                        no_outline();
                        draw_rectangle(m1_sword_left, m1_sword_top, m1_sword_width, m1_sword_height);
                        pop_settings();
                        draw_image(image_monsterSword_left1, m1_sword_left + 3.0, m1_sword_top - 5.0, m1_sword_width, m1_sword_height);
                        draw_image(image_monster_left1, monster1_left, monster1_top, monster1_width, monster1_height);
                        player.player_left -= 3.0;
                        m1_swordHP_width -= 1.0;
                    }
                }
            }
        }
        if (CheckKeyPressed[1])
        {
            if (CheckKeyPressed[2])
            {
                //When the player's sword touches the monster,
                if (player.player_left - 50.0 < monster1_left + 50.0 && player.player_left - 50.0 > monster1_left
                    && player.player_top + 10.0 > monster1_top && player.player_top < monster1_top + 50.0)
                {
                    monster1HP_width -= 1.0;
                    draw_image(image_monster_right1, monster1_left, monster1_top, monster1_width, monster1_height);
                }

                //When the monster and the player's sword come into contact
                if (m1_swordHP_width > 0.0)
                {
                    if (player.player_left - 50.0 > m1_sword_left + 110.0 && player.player_left - 50.0 < m1_sword_left + 170.0
                        && player.player_top + 10.0 > monster1_top && player.player_top < monster1_top + 50.0)
                    {
                        push_settings();
                        no_fill();
                        no_outline();
                        draw_rectangle(m1_sword_left + 110.0, m1_sword_top, m1_sword_width, m1_sword_height);
                        pop_settings();
                        draw_image(image_monsterSword_right1, m1_sword_left + 110.0, m1_sword_top - 5.0, m1_sword_width, m1_sword_height);
                        player.player_left += 3.0;
                        m1_swordHP_width -= 1.0;
                    }
                }
            }
        }
        push_settings();
        no_outline();
        set_fill_color(70, 50, 225);
        draw_rectangle(monster1_left - 25.0, monster1_top + 70.0, m1_swordHP_width, m1_swordHP_height);
        pop_settings();
    }
};
MONSTER1 stage2_monster1;