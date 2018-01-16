# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 14:34:26 by pnardozi          #+#    #+#              #
#    Updated: 2018/01/13 18:58:14 by pnardozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CHECKER = checker

PUSH_SWAP = push_swap

LIBFT_INCLUDES_PATH = ./libft/libft/includes/
PRINTF_INCLUDES_PATH = ./libft/printf/includes/

CHECKER_SRCS_PATH = ./check/srcs/
CHECKER_INCLUDES_PATH = ./check/includes/
CHECKER_OBJ_PATH = ./check/obj/

PUSH_SWAP_SRCS_PATH = ./p_s/srcs/
PUSH_SWAP_INCLUDES_PATH = ./p_s/includes/
PUSH_SWAP_OBJ_PATH = ./p_s/obj/

CHECKER_SRCS_NAME =	checker.c \
			cmd.c \
			cmd2.c \
			parsing.c \
			select_cmd.c

PUSH_SWAP_SRCS_NAME =	push_swap.c \
			algo_small.c \
			algo_big.c \
			algo_big2.c \
			simulation_big.c \
			simulation_big2.c \
			cmd.c \
			cmd_list.c \
			cmd_list2.c \
			cmd_sim.c \
			cmd_sim2.c \
			list.c \
			parsing.c

CHECKER_OBJ_NAME = $(CHECKER_SRCS_NAME:.c=.o)

PUSH_SWAP_OBJ_NAME =$(PUSH_SWAP_SRCS_NAME:.c=.o)

LIBFT_INC = $(addprefix -I,$(LIBFT_INCLUDES_PATH))
PRINTF_INC = $(addprefix -I,$(PRINTF_INCLUDES_PATH))

CHECKER_SRCS = $(addprefix $(CHECKER_SRCS_PATH),$(CHECKER_SRCS_NAME))
CHECKER_OBJ = $(addprefix $(CHECKER_OBJ_PATH),$(CHECKER_OBJ_NAME))
CHECKER_INC = $(addprefix -I,$(CHECKER_INCLUDES_PATH))

PUSH_SWAP_SRCS = $(addprefix $(PUSH_SWAP_SRCS_PATH),$(PUSH_SWAP_SRCS_NAME))
PUSH_SWAP_OBJ = $(addprefix $(PUSH_SWAP_OBJ_PATH),$(PUSH_SWAP_OBJ_NAME))
PUSH_SWAP_INC = $(addprefix -I,$(PUSH_SWAP_INCLUDES_PATH))

LIB_PATH = ./libft/
LIB_NAME = libftprintf.a
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all: $(LIB_NAME) $(CHECKER) $(PUSH_SWAP)

$(LIB_NAME):
	make -C $(LIB_PATH)

$(CHECKER): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJ) $(LIB)
	@echo "$(GREEN)CHECKER READY$(END)"

$(PUSH_SWAP): $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) $(LIB)
	@echo "$(GREEN)PUSH_SWAP READY$(END)"

$(CHECKER_OBJ_PATH)%.o: $(CHECKER_SRCS_PATH)%.c
	@mkdir -p $(CHECKER_OBJ_PATH)
	$(CC) -c $(CFLAGS) $(CHECKER_INC) $(LIBFT_INC) $(PRINTF_INC) -o $@ -c $<

$(PUSH_SWAP_OBJ_PATH)%.o: $(PUSH_SWAP_SRCS_PATH)%.c
	@mkdir -p $(PUSH_SWAP_OBJ_PATH)
	$(CC) -c $(CFLAGS) $(PUSH_SWAP_INC) $(LIBFT_INC) $(PRINTF_INC) -o $@ -c $<

clean:
	make clean -C $(LIB_PATH)
	/bin/rm -rf $(CHECKER_OBJ_PATH) $(PUSH_SWAP_OBJ_PATH)
	@echo "$(RED)CHECKER AND PUSH_SWAP OBJECTS REMOVE$(END)"

fclean: clean
	make fclean -C $(LIB_PATH)
	/bin/rm -rf $(CHECKER) $(PUSH_SWAP)
	@echo "$(RED)CHECKER AND PUSH_SWAP REMOVE$(END)"

re: fclean all

.PHONY: all clean fclean re
