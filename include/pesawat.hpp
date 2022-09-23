#pragma once

#include <iostream>

#include <include/transform.hpp>

class Pesawat
{
public:
    Transform Transform;
    Vector2 Velocity;
    float rotateSpeed;

    Pesawat();
    void Update();
};