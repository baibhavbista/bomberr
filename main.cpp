#include "Engine.h"
#include "MainMenu.h"
int main()
{
    MainMenu menu;
    int opt = menu.start();
    if(opt==0)
    {
        Engine engine(menu.App);
        engine.start();
    }
    return 0;
}
