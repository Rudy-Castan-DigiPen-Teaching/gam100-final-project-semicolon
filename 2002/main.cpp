
#include <doodle/doodle.hpp>
#include <vector>

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

using namespace doodle;

int main(void)
{
    create_window(1500, 800);
    const  Image background_stage1{ "asset/stage1.png" };
    const  Image background_stage2{ "asset/stage2.png" };

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


    while (!is_window_closed())
    {
        update_window();
        clear_background(HexColor{ 0xBF8679FF });

        switch (current_scene)
        {
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

            draw_text("Game Over", -200.0, -50.0);
            break;
        case 4:
            draw_text("Game Win!!", -200.0, -50.0);
            break;
        }
    }
    return 0;
}