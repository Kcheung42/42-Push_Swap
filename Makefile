# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcheung <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 11:10:05 by kcheung           #+#    #+#              #
#    Updated: 2017/04/21 20:59:05 by kcheung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

#Libft Library
LIB_DIR = ./libft/
LIB_INC_DIR = ./libft/includes
LIB = $(LIB_DIR)/libft.a
LIB_LINK = -L $(LIB_DIR) -lft

#Targets for Pushswap
SRC_DIR_P = ./pswap/srcs/
SRC_NAME_P = push_swap.c \
			 operations1.c \
			 operations2.c \
			 operations3.c \
			 setup_ops.c \
			 setup_stacks.c \
			 calc.c \
			 optimize.c \
			 helpers.c \
			 print.c \
			 sort_mini_a.c \
			 final_operations.c \
			 main.c \
			 free.c
SRCS_P = $(addprefix $(SRC_DIR_P), $(SRC_NAME_P))

OBJ_DIR_P = ./pswap/obj/
OBJS_P = $(addprefix $(OBJ_DIR_P), $(SRC_NAME_P:%.c=%.o))

INC_DIR_P = ./pswap/includes/
INC_P = -I$(LIB_INC_DIR) -I$(INC_DIR_P)

#Targets for Checker
SRC_DIR_C = ./check/srcs/
SRC_NAME_C = main.c \
			operations.c \
			operations2.c \
			operations3.c \
			setup.c \
			setup_stacks.c \
			validate.c \
			free.c \
			checker.c
SRCS_C = $(addprefix $(SRC_DIR_C), $(SRC_NAME_C))

OBJ_DIR_C = ./check/obj/
OBJS_C = $(addprefix $(OBJ_DIR_C), $(SRC_NAME_C:%.c=%.o))

INC_DIR_C = ./check/includes/
INC_C = -I$(LIB_INC_DIR) -I$(INC_DIR_C)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: obj $(NAME_P) $(NAME_C)

$(OBJ_DIR_P)%.o: $(SRC_DIR_P)%.c $(INC_DIR_P)*.h
	@$(CC) $< -o $@ -c $(INC_P) $(CFLAGS)
$(OBJ_DIR_C)%.o: $(SRC_DIR_C)%.c $(INC_DIR_C)*.h
	@$(CC) $< -o $@ -c $(INC_C) $(CFLAGS)

$(NAME_P): $(LIB) $(OBJS_P)
	@$(CC) $^ -o $@ $(LIB_LINK) $(CFLAGS)
	@chmod 755 $@
$(NAME_C): $(LIB) $(OBJS_C)
	@$(CC) $^ -o $@ $(LIB_LINK) $(CFLAGS)

$(LIB):
	@make -C $(LIB_DIR)

obj:
	@mkdir -p $(OBJ_DIR_P)
	@mkdir -p $(OBJ_DIR_C)

clean:
	@rm -f $(OBJS_P)
	@rm -rf $(OBJ_DIR_P)
	@rm -f $(OBJS_C)
	@rm -rf $(OBJ_DIR_C)
	@make -C $(LIB_DIR) clean
	@echo "Cleaning" [$(NAME_P)] "..." $(OK)
	@echo "Cleaning" [$(NAME_C)] "..." $(OK)

fclean: clean
	@rm -f $(NAME_P)
	@rm -f $(NAME_C)
	@make -C $(LIB_DIR) fclean
	@echo "Delete" [$(NAME_P)] "..." $(OK)
	@echo "Delete" [$(NAME_C)] "..." $(OK)
re: fclean all

.PHONY: all, clean, fclean, re
