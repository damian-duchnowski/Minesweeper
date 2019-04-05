//
// Created by Damian Duchnowski on 2019-04-02.
//

#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include <cmath>

MSSFMLView::MSSFMLView(MinesweeperBoard& b, int fieldSize, int x0, int y0)
        :board(b)
{
    sf::Vector2f LG(x0, y0);

    sf::Font font;
    font.loadFromFile("Roboto-Bold.ttf");

    for (int k = 0; k<board.getBoardHeight(); ++k) {
        for (int i = 0; i<board.getBoardWidth(); ++i) {
            texts[k][i].setFont(font);
            texts[k][i].setCharacterSize(16);
            texts[k][i].setFillColor(sf::Color(235, 225, 223));
            texts[k][i].setPosition(sf::Vector2f(fields[k][i].getPosition().x+0.5*fieldSize,
                    fields[k][i].getPosition().y+0.5*fieldSize));
            texts[k][i].setString(board.getFieldInfo(k, i));
        }
    }

    for (int i = 0; i<board.getBoardHeight(); ++i) {
        for (int j = 0; j<board.getBoardWidth(); ++j) {
            fields[i][j].setSize(sf::Vector2f(fieldSize, fieldSize));
            fields[i][j].setFillColor(sf::Color(46, 196, 182));     // (231,29,54)
            fields[i][j].setOutlineColor(sf::Color::Black);
            fields[i][j].setOutlineThickness(floor(-0.05*fieldSize));
            fields[i][j].setPosition(sf::Vector2f(LG.x+j*fieldSize, LG.y+i*fieldSize));
        }
    }
}

void MSSFMLView::draw(sf::RenderWindow& window)
{
    for (int i = 0; i<board.getBoardHeight(); ++i) {
        for (int j = 0; j<board.getBoardWidth(); ++j) {
            window.draw(fields[i][j]);
            window.draw(texts[i][j]);
        }
    }
}