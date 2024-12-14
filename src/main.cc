#include <iostream>
#include "header.hpp"

int main() 
{

    GameData data;
    data.x_field = 35;
    data.y_field = 30;
    data.cellSize = 20;
    data.dir = 0;
    data.fruit = {data.x_field / 2, data.y_field / 2};
    data.score = 0;
    data.shape.setSize(sf::Vector2f(data.cellSize, data.cellSize));
    data.speed_init = 0.3;
    data.speed = data.speed_init;
    data.x_size = data.x_field * data.cellSize;
    data.y_size = data.y_field * data.cellSize;
    data.snake = {{4, 3}, {3, 3}, {2, 3}};

    sf::Texture texture_continue;
    texture_continue.loadFromFile("img/continue.png");
    sf::RectangleShape s_continue(sf::Vector2f(90, 90));
    s_continue.setTexture(&texture_continue);
    s_continue.setPosition(sf::Vector2f(data.x_size/2 - 90/2, data.y_size/2 - 95));

    sf::Texture texture_quit;
    texture_quit.loadFromFile("img/quit.png");
    sf::RectangleShape s_quit(sf::Vector2f(90, 90));
    s_quit.setTexture(&texture_quit);
    s_quit.setPosition(sf::Vector2f(data.x_size/2 - 90/2, data.y_size/2 + 5));

    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(data.x_size, data.y_size), "Snake", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    
    sf::Clock clock;
    sf::Time elapsed = sf::seconds(0);
    menu(window, data, false, s_continue, s_quit);
    int to_menu = 0;
    while (window.isOpen())
    {
        to_menu = handle_events(window, clock, data);
        if (to_menu == -1) menu(window, data, false, s_continue, s_quit);
        
        elapsed += clock.getElapsedTime();
        clock.restart();
        if (elapsed.asSeconds() >= data.speed) {
            int res = logic_update(data);
            if (res == -1) {
                menu(window, data, true, s_continue, s_quit);
            }
            clock.restart();
            elapsed = sf::seconds(0);
        }

        draw_objects(window, data);

        window.display();
    }
}