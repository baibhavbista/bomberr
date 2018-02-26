#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu():App(sf::VideoMode(608, 481, 32), "Game Arena")
{
    Texture_back.loadFromFile("backgrounds/MainMenu.png");
    Sprite_back.setTexture(Texture_back);
    p1ubuttontext.loadFromFile("sprites/menu/1playerunpressed.png");
    p2ubuttontext.loadFromFile("sprites/menu/2playerunpressed.png");
    p1buttontext.loadFromFile("sprites/menu/1playerpressed.png");
    p2buttontext.loadFromFile("sprites/menu/2playerpressed.png");
    exitutext.loadFromFile("sprites/menu/exitunpressed.png");
    exittext.loadFromFile("sprites/menu/exitpressed.png");
    continueutext.loadFromFile("sprites/menu/continueunpressed.png");
    continuetext.loadFromFile("sprites/menu/continuepressed.png");
    Menu1.setTexture(&p2ubuttontext);
    Menu2.setTexture(&exitutext);
    Menu3.setTexture(&continueutext);
    Menu1.setSize(sf::Vector2f(206.0f,35.0f));
	//Menu1.setCharacterSize(20);
	//Menu1.setString("Play");
	Menu1.setPosition(sf::Vector2f(243.0f,266.0f));

	Menu2.setSize(sf::Vector2f(206.0f,35.0f));
	//Menu1.setCharacterSize(20);
	//Menu1.setString("Play");
	Menu2.setPosition(sf::Vector2f(243.0f,330.0f));

	Menu3.setSize(sf::Vector2f(206.0f,35.0f));
	//Menu1.setCharacterSize(20);
	//Menu1.setString("Play");
	Menu3.setPosition(sf::Vector2f(243.0f,266.0f));

}

int MainMenu::start()
{
	//Sprite.setColor(sf::Color(255, 255, 255, alpha));
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

		if (menu == 1)
		{
			Menu1.setTexture(&p2buttontext);
            Menu2.setTexture(&exitutext);
            Menu3.setTexture(&continuetext);
		}
		else
		{
			Menu1.setTexture(&p2ubuttontext);
            Menu2.setTexture(&exittext);
            Menu3.setTexture(&continueutext);
		}
		App.draw(Menu1);
		App.draw(Menu2);
		//App.draw(Menu3);
        App.display();

    }
    return 1;
}
