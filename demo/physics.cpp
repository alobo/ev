#include <SFML/Graphics.hpp>
#include "../Physics/Environment.h"
#include "../Circle.h"

int main() {
    int width = 800;
    int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Physics Demo");

    Environment env = Environment(width, height, 0.0005);
    Circle circle1 = Circle();
    circle1.position[0] = 100;
    circle1.position[1] = 100;
    circle1.velocity[0] = 1;
    circle1.velocity[1] = 0.5;
    env.addObject(&circle1);

    Circle circle2 = Circle();
    circle2.position[0] = 0;
    circle2.position[1] = 0;
    circle2.velocity[0] = 1;
    circle2.velocity[1] = 1;
    circle2.acceleration[0] = 0.001;
    circle2.acceleration[1] = 0;
    env.addObject(&circle2);

    Circle circle3 = Circle();
    circle3.position[0] = 300;
    circle3.position[1] = 300;
    circle3.velocity[0] = 1;
    circle3.velocity[1] = 0.5;
    env.addObject(&circle3);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        circle1.draw(&window);
        circle2.draw(&window);
        circle3.draw(&window);
        window.display();
        env.step(1.0);
    }

    return 0;
}
