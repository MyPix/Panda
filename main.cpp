#include <iostream>
#include <SFML\Graphics.hpp>
#include <vector>
using namespace std;

#include "pGlobals.hpp"
#include "Pandanimator.h"
float main(){

	cout << "Hello world !" << endl;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Panda 0.1");
	window.setFramerateLimit(60);
	sf::CircleShape circle;
	circle.setRadius(15);
	circle.setPosition(120, 120);
	circle.setFillColor(sf::Color::Black);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(3);
	circle.setPointCount(256);
	float time;

	Pandanimation anim;
	anim.start = circle;
	sf::Transformable end(circle);
	end.move(600, 300);
	anim.end = end;
	anim.duration = 120;
	anim.animType_Position_X = panda::Linear;
	anim.animType_Position_Y = panda::Quadratic_InOut;
	anim.animType_Scale_X = panda::Linear;
	anim.animType_Scale_Y = panda::Linear;
	anim.animType_Rotation = panda::Linear;
	Pandanimator pdn(anim);
	float step(0);

	vector < sf::CircleShape > phantom;

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
		sf::CircleShape mcircle(circle);
		mcircle.setOutlineColor(sf::Color(255, 255, 255, 128));
		mcircle.setFillColor(sf::Color(255, 255, 255, 128));
		phantom.push_back(mcircle);
		// end
		window.clear(sf::Color::Black);
		for (int k(0); k < phantom.size(); k++)
		{
			window.draw(phantom.at(k));
		}
		window.draw(circle);
		window.display();
	}

	return 0;
}