#pragma once

#include <doodle/doodle.hpp>
#include <vector>
#include "player.h"
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "monster4.h"
#include "stage2_mini_boss.h"
#include "Screen.h"
#include "SmallMini_virus.h"

using namespace doodle;

class STAGE2_BOSS
{
public:
    double boss_left{ -10.0 };
    double boss_left2{ -10.0 };
    double boss_left3{ -10.0 };
    double boss_left4{ -10.0 };
    double boss_left5{ -10.0 };
    double boss_left6{ -10.0 };
    double boss_left7{ -10.0 };
    double boss_left8{ -10.0 };
    double boss_left9{ -10.0 };

    double boss_top{ -95.0 };
    double boss_width{ 60.0 };
    double boss_height{ 60.0 };
    double boss_bottom = boss_top + boss_height;
    double boss_right = boss_left + boss_width;

    double bossHP_left{ -370.0 };
    double bossHP_top{ 150.0 };
    double bossHP_width{ 29.0 }; //800
    double bossHP_height{ 30.0 };

    double bossFly_left{ -470.0 };
    double bossFly_top{ 100.0 };
    double bossFly_width{ 2000.0 };
    double bossFly_height{ 30.0 };

    double virus_left{ -19.0 };
    double virus_left2{ 120.0 };
    double virus_left3{ -160.0 };
    double virus_left4{ 250.0 };
    double virus_left5{ -290.0 };
    double virus_left6{ 380.0 };
    double virus_left7{ -420.0 };
    double virus_left8{ 510.0 };
    double virus_left9{ -550.0 };

    double virus_top{ 100.0 };
    double virus_width{ 60.0 };

    double virus_height{ -20.0 };
    double virus_height2{ -20.0 };
    double virus_height3{ -20.0 };
    double virus_height4{ -20.0 };
    double virus_height5{ -20.0 };
    double virus_height6{ -20.0 };
    double virus_height7{ -20.0 };
    double virus_height8{ -20.0 };
    double virus_height9{ -20.0 };

    double wizard_left{ -80.0 };
    double wizard_top{ 300.0 };
    double wizard_width{ 40.0 };
    double wizard_height{ 40.0 };

    double w_attack_left{ -80.0 };
    double w_attack_top{ 200.0 };
    double w_attack_width{ 40.0 };
    double w_attack_height{ -40.0 };

    double last_boss_left{ -200.0 };
    double last_boss_top{ 30.0 };
    double last_boss_width{ 60.0 };
    double last_boss_height{ 60.0 };

    bool bossmove = true;
    bool bossmove1 = true;
    bool bossmove2 = true;

    const  Image lightning { "asset/lightning.png" };
    const  Image cane{ "asset/cane.png" };
    const  Image cane2{ "asset/cane2.png" };
    const Image wizard{ "asset/wizard.png" };
    const  Image bat{ "asset/bat.png" };
    const  Image bat2{ "asset/bat2.png" };

