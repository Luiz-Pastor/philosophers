######################################
NAME = philo
######################################
SRC_FOLDER = src
OBJ_FOLDER = obj

SRC =	main.c \
		arguments.c \
		set_env.c	\
		cleaner.c	\
		my_time.c	\
		utils.c		\
		manage.c	\
		synchronization.c	\
		print_status.c	\
		action_sleep.c

SRC =	action_eat.c		\
		action_sleep.c		\
		action_thinking.c	\
		arguments.c			\
		cleaner.c			\
		main.c				\
		manage.c			\
		monitor.c			\
		my_time.c			\
		print_status.c		\
		set_env.c			\
		synchronization.c	\
		utils.c				

OBJ=$(SRC:%.c=$(OBJ_FOLDER)/%.o)
######################################
CC := cc
CFLAGS := -Wall -Werror -Wextra -g3
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

ARGS = 4 800 200 200 5
run: all
	@./$(NAME) $(ARGS)

valgrind: all
	@valgrind --leak-check=full ./$(NAME) $(ARGS)

case1: all
	@./$(NAME) 1 800 200 200