#include "pucolo.hpp"

using namespace genv;

Pucolo::Pucolo(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy) {}

void Pucolo::draw(int nemkell) const
{
    gout << move_to(_x,_y) << color(0,0,0) << box(_size_x, _size_y);
}
