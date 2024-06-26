
TARGET	=	snake

CXX	=	g++

CXXFLAGS = -Wall -Wextra -std=c++11 -lncurses


SRCS	=	sources/main.cpp 			\
			sources/gameLoop.cpp 		\
			sources/classes/apple.cpp	\
			sources/classes/snake.cpp	\
			sources/classes/board.cpp 	\


OBJS	=	$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

.PHONY: all clean fclean re
