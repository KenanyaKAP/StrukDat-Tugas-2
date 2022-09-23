#pragma once

#include <iostream>
#include <graphics.h>

#include <include/vector2.hpp>

struct Lines
{
    Vector2 start;
    Vector2 end;
    int color;
    Lines(Vector2 start, Vector2 end, int color = 15);
    Lines(float startX, float startY, float endX, float endY, int color = 15);
};
