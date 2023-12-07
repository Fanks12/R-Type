/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** game
*/

#include <SFML/Graphics.hpp>
#include "Registry.hpp"

// need class Entity who stock index
// quand tu creer un entity etape:
// ajouté une nouvelle case dans chaque Component avec la fonction de registry
// retenir son index dans la variable a son nom qu'on reprend
// et ensuite ajouté autant de component que l'on veut // aucune method qui le fait


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::RectangleShape square(sf::Vector2f(10, 10));

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(square);

        // Update the window
        window.display();
    }
    return 0;
}