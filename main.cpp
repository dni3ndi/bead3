#include "graphics.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include "widget.hpp"
#include "graphics.hpp"
#include "application.hpp"
#include "kivalaszto_widget.hpp"
#include "gomb_widget.hpp"
#include "szam_widget.hpp"
using namespace genv;
using namespace std;


int main()
{
    Application myapp;
    myapp.event_loop();
    return 0;
}
