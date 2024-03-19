#pragma once
#include <iostream>
#include <sfml/graphics.hpp>

class game
{
public:
	game();
	void makemove();
private:
	int gameboard[8][8] =
	{
		{5,3,4,9,2,4,3,5},
		{1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1},
		{5,3,4,9,2,4,3,5}
	};
	bool whiteturn;
};

