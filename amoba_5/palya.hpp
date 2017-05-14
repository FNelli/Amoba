#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "felugyelo.hpp"
#include "menu.hpp"
#include <vector>

using namespace genv;
using namespace std;

class Palya {
protected:
    int _x;
    int _y;
    int _meret;
    Menu _menu;
public:
    //vector<Widget*> _wid_vector;
    string _jatekos1;
    string _jatekos2;
    int _jatekos1pont;
    int _jatekos2pont;
    vector<vector<Widget*>> _palya;
    vector<vector<int>> _jatekallas;
    Palya(vector<vector<Widget*>> palya, int x, int y, int m);
    virtual void event_loop();
};


#endif
