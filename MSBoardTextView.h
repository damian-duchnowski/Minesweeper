//
// Created by Damian Duchnowski on 2019-03-19.
//

#ifndef Z1_MSBOARDTEXTVIEW_H
#define Z1_MSBOARDTEXTVIEW_H

#include "minesboard.h"

class MSBoardTextView {
    MinesweeperBoard& board;
public:
    explicit MSBoardTextView(MinesweeperBoard& b);
    void display() const;
};

#endif //Z1_MSBOARDTEXTVIEW_H
