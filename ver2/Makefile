NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = -rm -f

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
	ft_putx.c ft_uniputnbr.c ft_putptr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus 



