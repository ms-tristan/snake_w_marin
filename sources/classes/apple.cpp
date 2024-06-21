

#include "../../includes/class.h"

Apple::Apple()
{
    apple_pos.x = 0;
    apple_pos.y = 0;
}

Apple::Apple(int x, int y)
{
    apple_pos.x = x;
    apple_pos.y = y;
}

void Apple::place_apple(Board *board)
{
    apple_pos.x = rand() % 19;
    apple_pos.y = rand() % 19;

    if (board->snake.onBody(apple_pos) == true)
        place_apple(board);
    else {
        board->tab[apple_pos.y][apple_pos.x] = '@';

    }
}

vector_t Apple::getApplePos()
{
    return apple_pos;
}