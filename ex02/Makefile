NAME = baser
CXX = c++
FLAGS = -Werror -Wextra -Wall -std=c++98 -pedantic
SRC = main.cpp Base.cpp
OBJ_DIR = .objs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEPS = Base.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp $(DEPS) | $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
