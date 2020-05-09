#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include "kivalaszto_widget.hpp"
#include "gomb_widget.hpp"
#include "Jatekmester.hpp"
#include "lista.hpp"
#include "szam_widget.hpp"
#include <vector>
#include "static_text.hpp"


class Application
{
protected:
    Szam_widget* widgets [9][9];
    Jatekmester jatekmester;
    Kivalaszto_widget* kival;
    GombWidget* start;
    GombWidget* kilep;
    GombWidget* megoldas;
    GombWidget* vissza;
    GombWidget* ellenorizz;
    Static_text* eredmeny;
    vector<string> szintek;
    Lista* lis;
    vector <Widget*> ossz_widget;
public:
    Application();
    void event_loop();
    void ossz_widgetbe (Widget*);
};


#endif // APPLICATION_HPP_INCLUDED
