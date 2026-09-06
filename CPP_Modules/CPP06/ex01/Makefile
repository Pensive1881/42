NAME = serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OPBJS) -o $(NAME)

clean:
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

re: flcean all

.PHONY: all clean fclean re