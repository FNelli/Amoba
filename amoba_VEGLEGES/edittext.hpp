#ifndef EDITTEXT_HPP_INCLUDED
#define EDITTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <iostream>

using namespace std;

class EditText : public Widget {
protected:
    string _szoveg;
public:
    EditText(int x, int y, int sx, int sy, string init_szoveg);
    virtual void draw(int tikktakk) const;
    virtual string handle(genv::event ev);
};


#endif

