//---------------------------------------------------------
// file:	Sketch.h
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// Copyright © 2021 DigiPen, All rights reserved.
//---------------------------------------------------------
#pragma once
#include <SFML/Audio.hpp>
#include <doodle/image.hpp>
#include <vector>

class Sketch
{
public:
    struct Ball
    {
        double x{ 0 }, y{ 0 }, xSpeed{ 0 }, ySpeed{ 0 };
    };

public:
    void setup();
    void draw();

private:
    constexpr static float       RADIUS{ 30.0 };
    doodle::Image                logo{};
    std::vector<sf::SoundBuffer> soundBuffers{};
    std::vector<sf::Sound>       sounds{};
    sf::Music                    music;
    std::vector<Ball>            balls;

private:
    void DrawAndUpdateBall(Ball& ball);
    void LoadSound(const std::string& file_path);
    void PlaySound();
};
