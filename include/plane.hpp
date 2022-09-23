#pragma once

#include <iostream>

#include <include/transform.hpp>

class Plane
{
public:
    Transform Transform;
    Vector2 Velocity;
    Vector2 bulletPos;

    Plane();
    void Update();
    void Fire();
};