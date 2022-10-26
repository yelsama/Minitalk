NAME = server
NAMEB = server_bonus

CNAME = client
CNAMEB = client_bonus

SSRC = server.c

CSRC = client.c

BSSRC = server_bonus.c

BCSRC = client_bonus.c

SOBJ = $(SSRC:%.c=%.o)
COBJ = $(CSRC:%.c=%.o)

BSOBJ = $(BSSRC:%.c=%.o)
BCOBJ = $(BCSRC:%.c=%.o)

LIBFTBF = ./resources/ft_libft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)$(NAMEC)

$(NAME)$(NAMEC) : $(SOBJ) $(COBJ)
	$(MAKE)	-C ./resources/ft_libft_printf
	$(CC) -o $(NAME) $(SSRC) $(LIBFTBF)
	$(CC) -o $(CNAME) $(CSRC) $(LIBFTBF)

bonus: $(NAMEB)$(NAMECB)

$(NAMEB)$(NAMECB) : $(BSOBJ) $(BCOBJ)
	$(MAKE)	-C ./resources/ft_libft_printf
	$(CC) -o $(NAMEB) $(BSSRC) $(LIBFTBF)
	$(CC) -o $(CNAMEB) $(BCSRC) $(LIBFTBF)

clean:
	$(MAKE) clean -C ./resources/ft_libft_printf
	/bin/rm -f $(SOBJ) $(COBJ)
	/bin/rm -f $(BSOBJ) $(BCOBJ)

fclean: clean
	$(MAKE) fclean -C ./resources/ft_libft_printf
	/bin/rm -f $(NAME) $(NAMEB)
	/bin/rm -f $(CNAME) $(CNAMEB)

re: fclean all
