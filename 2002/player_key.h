﻿// Filename : <player_key.h>
// Authors : <Hyunjun Lee, Dawoon Jung, Geumbi Yeo>
// Course : GAM100F21
// All content © 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <doodle/doodle.hpp>
using namespace doodle;

bool CheckKeyPressed[6];

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
    if (button == KeyboardButtons::Space)
    {
        CheckKeyPressed[5] = true;
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
    if (button == KeyboardButtons::Space)
    {
        CheckKeyPressed[5] = false;
    }
}