#include <iostream>
#include <include/vector2.hpp>

using namespace std;

Vector2::Vector2()
{
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator+(const Vector2 &rhs) const
{
    Vector2 temp;
    temp.x = this->x + rhs.x;
    temp.y = this->y + rhs.y;
    return temp;
}

Vector2 Vector2::operator-(const Vector2 &rhs) const
{
    Vector2 temp;
    temp.x = this->x - rhs.x;
    temp.y = this->y - rhs.y;
    return temp;
}

Vector2 Vector2::operator*(const Vector2 &rhs) const
{
    Vector2 temp;
    temp.x = this->x * rhs.x;
    temp.y = this->y * rhs.y;
    return temp;
}

Vector2 Vector2::operator*(const float &value) const
{
    Vector2 temp;
    temp.x = this->x * value;
    temp.y = this->y * value;
    return temp;
}

Vector2 Vector2::operator/(const Vector2 &rhs) const
{
    Vector2 temp;
    temp.x = this->x / rhs.x;
    temp.y = this->y / rhs.y;
    return temp;
}

Vector2 Vector2::operator/(const float &value) const
{
    Vector2 temp;
    temp.x = this->x / value;
    temp.y = this->y / value;
    return temp;
}

void Vector2::operator+=(const Vector2 &rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
}

void Vector2::operator-=(const Vector2 &rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
}

void Vector2::operator*=(const Vector2 &rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;
}

void Vector2::operator*=(const float &value)
{
    this->x *= value;
    this->y *= value;
}

void Vector2::operator/=(const Vector2 &rhs)
{
    this->x /= rhs.x;
    this->y /= rhs.y;
}

void Vector2::operator/=(const float &value)
{
    this->x /= value;
    this->y /= value;
}