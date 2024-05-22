#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <algorithm> 


using namespace std;

sf::RenderWindow window(sf::VideoMode(800, 600), "padavan");
sf::Font font;


void draw_text()
{
	sf::Text text;
	text.setFillColor(sf::Color::White);
	text.setPosition(100, 100);
	text.setFont(font);
	text.setString("Hello world");
	window.draw(text);
}

void redraw_frame()
{
	window.clear(sf::Color::Black);
	window.display();
}


int main() ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	if (!font.loadFromFile("resources\\sansation.ttf"))
	{
		return 0;
	}

	
	sf::Style::Default;
	window.clear(sf::Color::White);
	redraw_frame();

	int j = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				redraw_frame();
							
			}
		}
	}
}