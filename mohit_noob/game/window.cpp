#include <iostream>
#include "window.h"
//#include "../gittt"

void window::draw()
{
    sf::Texture Texture1;
	//Sprite.setColor(sf::Color(255, 255, 255, alpha));
    	sf::RenderWindow App(sf::VideoMode(608, 481, 32), "Game Arena");
    	sf::RectangleShape Menu1;
	sf::RectangleShape Menu2;
	sf::RectangleShape Menu3;
	int menu = 0;
	if (!Texture1.loadFromFile("MainMenu5.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
	}


	sf::Texture p1ubuttontext;
    p1ubuttontext.loadFromFile("sprites/1playerunpressed.png");
    sf::Texture p2ubuttontext;
    p2ubuttontext.loadFromFile("sprites/2playerunpressed.png");
    sf::Texture p1buttontext;
    p1buttontext.loadFromFile("sprites/1playerpressed.png");
    sf::Texture p2buttontext;
    p2buttontext.loadFromFile("sprites/2playerpressed.png");
    sf::Texture exitutext;
    exitutext.loadFromFile("sprites/exitunpressed.png");
    sf::Texture exittext;
    exittext.loadFromFile("sprites/exitpressed.png");
    sf::Texture continueutext;
    continueutext.loadFromFile("sprites/continueunpressed.png");
    sf::Texture continuetext;
    continuetext.loadFromFile("sprites/continuepressed.png");

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

	while (App.isOpen())
	{
		//Verifying events
		sf::Event Evnt;
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
				/*case sf::Keyboard::Return:
					if (menu == 0)
					{
						//Let's get play !
						//playing = true;;
						Engine engine;
						engine.start;
					}
					else
					{
						//Let's get work...
						//return (-1);
					}
					break;
				default:
					break;*/
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		//Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0)
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

}}

/*window::~window()
{
    //dtor
}*/
