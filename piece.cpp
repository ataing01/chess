#include "piece.h"

piece::piece(int f, int r, int t) {
	x = f;
	y = r;
	type = t;
	selected = false;
}

int piece::getx() { return x; }
int piece::gety() { return y; }
int piece::gettype() { return type; }
bool piece::getselect() { return selected; }

void piece::select() { selected = true; }
void piece::unselect() { selected = false; }

void piece::setpos(int f, int r) {
	x = f;
	y = r;
}

void piece::kill() {
	alive = false;
	setpos(-1, -1);
}

void piece::revive() {
	alive = true;
}

bool piece::isalive() { return alive; }

void piece::promote(int t) {
	type = t;
}