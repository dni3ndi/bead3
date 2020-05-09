#ifndef KIVALASZTO_WIDGET_HPP_INCLUDED
#define KIVALASZTO_WIDGET_HPP_INCLUDED
using namespace std;
using namespace genv;

class Kivalaszto_widget: public Widget
{
protected:
    virtual ~Kivalaszto_widget(){};
public:
    Kivalaszto_widget(Application*,int _m, double _sz, int _legordulo_hossz);
    Kivalaszto_widget(Application*,int _m, double _sz, int _legordulo_hossz, int _x, int _y);
    void rajzol();
    void mouse_ev(event& ev);
    bool folotte(int, int);
}
;

#endif // KIVALASZTO_WIDGET_HPP_INCLUDED
