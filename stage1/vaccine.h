#pragma once
#include <doodle/doodle.hpp>
using namespace doodle;

#include "player_key.h"
#include "player.h"

class VACCINE
{
public:
	double v_left = 30.0;
	double v_top = 30.0;
	
	void draw_vaccine()
	{
			if (CheckKeyPressed[3])
			{
					player.playerMP_width -= 0.3;
					move_vaccine();

					push_settings();
					no_outline();
					set_fill_color(0, 250, 0);
					draw_rectangle(v_left, v_top, 25, 7);
					draw_rectangle(v_left + 9.0, v_top - 9.0, 7, 25);

					draw_rectangle(v_left + 20.0, v_top - 19.0, 25, 7);
					draw_rectangle(v_left + 29.0, v_top - 28.0, 7, 25);
					pop_settings();
		    }

			if (player.playerMP_width < 50.0)
			{
				player.armorHP_width -= 0.1;
				if (player.armorHP_width < 1.0)
				{
					player.playerHP_width -= 0.1;
				}
			}
	}

	void move_vaccine(void)
	{
		double vaccine_move = 200.0 * DeltaTime;
		v_top += vaccine_move;
		if (v_top > player.player_top + 60.0)
		{
			v_left = random(player.player_left - 20.0, player.player_left + 60.0);
			v_top = player.player_top;
		}
	}
};
VACCINE vaccine;