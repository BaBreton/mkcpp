SRC = $(wildcard ./src/*.cpp)
NAME = mkcpp
OBJ_DIR = obj
OBJ = $(patsubst ./src/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Define ANSI escape codes for colored output
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)
	@echo "$(GREEN)Finished target: $@$(NC)"

$(NAME): $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++17 -s $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished target: $@$(NC)"

$(OBJ_DIR)/%.o: ./src/%.cpp | $(OBJ_DIR)
	c++ -Wall -Wextra -Werror -std=c++17 -c $< -o $@
	@echo "$(GREEN)Finished target: $@$(NC)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Finished target: $@$(NC)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(GREEN)Finished target: $@$(NC)"

re: fclean all
	rm -rf assets/stateFile
	@echo "$(GREEN)Finished target: $@$(NC)"

.PHONY: all clean fclean re