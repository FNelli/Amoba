#include "examplecheckbox.hpp"
#include "graphics.hpp"
#include "statictext.hpp"
using namespace genv;

StaticText::StaticText(int x, int y, int sx, int sy, string szoveg)
    : Widget(x,y,sx,sy)
{
    _szoveg = szoveg;
}

void StaticText::draw(int tikktakk) const
{
    gout << move_to(_x+6, _y+7+gout.cascent()) << color(255,255,255) << text(_szoveg);
}
