 SRCS = 	ft_printf.c converto.c putput.c
 
 NAME  = printf.a

 CC  = cc

 CFLAGS  = -Wall -Werror -Wextra

 AR = ar

 ARFLAGS = rcs

 OBJS  = $(SRCS:.c=.o)


all: $(NAME)
 
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
