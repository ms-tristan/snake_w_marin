#include "../../includes/snake.h"
#include "../../includes/class.h"
#include <vector>
#include <ostream>
#include <iostream>
#include <ncurses.h>
using namespace std;

Snake::Snake(vector_t pos = {0, 0}, vector_t dir = {1, 0}) {
    vector_t head = pos;
    vector_t first_body_part = {head.x - dir.x, head.y - dir.y};
    body.push_back(head);
    body.push_back(first_body_part);
    direction = dir;
}

bool checkOutsideMap(vector_t *vector)
{
    if (vector->x < 0 || vector->x > 19 || vector->y < 0 || vector->y > 19)
        return true;
    return false;
}
void Snake::move(Board *board) {
    vector_t head = body[0];
    vector_t new_head = {head.x + direction.x, head.y + direction.y};

    if (checkOutsideMap(&new_head) || onBody(new_head))
    {
        endwin();
        exit(0);
    }
    body.insert(body.begin(), new_head);
    board->tab[body.back().y][body.back().x] = ' ';
    body.pop_back();
    for (vector_t part : body)
        board->tab[part.y][part.x] = '#';
    board->tab[body.begin()->y][body.begin()->x] = 'O';
}

void Snake::change_direction(vector_t new_direction) {
    direction = new_direction;
}

vector_t Snake::get_position(void) {
    return body[0];
}

bool Snake::onBody(vector_t target) {
    for (vector_t part : body) {
        if (part.x == target.x && part.y == target.y)
            return true;
    }
    return false;
}

void Snake::grow() {
    body.push_back(body.back());
}
