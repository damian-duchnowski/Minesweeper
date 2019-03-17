#include <ctime>
#include <iostream>
#include "minesboard.h"

int main() {
    srand(time(NULL));
    MinesweeperBoard board(9, 7, DEBUG);
    board.debug_display();
    std::cout << board.countMines(0, 1);
    std::cout << board.countMines(9, 2);
    std::cout << board.countMines(1, 2);
    std::cout << board.countMines(7, 6);
    std::cout << board.getFieldInfo(0, 1);
}