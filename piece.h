#pragma once
#include <sfml/graphics.hpp>

class piece {
	//passing textures only sets a pointer to the texture
private:
	int x;
	int y;
	int type;
	bool alive = true;
	bool selected = false; 
public:
	piece() = default;
	piece(int f, int r, int t);
	int getx();
	int gety();
	int gettype();
	bool getselect();
	void select();
	void unselect();
	void setpos(int, int);
	void kill();
	void revive();
	bool isalive();
	void promote(int);
};

