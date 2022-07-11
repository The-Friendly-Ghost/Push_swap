# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cpost <cpost@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/20 11:27:58 by cpost         #+#    #+#                  #
#    Updated: 2022/07/05 14:21:13 by cpost         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
SHR_PATH = ./shared/
OBJ_PATH = ./obj/
BON_PATH = ./bonus/
INC_PATH = ./include/ ./lib/libft/include/ ./lib/printf/include

LIBFT_PATH = ./lib/libft/
LIBPRINTF_PATH = ./lib/printf/

NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC_NAME = $(shell ls $(SRC_PATH))
SHR_NAME = $(shell ls $(SHR_PATH))
BON_NAME = $(shell ls $(BON_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o) $(SHR_NAME:.c=.o)
BON_OBJ_NAME = $(BON_NAME:.c=.o) $(SHR_NAME:.c=.o)
LIBFT_NAME = libft.a
LIBFTPRINT_NAME = printf.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
SHR = $(addprefix $(SHR_PATH), $(SHR_NAME))
BON = $(addprefix $(BON_PATH), $(BON_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
BON_OBJ = $(addprefix $(OBJ_PATH), $(BON_OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBFT_PATH)$(LIBFT_NAME) $(LIBPRINTF_PATH)$(LIBFTPRINT_NAME)

BOLD = \033[1m
GREEN = \033[32;1m
RED	= \033[31;1m
YELLOW	= \033[33;1m
RESET = \033[0m

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(LIBPRINTF_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC) $(OBJ) -o $(NAME) && printf "$(YELLOW)$(BOLD)\rBuilt $(NAME)\r\e[35C[OK]\n$(RESET)"

$(BONUS_NAME): $(BON_OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(LIBPRINTF_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC) $(BON_OBJ) -o $(BONUS_NAME) && printf "$(YELLOW)$(BOLD)\rBuilt $(BONUS_NAME)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)%.o: $(SHR_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)%.o: $(BON_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

cleanlib:
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBPRINTF_PATH) clean

fcleanlib:
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIBPRINTF_PATH) fclean

clean: cleanlib
	@echo "$(RED)Cleaning$(RESET)"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean fcleanlib
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

.PHONY: clean, fclean, re, all