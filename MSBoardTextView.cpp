//
// Created by Damian Duchnowski on 2019-03-19.
//

#include <iostream>
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &b):board(b) {}

void MSBoardTextView::display() const {
    for (int i = 0; i < board.getBoardHeight(); ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            std::cout << "[" << board.getFieldInfo(i, j) << "]";
        }
        std::cout << std::endl;
    }
}