//
// Created by Damian Duchnowski on 2019-03-05.
//

#include <iostream>
#include "minesboard.h"
using namespace std;

MinesweeperBoard::MinesweeperBoard() {
    MinesweeperBoard::width = 10;
    MinesweeperBoard::height = 10;

    for (int i = 0; i < MinesweeperBoard::height; ++i) {
        for (int j = 0; j < MinesweeperBoard::width; ++j) {
            board[i][j] = {false, false, false};
        }
    }

    board[0][0] = {true, false, false};
    board[1][1] = {false, false, true};
    board[0][2] = {true, true, false};
}

void MinesweeperBoard::debug_display() const {
    for (int i = 0; i < MinesweeperBoard::height; ++i) {
        for (int j = 0; j < MinesweeperBoard::width; ++j) {
            char hasMine;
            char hasFlag;
            char isRevealed;

            if (board[i][j].hasMine) {
                hasMine = 'M';
            } else {
                hasMine = '.';
            }

            if (board[i][j].isRevealed) {
                isRevealed = 'o';
            } else {
                isRevealed = '.';
            }

            if (board[i][j].hasFlag) {
                hasFlag = 'f';
            } else {
                hasFlag = '.';
            }

            cout << "[" << hasMine << isRevealed << hasFlag << "]";
        }

        cout << endl;
    }
}