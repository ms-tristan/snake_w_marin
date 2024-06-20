#include "../../includes/snake.h"
#include <iostream>
#include <vector>

using namespace std;

class Snake {
private:
    vector<vector_t> body;
    vector_t direction;


public:

    void move() {
        vector_t head = body[0];
        vector_t new_head = {head.x + direction.x, head.y + direction.y};
        body.insert(body.begin(), new_head);
        body.pop_back();
    }

};
