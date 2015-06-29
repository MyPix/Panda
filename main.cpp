#include <iostream>
#include <SFML\Graphics.hpp>
using namespace std;

#include "pGlobals.hpp"
#include "Pandanimator.h"
int main(){

	cout << "Hello world !" << endl;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Panda 0.1");
	window.setFramerateLimit(30);
	sf::CircleShape circle;
	circle.setRadius(15);
	circle.setPosition(120, 120);
	circle.setFillColor(sf::Color::Black);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(3);
	circle.setPointCount(256);
	int time;

	Pandanimation anim;
	anim.start = circle;
	sf::Transformable end(circle);
	end.move(200, 300);
	anim.end = end;
	anim.duration = 120;
	anim.animType_Position_X = panda::Linear;
	anim.animType_Position_Y = panda::Linear;
	anim.animType_Scale_X = panda::Linear;
	anim.animType_Scale_Y = panda::Linear;
	anim.animType_Rotation = panda::Linear;
	Pandanimator pdn(anim);
	int step(0);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// update
		circle.setPosition(pdn.getTransformFor(step).getPosition());
		step += 1;
		cout << string(2, '\n');
		cout << "ANIM, NEW POS:" << circle.getPosition().x << " : " << circle.getPosition().y << endl;
		// end
		window.clear(sf::Color::White);
		window.draw(circle);
		window.display();
	}

	return 0;
}