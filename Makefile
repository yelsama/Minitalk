NAME = server

CNAME = client

SSRC = server.c

CSRC = client.c

SOBJ = $(SSRC:%.c=%.o)
COBJ = $(CSRC:%.c=%.o)

LIBFTBF = ./resources/ft_libft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)$(NAMEC)

$(NAME)$(NAMEC) : $(SOBJ) $(COBJ)
	$(MAKE)	-C ./resources/ft_libft_printf
	$(CC) -o $(NAME) $(SSRC) $(LIBFTBF)
	$(CC) -o $(CNAME) $(CSRC) $(LIBFTBF)

clean:
	$(MAKE) clean -C ./resources/ft_libft_printf
	/bin/rm -f $(SOBJ)
	/bin/rm -f $(COBJ)

fclean: clean
	$(MAKE) fclean -C ./resources/ft_libft_printf
	/bin/rm -f $(NAME)
	/bin/rm -f $(CNAME)

re: fclean all
