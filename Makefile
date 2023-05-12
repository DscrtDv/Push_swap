NAME		=	push_swap

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft


	# Mandatory Variables #
SRCs		=	srcs/main.c srcs/push_swap_operations.c srcs/radix_sort.c srcs/simple_sort.c srcs/stack_advanced_operations.c \
				utils/args_check.c utils/stack_init_index.c utils/t_list.c utils/utils.c
INC			=	-I. -I$(LIBFT_DIR)
				
	# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

	# Debugger #
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

	# Fsanitize #
ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=leak -g
endif

all: $(NAME)

$(NAME): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAG) $(SRCs) $(LIBFT) $(INC) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) ready.\n"

$(LIBFT):
	@ $(MAKE) DEBUG=$(DEBUG) -C $(LIBFT_DIR)

clean:
	@ $(RM) $(NAME)
	@printf "$(_INFO) $(NAME) removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME)
	@printf "$(_INFO) $(NAME) and libft.a removed.\n"

re: fclean all

mandatory:	$(NAME)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b