#include <iostream>
#include <include/vector2.hpp>
#include <include/lines.hpp>

Lines::Lines(Vector2 start, Vector2 end, int color)
:start(start), end(end), color(color){}

Lines::Lines(float startX, float startY, float endX, float endY, int color)
:start(startX, startY), end(endX, endY), color(color){}