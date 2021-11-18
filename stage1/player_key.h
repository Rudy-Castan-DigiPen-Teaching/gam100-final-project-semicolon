#pragma once
#include <doodle/doodle.hpp>
using namespace doodle;

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