// Filename : <stage2_mini_boss.h>
// Authors : <Hyunjun Lee>
// Course : GAM100F21
// All content © 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <doodle/doodle.hpp>
#include "player.h"
#include "background2.h"
using namespace doodle;

class MINI_BOSS
{
public:
	double Mboss_left{ -100.0 };
	double Mboss_top{ 100.0 };
	double Mboss_width{ 30.0 };
	double Mboss_height{ 30.0 };
	double MbossHP_width{ 40.0 };

	double Mb_sword_left{ -120.0 };
	double Mb_sword_top{ 115.0 };
	double Mb_sword_width{ 20.0 };
	double Mb_sword_height{ 10.0 };

	double Mb_swordHP_left{ 375.0 };
	double Mb_swordHP_top{ -460.0 };
	double Mb_swordHP_width{ 100.0 };
	double Mb_swordHP_height{ 10.0 };

	double Mboss_left2{ -400.0 };
	double Mboss_top2{ 100.0 };
	double Mboss_width2{ 30.0 };
	double Mboss_height2{ 30.0 };
	double MbossHP_width2{ 40.0 };

	double Mb_sword_left2{ -420.0 };
	double Mb_sword_top2{ 115.0 };
	double Mb_sword_width2{ 20.0 };
	double Mb_sword_height2{ 10.0 };

	double Mb_swordHP_left2{ 375.0 };
	double Mb_swordHP_top2{ -460.0 };
	double Mb_swordHP_width2{ 100.0 };
	double Mb_swordHP_height2{ 10.0 };

	double Mboss_left3{ 420.0 };
	double Mboss_top3{ 100.0 };
	double Mboss_width3{ 30.0 };
	double Mboss_height3{ 30.0 };
	double MbossHP_width3{ 40.0 };

	double Mb_sword_left3{ 400.0 };
	double Mb_sword_top3{ 115.0 };
	double Mb_sword_width3{ 20.0 };
	double Mb_sword_height3{ 10.0 };

	double Mb_swordHP_left3{ 375.0 };
	double Mb_swordHP_top3{ -460.0 };
	double Mb_swordHP_width3{ 100.0 };
	double Mb_swordHP_height3{ 10.0 };

	bool mini_move1 = true;
	bool mini_move2 = true;
	bool mini_move3 = true;

	const  Image Mimage_monster_right1{ "asset/bossvirus.png" };
	const  Image Mimage_monster_left1{ "asset/bossvirus2.png" };
	const  Image Mimage_monsterSword_right1{ "asset/knife.png" };
	const  Image Mimage_monsterSword_left1{ "asset/knife2.png" };

	const  Image Mimage_monster_right2{ "asset/bossvirus.png" };
	const  Image Mimage_monster_left2{ "asset/bossvirus2.png" };
	const  Image Mimage_monsterSword_right2{ "asset/knife.png" };
	const  Image Mimage_monsterSword_left2{ "asset/knife2.png" };

	const  Image Mimage_monster_right3{ "asset/bossvirus.png" };
	const  Image Mimage_monster_left3{ "asset/bossvirus2.png" };
	const  Image Mimage_monsterSword_right3{ "asset/knife.png" };
	const  Image Mimage_monsterSword_left3{ "asset/knife2.png" };

	void draw_Mboss(void)
	{
		if (MbossHP_width > 1.0)
		{
			sword_vs_sword1();
			contact_Msword_player1();
			contact_sword_monster1();
			contact_miniboss1();
			miniboss_move();
			contact_floor1();
			Mboss_top -= 3.0;

			push_settings();
			no_outline();
			no_fill();
			draw_rectangle(Mboss_left, Mboss_top, Mboss_width, Mboss_height);
			pop_settings();

			push_settings();
			no_outline();
			set_fill_color(255, 0, 0);
			draw_rectangle(Mboss_left - 7.0, Mboss_top + 40.0, MbossHP_width, 8.0);
			pop_settings();
		}

		if (MbossHP_width2 > 1.0)
		{
			sword_vs_sword2();
			miniboss_move();
			contact_floor1();
			contact_miniboss2();
			contact_sword_monster2();
			contact_Msword_player2();
			Mboss_top2 -= 3.0;

			push_settings();
			no_outline();
			no_fill();
			draw_rectangle(Mboss_left2, Mboss_top2, Mboss_width2, Mboss_height2);
			pop_settings();

			push_settings();
			no_outline();
			set_fill_color(255, 0, 0);
			draw_rectangle(Mboss_left2 - 7.0, Mboss_top2 + 40.0, MbossHP_width2, 8.0);
			pop_settings();
		}

		if (MbossHP_width3 > 1.0)
		{
			contact_floor1();
			sword_vs_sword3();
			contact_Msword_player3();
			contact_sword_monster3();
			contact_miniboss3();
			miniboss_move();
			Mboss_top3 -= 3.0;

			push_settings();
			no_outline();
			no_fill();
			draw_rectangle(Mboss_left3, Mboss_top3, Mboss_width3, Mboss_height3);
			pop_settings();

			push_settings();
			no_outline();
			set_fill_color(255, 0, 0);
			draw_rectangle(Mboss_left3 - 7.0, Mboss_top3 + 40.0, MbossHP_width3, 8.0);
			pop_settings();
		}
	}

