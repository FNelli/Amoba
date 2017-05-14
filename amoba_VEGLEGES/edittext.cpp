#include "widgets.hpp"
#include "graphics.hpp"
#include "edittext.hpp"

#include <vector>
using namespace genv;

EditText::EditText(int x, int y, int sx, int sy, string szoveg)
    : Widget(x,y,sx,sy)
{
    _szoveg = szoveg;
}

void EditText::draw(int tikktakk) const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(40,40,40) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+6, _y+7+gout.cascent()) << color(255,255,255) << text(_szoveg);

    if (_checked) {
        if (tikktakk%2) {
            gout << move_to(_x+8 + gout.twidth(_szoveg), _y + 7) << color(255,255,255) << line(0,15);
        } else {
            gout << move_to(_x+8 + gout.twidth(_szoveg), _y + 7) << color(40,40,40) << line(0,15);
        }
    } else {
        gout << move_to(_x+8 + gout.twidth(_szoveg), _y + 7) << color(40,40,40) << line(0,15);
    }
}

string EditText::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = 1;
    }
    if (ev.type == ev_mouse && !is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = 0;
    }

    if(ev.type == ev_key && ev.keycode >= ' ' && ev.keycode <= '~') {
        if (_szoveg.length()<10) {
            _szoveg.append((char*)&ev.keycode);
        }
    }
    if(ev.type == ev_key && ev.keycode == 8 ){
        _szoveg = _szoveg.substr(0,_szoveg.length()-1);
    }
    return _szoveg;
}

