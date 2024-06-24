
#include "../includes/class.h"
#include "../includes/snake.h"
#include <unistd.h>


void Board::gameLoop()
{
    this->InitNcurse();
    while (1) {
        this->update(this);
        this->printBoard();
        usleep(300000 - this->score * 5000);
    }
}