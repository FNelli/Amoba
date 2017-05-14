#include "menu.hpp"
#include <iostream>

using namespace genv;

Menu::Menu(int x, int y, int m)
{
    StaticText* st1 = new StaticText(x/2-30,y/2-120,60,30, "AMOBA");
    _startmenu.push_back(st1);
    ExampleCheckBox* ecb1 = new ExampleCheckBox(x/2-30,y/2+40,60,30, "START");
    _startmenu.push_back(ecb1);
    EditText* et1 = new EditText(x/2-60,y/2-60,120,30, "nev1");
    _startmenu.push_back(et1);
    EditText* et2 = new EditText(x/2-60,y/2-10,120,30, "nev2");
    _startmenu.push_back(et2);

    StaticText* st3 = new StaticText(x/2-37,y/2-120,60,30, "EREDMENY");
    _vegemenu.push_back(st3);
    ExampleCheckBox* ecb2 = new ExampleCheckBox(x/2-40,y/2+10,80,30, "RESTART");
    _vegemenu.push_back(ecb2);
    ExampleCheckBox* ecb3 = new ExampleCheckBox(10,10,60,30, "MENU");
    _vegemenu.push_back(ecb3);

    _k = new Kijelzo(x/2-60, y/2-90, 120, 60);
    _pucolo = new Pucolo(0,0,x,y);

}
