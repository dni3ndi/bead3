#include "graphics.hpp"
#include <iostream>
#include "widget.hpp"
#include "szam_widget.hpp"
#include <sstream>
using namespace genv;
using namespace std;

const int szelesseg = 600;
const int magassag = 600;

Szam_widget::Szam_widget(Application* parent, int _m, double _sz, int _also, int _felso, int _x, int _y) : Widget(parent,_m, _sz)
    {
        x=_x;
        y=_y;
        also=_also;
        felso=_felso;
    }
bool Szam_widget::folotte(int mouse_x, int mouse_y)
{
    return(mouse_x>x && mouse_x<x+sz+2+sz/4 && mouse_y>y && mouse_y<y+m);
}
void Szam_widget::rajzol()
    {
        stringstream ss;
        ss<<szam;
        string szo=ss.str();
        if(szam==0)
        {
            szo="";
        }
        gout<<move_to(x, y)<<color(255,218,185)<<box(sz, m)<<color(240,230,140)<<move_to(x+1,y+1)<<box(sz-2,m-2)<<move_to((x+sz/2.5),(y+m/1.5))<<color(r,0,b)<<text(szo);
        gout<<move_to(x+sz+2, y)<<color(255,218,185)<<box(sz/4, m)<<move_to(x+sz+3, y+1)<<color(240,230,140)<<box(sz/4-2,m-2);
        gout<<move_to(x+sz+4, y+(m/2.2))<<color(0,0,0)<<line_to(x+sz+4+(sz/4-2)/3, y+(m/4))<<line_to(x+sz+4.5+((sz/4-2)/4*3), y+(m/2.2));
        gout<<move_to(x+sz+4, y+(m-m/2.2))<<line_to(x+sz+4+(sz/4-2)/3, y+m/4*3)<<line_to(x+sz+4.5+((sz/4-2)/4*3), y+(m-m/2.2));
    }
int Szam_widget::getNumber()
    {
        return szam;
    }
void Szam_widget::szamcsere(int a)
{
    szam=a;
}
void Szam_widget::is_okay()
{
    r=0;
}
void Szam_widget::not_okay()
{
    r=250;
}
void Szam_widget::b_250()
{
    b=250;
}
void Szam_widget::b_0()
{
    b=0;
}
void Szam_widget:: mouse_ev (event& ev)
    {
        if(ev.type == ev_mouse && beallithato)
        {
            if(ev.button == btn_left && gomb_felett(ev.pos_x, ev.pos_y) && lathato_e())
            {
                if(ev.pos_x>=x+sz+2 && ev.pos_x<=x+sz+2+sz/4 && ev.pos_y>=y && ev.pos_y<y+m/2 && szam<felso)
                {
                    szam++;
                }
                if(ev.pos_x>=x+sz+2 && ev.pos_x<=x+sz+2+sz/4 && ev.pos_y>y+m/2 && ev.pos_y<=y+m && szam>also)
                {
                    szam--;
                }
            }
        }
    }
void Szam_widget::key_ev(event& ev, Widget* focus)
    {
        if (ev.type == ev_key && focus==this && beallithato)
        {
            if(ev.keycode == key_up && lathato_e() && szam<felso)
            {
                szam++;
            }
            if(ev.keycode == key_down && lathato_e() && szam>also)
            {
                szam--;
            }
        }
    }
void Szam_widget::nem_beall()
{
   beallithato=false;
}
void Szam_widget::beall()
{
   beallithato=true;
}
