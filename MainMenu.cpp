#include <iostream>
#include "MainMenu.h"

//MainMenu class constructor, initializes all the required variables for the menu
MainMenu::MainMenu():App(sf::VideoMode(608, 481, 32), "Bomberman")
{
    //set up texture ans sprite for background of main menu
    Texture_back.loadFromFile("backgrounds/MainMenu.png");
    Sprite_back.setTexture(Texture_back);

    //loading textures for buttons from file
    p1dbuttontext.loadFromFile("sprites/menu/1grey.png");
    p2ubuttontext.loadFromFile("sprites/menu/2playerunpressed.png");
    p2buttontext.loadFromFile("sprites/menu/2playerpressed.png");
    exitutext.loadFromFile("sprites/menu/exitunpressed.png");
    exittext.loadFromFile("sprites/menu/exitpressed.png");

    //set up RectangleShape Menu1 (Texture, Size, Position)
    Menu1.setTexture(&p2ubuttontext);
    Menu1.setSize(sf::Vector2f(206.0f,35.0f));
	Menu1.setPosition(sf::Vector2f(243.0f,266.0f));

	//set up RectangleShape Menu2 (Texture, Size, Position)
    Menu2.setTexture(&exitutext);
    Menu2.setSize(sf::Vector2f(206.0f,35.0f));
	Menu2.setPosition(sf::Vector2f(243.0f,266.0f+50));

	//set up RectangleShape Menu3 (Texture, Size, Position)
    Menu3.setTexture(&p1dbuttontext);
    Menu3.setSize(sf::Vector2f(206.0f,35.0f));
	Menu3.setPosition(sf::Vector2f(243.0f,266.0f-50));
}

//starts the Main Menu display loop and returns int depending on option chosen in the menu when pressed enter/return
//0 to continue to 2-player game
//1 to exit, called when "enter"ed on exit button or when escape key pressed
int MainMenu::start()
{
	int menu = 0;
	sf::Event Evnt;
	while (App.isOpen())
	{
	    App.clear(sf::Color::White);
	    App.draw(Sprite_back);
		//Verifying events
		while (App.pollEvent(Evnt))
		{
			// Window closed
			if (Evnt.type == sf::Event::Closed)
			{
				App.close();
			}
			//Key pressed
			if (Evnt.type == sf::Event::KeyPressed)
			{
				switch (Evnt.key.code)
				{
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Return:
					return menu;
					break;
				default:
					break;
				}
			}
		}

        //focus on one or other menu option
		if (menu == 1)
		{
			Menu1.setTexture(&p2buttontext);
            Menu2.setTexture(&exitutext);
		}
		else
		{
			Menu1.setTexture(&p2ubuttontext);
            Menu2.setTexture(&exittext);
		}
		App.draw(Menu1);
		App.draw(Menu2);
		App.draw(Menu3);
        App.display();
    }
    //default value 1 i.e. quit
    return 1;
}
