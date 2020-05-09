#include "graphics.hpp"
#include <iostream>
#include "widget.hpp"
#include "kivalaszto_widget.hpp"
#include "application.hpp"
using namespace genv;
using namespace std;

const int szelesseg = 550;
const int magassag = 600;
Kivalaszto_widget::Kivalaszto_widget(Application* parent, int _m, double _sz, int _legordulo_hossz): Widget(parent, _m, _sz)
    {
     x=rand()% (szelesseg-int(sz)-2-(int(sz)/4));
     legordulo_hossz=_legordulo_hossz;
     y=rand()% (magassag-(legordulo_hossz+1)*m-2);
    }
Kivalaszto_widget::Kivalaszto_widget(Application* parent, int _m, double _sz, int _legordulo_hossz, int _x, int _y): Widget(parent,_m, _sz)
    {
     x=_x;
     legordulo_hossz=_legordulo_hossz;
     y=_y;
    }
bool Kivalaszto_widget::folotte(int ex, int ey)
{
    return (ex>=x && ex<=x+sz+1+sz/4  && ey>=y && ey<=y+m);
}
void Kivalaszto_widget::rajzol()
    {
        gout<<move_to(x, y)<<color(250,250,250)<<box(sz, m)<<color(80,80,80)<<move_to(x+1,y+1)<<box(sz-2,m-2);
        gout<<move_to(x+sz+2, y)<<color(250,250,250)<<box(sz/4, m)<<move_to(x+sz+3, y+1)<<color(80,80,80)<<box(sz/4-2,m-2);
        gout<<move_to(x+sz+4, y+(m/4))<<color(0,0,0)<<line_to(x+sz+2+(sz/8), y+(m/4)*3)<<line_to(x+sz-2+sz/4, y+(m/4));
    }
void Kivalaszto_widget::mouse_ev(event& ev)
{
     if(ev.type == ev_mouse)
    {
        if(ev.button == btn_left)
        {
            if(gomb_felett(ev.pos_x,ev.pos_y))
            {
                lehuzva=!lehuzva;
            }
        }
    }
}
