#ifndef PUCOLO_HPP_INCLUDED
#define PUCOLO_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Pucolo : public Widget {
public:
    Pucolo(int x, int y, int mx, int my);
    virtual void draw(int nemkell) const;
};

#endif
