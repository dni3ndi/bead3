#include "graphics.hpp"
#include <iostream>
#include "widget.hpp"
#include "Jatekmester.hpp"
#include "application.hpp"
#include "kivalaszto_widget.hpp"
#include "gomb_widget.hpp"
#include "lista.hpp"
#include "szam_widget.hpp"
#include "static_text.hpp"
using namespace genv;
using namespace std;
const int X=550;
const int Y=600;


Application::Application()
{
    for(unsigned int i=0; i<9; i++)
    {
        for(unsigned int j=0; j<9; j++)
        {
            widgets[i][j]= new Szam_widget(this,50,38.4,1,9,j*50, i*50);
        }
    }
    kival = new Kivalaszto_widget(this,30,80,2,X/2-45, Y/2-25);
    start = new GombWidget(this,30,100,X/2-50, Y/2-65, "Start");
    kilep = new GombWidget(this,30,100,X-120, Y-40, "Kilep");
    megoldas = new GombWidget(this,30,200,X-220, Y-80, "Kerem a megoldast!");
    vissza = new GombWidget(this,30,200,X-220, Y-120, "Vissza a fomenube");
    ellenorizz = new GombWidget(this,30,200,X-220, Y-80, "Ellenorizd a megoldast");
    eredmeny = new Static_text(this, 30,300,X/2-150, Y/2-150, "Gratulalok, a megoldas helyes.");
    szintek={"konnyu", "nehez"};
    lis=new Lista(szintek,kival);
}
void Application::ossz_widgetbe (Widget* widget)
{
    ossz_widget.push_back(widget);
}
void Application::event_loop()
{
    gout.open(X,Y);
    event ev;
    Widget* focus = nullptr;
    kival->lathatova();
    kilep->lathatova();
    start->lathatova();
    vissza->lathatlanna();
    megoldas->lathatlanna();
    ellenorizz->lathatlanna();
    eredmeny->lathatlanna();
    bool vege=false;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (unsigned int i=0;i<ossz_widget.size();i++)
            {
                if (ossz_widget[i]->folotte(ev.pos_x, ev.pos_y)&& ossz_widget[i]->lathato_e())
                {
                        focus = ossz_widget[i];
                }
            }
        }
        if (focus!=nullptr)
        {
           focus->mouse_ev(ev);
           focus->key_ev(ev, focus);
           if(focus->gombnyomas(ev)=="Start")
           {
               for(unsigned int i=0; i<ossz_widget.size(); i++)
               {
                   ossz_widget[i]->lathatlanna();
                }
                for(unsigned int i=0; i<9; i++)
                {
                    for(unsigned int j=0; j<9; j++)
                    {
                        widgets[i][j]->lathatova();
                    }
                }
                kilep->lathatova();
                vissza->lathatova();
                megoldas->lathatova();
                jatekmester.keszits_sudokut();
                int kivett_szam=20;
                if(lis->index()==1)
                {
                    kivett_szam=30;
                }
                jatekmester.rejtveny(widgets, kivett_szam);
           }
           if(focus->gombnyomas(ev)=="Kilep")
           {
                exit(0);
           }
           if(focus->gombnyomas(ev)=="Kerem a megoldast!")
           {
               for(unsigned int i=0; i<ossz_widget.size(); i++)
               {
                   ossz_widget[i]->lathatlanna();
                }
                for(unsigned int i=0; i<9; i++)
                {
                    for(unsigned int j=0; j<9; j++)
                    {
                        widgets[i][j]->lathatova();
                    }
                }
                kilep->lathatova();
                vissza->lathatova();
                jatekmester.megold(widgets);
                vege=false;
           }
           if(focus->gombnyomas(ev)=="Vissza a fomenube")
           {
               for(unsigned int i=0; i<ossz_widget.size(); i++)
               {
                   ossz_widget[i]->lathatlanna();
                }
                kilep->lathatova();
                start->lathatova();
                kival->lathatova();
                vege=false;
           }
           if(focus->gombnyomas(ev) == "Ellenorizd a megoldast" )
           {
            gout<<color(0,0,0)<<box(X, Y);
            vege=true;
            for(unsigned int i=0; i<ossz_widget.size(); i++)
            {
               ossz_widget[i]->lathatlanna();
            }
            kilep->lathatova();
            vissza->lathatova();
           }
        }
        if(jatekmester.kitoltve(widgets)&&megoldas->lathato_e())
       {
         ellenorizz->lathatova();
       }
        gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
        jatekmester.ellentmondas(widgets);
        if (vege)
        {
            if(jatekmester.ellenoriz(widgets))
            {
                eredmeny->setText("Gratulalok, a megoldas helyes.");
            }
            if(!jatekmester.ellenoriz(widgets))
            {
                eredmeny->setText("Helytelen megoldas.");
            }
            eredmeny->lathatova();
        }
        for(unsigned int i=0; i<ossz_widget.size(); i++)
        {
             if(ossz_widget[i]->lathato_e())
            {
                ossz_widget[i]->rajzol();
            }
        }
        if(widgets[0][0]->lathato)
        {
            for(unsigned int i=1;i<3;i++)
            {
                gout<<move_to(0,(i*3*widgets[0][0]->m)-2)<<color(0,0,0)<<box(X,4);
                gout<<move_to((i*3*((widgets[0][0]->sz)/4*5+2))-2,0)<<box(4,Y);
            }
        }
        if(kival->lathato_e())
        {
            lis->kivalaszt(ev);
            lis->legordul();
        }
        gout << refresh;
    }
}
