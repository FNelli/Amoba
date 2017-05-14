#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <iostream>

using namespace std;

class StaticText : public Widget {
protected:
    string _szoveg;
public:
    StaticText(int x, int y, int sx, int sy, string init_szoveg);
    virtual void draw(int tikktakk) const ;

};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED

