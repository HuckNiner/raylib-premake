#include "SameGameModel.h"
#include <ctime>

BoardGame::BoardGame()
{
	fillboard();
}

void BoardGame::fillboard()
{
	srand(time(NULL));
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			int whatColor = rand() % 3 + 1;
			switch (whatColor)
			{
			case 1:
				board[row][col] = color::Red;
				break;
			case 2:
				board[row][col] = color::Blue;
				break;
			case 3:
				board[row][col] = color::Green;
				break;
			case 4:
				board[row][col] = color::Empty;
				break;
			}
		}
	}
}

color BoardGame::getcolor(int row, int col)
{
	color g = board[row][col];
	return g;
}

void BoardGame::setcolor(int row, int col, color color)
{
	board[row][col] = color;
}

bool BoardGame::isValidhit(int row, int col)
{
	if (row > 4 || col > 4) {
		return false;
	}
	if (board[row][col] != color::Empty) {
		return true;
	}
	return false;
}

void BoardGame::remove(int row, int col)
{
	color squareColor = board[row][col];
	board[row][col] = color::Empty;
	if (row > 0) {
		if (board[row - 1][col] == squareColor) {
			remove(row - 1, col);
		}
	}
	if (row < 4) {
		if (board[row + 1][col] == squareColor) {
			remove(row + 1, col);
		}
	}
	if (col > 0) {
		if (board[row][col - 1] == squareColor) {
			remove(row, col - 1);
		}
	}
	if (col < 4) {
		if (board[row][col + 1] == squareColor) {
			remove(row, col + 1);
		}
	}
}

bool BoardGame::stillFloatingColors()
{
	for (int col = 0; col < 5; col++) {
		bool foundColor = false;
		for (int row = 0; row < 5; row++) {
			if (!foundColor && board[row][col] != color::Empty) {
				foundColor = true;
				continue;
			}
			if (foundColor && board[row][col] == color::Empty) {
				if (row != 0) {
					board[row][col] = board[row - 1][col];
					board[row - 1][col] = color::Empty;
					return true;
				}
			}
		}
	}
	return false;
}

bool BoardGame::stillColors()
{
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			if (color::Empty != board[row][col]) {
				return true;
			}
		}
	}
	return false;
}