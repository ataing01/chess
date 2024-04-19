#pragma once
#include <iostream>
#include <vector>
#include <sfml/graphics.hpp>
#include <sfml/window.hpp>
#include "piece.h"
#include "game.h"
#include <windows.h>

class gui
{
public:
	gui(game gamma); //initialize v
	sf::Vector2i getclick(); //get mouse pos after a click
	void snap(int); //snap piece to square
	void drawpgui(int, int); //draw promotion gui at mouse pos
	void refresh(); //clear and draw the gui again
	void drawgui(); //create and maintain gui
private:
	game g;
	int selectindex = -1;
	sf::RenderWindow window;
	sf::Texture boardt, wk, wq, wb, wn, wr, wp, bk, bq, bb, bn, br, bp, pguit;
	sf::Sprite board, pguis;
	std::vector<sf::Sprite> sv;
	std::vector<sf::Sprite> pguiv;
};

