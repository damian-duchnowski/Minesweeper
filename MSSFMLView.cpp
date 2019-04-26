//
// Created by Damian Duchnowski on 2019-04-02.
//

#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include <cmath>

MSSFMLView::MSSFMLView(MinesweeperBoard& b)
        :board(b)
{
    int fieldSize = (int)(768 - 2*50) / board.getBoardHeight();

    sf::Vector2f LG((int)(1024 - board.getBoardWidth()*fieldSize) / 2, 50);

    int characterSize[3] = {40, 30, 20};
    
    font.loadFromFile("Roboto-Bold.ttf");

    for (int i = 0; i<board.getBoardHeight(); ++i) {
        for (int j = 0; j<board.getBoardWidth(); ++j) {
            fields[i][j].setSize(sf::Vector2f(fieldSize, fieldSize));
            fields[i][j].setFillColor(sf::Color(46, 196, 182));
            fields[i][j].setOutlineColor(sf::Color::Black);
            fields[i][j].setOutlineThickness(floor(-0.05*fieldSize));
            fields[i][j].setPosition(sf::Vector2f(LG.x+j*fieldSize, LG.y+i*fieldSize));
        }
    }

    for (int k = 0; k<board.getBoardHeight(); ++k) {
        for (int l = 0; l<board.getBoardWidth(); ++l) {
            if (board.isRevealed(k, l)) {
                texts[k][l].setFont(font);
                if (board.getBoardWidth() == 10) texts[k][l].setCharacterSize(40);
                else if (board.getBoardWidth() == 20) texts[k][l].setCharacterSize(30);
                else if (board.getBoardWidth() == 30) texts[k][l].setCharacterSize(20);
                texts[k][l].setFillColor(sf::Color(235, 225, 223));
                texts[k][l].setPosition(sf::Vector2f(fields[k][l].getPosition().x+0.35*fieldSize,
                        fields[k][l].getPosition().y+0.1*fieldSize));
                texts[k][l].setString(board.getFieldInfo(k, l));
            }
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