# pragma once
#include <vector>
#include <string>
#include "./includes/snake.h"

    class Apple
    {
    public:
        Apple();
        void place_apple();
        void eat_apple();
        void check_apple();
    private:
        vector_t apple_pos;
    };

    class Board {
    public:
        Board();
        void myFunction();
        std::vector<std::string> tab;
    private:
        Snake mySnake;
        Apple myApple;
        int myVariable;
    };