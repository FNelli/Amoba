#include "kijelzo.hpp"
#include <sstream>
using namespace genv;

Kijelzo::Kijelzo(int x, int y, int sx, int sy/*, std::string nev1, std::string nev2, int elsop, int masodikp*/)
    : Widget(x,y,sx,sy)
{
}

void Kijelzo::draw(int nemkell) const
{
    gout << move_to(_x,_y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+4, _y+20) << color(255,255,255) << text(_elsonev + ": " + _elsop);
    gout << move_to(_x+4, _y+50) << text(_masodiknev + ": " + _masodikp);
}


