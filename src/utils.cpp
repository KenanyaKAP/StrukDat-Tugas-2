#include <iostream>
#include <math.h>

#include <include/utils.hpp>
#include <include/vector2.hpp>

#define M_PI 3.14159265358979323846

Vector2 utils::Rotate(Vector2 v, float angle)
{
    Vector2 temp;
    temp.x = (cosf(angle * (M_PI / 180)) * v.x + (-sinf(angle * (M_PI / 180))) * v.y);
    temp.y = (cosf(angle * (M_PI / 180)) * v.y + sinf(angle * (M_PI / 180)) * v.x);
    return temp;
}

float utils::Snap(float v, float min, float max)
{
    if (v < min) return max;
    if (v > max) return min;
    return v;
}

Vector2 utils::Snap(Vector2 v, Vector2 min, Vector2 max)
{
    Vector2 temp;
    temp.x = utils::Snap(v.x, min.x, max.x);
    temp.y = utils::Snap(v.y, min.y, max.y);
    return temp;
}

float utils::Clamp(float v, float min, float max)
{
    if (v < min) return min;
    if (v > max) return max;
    return v;
}

Vector2 utils::Clamp(Vector2 v, Vector2 min, Vector2 max)
{
    Vector2 temp;
    temp.x = utils::Clamp(v.x, min.x, max.x);
    temp.y = utils::Clamp(v.y, min.y, max.y);
    return temp;
}