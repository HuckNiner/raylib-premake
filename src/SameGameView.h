#ifndef SAMEGAMEVIEW_H
#define SAMEGAMEVIEW_H

#include "SameGameModel.h"
#include "raylib.h"

class view {
private:
	BoardGame* board;
public:
	view(BoardGame& b);
	void display(int numOfMoves);
};

#endif