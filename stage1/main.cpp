
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

//player
#include "player.h"
#include "player_key.h"
#include "sword.h"
#include "alcohol.h"
#include "rain.h"

using namespace doodle;

int main(void)
{
    create_window();

    vector<Rain> RAIN;

    constexpr auto text = [](double t) { return (std::sin(t) * 0.5 + 0.5); };

    for (int i = 0; i < 20; ++i)
    {
        RAIN.push_back(rain);
    }

    while (!is_window_closed())
    {
        update_window();
        clear_background(HexColor{ 0xBF8679FF });

        switch (current_scene)
        {
        case 1:
            //background
            background.draw_stage1();

            //door
            first.draw_first_door();
            second.draw_second_door();
            third.draw_third_door();
            fourth.draw_fourth_door();

            //Attack
            sword.draw_sword_monster_attach();
            alcohol.alcohol_RightKey_K();
            alcohol.draw_alcohol_RightMove();
            alcohol.alcohol_LeftKey_K();
            alcohol.draw_alcohol_LeftMove();
            alcohol.monster_attach();

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

            //monster
            monster.draw_monster_and_HP();
            monster2.draw_monster_HP_2();
            monster3.draw_monster_HP_3();
            stage1_key.stage1_guage_draw_door();
            break;

        case 2:
            background.draw_stage1();
            player.draw_player();
            player.player_keyboard_A_D();
            player.draw_playerHP();
            player.draw_playerMP();
            break;
        case 3:
            const double texels_length = 1.0 + 2.0 * text(ElapsedTime * 2.0);
            set_font_backdrop_offset(std::sin(ElapsedTime * 4) * 
                texels_length, std::cos(ElapsedTime * 4) * texels_length);

            draw_text("Game Over", -200.0, -50.0);
            break;
        }
    }
    return 0;
}