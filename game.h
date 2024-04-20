#pragma once
#include <iostream>
#include <sfml/graphics.hpp>
#include "piece.h"
#include <utility>

class game
{
public:
	game();
	void printboard(); //print gameboard in console
	void updateboard(int, int, int); //given selectindex, update that piece on the board to pos x, y
	std::vector<piece> &getv(); //get piece vector
	int collision(int, int); //detect whether a move would make a piece collide with/go through another
	bool checkmate(); //func to see if king is in check and has no moves to escape
	bool check(int, int); //func to see if king is in check at pos x, y
	void possiblemoves(int, int, int, std::vector<std::pair<int, int>>&); //find every possible move for a given piece
	void capture(int, int); //one piece takes the pos of another, dead piece marked as such
	int findid(int, int); //find piece id of piece at x, y
	bool validmove(int, int, int); //given piece from v at index, check if move to x, y is valid
	bool makemove(int, int, int); //given piece from v at index, move to x, y; return true if one side if checkmated and false if the game continues
	int ispromoting(); //returning promoting var
	void donepromoting();
private:
	//this gameboard is the ONLY THING that starts indices at 0,0
	//everything else that tracks the board is 1,1 to 8,8
	//this is definitely a bad thing but i'm in too deep now
	//there's probably a code writing script that could fix this?
	//also i forgot that 2d arrays go [y][x] oopsies
	int gameboard[8][8] = {
		{-5,-3,-4,-9,-2,-4,-3,-5},
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1},
		{5,3,4,9,2,4,3,5}
	};
	bool whiteturn = true;
	std::vector<piece> v;
	std::pair<bool, int> enpassant = { false, 0 };
	int promoting = -1;

	//castling flags
	bool wr1move = false;
	bool wr2move = false;
	bool wkmove = false;
	bool br1move = false;
	bool br2move = false;
	bool bkmove = false;

	//possible vecs for captured pieces
	std::vector<piece> wprison;
	std::vector<piece> bprison;
};

