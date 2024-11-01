#include <iostream>
#include "SameGameModel.h"
#include "SameGameView.h"
#include <string>

using namespace std;


view::view(BoardGame& b) {
    board = &b;
}
struct square {
    int x; 
    int y;
    int width;
    int height;
    Color color;
};
vector <square> shapesArray;


Color colorToPrint(color color) {
    switch (color) {
    case color::Red: return RED;
    case color::Blue: return BLUE;
    case color::Green: return GREEN;
    case color::Empty: return WHITE;
    default: return ORANGE;

    }
}

void view::display(int numOfMoves) {
    shapesArray.clear();
    for (int height = 0; height < 5; height++) {
       for (int width = 0; width < 5; width++) {
           Color c = colorToPrint(board->getcolor(height, width));
           square s = { width * 200, height * 200, 200, 200, c };
           DrawRectangle(s.x, s.y, s.width, s.height, s.color);
    }
    }

    DrawText(to_string(numOfMoves).c_str(), 50, 50, 50, BLACK);
}