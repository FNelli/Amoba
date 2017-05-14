#ifndef KIJELZO_HPP_INCLUDED
#define KIJELZO_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
using namespace std;
class Kijelzo : public Widget {
public:
    string _elsonev;
    string _masodiknev;
    string _elsop;
    string _masodikp;
    Kijelzo(int x, int y, int mx, int my);
    void draw(int nemkell) const;
};

#endif
