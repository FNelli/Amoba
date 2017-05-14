#include "palya.hpp"
#include "x_kor.hpp"
#include "pucolo.hpp"

#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;

Palya::Palya(vector<vector<Widget*>> w, int x, int y, int m) :
    _x(x),
    _y(y),
    _meret(m),
    _jatekallas((int)x/m, vector<int>((int)y/m, 0)),
    _menu(x, y, m)
{
    _jatekos1 = "";
    _jatekos2 = "";
    _jatekos1pont = 0;
    _jatekos2pont = 0;

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
    int tikktakk = 0;
    int varj = 0;

    bool keslelteto = true;
    bool elsokor = true;
    bool start = false;
    bool korvege = false;

    vector<int> nyertes;
    gin.timer(600);

    while(gin >> ev && ev.keycode != key_escape) {

        /// KEZDOKEPERNYO - MENU
        if (!start && elsokor) {
            _menu._pucolo->draw(0);
            if (ev.type == 3) {
                tikktakk++;
            }
            if (ev.type == ev_mouse && ev.button==btn_left) {
                for (size_t i=0;i<_menu._startmenu.size();i++) {
                    if (_menu._startmenu[i]->is_selected(ev.pos_x, ev.pos_y)) {
                            focus = i;
                    }
                }
            }
            if (focus!=-1) {
                _menu._startmenu[focus]->_jatekos = 1;
                _menu._startmenu[focus]->handle(ev);
            }
            for (size_t i=0; i<_menu._startmenu.size(); i++) {
                if (i != focus) {
                    _menu._startmenu[i]->_jatekos = 0;
                }
                _menu._startmenu[i]->draw(tikktakk);
            }
            if (_menu._startmenu[1]->_jatekos) {
                _jatekos1 = _menu._startmenu[2]->handle(ev);
                _jatekos2 = _menu._startmenu[3]->handle(ev);
                start = true;
                elsokor = false;
            }
        }


        /// JATEK
        if (start) {
            if (ev.type == 3){
                keslelteto = false;
                elsokor = false;
            }
            if (!keslelteto && ev.type == ev_mouse && ev.button==btn_left && ev.button > 0 && nyertes.size()<2) {
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
                                stringstream ss1;
                                stringstream ss2;
                                for (int e=0; e<nyertes.size()-1; e=e+2){
                                    _palya[nyertes[e]][nyertes[e+1]]->draw(nyertes[nyertes.size()-1]);
                                }
                                if (nyertes[nyertes.size()-1] == 1) {
                                    _jatekos1pont++;
                                    ss1 << _jatekos1pont;
                                } else {
                                    _jatekos2pont++;
                                    ss2 << _jatekos2pont;
                                }
                                _menu._k->_elsonev = _jatekos1;
                                _menu._k->_masodiknev = _jatekos2;
                                if (_jatekos1pont == 0) {
                                    _menu._k->_elsop = "0";
                                } else {
                                    ss1 >> _menu._k->_elsop;
                                }
                                if (_jatekos2pont == 0) {
                                    _menu._k->_masodikp = "0";
                                } else {
                                    ss2 >> _menu._k->_masodikp;
                                }
                                keslelteto = true;
                                start = false;
                                focus = -1;
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

        /// MENU - ELSO KOR UTAN
        if (!start && !elsokor) {
            if (ev.type == 3  && varj<2) {
                varj++;
            }
            if (varj > 1) {
                _menu._pucolo->draw(0);
                if (ev.type == ev_mouse && ev.button==btn_left) {
                    for (size_t i=0;i<_menu._vegemenu.size();i++) {
                        if (_menu._vegemenu[i]->is_selected(ev.pos_x, ev.pos_y)) {
                                focus = i;
                        }
                    }
                }
                if (focus!=-1) {
                    _menu._vegemenu[focus]->_jatekos = 1;
                    _menu._vegemenu[focus]->handle(ev);
                }
                for (size_t i=0; i<_menu._vegemenu.size(); i++) {
                    if (i != focus) {
                        _menu._vegemenu[i]->_jatekos = 0;
                    }
                    _menu._vegemenu[i]->draw(tikktakk);
                }
                _menu._k->draw(0);
                if (_menu._vegemenu[2]->_jatekos) {
                    start = false;
                    elsokor = true;
                    focus = -1;
                    _jatekos1pont = 0;
                    _jatekos2pont = 0;
                }
                if (_menu._vegemenu[1]->_jatekos) {
                    start = true;
                    elsokor = false;
                    focus = -1;
                }
                /// PALYA URITES
                if (_menu._vegemenu[1]->_jatekos || _menu._vegemenu[2]->_jatekos) {
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
                    vector<vector<int>> ures((int)_x/_meret, vector<int>((int)_y/_meret, 0));
                    _jatekallas = ures;
                    nyertes.clear();
                    varj = 0;
                }
            }
        }




        gout << refresh;
    }
}

