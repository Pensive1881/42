NAME		= replace

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

all $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) ic %< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: flcean all

.PHONY: all clean fclean re