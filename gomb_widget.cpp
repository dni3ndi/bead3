#include "widget.hpp"
#include "graphics.hpp"
#include "gomb_widget.hpp"
#include <iostream>
using namespace std;
using namespace genv;

GombWidget::GombWidget(Application* parent, int _m, int _sz, int _x, int _y, string szov): Widget(parent, _m, _sz)
{
    x=_x;
    y=_y;
    szoveg=szov;
}

void GombWidget::rajzol()
{
    gout << move_to(x, y) << color(0,0,0) << box(sz, m);
    gout << move_to(x+2, y+2)<< color(120,120,120) << box(sz-4, m-4);
    gout<< color(0,0,0) <<move_to(x+sz/2-(gout.twidth(szoveg)/2),y+m/2+5)<<text(szoveg);
}

string GombWidget::gombnyomas(event& ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        return szoveg;
    }
    return "";
}

