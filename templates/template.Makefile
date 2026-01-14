SRCS = 

FLAGS = -Wall -Wextra -Werror -std=c++98 -g
CC    = c++
RM    = rm -f
OBJ_DIR = dot_o
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = 

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) ${FLAGS} -o $(NAME)

all: $(NAME)

clean:	
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: re

.PHONY: all bonus clean fclean re