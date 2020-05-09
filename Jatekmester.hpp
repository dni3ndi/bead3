#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include "szam_widget.hpp"

class Jatekmester
{
protected:
    int  megoldas [9][9];
    int  kitoltendo [9][9];
public:
    void keszits_sudokut();
    bool megengedett(int puzzle [9][9],int, int, int);
    void rejtveny(Szam_widget* widgets [9][9], int);
    bool kitoltve(Szam_widget* widgets [9][9]);
    void megold(Szam_widget* widgets [9][9]);
    bool ellenoriz(Szam_widget* widgets [9][9]);
    void ellentmondas(Szam_widget* widgets [9][9]);
};

#endif // JATEKMESTER_HPP_INCLUDED
