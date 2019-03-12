//
// Created by Damian Duchnowski on 2019-03-05.
//

#ifndef Z1_MINESBOARD_H
#define Z1_MINESBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard {
    Field board[100][100];
    int width;
    int height;

public:
    // generate a width*height sized board with the number of mines that depend on GameMode:
    // - EASY   - 10% of game fields with mines (random)
    // - NORMAL - 20% of game fields with mines (random)
    // - HARD   - 30% of game fields with mines (random)
    // - DEBUG  - predefined mine layout (read at the end of file)
    //
    // NOTE: You may assume, that width and height are not larger than 100
    // HINT: It is OK to allocate 100x100 board and only use part of it
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

    // simple getters - return appropriate values (passed to or calculated in constructor)
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
};

#endif //Z1_MINESBOARD_H
