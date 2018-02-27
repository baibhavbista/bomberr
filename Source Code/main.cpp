#include "Engine.h"
#include "MainMenu.h"
#include "iostream"

int main()
{
    std::cout << "BomberMan Clone: Bomberr \
                 \n\nMade as Semester Project for OOP class \
                 \n\nBy : Baibhav Bista 073BCT511 \
                 \n     Lumanti Dangol 073BCT521 \
                 \n     Mohit Kedia 073BCT523 \
                 \n\nGithub link: https://github.com/baibhavbista/bomberr \
                 \n\nInstructions: \
                 \nSame as Bomberman \
                 \nFor Player1(White): Controls: Directions(W, A, S, D), Drop Bomb(Space) \
                 \nFor Player2(Black): Controls: Directions(Up, Left, Down, Right), Drop Bomb(Semicolon)" << std::endl;
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
