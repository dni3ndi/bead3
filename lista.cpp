#include <iostream>
#include <vector>
#include "widget.hpp"
#include "kivalaszto_widget.hpp"
#include "lista.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;
const int szelesseg = 550;
const int magassag = 600;

Lista::Lista(vector<string> _elemek, Kivalaszto_widget* _kival)
    {
        elemek=_elemek;
        kival=_kival;
        xp=kival->x;
        yp=kival->y+kival->m+2;
        szeles=kival->sz+2+kival->sz/4;
        magas=kival->legordulo_hossz*kival->m;
        szoveg_vege=kival->x+kival->sz;
    }
int Lista::index()
{
    return kival_index;
};
void Lista::legordul()
    {
        xp=kival->x;
        yp=kival->y+kival->m+2;
        szoveg_vege=kival->x+kival->sz;
        gout<<color(250,250,250)<<move_to(kival->x+kival->sz/2-gout.twidth(elemek[kival_index])/2, kival->y+5+kival->m/2)<<text(elemek[kival_index]);
        if(kival->lehuzva && yp+magas<=magassag)
        {
            gout<<move_to(xp, yp)<<color(250,250,250)<<box(szeles, magas)<<move_to(xp+1, yp+1)<<color(80,80,80)<<box(kival->sz+kival->sz/4, kival->legordulo_hossz*kival->m-2);
            gout<<move_to(xp+kival->sz+1, yp)<<color(250,250,250)<<line(1, magas);
            if( yp+kival_index*kival->m+1-kulonb>yp)
            {
                 gout<<move_to(xp+1, yp+kival_index*kival->m+1-kulonb)<<color(0,0,130);
                 if(yp+kival_index*kival->m+1-kulonb< yp + magas-kival->m)
                 {
                     gout<<box(kival->sz-1, kival->m-2);
                 }
                 else if(yp+kival_index*kival->m+1-kulonb- (yp + magas-kival->m)<kival->m)
                 {
                     gout<<box(kival->sz-1, kival->m-2-(yp+kival_index*kival->m+1-kulonb- (yp + magas-kival->m)));
                 }
            }
             if( yp+kival_index*kival->m+1-kulonb<=yp && yp+kival_index*kival->m+1-kulonb>yp-kival->m)
             {
                 gout<<move_to(xp+1, yp+1)<<color(0,0,130)<<box(kival->sz-1, kival->m-2-(kulonb-((kival_index)*kival->m)));
             }
             for(unsigned int i=0; i<kival->legordulo_hossz;i++)
             {
                 gout<<color(250,250,250)<<move_to(xp+kival->sz/2-gout.twidth(elemek[i])/2,yp+kival->m*(1+i)-10)<<text(elemek[i]);
             }
        }
    }
void Lista::kivalaszt(event& ev)
    {
        xp=kival->x;
        yp=kival->y+kival->m+2;
        szoveg_vege=kival->x+kival->sz;
        if(kival->lehuzva &&ev.type==ev_mouse && ev.button==btn_left)
        {
            for(unsigned int i=0; i<=kival->legordulo_hossz; i++)
            {
                if(ev.pos_x>=xp && ev.pos_x<=(xp+kival->sz) && ev.pos_y>=yp+(kival->m*i)-(kulonb%kival->m) && ev.pos_y>=yp && ev.pos_y<=yp+(kival->m*(i+1))-(kulonb%kival->m) && ev.pos_y<=yp+kival->m*kival->legordulo_hossz)
                {
                    if((kulonb/kival->m)+i<=elemek.size()-1)
                    {
                        kival_index=(kulonb/kival->m)+i;
                        kival->lehuzva=!kival->lehuzva;
                    }
                }
            }
            }
        }
