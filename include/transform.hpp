#pragma once

#include <iostream>
#include <vector>
#include <include/vector2.hpp>
#include <include/lines.hpp>

struct Transform
{
    Vector2 Position;
    float Rotation;
    Vector2 Scale;
    std::vector<Lines> graphicLines;
    Transform();
    void DrawLines();
};