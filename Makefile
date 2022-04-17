NAME	=	ft_printf

CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
SRC		=	*.c
LIBS	=
OBJ		=
RM 		=	rm -rf

# Targets
all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(LIBS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: re
	@./$(NAME)

norm:
	@norminette -R CheckForbiddenSourceHeader