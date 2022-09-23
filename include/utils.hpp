#pragma once

#include <iostream>

struct Vector2;

namespace utils
{
    Vector2 Rotate(Vector2 v, float angle);
    float Snap(float v, float min, float max);
    Vector2 Snap(Vector2 v, Vector2 min, Vector2 max);
    float Clamp(float v, float min, float max);
    Vector2 Clamp(Vector2 v, Vector2 min, Vector2 max);
} // namespace utils
