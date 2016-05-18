#include "Food.h"

Food::Food():sf::CircleShape(4) {
    consumed = false;
    setOrigin(4, 4);
    setFillColor(sf::Color::Yellow);
}

void Food::reset(int frame_width, int frame_height) {
    int x = rand() % (frame_width - 4) + 4;
    int y = rand() % (frame_height - 4) + 4;
    setPosition(x, y);
    consumed = false;
}

void Food::consume() {
    consumed = true;
}

bool Food::isConsumed() {
    return consumed;
}

Food::~Food() {
}
