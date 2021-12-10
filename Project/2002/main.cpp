// Filename : <main.cpp>
// Authors : <Hyunjun Lee, Dawoon Jung, Geumbi Yeo>
// Course : GAM100F21
// All content © 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include <vector>
#include <iostream>
#include <SFML/Audio.hpp>

//screen
#include "Screen.h"

//Stage_1
#include "background.h"
#include "doors.h"
#include "first_floor_monster.h"
#include "second_floor_monster.h"
#include "third_floor_monster.h"
#include "Stage1_Key.h"

//Stage_2
#include "stage2boss.h"
#include "background2.h"
#include "boss_rain.h"
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "monster4.h"
#include "vaccine.h"

//player
#include "player.h"
#include "player_key.h"
#include "sword.h"
#include "alcohol.h"
#include "rain.h"

//screen
#include "Game Menu.h"

using namespace doodle;
bool isMusicStarted = false;
int main(void)
{
    create_window("2002",1500, 800);
    const  Image background_stage1{ "asset/stage1.png" };
    const  Image background_stage2{ "asset/stage2.png" };
    const Image  main{ "asset/main.png" };
    const Image  victory{ "asset/victory.png" };
    const Image  gameover2{ "asset/gameover.png" };
    const Image  Howtoplay{ "asset/Howtoplay.png" };
    const Image  Howtoplay2{ "asset/Howtoplay2.png" };
    const Image  Item2{ "asset/Item.png" };
    const Image  Next{ "asset/next.png" };
    const Image  black_logo{ "asset/DigiPen_BLACK.png" };
    double picture_scale{ -0.5 };

    double picture_x_move{ 700 };
    double picture_y_move{ 300 };

    double       picture_fade{ 0 };
    double       a = 0;
    double       c = 0;
    double       b = 500;

    vector<Rain> RAIN;
    vector<BOSS_RAIN> b_RAIN;


    for (int i = 0; i < 20; ++i)
    {
        RAIN.push_back(rain);
    }
    for (int t = 0; t < 12; ++t)
    {
        b_RAIN.push_back(boss_rain);
    }
    sf::Music music;
    while (!is_window_closed())
    {
        update_window();
        clear_background(HexColor{ 0xBF8679FF });
        
        switch (current_scene)
        {
        case 9:
            push_settings();
            if (ElapsedTime < 2)
            {
                picture_x_move -= DeltaTime * 700;
                picture_y_move -= DeltaTime * 300;
                picture_scale += DeltaTime;

                apply_translate(picture_x_move, picture_y_move);
                apply_scale(picture_scale);
                draw_image(black_logo, 0, 0);
            }
            else if (ElapsedTime < 5)
            {
                picture_fade += DeltaTime * 255;
                set_tint_color(255, picture_fade);
                draw_image(black_logo, -600, -200);
            }
            else if (ElapsedTime < 6)
            {
                current_scene = 0;
                music.openFromFile("sound/stage1.ogg");
                music.setLoop(true);
                music.play();
            }
            pop_settings();
            break;
        case 0:

            draw_image(main, -800, -400, 1600, 800);
            Game_menu.how_to_play_button();
            Game_menu.credit_button();
            Game_menu.start_button();
            break;
        case 1:
            //background
            draw_image(background_stage1, -700, -330, 1400, 700);
            background.draw_stage1();

            //door
            first.draw_first_door();
            second.draw_second_door();
            third.draw_third_door();
            fourth.draw_fourth_door();

            //Attack
            sword.draw_sword_move();
            alcohol.alcohol_RightKey_K();
            alcohol.draw_alcohol_RightMove();
            alcohol.alcohol_LeftKey_K();
            alcohol.draw_alcohol_LeftMove();
            alcohol.monster_attach();

            sword.stage1_mosters();

            for (auto& i : RAIN)
            {
                i.draw_rain();
            }

            //player
            player.draw_player();
            player.player_keyboard_A_D();
            player.contact_door();
            player.draw_playerHP();
            player.draw_playerMP();
            player.limit();

            //monster
            monster.draw_monster_and_HP();
            monster2.draw_monster_HP_2();
            monster3.draw_monster_HP_3();
            stage1_key.stage1_guage_draw_door();
            break;

        case 2:
            walls.draw_walls();
            draw_image(background_stage2, -570, -360, 1190, 600);
            walls.draw_stage2_floors();

            //Attack
            sword.draw_sword_move();

            for (auto& i : RAIN)
            {
                i.draw_rain();
            }
            if (stage2_boss.bossHP_width > 1.0)
            {
                for (auto& t : b_RAIN)
                {
                    t.draw_BossRain();
                }
            }

            player.draw_player();
            player.player_keyboard_A_D();
            player.draw_playerHP();
            player.draw_playerMP();
            player.player_falling();

            player.jump();

            //monster
            stage2_monster1.draw_monster1();

            stage2_monster2.draw_monster2();

            stage2_monster3.draw_monster3();

            stage2_monster4.draw_monster4();
            player.armor();

            //boss
            stage2_boss.draw_boss();
            vaccine.draw_vaccine();
            break;

        case 3:


            push_settings();
            draw_image(gameover2, -800, -400, 1550, 800);
            Game_menu.Game_Over();
            set_font_size(30);
            set_fill_color(0);
            draw_text("You are infected with " , -680 , 250);
            draw_text("a virus that fell from a bat." , -680 , 200);
            draw_text("There is no cure because " , -680 , 150);
            draw_text("you didn't get the vaccine." , -680 , 100);
            draw_text("Start again and save the world!" , -680 , 50);
            draw_text("God bless you." , -680 , 0);
            pop_settings();
            break;
        case 4:

            push_settings();
            draw_image(victory, -800, -400, 1550, 800);
            set_font_size(30);
            set_fill_color(0);
            draw_text(" You caught a bat " , -680, 50);
            draw_text(" and found the vaccine." , -680, 0);
            draw_text(" at the top of the castle!" , -680, -50);
            draw_text(" You saved the world " , -680, -100);
            draw_text(" with your vaccine." , -680, -150);
            pop_settings();

            Game_menu.restart();
            break; 
        case 5:

            draw_image(Howtoplay, -700, -350, 1400, 700);
            draw_image(Next, -680, -325, 219, 107);
            Game_menu.next_button();
            break;

        case 6:

            draw_image(Howtoplay2, -700, -350, 1400, 700);
            Game_menu.next_button2();
            break;

        case 7:
 
            draw_image(Item2, -700, -350, 1400, 700);
            Game_menu.Quit();
            break;

        case 8:

            draw_image(main, -800, -400, 1600, 800);
            a += 0.7;
            c += 0.7;

            if (-1350 + c > 400)
            {
                a = 0.0;
                c = 0.0;
            }
            push_settings();
            set_fill_color(255, 239, 213);
            draw_text("TEAM MEMBER", -200, -450 + a);
            pop_settings();

            push_settings();
            set_font_size(40);
            draw_text("Hyunjun Lee", -110, -570 + a); // a -110
            draw_text("Dawoon Jung", -110, -820 + a); // a -110
            draw_text("Geumbi Yeo", -100, -700 + a);  // b -100
            pop_settings();


            push_settings();
            set_font_size(30);
            set_fill_color(255, 239, 213);

            draw_text("PRODUCER", -240, -450 - b + a);
            draw_text("PROGRAMMER", 50, -450 - b + a);

            draw_text("DESIGN", -180, -620 - b + a);
            draw_text("AUDIO LEAD", 50, -620 - b + a);

            draw_text("PROGRAMMING ASSISTANT", -200, -780 - b + a);

            set_font_size(20);
            draw_text("AND", -20, -445 - b + a);
            draw_text("AND", -20, -615 - b + a);
            pop_settings();

            push_settings();
            set_font_size(40);
            draw_text("Hyunjun Lee", -110, -520 - b + a); // a -110
            draw_text("Dawoon Jung", -110, -1350 + c);    // a -110
            draw_text("Geumbi Yeo", -100, -690 - b + a);  // b -100
            pop_settings();
            Game_menu.back_button();
            if (get_mouse_x() > Game_menu.back_x && get_mouse_x() < Game_menu.back_x + 200.0 &&
                get_mouse_y() < Game_menu.back_y + 100.0 &&
                get_mouse_y() > Game_menu.back_y && MouseIsPressed)
            {
                current_scene = 0;
                a             = 0;
                c             = 0;
            }
            break;
        }
       
    }


    return 0;
}
