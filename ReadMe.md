//NAME : Semicolon
//ASSIGNMENT : Game Snapshot
//COURSE : CS120
//TERM & YEAR : Fall 2021

# gam100 doodle starter project

## doodle framework
main.cpp - 6,27

~~~
#include <doodle/doodle.hpp>
using namespace doodle;
~~~
## if
alcohol.h - 36~43
~~~
if (CheckKeyPressed[0])
{
    if (CheckKeyPressed[3] && player.playerMP_width >=5)
       {
           alcohol_left = player.player_left;   
           player.playerMP_width -= 5;
       }
}
~~~
## switch
main.cpp - 47~100
~~~
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
~~~
## while
third_floor_monster.h - 108~114
~~~
while (player.playerHP_width > 150.0)
{
     Rightdefense_wall_height3 += 0.1;

     if (Rightdefense_wall_height3 > 150.0)
         break;
}
~~~
## for
main.cpp - 37~40
~~~
for (int i = 0; i < 20; ++i)
{
    RAIN.push_back(rain);
}
~~~
## for range
main.cpp - 67~70
~~~
for (auto& i : RAIN)
{
     i.draw_rain();
}
~~~
## class
doors.h - 10~29
~~~
class first_door
{
public:
    double under_door_left{ 570.0 };
    double under_door_top{ -300.0 };
    double under_door_width{ 20.0 };
    double under_door_height{ 100.0 };
    double under_door_right = under_door_left + under_door_width;
    double under_door_bottom = under_door_top + under_door_height;

    void draw_first_door()
    {
        push_settings();
        no_fill();
        no_outline();
        draw_rectangle(under_door_left, under_door_top, under_door_width, under_door_height);
        pop_settings();
    }
};
first_door first;
~~~
## int 
screen.h - 8
~~~
int current_scene = 1;
~~~
## double
sword.h - 20
~~~
double sword_left{ 40.0 };
~~~
## bool
first_floor_monster.h - 38,65~84
~~~
bool direction = true;

        if (direction == true)
        {
            monster_sword_left += 0.3;
            monster_left += 0.3;
            monsterHP_left +=0.3;
            if (monster_left > 400 && monsterHP_left > 400)
            {
                direction = false;
            }
        }
        else
        {
            monster_sword_left -= 0.3;
            monster_left -= 0.3;
            monsterHP_left -=0.3;
            if (monster_left <200 && monsterHP_left<200)
            {
                direction = true;
            }
        }
~~~
## vector
main.cpp- 33
~~~
vector<Rain> RAIN;
~~~
## constexpr
main.cpp - 35
~~~
constexpr auto text = [](double t) { return (std::sin(t) * 0.5 + 0.5); };
~~~
## array
player_key.h - 10~58
~~~
bool CheckKeyPressed[5];

void on_key_pressed(KeyboardButtons button)
{
    if (button == KeyboardButtons::D)
    {
        CheckKeyPressed[0] = true;
    }
    if (button == KeyboardButtons::A)
    {
        CheckKeyPressed[1] = true;
    }
    if (button == KeyboardButtons::J)
    {
        CheckKeyPressed[2] = true;
    }
    if (button == KeyboardButtons::K)
    {
        CheckKeyPressed[3] = true;
    }
    if (button == KeyboardButtons::L)
    {
        CheckKeyPressed[4] = true;
    }
}

void on_key_released(KeyboardButtons button)
{
    if (button == KeyboardButtons::D)
    {
        CheckKeyPressed[0] = false;
    }
    if (button == KeyboardButtons::A)
    {
        CheckKeyPressed[1] = false;
    }
    if (button == KeyboardButtons::J)
    {
        CheckKeyPressed[2] = false;
    }
    if (button == KeyboardButtons::K)
    {
        CheckKeyPressed[3] = false;
    }
    if (button == KeyboardButtons::L)
    {
        CheckKeyPressed[4] = false;
    }
}
~~~

## Section describing anything incomplete about the assignment

The standard of the core was met. However, several other requirements were not met.
Of course, we tried to match it, but if we code prematurely, errors occur in other code, so we tried our best.

## Section describing something you’re proud of about the assignment
I'm proud of the code in part player_key.h. Array is the code that I don't understand more than vector in code. So, although it may be a simple code to others, it is a code that I am proud of.

