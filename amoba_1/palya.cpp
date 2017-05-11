#include "graphics.hpp"
#include "palya.hpp"
#include "examplecheckbox.hpp"
#include <iostream>
#include <vector>

using namespace genv;
using namespace std;

Palya::Palya(vector<vector<Widget*>> w, int x, int y, int m)
{
    _x = x;
    _y = y;
    _meret = m;
    for (int i=0; i<(int)y/m; i++){
        vector<Widget*> proba;
        for(int e=0; e<(int)x/m; e++) {
            ExampleCheckBox* _ecb = new ExampleCheckBox(e*m,i*m,m,m);
            proba.push_back(_ecb);
        }
        _palya.push_back(proba);
    }
}


void Palya::event_loop()
{
    gout.open(_x,_y);
    event ev;
    int focus_y = -1;
    int focus_x = -1;
    int lepesek = 0;
    while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left && ev.button > 0) {
            for (size_t i=0; i<(int)_y/_meret; i++) {
                for (size_t e=0; e<(int)_x/_meret; e++) {
                    if (_palya[e][i]->is_selected(ev.pos_x, ev.pos_y) && _palya[e][i]->_checked == false) {
                            focus_x = e;
                            focus_y = i;
                            _palya[e][i]->_checked = true;
                            lepesek++;
                    }
                }
            }
        }
        if (focus_x != -1 && focus_y != -1) {
            _palya[focus_x][focus_y]->is_checked(lepesek%2+1);
        }
        for (int i=0; i<(int)_y/_meret; i++) {
            for (int e=0; e<(int)_x/_meret; e++) {
                _palya[e][i]->draw();
            }
        }
        gout << refresh;
    }
}

