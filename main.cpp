#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "minesboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");

    srand(time(NULL));
    MinesweeperBoard board(30, 20, DEBUG);
    MSSFMLView view(board);

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type==sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(85, 85, 85));
        view.draw(window);

        // end the current frame
        window.display();
    }

    return 0;
}