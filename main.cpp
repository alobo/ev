#include <SFML/Graphics.hpp>
#include "Physics/Environment.h"
#include "AI/Creature.h"

int main() {
    int width = 1600;
    int height = 1200;

    sf::RenderWindow window(sf::VideoMode(width, height), "Main");

    Environment env = Environment(width, height, 0.5);

    // Setup test creature
    Creature creature = Creature();
    creature.position[0] = 100;
    creature.position[1] = 100;
    creature.velocity[0] = 20;
    creature.velocity[1] = 20;
    creature.setRotation(50);
    env.addObject(&creature);

    // Setup creatures
    static const int NUM_CREATURES = 4;
    Creature creatures [NUM_CREATURES];
    for (int i = 0; i < NUM_CREATURES; ++i) {
        creatures[i] = Creature();
        creatures[i].position[0] = 100 * (i + 1);
        creatures[i].position[1] = 100 * (i + 1);
        env.addObject(&creatures[i]);
    }

    // Setup food
    static const int NUM_FOOD = 50;
    std::vector<sf::CircleShape> food;
    for (int i = 0; i < NUM_FOOD; ++i) {
        sf::CircleShape f = sf::CircleShape(4);
        f.setOrigin(4, 4);
        f.setFillColor(sf::Color::Yellow);
        int x = rand() % (width - 4) + 4;
        int y = rand() % (height - 4) + 4;
        f.setPosition(x, y);
        food.push_back(f);
    }

    sf::Clock frame_clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::W) {
                        creature.moveForward();
                    } else if (event.key.code == sf::Keyboard::S) {
                        printf("%s\n", "S PRESSED");
                    } else if (event.key.code == sf::Keyboard::A) {
                        creature.setRotation(creature.getRotation() + 5);
                    } else if (event.key.code == sf::Keyboard::D) {
                        creature.setRotation(creature.getRotation() - 5);
                    }
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        sf::Vector2f position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                        printf("%d\n", creature.isPointInFOV(position));
                    }
                    break;

                default:
                    break;
            }
        }

        window.clear();

        for (int i = 0; i < NUM_FOOD; ++i) {
            window.draw(food[i]);
        }

        creature.draw(&window);
        for (int i = 0; i < NUM_CREATURES; ++i) {
            creatures[i].process(food);
            creatures[i].draw(&window);
        }

        window.display();

        sf::Time elapsed = frame_clock.restart();
        env.step(elapsed.asSeconds());
    }

    return 0;
}
