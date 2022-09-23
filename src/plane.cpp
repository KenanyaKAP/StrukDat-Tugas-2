#include <iostream>
#include <conio.h>
#include <graphics.h>

#include <include/plane.hpp>

#include <include/utils.hpp>
#include <include/lines.hpp>
#include <include/vector2.hpp>
#include <include/transform.hpp>

Plane::Plane()
{
    this->Transform.graphicLines.push_back(Lines(-1, .9, -2, .5));
    this->Transform.graphicLines.push_back(Lines(-2, .5, -3.8, .6));
    this->Transform.graphicLines.push_back(Lines(-3.8, .6, -3.5, -0));
    this->Transform.graphicLines.push_back(Lines(-3.5, -0, -3.65, -1.46));
    this->Transform.graphicLines.push_back(Lines(-3.65, -1.46, -3.2, -1.46));
    this->Transform.graphicLines.push_back(Lines(-3.2, -1.46, -1.9, -.3));
    this->Transform.graphicLines.push_back(Lines(-1.9, -.3, 2.15, -.5));
    this->Transform.graphicLines.push_back(Lines(2.15, -.5, 2.6, -.5));
    this->Transform.graphicLines.push_back(Lines(2.6, -.5, 2.8, -.47));
    this->Transform.graphicLines.push_back(Lines(2.8, -.47, 3, -.4));
    this->Transform.graphicLines.push_back(Lines(3, -.4, 3.2, -.27));
    this->Transform.graphicLines.push_back(Lines(3.2, -.27, 3.4, -.04));
    this->Transform.graphicLines.push_back(Lines(3.4, -.04, 3.5, .2));
    this->Transform.graphicLines.push_back(Lines(3.5, .2, 4.2, .5));
    this->Transform.graphicLines.push_back(Lines(4.2, .5, 3.5, .9));
    this->Transform.graphicLines.push_back(Lines(3.5, .9, 2, 1.2));
    this->Transform.graphicLines.push_back(Lines(2, 1.2, 1, 1.3));
    this->Transform.graphicLines.push_back(Lines(1, 1.3, 0, 1.3));

    this->Transform.graphicLines.push_back(Lines(-.5, .5, -1.75, 1.5));
    this->Transform.graphicLines.push_back(Lines(-1.75, 1.5, -.8, 1.5));
    this->Transform.graphicLines.push_back(Lines(-.8, 1.5, -.6, 1.48));
    this->Transform.graphicLines.push_back(Lines(-.6, 1.48, -.4, 1.44));
    this->Transform.graphicLines.push_back(Lines(-.4, 1.44, -.2, 1.39));
    this->Transform.graphicLines.push_back(Lines(-.2, 1.39, 0, 1.32));
    this->Transform.graphicLines.push_back(Lines(0, 1.32, .2, 1.25));
    this->Transform.graphicLines.push_back(Lines(.2, 1.25, 1.5, 0.7));

    this->Velocity = Vector2(rand() % 10 + 10, 0);

    this->Transform.Scale = Vector2(rand() % 5 + 12, rand() % 5 + 12);
}

void Plane::Update()
{
    this->Transform.Position += this->Velocity;
    this->Transform.Position = utils::Snap(this->Transform.Position, Vector2(0, 0), Vector2(getmaxx(), getmaxy()));

    this->Transform.DrawLines();

    if (rand()%90 == 0)
    {
        Fire();
    }

    circle(bulletPos.x, bulletPos.y, 5);
    bulletPos.y += 10;
}

void Plane::Fire()
{
    bulletPos = this->Transform.Position;
}