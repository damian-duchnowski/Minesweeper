//
// Created by Damian Duchnowski on 2019-03-05.
//

#include <cmath>
#include <iostream>
#include "minesboard.h"
using namespace std;

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {
    MinesweeperBoard::width = width;
    MinesweeperBoard::height = height;

    for (int i = 0; i < MinesweeperBoard::height; ++i) {
        for (int j = 0; j < MinesweeperBoard::width; ++j) {
            board[i][j] = {false, false, false};
        }
    }

    int number_of_fields = MinesweeperBoard::width * MinesweeperBoard::height;
    double number_of_mines = 0;

    switch (mode) {
        case EASY:
            number_of_mines = floor(0.1 * number_of_fields);
            break;

        case NORMAL:
            number_of_mines = floor(0.2 * number_of_fields);
            break;

        case HARD:
            number_of_mines = floor(0.3 * number_of_fields);
            break;

        case DEBUG:
            for (int i = 0; i < MinesweeperBoard::height; ++i) {
                for (int j = 0; j < MinesweeperBoard::width; ++j) {
                    if (i == j) board[i][j].hasMine = true;
                    if (i == 0) board[i][j].hasMine = true;
                    if (j == 0 && i % 2 == 0) board[i][j].hasMine = true;
                }
            }
            break;
    }

    for (int k = 0; k < number_of_mines; ++k) {
        int x = rand() % MinesweeperBoard::height;
        int y = rand() % MinesweeperBoard::width;

        if (board[y][x].hasMine) {
            k--;
            continue;
        }

        board[y][x].hasMine = true;
    }
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

int MinesweeperBoard::getBoardWidth() const {
    return MinesweeperBoard::width;
}

int MinesweeperBoard::getBoardHeight() const {
    return MinesweeperBoard::height;
}

int MinesweeperBoard::getMineCount() const {
    int mine_count = 0;
    for (int i = 0; i < MinesweeperBoard::width; ++i) {
        for (int j = 0; j < MinesweeperBoard::height; ++j) {
            if (board[i][j].hasMine) {
                mine_count++;
            }
        }
    }
    return mine_count;
}

int MinesweeperBoard::countMines(int x, int y) const {
//    if(!board[y][x].isRevealed) return -1;
    if(x < 0 || x > MinesweeperBoard::width || y < 0 || y > MinesweeperBoard::height) return -1;

    int counter = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            if (board[y + i][x + j].hasMine) counter++;
        }
    }
    return counter;
};

bool MinesweeperBoard::hasFlag(int x, int y) const {
    if (board[y][x].hasFlag) return true;
    if (x < 0 || x > MinesweeperBoard::width || y < 0 || y > MinesweeperBoard::height) return false;
    if (!board[y][x].hasFlag) return false;
    if (board[y][x].isRevealed) return false;
}

void MinesweeperBoard::toggleFlag(int x, int y) {
    if (!board[y][x].isRevealed) {
        if (board[y][x].hasFlag) board[y][x].hasFlag = false;
        else board[y][x].hasFlag = true;
    }
}