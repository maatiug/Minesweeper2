 #include "SFML/Graphics.hpp"
#include "Game.hpp"
#include "Error.hpp"
#include <iostream>

using namespace std;
using namespace sf;

/**
 * \brief Main function
 *
 * \param argc - number of args
 * \param argv - values of arg
 * \return int - error code
 * \retval 0 - correct close
 */
int main( int argc, char* argv[] ){

    try {
        /// 1. Choose sizes of the board.
        Game game( argc, argv );    //< Main object of game


        /// 1. Create window
        RenderWindow window(
            VideoMode( game.width(), game.height() ),
            "Minesweeper | maatiug",
            Style::Close | Style::Titlebar  );
        Event event;


        /// 3. Game loop
        bool change = true;

        while( window.isOpen() ){

            //* Process events
            while( window.pollEvent(event) ){

                // Close window: exit
                if (event.type == Event::Closed)
                    window.close();

                // Buttons
                if( Mouse::isButtonPressed( Mouse::Left ) )
                    game.click( window, Mouse::Left );

                if( Mouse::isButtonPressed( Mouse::Right ) )
                    game.click( window, Mouse::Right );

                change = true;
            }

            //* Clock
            if( game.clockChange() ) change = true;

            //* Display
            if( change ){
                // Clear screen
                window.clear();
                // Draw the string
                window.draw( game );
                // Update the window
                window.display();

                change = false;
            }

            sf::sleep( milliseconds( SLEEP_TIME ) );
        }

    }
    catch( const Error& err ){
        cerr << "!!! Critical error: " << endl;
        cerr << "! " << err.what() << endl;
    }

    return 0;
}