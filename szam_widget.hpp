#ifndef SZAM_WIDGET_HPP_INCLUDED
#define SZAM_WIDGET_HPP_INCLUDED
using namespace genv;

class Szam_widget: public Widget
{
protected:
    int szam=0;
    int also;
    int felso;
    int r=0;
    int b=0;
    bool beallithato=true;
public:
    Szam_widget(Application*, int, double, int, int, int, int);
    virtual ~Szam_widget(){};
    void rajzol();
    void mouse_ev (event& ev);
    void key_ev(event& ev, Widget*);
    int getNumber();
    void szamcsere(int);
    void is_okay();
    void not_okay();
    bool folotte(int,int);
    void nem_beall();
    void beall();
    void b_250();
    void b_0();
};

#endif // SZAM_WIDGET_HPP_INCLUDED
