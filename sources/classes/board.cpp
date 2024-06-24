
#include "../../includes/class.h"
#include "../../includes/snake.h"
#include <iostream>
#include <ostream>
#include <ncurses.h>

Board::Board() : tab(20, std::string(20, ' ')), snake(vector_t{10, 10}, vector_t{0, 1}), apple(), score(1)
{
    this->apple.place_apple(this);
}

void Board::captureInput()
{
    nodelay(stdscr, true); // Set getch() to non-blocking mode
    int ch = getch();
    if (ch != ERR) // Check if a key is pressed
    {
        switch (ch)
        {
        case KEY_UP:
            this->snake.change_direction(vector_t{0, -1});
            break;
        case KEY_DOWN:
            this->snake.change_direction(vector_t{0, 1});
            break;
        case KEY_LEFT:
            this->snake.change_direction(vector_t{-1, 0});
            break;
        case KEY_RIGHT:
            this->snake.change_direction(vector_t{1, 0});
            break;
        }
    }
}

void Board::InitNcurse()
{
    initscr();            // Initialise l'écran
    cbreak();             // Désactive le buffering de ligne
    keypad(stdscr, TRUE); // Active la capture des touches spéciales
    noecho();             // Empêche l'affichage des touches pressées
    curs_set(FALSE); // Cacher le curseur
}

void Board::printBoard()
{
    int rows, cols;
    getmaxyx(stdscr, rows, cols); // Get the dimensions of the terminal window

    int boardRows = this->tab.size();
    int boardCols = this->tab[0].size();

    int startRow = (rows - boardRows) / 2; // Calculate the starting row for printing
    int startCol = (cols - boardCols) / 2; // Calculate the starting column for printing

    mvprintw(startRow - 3, startCol, "+----------------------+"); // Print the bottom border
    mvprintw(startRow -2, startCol, "|       score = %i      |", this->score); // Print the bottom border
    mvprintw(startRow - 1, startCol, "+----------------------+"); // Print the top border

    for (int i = 0; i < boardRows; i++)
        mvprintw(startRow + i, startCol, "| %s |", this->tab[i].c_str()); // Print each line of the board

    mvprintw(startRow + boardRows, startCol, "+----------------------+"); // Print the bottom border

    refresh(); // Refresh the screen to display the changes

}

void Board::update(Board *board)
{
    this->captureInput();
    this->snake.move(board);
    if (this->snake.get_position().x == this->apple.getApplePos().x && this->snake.get_position().y == this->apple.getApplePos().y)
    {
        this->score++;
        this->apple.place_apple(this);
        this->snake.grow();
    }
}