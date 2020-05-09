#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include <iostream>
#include "graphics.hpp"
#include <string>
#include <vector>
using namespace genv;
using namespace std;

class Application;

class Widget
{
public:
    int x;
    int y;
    double sz;
    int m;
    int legordulo_hossz;
    bool lehuzva=false;
    bool lathato;
    int dx=0;
    int dy=0;
    Widget(Application*,int _m, double _sz);
    void lathatova();
    void lathatlanna();
    bool lathato_e();
    virtual void rajzol();
    virtual bool folotte(int ex, int ey);
    bool gomb_felett(int ex, int ey);
    virtual void mouse_ev (event& ev){};
    virtual void key_ev(event& ev, Widget*){};
    virtual string gombnyomas(event&ev);
};

#endif // WIDGET_HPP_INCLUDED
