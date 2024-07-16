# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 19:01:23 by dolifero          #+#    #+#              #
#    Updated: 2024/07/16 21:38:35 by dolifero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = philo

CC              = cc
CFLAGS          = -Wall -Wextra -Werror

SRC_DIR         = ./src
OBJ_DIR         = ./obj

SRC_FILES       = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES       = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


BOLD_PURPLE = \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_YELLOW = \033[1;33m
BOLD_WHITE  = \033[1;97m
BOLD_GREEN  = \033[1;92m
NO_COLOR    = \033[0m
DEF_COLOR   = \033[0;39m
GRAY        = \033[0;90m
RED         = \033[0;91m
GREEN       = \033[0;92m
YELLOW      = \033[0;93m
BLUE        = \033[0;94m
MAGENTA     = \033[0;95m
CYAN        = \033[2;96m
BR_CYAN     = \033[0;96m
WHITE       = \033[0;97m

all: $(NAME)
	clear
	@$(MAKE) PHILO_CYAN
	@$(MAKE) loading
	clear
	@$(MAKE) PHILO_GREEN
	@echo "     $(BOLD_GREEN) DONE!\n$(DEF_COLOR)"

clean:
	@echo "$(CYAN)"
	rm -rf $(OBJ_DIR)
	clear
	@echo "$(DEF_COLOR)"

fclean: clean
	@echo "$(CYAN)"
	rm -f $(NAME)
	clear
	@echo "$(DEF_COLOR)"

re: fclean all

PHILO_CYAN:
	@echo "\n$(BR_CYAN)┏┓┓ •┓       ┓"
	@echo "┃┃┣┓┓┃┏┓┏┏┓┏┓┣┓┏┓┏┓┏ "
	@echo "┣┛┛┗┗┗┗┛┛┗┛┣┛┛┗┗ ┛ ┛ $(BOLD_CYAN)\n"

PHILO_GREEN:
	@echo "\n$(GREEN)┏┓┓ •┓       ┓"
	@echo "┃┃┣┓┓┃┏┓┏┏┓┏┓┣┓┏┓┏┓┏ "
	@echo "┣┛┛┗┗┗┗┛┛┗┛┣┛┛┗┗ ┛ ┛   -dolifero$(BOLD_CYAN)\n"

loading:
	@for i in {1..42}; do \
		printf '%s' "█"; \
		sleep 0.01; \
	done

.PHONY: all clean fclean re