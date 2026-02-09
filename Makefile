SRCS = cppMaker.main.cpp utils/printUtils.cpp utils/replace.cpp \
	classes/UserInput/UserInput.class.cpp classes/Menu/Menu.class.cpp \
	includes/CheckString/CheckString.cpp utils/handleInputs.cpp \
	fileMakers/makefileMaker.cpp fileMakers/pathHandler.cpp \
	fileMakers/fileCreation.cpp fileMakers/classMaker.cpp \
	fileMakers/mainMaker.cpp fileMakers/dotCppMaker.cpp fileMakers/addToMakefile.cpp \

FLAGS = -Wall -Wextra -Werror -std=c++20 -g
CC    = c++
RM    = rm -f
OBJ_DIR = dot_o
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = cppMaker

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