	void contact_floor1(void)
	{
		if (Mboss_left + 30 > walls.floor1_left && Mboss_left < walls.floor1_right
			&& Mboss_top > walls.floor1_top && Mboss_top < walls.floor1_top + 15.0)
		{
			Mboss_top += 3.0;
		}

		if (Mboss_left2 + 30 > walls.floor3_left && Mboss_left2 < walls.floor3_right
			&& Mboss_top2 > walls.floor3_top && Mboss_top2 < walls.floor3_top + 15.0)
		{
			Mboss_top2 += 3.0;
		}

		if (Mboss_left3 + 30 > walls.floor3_left + 825.0 && Mboss_left3 < walls.floor3_right + 825.0
			&& Mboss_top3 > walls.floor3_top && Mboss_top3 < walls.floor3_top + 15.0)
		{
			Mboss_top3 += 3.0;
		}
	}

	void miniboss_move(void)
	{
		if (mini_move1 == true)
		{
			if (MbossHP_width > 1.0)
			{
				draw_image(Mimage_monster_left1, Mboss_left, Mboss_top, Mboss_width, Mboss_height);
				if (Mb_swordHP_width > 1.0)
				{
					draw_image(Mimage_monsterSword_left1, Mb_sword_left, Mboss_top + 5.0, Mb_sword_width, Mb_sword_height);
				}
			}
			Mb_sword_left -= 0.4;
			Mboss_left -= 0.4;
			if (Mboss_left < -170.0)
			{
				mini_move1 = false;
			}
		}
		else
		{
			if (MbossHP_width > 1.0)
			{
				draw_image(Mimage_monster_right1, Mboss_left, Mboss_top, Mboss_width, Mboss_height);
				if (Mb_swordHP_width > 1.0)
				{
					draw_image(Mimage_monsterSword_right1, Mb_sword_left + 50.0, Mboss_top + 5.0, Mb_sword_width, Mb_sword_height);
				}
			}
			Mb_sword_left += 0.4;
			Mboss_left += 0.4;
			if (Mboss_left > 140.0)
			{
				mini_move1 = true;
			}
		}

		if (mini_move2 == true)
		{
			if (MbossHP_width2 > 1.0)
			{
				draw_image(Mimage_monster_left2, Mboss_left2, Mboss_top2, Mboss_width2, Mboss_height2);
				if (Mb_swordHP_width2 > 1.0)
				{
					draw_image(Mimage_monsterSword_left2, Mb_sword_left2, Mboss_top2 + 5.0, Mb_sword_width2, Mb_sword_height2);
				}
			}
			Mb_sword_left2 -= 0.3;
			Mboss_left2 -= 0.3;
			if (Mboss_left2 < -480.0)
			{
				mini_move2 = false;
			}
		}
		else
		{
			if (MbossHP_width2 > 1.0)
			{
				draw_image(Mimage_monster_right2, Mboss_left2, Mboss_top2, Mboss_width2, Mboss_height2);
				if (Mb_swordHP_width2 > 1.0)
				{
					draw_image(Mimage_monsterSword_right2, Mb_sword_left2 + 50.0, Mboss_top2 + 5.0, Mb_sword_width2, Mb_sword_height2);
				}
			}
			Mb_sword_left2 += 0.3;
			Mboss_left2 += 0.3;
			if (Mboss_left2 > -370.0)
			{
				mini_move2 = true;
			}
		}

		if (mini_move3 == true)
		{
			if (MbossHP_width3 > 1.0)
			{
				draw_image(Mimage_monster_left3, Mboss_left3, Mboss_top3, Mboss_width3, Mboss_height3);
				if (Mb_swordHP_width3 > 1.0)
				{
					draw_image(Mimage_monsterSword_left3, Mb_sword_left3, Mboss_top3 + 5.0, Mb_sword_width3, Mb_sword_height3);
				}
			}
			Mb_sword_left3 -= 0.15;
			Mboss_left3 -= 0.15;
			if (Mboss_left3 < 360.0)
			{
				mini_move3 = false;
			}
		}
		else
		{
			if (MbossHP_width3 > 1.0)
			{
				draw_image(Mimage_monster_right3, Mboss_left3, Mboss_top3, Mboss_width3, Mboss_height3);
			}
			if (Mb_swordHP_width3 > 1.0)
			{
				draw_image(Mimage_monsterSword_right3, Mb_sword_left3 + 50.0, Mboss_top3 + 5.0, Mb_sword_width3, Mb_sword_height3);
			}
			Mb_sword_left3 += 0.15;
			Mboss_left3 += 0.15;
			if (Mboss_left3 > 480.0)
			{
				mini_move3 = true;
			}
		}
	}

