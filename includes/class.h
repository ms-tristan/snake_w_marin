# pragma once
#include <vector>
#include <string>
#include "./includes/snake.h"

    class Apple
    {
    public:
        Apple();
        Apple(int x, int y);
        void place_apple(Board board);
    private:
        vector_t apple_pos;
    };

    class Board {
    public:
        Board();
        void myFunction();
        std::vector<std::string> tab;
    private:
        int score;
        Snake mySnake;
        Apple myApple;
    };