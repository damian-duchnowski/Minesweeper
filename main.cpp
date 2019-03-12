#include <ctime>
#include <iostream>
#include "minesboard.h"

int main() {
    srand(time(NULL));
    MinesweeperBoard board(8, 10, DEBUG);
    board.debug_display();
}