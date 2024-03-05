#pragma once
#include "SFML/Graphics.hpp"
class game
{public:
	 game();
	 void run();

private:
	const int screenWidth=800;
	const int screenHeight=600;
	const float paddleWidth=20.0f;
	const float paddleHeight=100.0f;
	const float ballRadius=10.0f;
	const float ballVelocityX=6.0f;
	const float ballVelocityY=6.0f;

	sf::RenderWindow window;
	sf::RectangleShape leftpaddle;
	sf::RectangleShape rightpaddle;
	sf::CircleShape ball;
	sf::Vector2f ballVelocity;
	void resetball();





};

