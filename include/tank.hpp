#pragma once

#include <iostream>

#include <include/transform.hpp>

class Tank
{
public:
    Transform Transform;
    Vector2 Velocity;
    Vector2 bulletPos;

    Tank();
    void Update();
    void Fire();
};