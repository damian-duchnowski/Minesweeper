//
// Created by Damian Duchnowski on 2019-03-19.
//

#include <iostream>
#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard& b, MSBoardTextView& v)
        :board(b), view(v) { }

void MSTextController::displayGreeting()
{
    std::cout << "\n"
                 "███╗   ███╗██╗███╗   ██╗███████╗███████╗██╗    ██╗███████╗███████╗██████╗ ███████╗██████╗ \n"
                 "████╗ ████║██║████╗  ██║██╔════╝██╔════╝██║    ██║██╔════╝██╔════╝██╔══██╗██╔════╝██╔══██╗\n"
                 "██╔████╔██║██║██╔██╗ ██║█████╗  ███████╗██║ █╗ ██║█████╗  █████╗  ██████╔╝█████╗  ██████╔╝\n"
                 "██║╚██╔╝██║██║██║╚██╗██║██╔══╝  ╚════██║██║███╗██║██╔══╝  ██╔══╝  ██╔═══╝ ██╔══╝  ██╔══██╗\n"
                 "██║ ╚═╝ ██║██║██║ ╚████║███████╗███████║╚███╔███╔╝███████╗███████╗██║     ███████╗██║  ██║\n"
                 "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚══════╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝\n"
                 "                                                                                          "
              << std::endl;

    std::cout
            << "┌───────────────────────────────────────────────────────────────────────────────────────────────────────┐\n"
               "│ Po planszy poruszaj się klawiszami WASD, r - odkrywa aktualnie wybrane pole, f - stawia na nim flagę. │\n"
               "└───────────────────────────────────────────────────────────────────────────────────────────────────────┘" << std::endl;
}

void MSTextController::play()
{
    displayGreeting();

//    27 - esc, a - 97, d - 100, 102 - f, 114 - r, 115 - s, 119 - w
    int key;
    int x = 0, y = 0;
    view.display(0, 0);
    do {
        key = getchar();

        if (key==102) {
            if (!(board.isRevealed(x, y) && board.hasFlag(x, y))) {
                board.toggleFlag(x, y);
                view.display(x, y);
            }
        }

        else if (key==114) {
            board.revealField(x, y);
            view.display(x, y);
        }

        switch (key) {
        case 119:
            if (x-1<0) x = board.getBoardHeight()-1;
            else x = x-1;
            view.display(x, y);
            break;
        case 115:
            if (x+1>=board.getBoardHeight()) x = 0;
            else x = x+1;
            view.display(x, y);
            break;
        case 97:
            if (y-1<0) y = board.getBoardWidth()-1;
            else y = y-1;
            view.display(x, y);
            break;
        case 100:
            if (y+1>=board.getBoardWidth()) y = 0;
            else y = y+1;
            view.display(x, y);
            break;
        default:continue;
        }
    }
    while (key!=98 && board.getGameState()==RUNNING);
}