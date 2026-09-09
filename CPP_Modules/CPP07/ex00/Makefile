NAME = whatever

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = #(STCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %,cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fc lean re