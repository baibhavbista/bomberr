#include <SFML/Graphics.hpp>
//class of main menu
class MainMenu
{
public:
    sf::RenderWindow App;


    //MainMenu class constructor, initializes all the required variables for the menu
    MainMenu();

    //starts the Main Menu display loop and returns int depending on option chosen in the menu when pressed enter/return
    //0 to continue to 2-player game
    //1 to exit, called when "enter"ed on exit button or when escape key pressed
    int start();

private:
    sf::Texture Texture_back;
    sf::Sprite Sprite_back;

    sf::RectangleShape Menu1;
	sf::RectangleShape Menu2;
    sf::RectangleShape Menu3;

	sf::Texture p2ubuttontext;
	sf::Texture p1dbuttontext;
	sf::Texture p2buttontext;
	sf::Texture exitutext;
	sf::Texture exittext;
    sf::Texture continueutext;
    sf::Texture continuetext;
};
