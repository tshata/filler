# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshata <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 09:42:04 by tshata            #+#    #+#              #
#    Updated: 2018/08/22 15:17:56 by tshata           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary

NAME = ./srcs/filler

# Path

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

INC_PATH = ./includes/

# Name

SRC_NAME =	main.c\
			memory_manage.c\
			get_token.c\
			play.c\
			init_filler.c\
			dist.c\
			get_map.c\
			offset.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags

LDFLAGS+= -L ./libft -lft

CC = gcc $(CFLAGS)
#-fsanitize=address

CFLAGS = -Wall -Wextra -Werror -I. -g

# Rules

all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	@make -C./libft/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(LDFLAGS) $(OBJ) -o $@
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

cleanlib:
	@make clean -C ./libft/

fclean: clean fcleanlib
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

fcleanlib:
	@make fclean -C ./libft/

re : fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY : all clean fclean re
