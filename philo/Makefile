######################################
NAME = philo
######################################
SRC_FOLDER = src
OBJ_FOLDER = obj

# SRC =	action_eat.c		\
# 		action_sleep.c		\
# 		action_thinking.c	\
# 		arguments.c			\
# 		cleaner.c			\
# 		main.c				\
# 		manage.c			\
# 		monitor.c			\
# 		my_time.c			\
# 		print_status.c		\
# 		set_env.c			\
# 		synchronization.c	\
# 		utils.c				

SRC =	arguments.c			\
		cleaner.c			\
		eat_action.c		\
		is_finished.c		\
		main.c				\
		monitor_routine.c	\
		my_time.c			\
		philo_routine.c		\
		print_action.c		\
		set_env.c			\
		synchronization.c	\
		think_action.c		\
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

case1:
	@./$(NAME) 5 800 200 200

case2:
	@./$(NAME) 5 800 200 200 7

case3:
	@./$(NAME) 4 410 200 200

case4:
	@./$(NAME) 3 310 200 100