

        // Apple();
        // void place_apple();
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

void Apple::place_apple(Board board)
{
    // fait attention si la pomme est sur le serpent
    // fait attention taille du tableau
    apple_pos.x = rand() % 1;
    apple_pos.y = rand() % 1;
    if (board.tab[apple_pos.y][apple_pos.x] == 'O')
        place_apple(board);
}
