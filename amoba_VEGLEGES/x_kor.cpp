#include "x_kor.hpp"
#include <iostream>
#include <cmath>
using namespace genv;

X_kor::X_kor(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy) {}

void X_kor::is_checked(int jatekos)
{
    _checked = jatekos;
}


void X_kor::draw(int nyert) const
{
    gout << move_to(_x, _y) << color(0,0,0) << box(_size_x, _size_y);
    gout << move_to(_x+1, _y+1) << color(255-nyert*152.5,255,255-nyert*50) << box(_size_x-2, _size_y-2);
    if (_checked == 1) {
        gout << color(0,0,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
    if (_checked == 2) {
        int center_x = _x+_size_x/2;
        int center_y = _y+_size_y/2;
        int r = _size_x/2-3;
        gout << color(0,0,0);
        for (int x=center_x-r; x<center_x+r; ++x) {
            for (int y=center_y-r; y<center_y+r; ++y) {
                if(pow(x-center_x,2)+pow(y-center_y,2)<pow(r,2)){
                    gout << move_to(x,y) << dot;
                }
            }
        }
        r-=2;
        gout << color(255-nyert*152.5,255,255-nyert*50);
        for (int x=center_x-r; x<center_x+r; ++x) {
            for (int y=center_y-r; y<center_y+r; ++y) {
                if(pow(x-center_x,2)+pow(y-center_y,2)<pow(r,2)){
                    gout << move_to(x,y) << dot;
                }
            }
        }
    }
}