	void contact_miniboss1(void)
	{
		if (Mboss_left < player.player_left + 40.0 && Mboss_left + 30.0 > player.player_left + 40.0
			&& Mboss_top + 30.0 > player.player_top && Mboss_top + 30.0 < player.player_top + 40.0)
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
		if (Mboss_left  < player.player_left && Mboss_left + 30.0 > player.player_left
			&& Mboss_top + 30.0 > player.player_top && Mboss_top + 30.0 < player.player_top + 40.0)
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
	}

	void contact_miniboss2(void)
	{
		if (Mboss_left2 < player.player_left + 40.0 && Mboss_left2 + 30.0 > player.player_left + 40.0
			&& Mboss_top2 + 30.0 > player.player_top && Mboss_top2 + 30.0 < player.player_top + 40.0)
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
		if (Mboss_left2  < player.player_left && Mboss_left2 + 30.0 > player.player_left
			&& Mboss_top2 + 30.0 > player.player_top && Mboss_top2 + 30.0 < player.player_top + 40.0)
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
	}

	void contact_miniboss3(void)
	{
		if (Mboss_left3 < player.player_left + 40.0 && Mboss_left3 + 30.0 > player.player_left + 40.0
			&& Mboss_top3 + 30.0 > player.player_top && Mboss_top3 + 30.0 < player.player_top + 40.0)
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
		if (Mboss_left3  < player.player_left && Mboss_left3 + 30.0 > player.player_left
			&& Mboss_top3 + 30.0 > player.player_top && Mboss_top3 + 30.0 < player.player_top + 40.0)
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
	}

	void contact_sword_monster1(void)
	{
		if (CheckKeyPressed[0])
		{
			if (CheckKeyPressed[2])
			{
				//When the player's sword touches the monster
				if (player.player_left + 100.0 > Mboss_left && player.player_left + 100.0 < Mboss_left + 30.0
					&& player.player_top + 10.0 > Mboss_top && player.player_top < Mboss_top + 30.0)
				{
					MbossHP_width -= 0.3; //0.3
				}
			}
		}
		if (CheckKeyPressed[1])
		{
			if (CheckKeyPressed[2])
			{
				//When the player's sword touches the monster,
				if (player.player_left - 50.0 < Mboss_left + 30.0 && player.player_left - 50.0 > Mboss_left
					&& player.player_top + 10.0 > Mboss_top && player.player_top < Mboss_top + 30.0)
				{
					MbossHP_width -= 0.3; //0.3
				}
			}
		}
	}

	void contact_sword_monster2(void)
	{
		if (CheckKeyPressed[0])
		{
			if (CheckKeyPressed[2])
			{
				//When the player's sword touches the monster
				if (player.player_left + 100.0 > Mboss_left2 && player.player_left + 100.0 < Mboss_left2 + 30.0
					&& player.player_top + 10.0 > Mboss_top2 && player.player_top < Mboss_top2 + 30.0)
				{
					MbossHP_width2 -= 0.3; //0.3
				}
			}
		}
		if (CheckKeyPressed[1])
		{
			if (CheckKeyPressed[2])
			{
				//When the player's sword touches the monster,
				if (player.player_left - 50.0 < Mboss_left2 + 30.0 && player.player_left - 50.0 > Mboss_left2
					&& player.player_top + 10.0 > Mboss_top2 && player.player_top < Mboss_top2 + 30.0)
				{
					MbossHP_width2 -= 0.3; //0.3
				}
			}
		}
	}

