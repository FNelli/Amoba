#include "palya.hpp"
#include "x_kor.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Palya::Palya(vector<vector<Widget*>> w, int x, int y, int m) :
    _x(x),
    _y(y),
    _meret(m),
    _jatekallas((int)x/m, vector<int>((int)y/m, 0))
{
    for(int e=0; e<(int)x/m; e++) {
        vector<Widget*> proba;
        for (int i=0; i<(int)y/m; i++){
            X_kor* _ecb = new X_kor(e*m,i*m,m,m);
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
    int nyertes = 0;
    while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left && ev.button > 0 && !nyertes) {
            for (int i=0; i<(int)_y/_meret; i++) {
                for (int e=0; e<(int)_x/_meret; e++) {
                    if (_palya[e][i]->is_selected(ev.pos_x, ev.pos_y) && _palya[e][i]->_jatekos == 0 && !nyertes) {
                        focus_x = e;
                        focus_y = i;
                        _palya[e][i]->_jatekos = lepesek%2+1;
                        _jatekallas[e][i] = lepesek%2+1;
                        nyertes = jatekvege(_jatekallas,e,i,lepesek%2+1);
                        if (nyertes) {
                            cout << "nyertes: " << nyertes << " jupi";
                            /// ha vege a jateknak akkor ki kell irni majd az eredmenyeket
                        }
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

