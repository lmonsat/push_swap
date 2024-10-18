SRCS = srcs/push_swap.c srcs/utils.c srcs/check_input.c srcs/commands.c srcs/algorithmes.c srcs/free.c \
		srcs/nodes.c

NAME = push_swap
CC = cc
CFLAGS = #-Wall -Werror -Wextra -g

LDFLAGS_PRINTF = -L$(PRINTF_DIR)
LDLIBS_PRINTF = $(PRINTF)

LDFLAGS_LIBFT = -L$(LIBFT_DIR)
LDLIBS_LIBFT = $(LIBFT)

OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)
PRINTF = $(PRINTF_DIR)/printf.a
LIBFT = $(LIBFT_DIR)/libft.a

OBJS_DIR = ./objs
PRINTF_DIR = ./printf
LIBFT_DIR = ./libft

B_BLUE = \033[1;36m
B_GREEN = \033[1;32m
B_WHITE = \033[1;37m
RESET = \033[0m


all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	@echo "\n$(B_BLUE)Compiling $(NAME)...$(B_WHITE)\n"
	$(CC) $(OBJS) $(LDFLAGS_PRINTF) $(LDLIBS_PRINTF) $(LDFLAGS_LIBFT) $(LDLIBS_LIBFT) -o $(NAME)
	@echo "\n$(B_GREEN)$(NAME) compiled successfully!$(B_WHITE)\n"

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	@echo "\n$(B_BLUE)Compiling printf...$(B_WHITE)\n"
	@if ! make -C $(PRINTF_DIR) ; then echo "\n$(B_BLUE)Error compiling printf$(RESET)\n"; exit 1; fi

$(LIBFT):
	@echo "\n$(B_BLUE)Compiling Libft...$(B_WHITE)\n"
	@if ! make -C $(LIBFT_DIR) ; then echo "\n$(B_BLUE)Error compiling Libft$(RESET)\n"; exit 1; fi

clean:
	@echo "\n$(B_BLUE)Cleaning objs and objs directory...$(B_WHITE)\n"
	rm -rf $(OBJS_DIR)
	@make -C $(PRINTF_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@echo "\n$(B_GREEN)Objs files was removed successfully!$(B_WHITE)\n"
	@echo "$(RESET)"

fclean: clean
	@echo "\n$(B_BLUE)Removing executables...$(B_WHITE)\n"
	rm -rf $(NAME)
	@echo "\n$(B_BLUE)Removing printf files...$(B_WHITE)\n"
	@make -C $(PRINTF_DIR) fclean 
	@echo "\n$(B_BLUE)Removing Libft files...$(B_WHITE)\n"
	@make -C $(LIBFT_DIR) fclean
	@echo "\n$(B_GREEN)All files was removed successfully!$(B_WHITE)\n"
	@echo "$(RESET)"

re: fclean all

.PHONY: all clean fclean re