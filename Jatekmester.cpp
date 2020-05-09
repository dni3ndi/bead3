#include "graphics.hpp"
#include <iostream>
#include "widget.hpp"
#include "Jatekmester.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace genv;
using namespace std;

bool Jatekmester::megengedett(int puzzle [9][9], int szam, int i, int j)
{
    for(unsigned int k=0; k<9; k++)
    {
        if(i!=k && szam==puzzle[k][j])
        {
            return false;
        }
    }
    for(unsigned int k=0; k<9; k++)
    {
        if(j!=k && szam==puzzle[i][k])
        {
            return false;
        }
    }
    for(unsigned int k=(i/3)*3; k<(i/3)*3+3; k++)
    {
        for(unsigned int h=(j/3)*3; h<(j/3)*3+3; h++)
        {
            if(!(i==k && j==h) && szam==puzzle[k][h])
            {
                return false;
            }
        }
    }
    return true;
}

void Jatekmester::keszits_sudokut()
{
    srand(time(0));
    for(unsigned int i=0;i<9;i++)
    {
        for(unsigned int j = 0; j<9 ; j++)
        {
            megoldas[i][j]=0;
        }
    }
    vector<int>voltak;
    int szam;
    int szamlalo=0;
    for(unsigned int i=0;i<9;i++)
    {
        for(unsigned int j = 0; j<9 ; j++)
        {
            szam = rand()%9+1;
            while(!megengedett(megoldas, szam, i, j) && voltak.size() != 9)
            {
                bool volt = false;
                for(unsigned int u = 0; u < voltak.size(); u++)
                {
                    if(szam == voltak[u])
                    {
                        volt=true;
                    }
                }
                if(!volt)
                {
                  voltak.push_back(szam);
                }
                 szam = rand()%9+1;
            }
            if(voltak.size() < 9)
            {
                megoldas[i][j]=szam;
            }
            if(voltak.size()==9)
            {
                if(j>0)
                {
                    j=j-2;
                    if(i>0)
                    {
                        i=i-1;
                    }
                }
                if(j==0)
                {
                        i=i-2;
                        j=8;
                }
            }
             voltak.clear();
             szamlalo++;
             if(szamlalo>=1000)
             {
                 i=0;
                 j=-1;
                 szamlalo=0;
                 for(unsigned int t=0;t<9;t++)
                {
                    for(unsigned int f=0;f<9;f++)
                    {
                       megoldas[t][f]=0;
                    }
                }
            }
        }
    }
}

void Jatekmester::rejtveny(Szam_widget* widgets [9][9], int kivett_szam)
{
    int a;
    int b;
    int szamlalo;
    int ertek;
    for(unsigned int i=0;i<9;i++)
    {
        for(unsigned int j=0;j<9;j++)
        {
            kitoltendo[i][j]=megoldas[i][j];
        }
    }
    for(unsigned int h=0;h<kivett_szam;h++)
    {
        a = rand()%9;
        b = rand()%9;
        ertek = kitoltendo[a][b];
        if(ertek!=0)
        {
            kitoltendo[a][b]=0;
            szamlalo=0;
            for(unsigned int k=1;k<10;k++)
            {
                if(megengedett(kitoltendo, k, a,b))
                {
                    szamlalo++;
                }
            }
            if(szamlalo!=1)
            {
                kitoltendo[a][b]=ertek;
                h--;
            }
        }
        if(ertek==0)
        {
            h--;
        }
    }
      for(unsigned int i=0;i<9;i++)
    {
        for(unsigned int j=0;j<9;j++)
        {
            widgets[i][j]->szamcsere(kitoltendo[i][j]);
            if(widgets[i][j]->getNumber()!=0)
            {
                widgets[i][j]->nem_beall();
                widgets[i][j]->b_0();
            }
            if(widgets[i][j]->getNumber()==0)
            {
                widgets[i][j]->beall();
                widgets[i][j]->b_250();
            }
        }
    }
}

bool Jatekmester::ellenoriz(Szam_widget* widgets [9][9])
{
    for(unsigned int i=0; i<9; i++)
    {
        for(unsigned int j=0; j<9; j++)
        {
            if(widgets[i][j]-> getNumber()!= megoldas [i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void Jatekmester::megold(Szam_widget* widgets [9][9])
{
    for(unsigned int i=0; i<9; i++)
    {
        for(unsigned int j=0; j<9; j++)
        {
            widgets[i][j]->szamcsere(megoldas[i][j]);
        }
    }
}
bool Jatekmester::kitoltve(Szam_widget* widgets [9][9])
{
    for(unsigned int i=0; i<9; i++)
    {
        for(unsigned int j=0; j<9; j++)
        {
            if(widgets[i][j]->getNumber()==0)
            {
                return false;
            }
        }
    }
    return true;
}
void Jatekmester::ellentmondas(Szam_widget* widgets [9][9])
{
    for(unsigned int i=0; i<9; i++)
        {
            for(unsigned int j=0; j<9; j++)
            {
                int ert=widgets[i][j]->getNumber();
                bool van=false;
                for(unsigned int k=0; k<9; k++)
                {
                    if(i!=k && ert!=0 && ert==widgets[k][j]->getNumber())
                    {
                        widgets[k][j]->not_okay();
                        widgets[i][j]->not_okay();
                        van=true;
                    }
                }
                for(unsigned int k=0; k<9; k++)
                {
                    if(j!=k && ert!=0 && ert==widgets[i][k]->getNumber())
                    {
                        widgets[i][k]->not_okay();
                        widgets[i][j]->not_okay();
                        van=true;
                    }
                }
                for(unsigned int k=(i/3)*3; k<(i/3)*3+3; k++)
                {
                    for(unsigned int h=(j/3)*3; h<(j/3)*3+3; h++)
                    {
                        if(!(i==k && j==h) && ert!=0 && ert==widgets[k][h]->getNumber())
                        {
                            widgets[k][h]->not_okay();
                            widgets[i][j]->not_okay();
                            van=true;
                        }
                    }
                }
                if(!van)
                {
                    widgets[i][j]->is_okay();
                }
            }
        }
}
