#include "header.hpp"

int logic_update(GameData &data) {
    Point new_head = {data.snake[0]};
    int x_d = 0;
    int y_d = 0;
    switch (data.dir)
    {
    case 0:
        x_d = 1;
        break;
    case 1:
        y_d = -1;
        break;
    case 2:
        x_d = -1;
        break;
    case 3:
        y_d = 1;
        break;
    default:
        break;
    }
    new_head.x += x_d;
    new_head.y += y_d;
    for (long unsigned int i = 0; i < data.snake.size(); i++) {
        if ((data.snake[i].x == new_head.x && data.snake[i].y == new_head.y)) {
            return -1;
        }
    }
    if (new_head.x < 0 || new_head.x >= data.x_field || new_head.y < 0 || new_head.y >= data.y_field) return -1;
    bool plus_len = (data.fruit.x == new_head.x && data.fruit.y == new_head.y);
    if (plus_len) {
        data.score += 1;
        if (data.speed > 0.05) data.speed *= 0.9;
        data.snake.insert(data.snake.begin(), new_head);
        Point new_fruit;
        while(true) {
            new_fruit = {rand() % data.x_field, rand() % data.y_field};
            bool c = false;
            for (long unsigned int i = 0; i < data.snake.size(); i++) {
                if ((data.snake[i].x == new_fruit.x && data.snake[i].y == new_fruit.y)) {
                    c = true;
                }
            }
            if (c) continue;
            data.fruit = {new_fruit.x, new_fruit.y};
            break;
        }
    }
    else {
        data.snake.insert(data.snake.begin(), new_head);
        data.snake.pop_back();
    }
    return 0;

}