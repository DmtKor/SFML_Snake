#include <SFML/Graphics.hpp>
#include <vector>

#ifndef GAME_DATA_H
#define GAME_DATA_H
struct Point {int x; int y;};
class GameData {
public:
    // 0 - r, 1 - d, 2 - l, 3 - u
    int dir;
    int cellSize;
    sf::Event event;
    int score;
    float speed_init;
    float speed;
    int x_field, y_field;
    int x_size, y_size;
    Point fruit;
    std::vector <Point>snake;
    sf::RectangleShape shape;
};
#endif

#ifndef HANDLE_EVENTS_H
#define HANDLE_EVENTS_H
int handle_events(sf::RenderWindow &window, sf::Clock &clock, GameData &data);
#endif

#ifndef LOGIC_UPDATE_H
#define LOGIC_UPDATE_H
int logic_update(GameData &data);
#endif

#ifndef DRAW_OBJECTS_H
#define DRAW_OBJECTS_H
void draw_objects(sf::RenderWindow &window, GameData &data);
#endif

#ifndef MENU_F
#define MENU_F
int menu(sf::RenderWindow &window, GameData &data, bool lost, sf::RectangleShape &restart_or_continue, sf::RectangleShape &quit);
#endif