#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "edittext.hpp"
#include "statictext.hpp"
#include "examplecheckbox.hpp"
#include "pucolo.hpp"
#include "kijelzo.hpp"

#include <vector>

using namespace std;

class Menu  {
public:
    vector<Widget*> _startmenu;
    vector<Widget*> _vegemenu;
    Pucolo* _pucolo;
    Kijelzo* _k;
    Menu(int x, int y, int m);
};


#endif
