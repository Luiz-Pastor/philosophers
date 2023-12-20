######################################
NAME = philo
######################################
SRC_FOLDER = src
OBJ_FOLDER = obj

SRC =	main.c	\
		utils.c

OBJ=$(SRC:%.c=$(OBJ_FOLDER)/%.o)
######################################
CC := cc
CFLAGS := -Wall -Werror -Wextra
######################################

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME) -lpthread

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

######################################

clean:
	@rm -rf $(OBJ_FOLDER)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

######################################

run: all
	@./$(NAME) 1 800 200 200