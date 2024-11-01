#ifndef SAMEGAMEMODEL_H
#define SAMEGAMEMODEL_H

#include <vector>
using namespace std;

enum color {
	Red,
	Green,
	Blue,
	Empty
};

class BoardGame {
private:
	color board[5][5];
	void fillboard();

public:
	BoardGame();
	color getcolor(int row, int col);
	void setcolor(int row, int col, color color);
	bool isValidhit(int row, int col);
	void remove(int row, int col);
	bool stillFloatingColors();
	bool stillColors();
};

#endif