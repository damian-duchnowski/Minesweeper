//
// Created by Damian Duchnowski on 2019-03-19.
//

#ifndef Z1_MSTEXTCONTROLLER_H
#define Z1_MSTEXTCONTROLLER_H

#include "minesboard.h"
#include "MSBoardTextView.h"

class MSTextController {
    MinesweeperBoard &board;
    MSBoardTextView &view;

public:
    MSTextController(MinesweeperBoard &b, MSBoardTextView &v);
    void play();
};

#endif //Z1_MSTEXTCONTROLLER_H
