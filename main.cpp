#include <ctime>
#include <iostream>
#include "minesboard.h"
#include "MSBoardTextView.h"

int main() {
    srand(time(NULL));
    MinesweeperBoard board(9, 7, DEBUG);
    MSBoardTextView view (board);
    view.display();
//    if you want to test countMines below, comment out the marked line in this function
//    std::cout << board.countMines(0, 1);
//    std::cout << board.countMines(9, 2);
//    std::cout << board.countMines(1, 2);
//    std::cout << board.countMines(7, 6);
//    std::cout << board.getFieldInfo(0, 1);
}