#include "palya.hpp"
#include "x_kor.hpp"
#include "edittext.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Palya::Palya(vector<vector<Widget*>> w, int x, int y, int m) :
    _x(x),
    _y(y),
    _meret(m),
    _jatekallas((int)x/m, vector<int>((int)y/m, 0))
{
    _jatekos1 = "";
    _jatekos2 = "";

    Widget* szovegd1 = new EditText(_x/2-60, _y/2-40, 120, 30, "jatekos1");
    Widget* szovegd2 = new EditText(_x/2-60, _y/2+10, 120, 30, "jatekos2");
    _wid_vector.push_back(szovegd1);
    _wid_vector.push_back(szovegd2);

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
    int focus = -1;
    int lepesek = -1;
    vector<int> nyertes;
    bool start = false;
    gin.timer(600);
    int tikktakk = 0;

    while(gin >> ev && ev.keycode != key_escape) {
        if (!start) {
            if (ev.type == 3) {
                tikktakk++;
            }
            if (ev.type == ev_mouse && ev.button==btn_left) {
                for (size_t i=0;i<_wid_vector.size();i++) {
                    if (_wid_vector[i]->is_selected(ev.pos_x, ev.pos_y)) {
                            focus = i;
                    }
                }
            }
            if (focus!=-1) {
                _wid_vector[focus]->_jatekos = 1;
                _wid_vector[focus]->handle(ev);
            }
            for (size_t i=0; i<_wid_vector.size(); i++) {
                if (i != focus) {
                    _wid_vector[i]->_jatekos = 0;
                }
                _wid_vector[i]->draw(tikktakk);
            }
            if (ev.type == ev_key && ev.keycode == key_enter) {
                _jatekos1 = _wid_vector[0]->handle(ev);
                _jatekos2 = _wid_vector[1]->handle(ev);
                start = true;
            }
        }


        if (start) {
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
                                for (int e=0; e<nyertes.size()-1; e=e+2){
                                    _palya[nyertes[e]][nyertes[e+1]]->draw(nyertes[nyertes.size()-1]);
                                }
                                if (nyertes.size()-1 == 1) {
                                    cout << _jatekos1 << " nyert.";
                                } else {
                                    cout << _jatekos2 << " nyert.";
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
        }
        /// PALYA URITES
        if (ev.type == ev_key && ev.keycode == key_backspace) {
            vector<vector<Widget*>> v;
            for(int e=0; e<(int)_x/_meret; e++) {
                vector<Widget*> proba;
                for (int i=0; i<(int)_y/_meret; i++){
                    X_kor* xk = new X_kor(e*_meret,i*_meret,_meret,_meret);
                    proba.push_back(xk);
                }
                v.push_back(proba);
            }
            _palya = v;
            vector<vector<int>> ures1((int)_x/_meret, vector<int>((int)_y/_meret, 0));
            _jatekallas = ures1;
            vector<int> ures2;
            nyertes = ures2;
        }
        gout << refresh;
    }
}

