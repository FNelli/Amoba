#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
public:
    int _jatekos;
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void is_checked(int jatekos);
    virtual void draw() const;
    virtual void handle(genv::event ev);
};


#endif // WIDGETS_HPP_INCLUDED
