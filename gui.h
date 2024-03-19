#pragma once
#include <iostream>
#include <vector>
#include <sfml/graphics.hpp>
#include <sfml/window.hpp>

struct piece {
	sf::Sprite sprite;
	int rank;
	int file;

	piece(sf::Sprite s, int r, int f) {
		sprite = s;
		rank = r;
		file = f;
	}
};

class gui
{
public:
	gui();
	void drawgui();
	void makemove();
private:
	std::vector<piece*> v;
	sf::RenderWindow window;
};

