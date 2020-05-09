#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "widget.hpp"
#include "graphics.hpp"
using namespace std;
using namespace genv;

class Textbox: public Widget
{
protected:
    string ertek;
    bool checked;
    bool ok=true;
    int r=0;
public:
    Textbox(Application*,int, int, string, int, int);
    virtual ~Textbox(){};
    void rajzol() ;
    void mouse_ev(event& ev);
    bool folotte(int mouse_x, int mouse_y);
    string getText();
    void szovegcsere(string);
    void is_okay();
    void not_okay();
};

#endif // TEXTBOX_HPP_INCLUDED
