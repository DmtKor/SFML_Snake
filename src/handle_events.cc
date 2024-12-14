#include "header.hpp"

int handle_events(sf::RenderWindow &window, sf::Clock &clock, GameData &data) {
    while(window.pollEvent(data.event)) {
        if (data.event.type == sf::Event::Closed) {
            window.close();
        }
        else if (data.event.type == sf::Event::KeyReleased && window.hasFocus()) {
            switch (data.event.key.code)
            {
            case sf::Keyboard::Up:
                if(data.snake[0].x != data.snake[1].x || data.snake[0].y > data.snake[1].y) data.dir = 1;
                break;
            case sf::Keyboard::Right:
                if(data.snake[0].y != data.snake[1].y || data.snake[0].x > data.snake[1].x) data.dir = 0;
                break;
            case sf::Keyboard::Down:
                if(data.snake[0].x != data.snake[1].x || data.snake[0].y < data.snake[1].y) data.dir = 3;
                break;
            case sf::Keyboard::Left:
                if(data.snake[0].y != data.snake[1].y || data.snake[0].x < data.snake[1].x) data.dir = 2;
                break;
            //case sf::Keyboard::A:
            //    if (data.speed < 5) data.speed += 0.1;
            //    break;
            //case sf::Keyboard::D:
            //    if (data.speed > 0.1) data.speed -= 0.1;
            //    break;
            case sf::Keyboard::Q:
                window.close();
                break;
            case sf::Keyboard::Space:
                return -1;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}