    //-475 -345 -215 -80 60 195 325 455
    void draw_boss()
    {
        if (bossHP_width > 1.0)
        {
            //570 ~ 620
            draw_line(250, 180, 250, 150);
            draw_line(200, 180, 200, 150);
            //380~410
            draw_line(10, 180, 10, 150);
            draw_line(60, 180, 60, 150);
            //170~220
            draw_line(-253, 180, -253, 150);
            boss_top -= 3;
            if (stage2_monster1.monster1HP_width + stage2_monster2.monster2HP_width + stage2_monster3.monster3HP_width + stage2_monster4.monster4HP_width < 1.0)
            {
                boss_move();
                bossHP_skill();
                boss_HP();
                if (!(boss_top + 60.0 < bossFly_top - 70.0 && boss_top + 60.0 > bossFly_top - 100.0
                    && boss_left < bossFly_left + 2000.0 && boss_left + 60.0 > bossFly_left))
                {
                    push_settings();
                    no_outline();
                    no_fill();
                    draw_rectangle(boss_left, boss_top, boss_width, boss_height);
                    pop_settings();

                    draw_image(bat, boss_left - 20.0, boss_top, boss_width + 40.0, boss_height + 30.0);

                    contact_playersword();
                    contact_player();
                }
            }
            contact_floor();
        }
        if (bossHP_width < 1.1)
        {
            current_scene = gamewin;
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
        if (!(bossHP_width < 620.0 && bossHP_width > 570.0 || bossHP_width < 430.0 && bossHP_width > 380.0 || bossHP_width < 100.0))
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
            bossHP_width -= 0.02;
            boss_top += 6.0;
        }

        if (bossHP_width < 120.0)
        {
            if (boss_top + 60.0 < bossFly_top - 70.0 && boss_top + 60.0 > bossFly_top - 100.0
                && boss_left < bossFly_left + 2000.0 && boss_left + 60.0 > bossFly_left)
            {
                boss_top -= 3.0;

                push_settings();
                no_outline();
                no_fill();
                draw_rectangle(last_boss_left, last_boss_top, last_boss_width, last_boss_height);
                pop_settings();


                if (player.player_left < last_boss_left + 60.0 && player.player_left + 40.0 > last_boss_left
                    && player.player_top + 40.0 < last_boss_top + 60.0)
                {
                    last_boss_top -= 7;
                    draw_image(bat2, last_boss_left - 10.0, last_boss_top, last_boss_width + 15.0, last_boss_height + 20.0);
                }
                else
                {
                    draw_image(bat, last_boss_left - 20.0, last_boss_top, last_boss_width + 40.0, last_boss_height + 30.0);
                }

                if (CheckKeyPressed[0])
                {
                    if (CheckKeyPressed[2])
                    {
                        //When the player's sword touches the monster
                        if (player.player_left + 100.0 > last_boss_left && player.player_left + 100.0 < last_boss_left + 60.0
                            && player.player_top + 10.0 > last_boss_top && player.player_top < last_boss_top + 60.0)
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
                        if (player.player_left - 50.0 < last_boss_left + 60.0 && player.player_left - 50.0 > last_boss_left
                            && player.player_top + 10.0 > last_boss_top && player.player_top < last_boss_top + 60.0)
                        {
                            bossHP_width -= 1.3; //0.3
                        }
                    }
                }

                if (bossmove2 == true)
                {
                    last_boss_left -= 2.5;
                    if (last_boss_left < -490.0)
                    {
                        bossmove2 = false;
                    }
                }
                else
                {
                    last_boss_left += 2.5;
                    if (last_boss_left > 550.0)
                    {
                        bossmove2 = true;
                    }
                }


                if (bossmove1 == true)
                {
                    last_boss_top -= 0.4;
                    if (last_boss_top < -25)
                    {
                        bossmove1 = false;
                    }
                }
                else
                {
                    last_boss_top += 0.4;
                    if (last_boss_top > 50)
                    {
                        bossmove1 = true;
                    }
                }

                if (player.player_left < last_boss_left + 60.0 && player.player_left > last_boss_left
                    && player.player_top + 40.0 > last_boss_top && player.player_top < last_boss_top + 60.0)
                {
                    push_settings();
                    set_fill_color(155, 30, 30);
                    draw_rectangle(-570, -359, 1190, 600);
                    pop_settings();
                    player.player_left += 3.0;
                    player.armorHP_width -= 1.0;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.5;
                    }
                }
                if (player.player_left + 40 > last_boss_left && player.player_left + 40.0 < last_boss_left + 60.0
                    && player.player_top + 40.0 > last_boss_top && player.player_top < last_boss_top + 60.0)
                {
                    push_settings();
                    set_fill_color(155, 30, 30);
                    draw_rectangle(-570, -359, 1190, 600);
                    pop_settings();
                    player.player_left -= 3.0;
                    player.armorHP_width -= 1.0;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.5;
                    }
                }
            }
            boss_top += 6.0;
        }

        if (boss_top + 60.0 < bossFly_top + 30 && boss_top + 60.0 > bossFly_top
            && boss_left < bossFly_left + 2000.0 && boss_left + 60.0 > bossFly_left)
        {
            boss_top -= 3.0;
            if (bossHP_width < 430.0 && bossHP_width > 380.0)
            {
                boss_left = -20.0;
                virus();

                push_settings();
                no_outline();
                no_fill();
                draw_rectangle(boss_left2, boss_top, boss_width, boss_height);
                draw_rectangle(boss_left3, boss_top, boss_width, boss_height);
                draw_rectangle(boss_left4, boss_top, boss_width, boss_height);
                draw_rectangle(boss_left5, boss_top, boss_width, boss_height);
                draw_rectangle(boss_left6, boss_top, boss_width, boss_height);
                draw_rectangle(boss_left7, boss_top, boss_width, boss_height);
                draw_rectangle(boss_left8, boss_top, boss_width, boss_height);
                draw_rectangle(boss_left9, boss_top, boss_width, boss_height);
                pop_settings();

                draw_image(bat2, boss_left2- 10.0, boss_top, boss_width + 15.0, boss_height + 10.0);
                draw_image(bat2, boss_left3 - 10.0, boss_top, boss_width + 15.0, boss_height + 10.0);
                draw_image(bat2, boss_left4 - 10.0, boss_top, boss_width + 15.0, boss_height + 10.0);
                draw_image(bat2, boss_left5 - 10.0, boss_top, boss_width + 15.0, boss_height + 10.0);
                draw_image(bat2, boss_left6 - 10.0, boss_top, boss_width + 15.0, boss_height + 10.0);
                draw_image(bat2, boss_left7 - 10.0, boss_top, boss_width + 15.0, boss_height + 10.0);
                draw_image(bat2, boss_left8 - 10.0, boss_top, boss_width + 15.0, boss_height + 10.0);
                draw_image(bat2, boss_left9-10.0, boss_top, boss_width + 15.0, boss_height+ 10.0);

                if (boss_left8 > 450)
                {
                    mini.draw_minivirus();
                }

                bosses();
                Wizard();
                draw_image(wizard, -560, -130, 100, 100);
                draw_image(cane2, -476, -130, 30, 90);
            }

        }
    }

    void Wizard()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(wizard_left, wizard_top, wizard_width, wizard_height);
        pop_settings();

        draw_image(cane, wizard_left, wizard_top, wizard_width, wizard_height + 100.0);

        if (player.player_left + 40.0 < wizard_left + 40.0 && player.player_left + 40.0 > wizard_left
            && player.player_top + 40.0 > w_attack_height)
        {
            player.playerHP_width -= 1000.0;
            player.player_left -= 3.0;
        }
        if (player.player_left > wizard_left && player.player_left < wizard_left + 40.0
            && player.player_top + 40.0 > w_attack_height)
        {
            player.playerHP_width -= 1000.0;
            player.player_left += 3.0;
        }

        if (wizard_top > 200)
        {
            wizard_top--;
        }
        else if (wizard_top < 201)
        {
            push_settings();
            no_fill();
            no_outline();
            draw_rectangle(wizard_left, w_attack_top, w_attack_width, w_attack_height);
            pop_settings();

            draw_image(lightning, wizard_left+10.0, w_attack_top, w_attack_width+10.0, w_attack_height);
            w_attack_height -= 30.0;
            if (w_attack_height < -580.0)
            {
                wizard_top = 300;
                w_attack_height = -40.0;
                wizard_left = random(-550, 580); //-475,-345,-215, -80, 60, 195, 325, 455
            }
        }
    }

    void virus(void)
    {
        push_settings();
        no_fill();
        no_outline();
        if (boss_top > 0.0)
        {
            virus_height--;
            draw_rectangle(virus_left, virus_top, virus_width, virus_height);
            if (player.player_left < virus_left + 60.0 && player.player_left + 40.0 > virus_left
                && player.player_top > virus_height)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }

        if (boss_left2 > 119.0)
        {
            virus_height2--;
            draw_rectangle(virus_left2, virus_top, virus_width, virus_height2);
            if (player.player_left < virus_left2 + 60.0 && player.player_left + 40.0 > virus_left2
                && player.player_top > virus_height2)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        if (boss_left4 > 249.0)
        {
            virus_height4--;
            draw_rectangle(virus_left4, virus_top, virus_width, virus_height4);
            if (player.player_left < virus_left4 + 60.0 && player.player_left + 40.0 > virus_left4
                && player.player_top > virus_height4)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        if (boss_left6 > 379.0)
        {
            virus_height6--;
            draw_rectangle(virus_left6, virus_top, virus_width, virus_height6);
            if (player.player_left < virus_left6 + 60.0 && player.player_left + 40.0 > virus_left6
                && player.player_top > virus_height6)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        if (boss_left8 > 509.0)
        {
            virus_height8--;
            draw_rectangle(virus_left8, virus_top, virus_width, virus_height8);
            if (player.player_left < virus_left8 + 60.0 && player.player_left + 40.0 > virus_left8
                && player.player_top > virus_height8)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        if (boss_left3 < -159.0)
        {
            virus_height3--;
            draw_rectangle(virus_left3, virus_top, virus_width, virus_height3);
            if (player.player_left < virus_left3 + 60.0 && player.player_left + 40.0 > virus_left3
                && player.player_top > virus_height3)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        if (boss_left5 < -289.0)
        {
            virus_height5--;
            draw_rectangle(virus_left5, virus_top, virus_width, virus_height5);
            if (player.player_left < virus_left5 + 60.0 && player.player_left + 40.0 > virus_left5
                && player.player_top > virus_height5)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        if (boss_left7 < -419.0)
        {
            virus_height7--;
            draw_rectangle(virus_left7, virus_top, virus_width, virus_height7);
            if (player.player_left < virus_left7 + 60.0 && player.player_left + 40.0 > virus_left7
                && player.player_top > virus_height7)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        if (boss_left9 < -549.0)
        {
            virus_height9--;
            draw_rectangle(virus_left9, virus_top, virus_width, virus_height9);
            if (player.player_left < virus_left9 + 60.0 && player.player_left + 40.0 > virus_left9
                && player.player_top > virus_height9)
            {
                if (!CheckKeyPressed[3])
                {
                    player.armorHP_width -= 0.1;
                    if (player.armorHP_width < 0.0)
                    {
                        player.playerHP_width -= 0.2;
                    }
                }
            }
        }
        pop_settings();
    }

    void bosses(void)
    {
        if (boss_left2 < 120.0)
        {
            boss_left2++;
        }
        if (boss_left4 < 250.0)
        {
            boss_left4++;
        }
        if (boss_left6 < 380.0)
        {
            boss_left6++;
        }
        if (boss_left8 < 510.0)
        {
            boss_left8++;
        }
        if (boss_left3 > -160.0)
        {
            boss_left3--;
        }
        if (boss_left5 > -290.0)
        {
            boss_left5--;
        }
        if (boss_left7 > -420.0)
        {
            boss_left7--;
        }
        if (boss_left9 > -550.0)
        {
            boss_left9--;
        }
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