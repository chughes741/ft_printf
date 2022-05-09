NAME	=	libftprintf.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
AFLAGS	=	-crs
RM 		=	rm -rf

SRCS	=	$(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)

LDIR	=	libft

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(LDIR)/libft.a
	@ar $(AFLAGS) $@ $^
	@$(RM) *.o

$(LDIR)/libft.a:
	@cd $(LDIR) && make

# Removes objects
clean:
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

# Test function used with main
test:
	@clear
	@$(CC) $(CFLAGS) -o test $(SRCS) $(LDIR)/libft.a
	@./test
	@rm test
