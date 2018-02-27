#include "Engine.h"
#include "MainMenu.h"

int main()
{
    MainMenu menu;

    //opt stores the return value of menu.start()
    //value is 0 for two player mode which has been implemented
    //value is 1 for exit
    int opt = menu.start();
    if(opt==0)
    {
        //calls engine constructor with the window of Menu(to continue in the same window)
        Engine engine(menu.App);

        //starts the game engine
        //runs the main loop until quit
        engine.start();
    }
    return 0;
}
