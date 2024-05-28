#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "Textbox.h"
#include "Button.h"


int padavan(int n)
{
	int pPrevPrev = 1, pPrev = 1, pCurr = 1, pNext = 1;

	for (int i = 3; i <= n; i++)
	{
		pNext = pPrevPrev + pPrev;
		pPrevPrev = pPrev;
		pPrev = pCurr;
		pCurr = pNext;
	}

	return pNext;
}

int main()
{
	sf::RenderWindow window;

	float window_x = 800;
	float window_y = 600;

	window.create(sf::VideoMode(window_x, window_y), "padavan");

	window.setKeyRepeatEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("resources\\sansation.ttf"))
	{
		std::cout << "Font not found!\n";
	}

	Textbox text1(14, sf::Color::White, true);
	text1.setPosition({ 100, 100 });
	text1.setLimit(true, 2);
	text1.setFont(font);

	Button btn1("Enter", { 200, 100 }, 30, sf::Color::Green, sf::Color::Black);
	btn1.setFont(font);
	btn1.setPosition({ 100, 300 });

	sf::Text answer;
	answer.setFont(font);
	answer.setString("");
	answer.setCharacterSize(16);
	answer.setFillColor(sf::Color::Red);
	answer.setStyle(sf::Text::Bold | sf::Text::Underlined);
	answer.setPosition({100,200});
	

	while (window.isOpen()) {

		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			text1.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text1.setSelected(false);
		}



		while (window.pollEvent(Event)) 
		{
			switch (Event.type)
			{

			case sf::Event::Closed:
				window.close();

			case sf::Event::TextEntered:
				text1.typedOn(Event);


			case sf::Event::MouseMoved:

				if (btn1.isMouseOver(window))
				{
					btn1.setBackColor(sf::Color::Magenta);
				}
				else {
					btn1.setBackColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:

				if (btn1.isMouseOver(window))
				{


					std::string input_string = text1.getText();
					
					if (input_string.length() == 0)
					{
						input_string = "0";
					}

					answer.setString(std::to_string(padavan(std::stoi(input_string) - 1)));

					std::cout << padavan(std::stoi(input_string) - 1) << "\n";

				}
			}
		}

		window.clear();
		text1.drawTo(window);
		btn1.drawTo(window);
		window.draw(answer);
		window.display();
	}

}