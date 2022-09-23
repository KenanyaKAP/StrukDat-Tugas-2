#include <iostream>
#include <graphics.h>

#include <include/pesawat.hpp>

#include <include/utils.hpp>
#include <include/lines.hpp>
#include <include/vector2.hpp>
#include <include/transform.hpp>

Pesawat::Pesawat()
{
    this->Transform.graphicLines.push_back(Lines(0, -3.85, .18, -3.45));
    this->Transform.graphicLines.push_back(Lines(.18, -3.45, .33, -3.4));
    this->Transform.graphicLines.push_back(Lines(.33, -3.4, .44, -3.2));
    this->Transform.graphicLines.push_back(Lines(.44, -3.2, .577, -2.4));
    this->Transform.graphicLines.push_back(Lines(.577, -2.4, .6, -0));
    this->Transform.graphicLines.push_back(Lines(.6, -0, .25, 2.4));
    this->Transform.graphicLines.push_back(Lines(.25, 2.4, 1.7, 2.6));
    this->Transform.graphicLines.push_back(Lines(1.7, 2.6, 1.7, 3.5));
    this->Transform.graphicLines.push_back(Lines(1.7, 3.5, 0, 3.5));
    
    this->Transform.graphicLines.push_back(Lines(-0, -3.85, -.18, -3.45));
    this->Transform.graphicLines.push_back(Lines(-.18, -3.45, -.33, -3.4));
    this->Transform.graphicLines.push_back(Lines(-.33, -3.4, -.44, -3.2));
    this->Transform.graphicLines.push_back(Lines(-.44, -3.2, -.577, -2.4));
    this->Transform.graphicLines.push_back(Lines(-.577, -2.4, -.6, -0));
    this->Transform.graphicLines.push_back(Lines(-.6, -0, -.25, 2.4));
    this->Transform.graphicLines.push_back(Lines(-.25, 2.4, -1.7, 2.6));
    this->Transform.graphicLines.push_back(Lines(-1.7, 2.6, -1.7, 3.5));
    this->Transform.graphicLines.push_back(Lines(-1.7, 3.5, -0, 3.5));

    this->Transform.graphicLines.push_back(Lines(.58, -1.7, 5, -1.7));
    this->Transform.graphicLines.push_back(Lines(5, -1.7, 5, -.5));
    this->Transform.graphicLines.push_back(Lines(5, -.5, .6, -0));

    this->Transform.graphicLines.push_back(Lines(-.58, -1.7, -5, -1.7));
    this->Transform.graphicLines.push_back(Lines(-5, -1.7, -5, -.5));
    this->Transform.graphicLines.push_back(Lines(-5, -.5, -.6, -0));

    this->Transform.Scale = Vector2(10, 10);
}

void Pesawat::Update()
{
    this->Transform.Position += utils::Rotate(Velocity, this->Transform.Rotation);
    this->Transform.Position = utils::Snap(this->Transform.Position, Vector2(0, 0), Vector2(getmaxx(), getmaxy()));

    this->Transform.Rotation += this->rotateSpeed;

    this->Transform.DrawLines();
}