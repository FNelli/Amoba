#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
using namespace genv;
using namespace std;

class Palya {
protected:
    int _x;
    int _y;
    int _meret;

public:
    vector<vector<Widget*>> _palya;
    Palya(vector<vector<Widget*>> palya, int x, int y, int m);
    virtual void event_loop();
};


#endif
