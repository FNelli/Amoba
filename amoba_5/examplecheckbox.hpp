#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
protected:
    std::string _felirat;
    //bool _checked;
public:
    ExampleCheckBox(int x, int y, int sx, int sy, std::string felirat);
    virtual void draw(int tikktakk/*, bool a*/) const ;
    virtual std::string handle(genv::event ev);
    virtual bool is_checked() const ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
