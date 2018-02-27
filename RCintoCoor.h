#include <SFML/Graphics.hpp>

//changes row r and column c into position vector2f
sf::Vector2f rcIntoCoor(int r, int c);

//returns the closest good coordinate(a coordinate vector2f that is at the center of a cell) to  badCoor, a bad(not-good) coordinate
sf::Vector2f coorIntoGood(sf::Vector2f badCoor);

//changes Coordinate vector2f into Vector2i(row, column). Calls coorIntoGood internally, so bad coordinate can also be passed as argument
sf::Vector2i coorToRc(sf::Vector2f badCoor);
