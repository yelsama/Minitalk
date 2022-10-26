NAME = libftprintf.a

SOURCES = ft_printf.c ft_printhex.c

OBJECTS = $(SOURCES:%.c=%.o)

LIBFT = ./Libft/libft.a

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	$(MAKE) -C ./Libft
	cp Libft/libft.a $(NAME) 
	ar -rcs $(NAME) $(OBJECTS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./Libft 
	rm -rf $(OBJECTS)

fclean : clean
	$(MAKE) fclean -C ./Libft
	rm -rf $(NAME)

re : fclean all
