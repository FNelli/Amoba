#ifndef X_KOR_HPP_INCLUDED
#define X_KOR_HPP_INCLUDED

#include "widgets.hpp"

class X_kor : public Widget {
public:
    X_kor(int x, int y, int sx, int sy);
    virtual void is_checked(int jatekos);
    virtual void draw(int nyertes) const ;
};


#endif // X_KOR_HPP_INCLUDED
