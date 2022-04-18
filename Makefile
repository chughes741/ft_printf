NAME	=	libftprintf

CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
SRC		=	*.c
LIBS	=
OBJ		=	$(SRC:.c=.o)
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

norm:
	@norminette -R CheckForbiddenSourceHeader