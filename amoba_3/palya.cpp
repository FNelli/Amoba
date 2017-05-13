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
            X_kor* xk = new X_kor(e*m,i*m,m,m);
            proba.push_back(xk);
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
    int lepesek = -1;
    vector<int> nyertes;
    while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left && ev.button > 0 && nyertes.size()<2) {
            for (int i=0; i<(int)_y/_meret; i++) {
                for (int e=0; e<(int)_x/_meret; e++) {
                    if (_palya[e][i]->is_selected(ev.pos_x, ev.pos_y) && _palya[e][i]->_jatekos == 0 && nyertes.size()<2) {
                        lepesek++;
                        focus_x = e;
                        focus_y = i;
                        _palya[e][i]->_jatekos = lepesek%2+1;
                        _jatekallas[e][i] = lepesek%2+1;
                        nyertes = jatekvege(_jatekallas,e,i,lepesek%2+1);
                        if (nyertes.size()>1) {
                            cout << "nyertes: " << nyertes[nyertes.size()-1] << " jupi";
                            for (int e=0; e<nyertes.size()-1; e=e+2){
                                _palya[nyertes[e]][nyertes[e+1]]->draw(nyertes[nyertes.size()-1]);
                            }
                        }
                    }
                }
            }
        }
        if (focus_x != -1 && focus_y != -1) {
            _palya[focus_x][focus_y]->is_checked(lepesek%2+1);
        }
        if (nyertes.size()<2) {
            for (int e=0; e<(int)_x/_meret; e++){
                for (int i=0; i<(int)_y/_meret; i++) {
                    _palya[e][i]->draw(0);
                }
            }
        }
        gout << refresh;
    }
}