	void contact_sword_monster3(void)
	{
		if (CheckKeyPressed[0])
		{
			if (CheckKeyPressed[2])
			{
				//When the player's sword touches the monster
				if (player.player_left + 100.0 > Mboss_left3 && player.player_left + 100.0 < Mboss_left3 + 30.0
					&& player.player_top + 10.0 > Mboss_top3 && player.player_top < Mboss_top3 + 30.0)
				{
					MbossHP_width3 -= 0.3; //0.3
				}
			}
		}
		if (CheckKeyPressed[1])
		{
			if (CheckKeyPressed[2])
			{
				//When the player's sword touches the monster,
				if (player.player_left - 50.0 < Mboss_left3 + 30.0 && player.player_left - 50.0 > Mboss_left3
					&& player.player_top + 10.0 > Mboss_top3 && player.player_top < Mboss_top3 + 30.0)
				{
					MbossHP_width3 -= 0.3; //0.3
				}
			}
		}
	}

	void contact_Msword_player1(void)
	{
		if (Mb_swordHP_width > 1.0)
		{
			if (player.player_left + 40.0 > Mb_sword_left && player.player_left + 40.0 < Mb_sword_left + 20.0
				&& player.player_top + 10.0 > Mboss_top && player.player_top < Mboss_top + 30.0)
			{
				push_settings();
				set_fill_color(155, 30, 30);
				draw_rectangle(-570, -359, 1190, 600);
				pop_settings();
				player.armorHP_width -= 1.0;
				if (player.armorHP_width < 0.0)
				{
					player.playerHP_width -= 2.0;
				}
				player.player_left -= 3.0;

				push_settings();
				no_outline();
				no_fill();
				draw_rectangle(Mb_sword_left, Mboss_top + 15.0, Mb_sword_width, Mb_sword_height);
				pop_settings();

;				draw_image(Mimage_monsterSword_left1, Mb_sword_left, Mboss_top + 5.0, Mb_sword_width, Mb_sword_height);
			}
			if (player.player_left < Mb_sword_left + 70.0 && player.player_left > Mb_sword_left + 50.0
				&& player.player_top + 10.0 > Mboss_top && player.player_top < Mboss_top + 30.0)
			{
				push_settings();
				set_fill_color(155, 30, 30);
				draw_rectangle(-570, -359, 1190, 600);
				pop_settings();
				player.armorHP_width -= 1.0;
				if (player.armorHP_width < 0.0)
				{
					player.playerHP_width -= 2.0;
				}
				player.player_left += 3.0;

				push_settings();
				no_outline();
				no_fill();
				draw_rectangle(Mb_sword_left + 50.0, Mboss_top + 15.0, Mb_sword_width, Mb_sword_height);
				pop_settings();
				draw_image(Mimage_monsterSword_right1, Mb_sword_left + 50.0, Mboss_top + 5.0, Mb_sword_width, Mb_sword_height);
			}
		}
	}

	void contact_Msword_player2(void)
	{
		if (Mb_swordHP_width2 > 1.0)
		{
			if (player.player_left + 40.0 > Mb_sword_left2 && player.player_left + 40.0 < Mb_sword_left2 + 20.0
				&& player.player_top + 10.0 > Mboss_top2 && player.player_top < Mboss_top2 + 30.0)
			{
				push_settings();
				set_fill_color(155, 30, 30);
				draw_rectangle(-570, -359, 1190, 600);
				pop_settings();
				player.armorHP_width -= 1.0;
				if (player.armorHP_width < 0.0)
				{
					player.playerHP_width -= 2.0;
				}
				player.player_left -= 3.0;

				push_settings();
				no_outline();
				no_fill();
				draw_rectangle(Mb_sword_left2, Mboss_top2 + 15.0, Mb_sword_width2, Mb_sword_height2);
				pop_settings();

				draw_image(Mimage_monsterSword_left2, Mb_sword_left2, Mboss_top2+5.0, Mb_sword_width2, Mb_sword_height2);
			}
			if (player.player_left < Mb_sword_left2 + 70.0 && player.player_left > Mb_sword_left2 + 50.0
				&& player.player_top + 10.0 > Mboss_top2 && player.player_top < Mboss_top2 + 30.0)
			{
				push_settings();
				set_fill_color(155, 30, 30);
				draw_rectangle(-570, -359, 1190, 600);
				pop_settings();
				player.armorHP_width -= 1.0;
				if (player.armorHP_width < 0.0)
				{
					player.playerHP_width -= 2.0;
				}
				player.player_left += 3.0;

				push_settings();
				no_outline();
				no_fill();
				draw_rectangle(Mb_sword_left2 + 50.0, Mboss_top2 + 15.0, Mb_sword_width2, Mb_sword_height2);
				pop_settings();


				draw_image(Mimage_monsterSword_right2, Mb_sword_left2 + 50.0, Mboss_top2+5.0, Mb_sword_width2, Mb_sword_height2);
			}
		}
	}

