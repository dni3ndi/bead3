#include <iostream>
#include "widget.hpp"
#include "static_text.hpp"
using namespace genv;
using namespace std;

Static_text::Static_text(Application* parent, int _m, double _sz, int _x, int _y, string szov) : Widget(parent,_m, _sz)
{
    x=_x;
    y=_y;
    szoveg=szov;
}

void Static_text::rajzol()
{
    gout << move_to(x, y) << color(0,0,0) << box(sz, m);
    gout<< color(30,123,20) <<move_to(x+sz/2-(gout.twidth(szoveg)/2),y+m/2+5)<<text(szoveg);
}
void Static_text::setText(string felirat)
{
    szoveg=felirat;
}
