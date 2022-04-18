NAME	=	libftprintf.a

CC		=	gcc
CFLAGS	=	-I$(IDIR)-Wall -Werror -Wextra
AFLAGS	=	-crs
RM 		=	rm -rf

SRCS		=	$(wildcard $(SDIR)*.c)
OBJS		=	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

IDIR	=	include
SDIR	=	src
ODIR	=	obj
LDIR	=	libft

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	ar $(AFLAGS) $@ $^

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

libft:
	cd ../$(LDIR) ; Make all

clean:
	$(RM) $(ODIR)/*

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader