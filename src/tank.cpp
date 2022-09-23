#include <iostream>
#include <graphics.h>
#include <conio.h>

#include <include/tank.hpp>

#include <include/utils.hpp>
#include <include/lines.hpp>
#include <include/vector2.hpp>
#include <include/transform.hpp>

Tank::Tank()
{
    this->Transform.graphicLines.push_back(Lines(0, -2.15, 3, -2.15));
    this->Transform.graphicLines.push_back(Lines(3, -2.15, 3.4, -1.6));
    this->Transform.graphicLines.push_back(Lines(3.4, -1.6, 3.8, -1.6));
    this->Transform.graphicLines.push_back(Lines(3.8, -1.6, 3.8, -2.15));
    this->Transform.graphicLines.push_back(Lines(3.8, -2.15, 3, -3.15));
    this->Transform.graphicLines.push_back(Lines(3, -3.15, 0, -3.15));

    this->Transform.graphicLines.push_back(Lines(-0, -2.15, -3, -2.15));
    this->Transform.graphicLines.push_back(Lines(-3, -2.15, -3.4, -1.6));
    this->Transform.graphicLines.push_back(Lines(-3.4, -1.6, -3.8, -1.6));
    this->Transform.graphicLines.push_back(Lines(-3.8, -1.6, -3.8, -2.15));
    this->Transform.graphicLines.push_back(Lines(-3.8, -2.15, -3, -3.15));
    this->Transform.graphicLines.push_back(Lines(-3, -3.15, -0, -3.15));

    this->Transform.graphicLines.push_back(Lines(2.5, -3.15, 2.5, -4));
    this->Transform.graphicLines.push_back(Lines(2.5, -4, 2, -4.5));
    this->Transform.graphicLines.push_back(Lines(2, -4.5, .2, -4.5));
    this->Transform.graphicLines.push_back(Lines(.2, -4.5, .2, -5));
    this->Transform.graphicLines.push_back(Lines(.2, -5, .4, -5));
    this->Transform.graphicLines.push_back(Lines(.4, -5, .4, -5.5));
    this->Transform.graphicLines.push_back(Lines(.4, -5.5, 0, -5.5));

    this->Transform.graphicLines.push_back(Lines(-2.5, -3.15, -2.5, -4));
    this->Transform.graphicLines.push_back(Lines(-2.5, -4, -2, -4.5));
    this->Transform.graphicLines.push_back(Lines(-2, -4.5, -.2, -4.5));
    this->Transform.graphicLines.push_back(Lines(-.2, -4.5, -.2, -5));
    this->Transform.graphicLines.push_back(Lines(-.2, -5, -.4, -5));
    this->Transform.graphicLines.push_back(Lines(-.4, -5, -.4, -5.5));
    this->Transform.graphicLines.push_back(Lines(-.4, -5.5, -0, -5.5));

    this->Transform.Scale = Vector2(10, 10);
}

char c;

void Tank::Update()
{
    this->Transform.Position = utils::Clamp(this->Transform.Position, Vector2(0, 0), Vector2(getmaxx(), getmaxy()));

    circle(0 * this->Transform.Scale.x + this->Transform.Position.x, -1 * this->Transform.Scale.x + this->Transform.Position.y, .8 * this->Transform.Scale.x);
    circle(-2.1 * this->Transform.Scale.x + this->Transform.Position.x, -1 * this->Transform.Scale.x + this->Transform.Position.y, .8 * this->Transform.Scale.x);
    circle(2.1 * this->Transform.Scale.x + this->Transform.Position.x, -1 * this->Transform.Scale.x + this->Transform.Position.y, .8 * this->Transform.Scale.x);
    this->Transform.DrawLines();

    circle(bulletPos.x, bulletPos.y, 5);
    bulletPos.y -= 20;
}

void Tank::Fire()
{
    bulletPos = this->Transform.Position;
}