#include "game.h"
game::game() : window(sf::VideoMode(screenWidth, screenHeight), "game") {
	leftpaddle.setFillColor(sf::Color::White);
	leftpaddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	leftpaddle.setPosition(20, screenHeight / 2 - paddleHeight / 2);

	rightpaddle.setFillColor(sf::Color::White);
	rightpaddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	rightpaddle.setPosition(screenWidth - 40, screenHeight / 2 - paddleHeight / 2);

	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color::White);
	ballVelocity = sf::Vector2f(ballVelocityX, ballVelocityY);
	resetball();
}
void game::run() {
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}


	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftpaddle.getPosition().y>0)
	{
		leftpaddle.move(0,-5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftpaddle.getPosition().y + paddleHeight<screenHeight)
	{
		leftpaddle.move( 0,5);
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& rightpaddle.getPosition().y>0)
	{
		rightpaddle.move(0,-5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightpaddle.getPosition().y +paddleHeight<screenHeight)
	{
		rightpaddle.move(0, 5);
	}



	ball.move(ballVelocity);


	if (ball.getPosition().x<=0 ||ball.getPosition().x + 2 * ballRadius >= screenWidth)
	{
		resetball();
	}

	if (ball.getPosition().y<=0 || ball.getPosition().y +2 *ballRadius >screenHeight)
	{
		ballVelocity = sf::Vector2f(ballVelocity.x, -ballVelocity.y);

	}

	if (ball.getPosition().x <= leftpaddle.getPosition().x + paddleWidth &&
		ball.getPosition().x >= leftpaddle.getPosition().x &&
		ball.getPosition().y - ballRadius <= leftpaddle.getPosition().y + paddleHeight &&
		ball.getPosition().y + ballRadius >= leftpaddle.getPosition().y)
	{
		ballVelocity = sf::Vector2f(-ballVelocity.x, ballVelocity.y)
			;
	}
	if (ball.getPosition().x  +2 * ballRadius <= rightpaddle.getPosition().x + paddleWidth &&
		ball.getPosition().x+ 2*ballRadius >= rightpaddle.getPosition().x &&
		ball.getPosition().y - ballRadius <= rightpaddle.getPosition().y + paddleHeight &&
		ball.getPosition().y + ballRadius >= rightpaddle.getPosition().y)
		{
		ballVelocity = sf::Vector2f(-ballVelocity.x, ballVelocity.y)
			;
	}
	
	window.clear(sf::Color::Black);
	window.draw(rightpaddle);
	window.draw(leftpaddle);
	window.draw(ball);
	window.display();

}
}
void game::resetball() {
	ball.setPosition(screenWidth / 2 - ballRadius, screenHeight / 2 - ballRadius);
	ballVelocity = sf::Vector2f(ballVelocity.x, -ballVelocity.y);

}