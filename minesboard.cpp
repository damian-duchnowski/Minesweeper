//
// Created by Damian Duchnowski on 2019-03-05.
//

#include <cmath>
#include <iostream>
#include "minesboard.h"
using namespace std;

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    MinesweeperBoard::width = width;
    MinesweeperBoard::height = height;

    for (int i = 0; i<MinesweeperBoard::height; ++i) {
        for (int j = 0; j<MinesweeperBoard::width; ++j) {
            board[i][j] = {false, false, false};
        }
    }

    int number_of_fields = MinesweeperBoard::width*MinesweeperBoard::height;
    double number_of_mines = 0;

    switch (mode) {
    case EASY:number_of_mines = floor(0.1*number_of_fields);
        break;

    case NORMAL:number_of_mines = floor(0.2*number_of_fields);
        break;

    case HARD:number_of_mines = floor(0.3*number_of_fields);
        break;

    case DEBUG:
        for (int i = 0; i<MinesweeperBoard::height; ++i) {
            for (int j = 0; j<MinesweeperBoard::width; ++j) {
                if (i==j) board[i][j].hasMine = true;
                if (i==0) board[j][i].hasMine = true;
                if (j==0 && i%2==0) board[j][i].hasMine = true;
            }
        }
        break;
    }

    for (int k = 0; k<number_of_mines; ++k) {
        int x = rand()%MinesweeperBoard::height;
        int y = rand()%MinesweeperBoard::width;

        if (board[y][x].hasMine) {
            k--;
            continue;
        }

        board[y][x].hasMine = true;
    }
}

void MinesweeperBoard::debug_display() const
{
    for (int i = 0; i<MinesweeperBoard::height; ++i) {
        for (int j = 0; j<MinesweeperBoard::width; ++j) {
            char hasMine;
            char hasFlag;
            char isRevealed;

            if (board[i][j].hasMine) {
                hasMine = 'M';
            }
            else {
                hasMine = '.';
            }

            if (board[i][j].isRevealed) {
                isRevealed = 'o';
            }
            else {
                isRevealed = '.';
            }

            if (board[i][j].hasFlag) {
                hasFlag = 'f';
            }
            else {
                hasFlag = '.';
            }

            cout << "[" << hasMine << isRevealed << hasFlag << "]";
        }
        cout << endl;
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return MinesweeperBoard::width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return MinesweeperBoard::height;
}

int MinesweeperBoard::getMineCount() const
{
    int mine_count = 0;
    for (int i = 0; i<MinesweeperBoard::width; ++i) {
        for (int j = 0; j<MinesweeperBoard::height; ++j) {
            if (board[i][j].hasMine) {
                mine_count++;
            }
        }
    }
    return mine_count;
}

int MinesweeperBoard::countMines(int x, int y) const
{
    if (!board[y][x].isRevealed) return -1;  // comment this out if needed
    if (x<0 || x>MinesweeperBoard::height || y<0 || y>MinesweeperBoard::width) return -1;

    int counter = 0;
    for (int i = -1; i<=1; ++i) {
        for (int j = -1; j<=1; ++j) {
            if (i==0 && j==0) continue;
            if (x+j<0 || x+j>MinesweeperBoard::height || y+i<0 || y+i>MinesweeperBoard::width) continue;
            if (board[y+i][x+j].hasMine) counter++;
        }
    }
    return counter;
};

bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if (board[y][x].hasFlag) return true;
    if (x<0 || x>MinesweeperBoard::height || y<0 || y>MinesweeperBoard::width) return false;
    if (!board[y][x].hasFlag) return false;
    if (board[y][x].isRevealed) return false;
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if (MinesweeperBoard::getGameState()==RUNNING) {
        if (x>=0 && x<MinesweeperBoard::height && y>=0 && y<=MinesweeperBoard::width) {
            if (!board[y][x].isRevealed) {
                if (MinesweeperBoard::hasFlag(x, y)) board[y][x].hasFlag = false;
                else board[y][x].hasFlag = true;
            }
        }
    }
}

void MinesweeperBoard::revealField(int x, int y)
{
    if (MinesweeperBoard::getGameState()==RUNNING) {
        if (x>=0 && x<MinesweeperBoard::height && y>=0 && y<=MinesweeperBoard::width &&
                !MinesweeperBoard::hasFlag(x, y)) {
            if (!board[y][x].isRevealed && !board[y][x].hasMine) board[y][x].isRevealed = true;
            if (!board[y][x].isRevealed && board[y][x].hasMine) {
                if (checkIfFirstMove()) {
                    int new_x = 0;
                    int new_y = 0;
                    do {
                        new_x = rand()%MinesweeperBoard::height;
                        new_y = rand()%MinesweeperBoard::width;
                    }
                    while (board[new_y][new_x].hasMine);
                    board[y][x].hasMine = false;
                    board[new_y][new_x].hasMine = true;
                    board[y][x].isRevealed = true;
                }
                else board[y][x].isRevealed = true;
            }
        }
    }
}

bool MinesweeperBoard::checkIfFirstMove() const
{
    for (int i = 0; i<MinesweeperBoard::height; ++i) {
        for (int j = 0; j<MinesweeperBoard::width; ++j) {
            if (isRevealed(i, j)) return false;
        }
    }
    return true;
}

bool MinesweeperBoard::isRevealed(int x, int y) const
{
    return board[y][x].isRevealed;
}

GameState MinesweeperBoard::getGameState() const {
    for (int i = 0; i<MinesweeperBoard::height; ++i) {
        for (int j = 0; j<MinesweeperBoard::width; ++j) {
            if (board[i][j].hasMine && board[i][j].isRevealed) return FINISHED_LOSS;
            if (board[i][j].hasMine && !MinesweeperBoard::hasFlag(i, j)) return RUNNING;
        }
    }
    return FINISHED_WIN;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if (x<0 || x>MinesweeperBoard::height || y<0 || y>MinesweeperBoard::width) return '#';
    if (!board[y][x].isRevealed && MinesweeperBoard::hasFlag(x, y)) return 'F';
    if (!board[y][x].isRevealed && !MinesweeperBoard::hasFlag(x, y)) return '_';
    if (board[y][x].isRevealed && board[y][x].hasMine) return 'x';
    if (board[y][x].isRevealed && MinesweeperBoard::countMines(x, y)==0) return ' ';
    if (board[y][x].isRevealed && MinesweeperBoard::countMines(x, y)!=0)
        return static_cast<char>(MinesweeperBoard::countMines(x, y))+'0';
    else return '?';    // FOR DEBUG PURPOSES
}