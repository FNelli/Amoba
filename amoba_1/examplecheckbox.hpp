#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
public:
    int _allapot;
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void is_checked(int jatekos);
    virtual void draw() const ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
