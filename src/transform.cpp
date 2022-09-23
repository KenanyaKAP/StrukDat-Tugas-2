#include <iostream>
#include <vector>
#include <graphics.h>
#include <math.h>

#include <include/utils.hpp>
#include <include/transform.hpp>
#include <include/vector2.hpp>
#include <include/lines.hpp>

Transform::Transform()
{
    this->Position = Vector2(0, 0);
    this->Rotation = 0;
    this->Scale = Vector2(1, 1);
}

void Transform::DrawLines()
{
    Rotation = fmodf(Rotation, 360);
    for (Lines l : this->graphicLines)
    {
        setcolor(l.color);
        line(
            utils::Rotate(l.start * this->Scale, this->Rotation).x + Position.x,
            utils::Rotate(l.start * this->Scale, this->Rotation).y + Position.y,
            utils::Rotate(l.end * this->Scale, this->Rotation).x + Position.x,
            utils::Rotate(l.end * this->Scale, this->Rotation).y + Position.y
        );
    }
}