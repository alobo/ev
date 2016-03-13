#include <iostream>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Physics/Environment.h"
#include "AI/Creature.h"
#include "AI/Food.h"
#include "AI/Mutator.h"

const int WIDTH = 1600;
const int HEIGHT = 1200;
const int NUM_CREATURES = 25;
const int NUM_FOOD = 50;
const int GENERATION_LENGTH_SECONDS = 10;

Environment env = Environment(WIDTH, HEIGHT, 0.5);
Creature creatures [NUM_CREATURES];
std::vector<Food> food;

/**
* Provide an interactive console
*/
void launchConsole() {
    std::cout << "Commands" << std::endl;
    std::cout << "\tr:\tResume Simulation" << std::endl;
    for (std::string line; line != "r"; std::getline(std::cin, line)) {
        int index = 0;
        switch (line[0]) {
            case 'c':
                index = (int) (line[2] - '0');
                std::cout << creatures[index].getNeuralNetwork() << std::endl;
                break;
        }
    }
}

bool compareCreatures(Creature  & a, Creature  & b) {
    return a.getEnergy() > b.getEnergy();
}

int main() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Main");

    // Setup test creature
    Creature creature = Creature();
    creature.position[0] = 100;
    creature.position[1] = 100;
    // creature.velocity[0] = 20;
    // creature.velocity[1] = 20;
    creature.setRotation(50);
    env.addObject(&creature);

    // Setup creatures
    for (int i = 0; i < NUM_CREATURES; ++i) {
        creatures[i] = Creature();
        creatures[i].position[0] = 50 * (i + 1);
        creatures[i].position[1] = 50 * (i + 1);
        creatures[i].setRotation(0);
        env.addObject(&creatures[i]);
    }

    // Setup food
    for (int i = 0; i < NUM_FOOD; ++i) {
        Food f = Food();
        f.reset(WIDTH, HEIGHT);
        food.push_back(f);
    }

    sf::Clock frame_clock;
    sf::Clock gen_clock;
    int gen_count = 0;
    int frame_count = 0;

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
                    } else if (event.key.code == sf::Keyboard::P) {
                        launchConsole();
                        frame_clock.restart();
                    }
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        sf::Vector2f position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                    }
                    break;

                default:
                    break;
            }
        }

        window.clear();

        for (int i = 0; i < NUM_FOOD; ++i) {
            if (!food[i].isConsumed()) window.draw(food[i]);
        }

        // Debug creature
        creature.draw(&window);
        for (int i = 0; i < NUM_FOOD; ++i) {
            if (creature.isPointInFOV(food[i].getPosition())) {
                // printf("%f\n", creature.distanceToPoint(food[i].getPosition()));
            }
        }

        for (int i = 0; i < NUM_CREATURES; ++i) {
            creatures[i].process(&food);
            creatures[i].draw(&window);
        }

        // Handle generations
        if (gen_clock.getElapsedTime().asSeconds() > GENERATION_LENGTH_SECONDS) {
            std::cout << "Generation: " << ++gen_count << std::endl;

            // Reset food
            for (int i = 0; i < NUM_FOOD; ++i) {
                food[i].reset(WIDTH, HEIGHT);
            }

            // Sort by energy level
            std::sort(creatures, creatures + NUM_CREATURES, compareCreatures);

            // Select and mutate the top 50% of creatures
            Mutator mutator = Mutator();
            for (int i = 0; i < NUM_CREATURES/2; ++i) {
                printf("Creature %d  %f\n", i, creatures[i].getEnergy());
                mutator.setTarget(&creatures[i]);
                creatures[i].resetEnergy();
                creatures[i].position[0] = WIDTH / 2;
                creatures[i].position[1] = HEIGHT / 2;

                mutator.mutate(&creatures[NUM_CREATURES - 1 - i]);
                creatures[NUM_CREATURES - 1 - i].resetEnergy();
                creatures[NUM_CREATURES - 1 - i].position[0] = WIDTH / 2;
                creatures[NUM_CREATURES - 1 - i].position[1] = HEIGHT / 2;
            }

            gen_clock.restart();
        }

        window.display();

        sf::Time elapsed = frame_clock.restart();
        env.step(elapsed.asSeconds());
    }

    return 0;
}
