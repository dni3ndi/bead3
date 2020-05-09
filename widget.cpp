#include "graphics.hpp"
#include <iostream>
#include "widget.hpp"
#include "application.hpp"
using namespace genv;
using namespace std;

const int szelesseg = 550;
const int magassag = 600;

Widget::Widget(Application* parent, int _m, double _sz)
{
    m=_m;
    sz=_sz;
    parent->ossz_widgetbe(this);
}
void  Widget:: rajzol()
{
}
bool Widget::lathato_e()
{
    return lathato;
}
void Widget::lathatova()
{
    lathato=true;
}
void Widget::lathatlanna()
{
    lathato=false;
}
bool Widget::folotte(int ex, int ey)
{
    return (ex>=x && ex<=x+sz && ey>=y && ey<=y+m);
}
bool Widget::gomb_felett(int ex, int ey)
{
    return (ex>=x+sz && ex<=x+sz+1+sz/4 && ey>=y && ey<=y+m);
}
string Widget::gombnyomas(event&ev)
{
    return "";
}
