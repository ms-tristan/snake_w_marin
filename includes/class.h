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
