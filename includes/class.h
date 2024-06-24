#pragma once
#include <vector>
#include <string>
#include "./snake.h"

using namespace std;
    class Apple;
    class Board;
    class Snake {

    private:
        std::vector<vector_t> body;
        vector_t direction;
        bool is_growing = false;
    public:
        Snake(vector_t pos, vector_t dir);
        void move(Board *board);
        void change_direction(vector_t new_direction);
        vector_t get_position(void);
        bool onBody(vector_t target);
        void grow();
    };


    class Apple
    {
    public:
        Apple();
        Apple(int x, int y);
        void place_apple(Board *board);
        vector_t getApplePos();
    private:
        vector_t apple_pos;
    };

    class Board {
    public:
        Board();
        void InitNcurse();
        void printBoard();
        void gameLoop();
        void captureInput();
        void update(Board *board);
        std::vector<std::string> tab;
        Snake snake;
        Apple apple;
        int score;
    };
