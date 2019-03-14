# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huszalew <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 12:20:25 by huszalew          #+#    #+#              #
#    Updated: 2019/03/13 12:17:39 by vlhomme          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

DEBUG = yes

SRC_PATH := ./
OBJ_PATH := ./
HDR_PATH := ./
LIB_PATH := ./libft/

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LFLAGS := -L$(LIB_PATH) -lft

ifeq ($(DEBUG),yes)
	CFLAGS += -g
endif

SRC := main.c check.c

HDR := fillit.h

LIB := libft.a

OBJ := $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
SRC := $(addprefix $(SRC_PATH), $(SRC))
HDR := $(addprefix $(HDR_PATH), $(HDR))

C_NO		=	"\033[00m"
C_OK		=	"\033[36m"
C_GOOD		=	"\033[32m"

SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
	@echo "Compile" [ $(NAME) ] $(SUCCESS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDR)
	@$(CC) $(CFLAGS) -I$(HDR_PATH) -o $@ -c $<

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@rm -f $(OBJ)
	@echo "Clean" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(LIB_PATH)$(LIB)
	@echo "Delete" [ $(LIB) ] "..." $(OK)
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] "..." $(OK)

re: fclean all

.PHONY: all clean fclean re
