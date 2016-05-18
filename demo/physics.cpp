#include <SFML/Graphics.hpp>
#include "../Physics/Environment.h"
#include "Circle.h"

int main() {
    int width = 1600;
    int height = 1200;

    sf::RenderWindow window(sf::VideoMode(width, height), "Physics Demo");

    Environment env = Environment(width, height, 0.005);

    const int num_circles = 25;
    Circle circles [num_circles];
    for (int i = 0; i < num_circles; ++i) {
        circles[i] = Circle();
        circles[i].position[0] = 12 * (i + 1);
        circles[i].position[1] = 12 * (i + 1);
        circles[i].velocity[0] = 100 * (rand()/100 * i * (i % 2) ? -5 : 5);
        circles[i].velocity[1] = 100 * (i * (i % 2) ? 5 : -5);
        circles[i].acceleration[1] = 980;
        env.addObject(&circles[i]);
    }

    sf::Clock frame_clock;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < num_circles; ++i) {
            circles[i].draw(&window);
        }

        window.display();

        sf::Time elapsed = frame_clock.restart();
        env.step(elapsed.asSeconds());
    }

    return 0;
}
