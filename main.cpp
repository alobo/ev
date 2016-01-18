#include <SFML/Graphics.hpp>
#include "Physics/Environment.h"
#include "AI/Creature.h"

int main() {
    int width = 1600;
    int height = 1200;

    sf::RenderWindow window(sf::VideoMode(width, height), "Main");

    Environment env = Environment(width, height, 0.0005);

    Creature creature = Creature();
    creature.position[0] = 400;
    creature.position[1] = 400;
    env.addObject(&creature);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        creature.draw(&window);

        window.display();
        env.step(1.0);
    }

    return 0;
}
