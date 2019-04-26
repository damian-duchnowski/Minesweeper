//
// Created by Damian Duchnowski on 2019-04-02.
//

#ifndef Z1_MSSFMLVIEW_H
#define Z1_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "minesboard.h"

class MSSFMLView {
    MinesweeperBoard& board;
    sf::RectangleShape fields[100][100];
    sf::Text texts[100][100];
    sf::Font font;
public:
    MSSFMLView(MinesweeperBoard& b);
    void draw(sf::RenderWindow& window);
};

#endif //Z1_MSSFMLVIEW_H
