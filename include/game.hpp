#pragma once

#include <iostream>

#include <include/game.hpp>
#include <include/pesawat.hpp>
#include <include/plane.hpp>
#include <include/tank.hpp>

#include <include/utils.hpp>
#include <include/lines.hpp>
#include <include/vector2.hpp>
#include <include/transform.hpp>

Pesawat musuh1;
Plane enemy0;
Plane enemy1;
Plane enemy2;
Plane enemy3;
Plane enemy4;
Tank player;

namespace game
{
    void Start();
    void Update();
} // namespace game
