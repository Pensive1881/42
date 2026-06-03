NAME        = phonebook
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include

SRC         = $(SRC_DIR)/main.cpp $(SRC_DIR)/PhoneBook.cpp $(SRC_DIR)/Contact.cpp
OBJ         = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
