#pragma once
#include <vector>
#include <string>
#include "./snake.h"

using namespace std;

    class Snake {

    private:
        vector<vector_t> body;
        vector_t direction;
        bool is_growing = false;
    public:
        Snake(vector_t pos, vector_t dir);
        void move();
        void change_direction(vector_t new_direction);
        vector_t get_position(void);
        bool onBody(vector_t target);
        void grow();
    };


    class Board;
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
