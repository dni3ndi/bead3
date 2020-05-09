#include "graphics.hpp"
#include <iostream>
#include "widget.hpp"
#include "textbox.hpp"
using namespace genv;
using namespace std;

Textbox::Textbox(Application* parent, int _m, int _sz, string sz, int _x, int _y): Widget(parent,_m, _sz)
{
    x=_x;
    y=_y;
    ertek=sz;
}
void Textbox::is_okay()
{
    r=0;
}
void Textbox::not_okay()
{
    r=250;
    ok=false;
}

void Textbox::rajzol()
{
    gout << move_to(x, y) << color(255,218,185) << box(sz, m);
    gout << move_to(x+2, y+2) << color(240,230,140) << box(sz-4, m-4);
    gout<< color(r,0,0) <<move_to(x+15,y+15+gout.cascent())<<text(ertek);
    if (checked)
    {
        gout<< color(0,0,0)<<move_to(x+15+gout.twidth(ertek)+1, y+15);
        gout<< line(0, gout.cascent() + gout.cdescent());
    }
}

bool Textbox::folotte(int mouse_x, int mouse_y)
{
    if (mouse_x>x && mouse_x<x+sz && mouse_y>y && mouse_y<y+m)
    {
        checked=true;
    }
    else{checked=false;}
    return(mouse_x>x && mouse_x<x+sz && mouse_y>y && mouse_y<y+m);
}

void Textbox::mouse_ev(event& ev)
{
    if (checked && ev.type == ev_key)
    {
        if (ev.keycode > 48 && ev.keycode <=57 && x+15+gout.twidth(ertek)+1 < x+sz && ertek.length()==0)
        {
            ertek+=ev.keycode;
        }
        if (ev.keycode == key_backspace && ertek.length() > 0)
        {
            ertek.pop_back();
        }
    }
}

string Textbox::getText()
{
    return ertek;
}

void Textbox::szovegcsere(string a)
{
    ertek=a;
}

//void StringWidget::become_checked()
//{
//    checked=!checked;
//}
