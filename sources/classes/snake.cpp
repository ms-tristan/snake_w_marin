#include "../../includes/snake.h"
#include "../../includes/class.h"
#include <vector>

using namespace std;


Snake::Snake(vector_t pos = {0, 0}, vector_t dir = {1, 0}) {
        vector_t head = pos;
        body.push_back(head);
        direction = dir;
}

void Snake::move() {
        vector_t head = body[0];
        vector_t new_head = {head.x + direction.x, head.y + direction.y};
        body.insert(body.begin(), new_head);
        body.pop_back();
        if (!is_growing)
            body.push_back(head);
        else
            is_growing = false;
}

void Snake::change_direction(vector_t new_direction) {
        direction = new_direction;
}

vector_t Snake::get_position(void) {
        return body[0];
}

vector<vector_t> Snake::get_body() {
        return body;
}

void Snake::grow() {
    is_growing = true;
}
