#ifndef STATIC_TEXT_HPP_INCLUDED
#define STATIC_TEXT_HPP_INCLUDED
#include "graphics.hpp"
#include <iostream>
#include "widget.hpp"
using namespace genv;
using namespace std;

class Static_text: public Widget
{
protected:
    string szoveg;
public:
    Static_text(Application*, int, double, int, int, string);
    virtual ~Static_text(){};
    void rajzol();
    void setText(string);
};


#endif // STATIC_TEXT_HPP_INCLUDED
