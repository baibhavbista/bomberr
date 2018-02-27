#include <SFML/Graphics.hpp>
class MainMenu
{
public:
    sf::RenderWindow App;
    MainMenu();
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
