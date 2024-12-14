#include "header.hpp"

void draw_objects(sf::RenderWindow &window, GameData &data) {
    window.clear(sf::Color::Cyan);
    data.shape.setFillColor(sf::Color::Green);
    for (int i = 0; i < data.snake.size(); i++) {
        data.shape.setPosition(data.snake[i].x * data.cellSize, data.snake[i].y * data.cellSize);
        window.draw(data.shape);
    }
    data.shape.setFillColor(sf::Color::Red);
    data.shape.setPosition(data.fruit.x * data.cellSize, data.fruit.y * data.cellSize);
    window.draw(data.shape);
}