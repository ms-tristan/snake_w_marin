
#include "../includes/class.h"
#include "../includes/snake.h"
#include <unistd.h>


void Board::gameLoop()
{
    while (1) {
        this->update(this);
        this->printBoard();
        usleep(300000 - this->score * 5000);
    }
}