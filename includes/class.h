# pragma once
#include <vector>
#include <string>
#include "./includes/snake.h"

    class Snake {

    private:
        vector<vector_t> body;
        vector_t direction;
        bool is_growing = false;
    public:
        Snake(vector_t pos = {0, 0}, vector_t dir = {1, 0});
        void move();
        void change_direction(vector_t new_direction);
        vector_t get_position(void);
        vector<vector_t> get_body();
        void grow();
    };

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
