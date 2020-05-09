#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED
#include "graphics.hpp"
#include <iostream>
#include <vector>
#include "widget.hpp"
#include "kivalaszto_widget.hpp"
using namespace genv;
using namespace std;

class Lista
{
private:
    canvas c;
public:
    int kival_index=0;
    int xp, yp, szeles, magas, szoveg_vege;
    Kivalaszto_widget* kival;
    vector<string> elemek;
    int canv_x=0;
    int canv_y=0;
    int kulonb=0;
    Lista(vector<string> _elemek, Kivalaszto_widget* _kival);
    void legordul();
    void kivalaszt(event& ev);
    int index();
    string kiirni ()
    {
        return elemek[kival_index];
    }
};


#endif // LISTA_HPP_INCLUDED
