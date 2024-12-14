#include "header.hpp"

int menu(sf::RenderWindow &window, GameData &data, bool lost, sf::RectangleShape &cont, sf::RectangleShape &quit) {
    bool play = false;
    while (window.isOpen())
    {
        while(window.pollEvent(data.event)) {
            switch (data.event.type)
            {
            case sf::Event::Closed:
                window.close();
                return 0;
                break;
            case sf::Event::KeyReleased:
                if(data.event.key.code == sf::Keyboard::Space) play = true;
                break;
            case sf::Event::MouseButtonReleased:
                sf::Vector2i pos = sf::Mouse::getPosition(window);

                if (pos.x >= cont.getPosition().x && pos.x <= cont.getPosition().x + cont.getSize().x && pos.y >= cont.getPosition().y && pos.y <= cont.getPosition().y + cont.getSize().y) play = true;

                else if (pos.x >= quit.getPosition().x && pos.x <= quit.getPosition().x + quit.getSize().x && pos.y >= quit.getPosition().y && pos.y <= quit.getPosition().y + quit.getSize().y) {
                    window.close();
                    return 0;
                }
                break;
            }
        }

        window.clear(sf::Color::Cyan);
        window.draw(cont);
        window.draw(quit);
        window.display();
        if (play) {
            if (lost) {
                data.fruit = {data.x_field / 2, data.y_field / 2};
                data.score = 0;
                data.speed = data.speed_init;
                data.snake = {{4, 3}, {3, 3}, {2, 3}};
                data.dir = 0;
            }
            return 0;
        }
    }
}