NAME	= pipex
LIBFT	= libft

CFLAGS = -Wextra -Wall -Werror -Ofast -g
HEADERS := -I /include -I $(LIBFT)
LIBS = -L$(LIBFT)
SRCS := $(shell find -iname "*.c")
OBJS := $(SRCS:.c=.o)

# Colors
GREEN  := \033[1;32m
YELLOW := \033[1;33m
BLUE   := \033[1;34m
RED    := \033[1;31m
RESET  := \033[0m

all: loading  libft $(NAME) fun_msg

	@echo "$(BLUE)"
	@echo "██████╗ ██╗██████╗ ███████╗██╗  ██╗"
	@echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝"
	@echo "██████╔╝██║██████╔╝█████╗   ╚███╔╝ "
	@echo "██╔═══╝ ██║██╔══   ██╔══╝   ██╔██╗ "
	@echo "██║     ██║██║     ███████╗██╔╝ ██╗"
	@echo "╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝"
	@echo "$(RESET)"
loading:
	@echo -n "Building"; for i in {1..3}; do sleep 0.3; echo -n "."; done; echo " 🚀"

libft:
	@echo "$(YELLOW)🔧 Building libft...$(RESET)"
	@make -C $(LIBFT)

%.o: %.c
	@echo "$(BLUE)🛠️  Compiling $< $(RESET)"
	cc $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)🔗 Linking $(NAME)...$(RESET)"
	cc $(OBJS) -L$(LIBFT) -lft -o $(NAME)

fun_msg:
	@echo "$(GREEN)$(shell shuf -n 1 -e 'Build complete! 🚀' 'Time to sort! 🎮' 'Push_swap is ready! ✅')$(RESET)"

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)🔥 Full clean in progress...$(RESET)"
	@rm -rf $(NAME)	

re: fclean all

.PHONY: all clean fclean re libft % 