	void contact_Msword_player3(void)
	{
		if (Mb_swordHP_width3 > 1.0)
		{
			if (player.player_left + 40.0 > Mb_sword_left3 && player.player_left + 40.0 < Mb_sword_left3 + 20.0
				&& player.player_top + 10.0 > Mboss_top3 && player.player_top < Mboss_top3 + 30.0)
			{
				push_settings();
				set_fill_color(155, 30, 30);
				draw_rectangle(-570, -359, 1190, 600);
				pop_settings();
				player.armorHP_width -= 1.0;
				if (player.armorHP_width < 0.0)
				{
					player.playerHP_width -= 2.0;
				}
				player.player_left -= 3.0;

				push_settings();
				no_outline();
				no_fill();
				draw_rectangle(Mb_sword_left3, Mboss_top3 + 15.0, Mb_sword_width3, Mb_sword_height3);
				pop_settings();

				draw_image(Mimage_monsterSword_left3, Mb_sword_left3, Mboss_top3 + 5.0, Mb_sword_width3, Mb_sword_height3);
			}
			if (player.player_left < Mb_sword_left3 + 70.0 && player.player_left > Mb_sword_left3 + 50.0
				&& player.player_top + 10.0 > Mboss_top3 && player.player_top < Mboss_top3 + 30.0)
			{
				push_settings();
				set_fill_color(155, 30, 30);
				draw_rectangle(-570, -359, 1190, 600);
				pop_settings();
				player.armorHP_width -= 1.0;
				if (player.armorHP_width < 0.0)
				{
					player.playerHP_width -= 2.0;
				}
				player.player_left += 3.0;

				push_settings();
				no_outline();
				no_fill();
				draw_rectangle(Mb_sword_left3 + 50.0, Mboss_top3 + 15.0, Mb_sword_width3, Mb_sword_height3);
				pop_settings();

				draw_image(Mimage_monsterSword_right3, Mb_sword_left3 + 50.0, Mboss_top3 + 5.0, Mb_sword_width3, Mb_sword_height3);
			}
		}
	}

	void sword_vs_sword1(void)
	{
		if (Mb_swordHP_width > 1.0)
		{
			if (CheckKeyPressed[0])
			{
				if (CheckKeyPressed[2])
				{
					if (player.player_left + 40.0 > Mb_sword_left - 40 && player.player_left + 40.0 < Mb_sword_left - 20
						&& player.player_top + 10.0 > Mboss_top && player.player_top < Mboss_top + 30.0)
					{
						Mb_swordHP_width -= 15.0;
						player.player_left -= 30.0;

						push_settings();
						no_outline();
						no_fill();
						draw_rectangle(Mb_sword_left, Mboss_top + 15.0, Mb_sword_width, Mb_sword_height);
						pop_settings();

						draw_image(Mimage_monsterSword_left1, Mb_sword_left, Mboss_top + 5.0, Mb_sword_width, Mb_sword_height);
					}
				}
			}
			if (CheckKeyPressed[1])
			{
				if (CheckKeyPressed[2])
				{
					if (player.player_left - 40.0 > Mb_sword_left + 50 && player.player_left - 40.0 < Mb_sword_left + 70
						&& player.player_top + 10.0 > Mboss_top && player.player_top < Mboss_top + 30.0)
					{
						Mb_swordHP_width -= 15.0;
						player.player_left += 30.0;

						push_settings();
						no_outline();
						no_fill();
						draw_rectangle(Mb_sword_left + 50.0, Mboss_top + 15.0, Mb_sword_width, Mb_sword_height);
						pop_settings();

						draw_image(Mimage_monsterSword_right1, Mb_sword_left + 50.0, Mboss_top + 5.0, Mb_sword_width, Mb_sword_height);
					}
				}
			}
		}
		draw_rectangle(Mb_swordHP_left, Mb_swordHP_top, Mb_swordHP_width, Mb_swordHP_height);
	}

