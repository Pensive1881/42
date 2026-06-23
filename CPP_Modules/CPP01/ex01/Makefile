NAME		= zombieHorde

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror - std=c++98

SRCS		= main.cpp Zombie.cpp zombieHorde.cpp
OBJS		= $(SRCS:.cpp=.0)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re