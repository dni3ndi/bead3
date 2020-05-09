#ifndef GOMB_WIDGET_HPP_INCLUDED
#define GOMB_WIDGET_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
using namespace std;
using namespace genv;


class GombWidget: public Widget
{
protected:
    string szoveg;
    virtual ~GombWidget(){};
public:
    GombWidget(Application*, int, int, int, int, string);
    void rajzol() ;
    string gombnyomas (event&ev);
    void become_checked();
};


#endif // GOMB_WIDGET_HPP_INCLUDED