	void sword_vs_sword2(void)
	{
		if (Mb_swordHP_width2 > 1.0)
		{
			if (CheckKeyPressed[0])
			{
				if (CheckKeyPressed[2])
				{
					if (player.player_left + 40.0 > Mb_sword_left2 - 40 && player.player_left + 40.0 < Mb_sword_left2 - 20
						&& player.player_top + 10.0 > Mboss_top2 && player.player_top < Mboss_top2 + 30.0)
					{
						Mb_swordHP_width2 -= 15.0;
						player.player_left -= 30.0;

						push_settings();
						no_outline();
						no_fill();
						draw_rectangle(Mb_sword_left2, Mboss_top2 + 15.0, Mb_sword_width2, Mb_sword_height2);
						pop_settings();

						draw_image(Mimage_monsterSword_left2, Mb_sword_left2, Mboss_top2 + 5.0, Mb_sword_width2, Mb_sword_height2);
					}
				}
			}
			if (CheckKeyPressed[1])
			{
				if (CheckKeyPressed[2])
				{
					if (player.player_left - 40.0 > Mb_sword_left2 + 50 && player.player_left - 40.0 < Mb_sword_left2 + 70
						&& player.player_top + 10.0 > Mboss_top2 && player.player_top < Mboss_top2 + 30.0)
					{
						Mb_swordHP_width2 -= 15.0;
						player.player_left += 30.0;

						push_settings();
						no_outline();
						no_fill();
						draw_rectangle(Mb_sword_left2 + 50.0, Mboss_top2 + 15.0, Mb_sword_width2, Mb_sword_height2);
						pop_settings();

						draw_image(Mimage_monsterSword_right2, Mb_sword_left2 + 50.0, Mboss_top2 + 5.0, Mb_sword_width2, Mb_sword_height2);
					}
				}
			}
		}
		draw_rectangle(Mb_swordHP_left2, Mb_swordHP_top2, Mb_swordHP_width2, Mb_swordHP_height2);
	}

	void sword_vs_sword3(void)
	{
		if (Mb_swordHP_width3 > 1.0)
		{
			if (CheckKeyPressed[0])
			{
				if (CheckKeyPressed[2])
				{
					if (player.player_left + 40.0 > Mb_sword_left3 - 40 && player.player_left + 40.0 < Mb_sword_left3 - 20
						&& player.player_top + 10.0 > Mboss_top3 && player.player_top < Mboss_top3 + 30.0)
					{
						Mb_swordHP_width3 -= 15.0;
						player.player_left -= 30.0;

						push_settings();
						no_outline();
						no_fill();
						draw_rectangle(Mb_sword_left3, Mboss_top3 + 15.0, Mb_sword_width3, Mb_sword_height3);
						pop_settings();

						draw_image(Mimage_monsterSword_left3, Mb_sword_left3, Mboss_top3 + 5.0, Mb_sword_width3, Mb_sword_height3);
					}
				}
			}
			if (CheckKeyPressed[1])
			{
				if (CheckKeyPressed[2])
				{
					if (player.player_left - 40.0 > Mb_sword_left3 + 50 && player.player_left - 40.0 < Mb_sword_left3 + 70
						&& player.player_top + 10.0 > Mboss_top3 && player.player_top < Mboss_top3 + 30.0)
					{
						Mb_swordHP_width3 -= 15.0;
						player.player_left += 30.0;

						push_settings();
						no_outline();
						no_fill();
						draw_rectangle(Mb_sword_left3 + 50.0, Mboss_top3 + 15.0, Mb_sword_width3, Mb_sword_height3);
						pop_settings();

						draw_image(Mimage_monsterSword_right3, Mb_sword_left3 + 50.0, Mboss_top3 + 5.0, Mb_sword_width3, Mb_sword_height3);
					}
				}
			}
		}
		draw_rectangle(Mb_swordHP_left3, Mb_swordHP_top3, Mb_swordHP_width3, Mb_swordHP_height3);
	}
};
MINI_BOSS mini_boss;