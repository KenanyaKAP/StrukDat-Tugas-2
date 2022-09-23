#pragma once

#include <iostream>

struct Vector2
{
    float x;
    float y;
    Vector2();
    Vector2(float x, float y);
    Vector2 operator+(const Vector2 &rhs) const;
    Vector2 operator-(const Vector2 &rhs) const;
    Vector2 operator*(const Vector2 &rhs) const;
    Vector2 operator*(const float &value) const;
    Vector2 operator/(const Vector2 &rhs) const;
    Vector2 operator/(const float &value) const;
    void operator+=(const Vector2 &rhs);
    void operator-=(const Vector2 &rhs);
    void operator*=(const Vector2 &rhs);
    void operator*=(const float &value);
    void operator/=(const Vector2 &rhs);
    void operator/=(const float &value);
};
