# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 22:37:02 by aouichou          #+#    #+#              #
#    Updated: 2022/07/11 22:51:10 by aouichou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME	= client
S_NAME	= server

SRC_D	= srcs/
OBJ_D	= objs/
C_SRC_D	= srcs/client/
S_SRC_D	= srcs/server/
C_OBJ_D	= client_objs/
S_OBJ_D	= server_objs/
INC_D	= includes/
LIBFT_D	= libft/

SRC		= utils.c

C_SRC	= main.c	\
		client_utils.c	\

S_SRC		= main.c

OBJ		= $(addprefix $(OBJ_D), $(SRC:.c=.o))
C_OBJ	= $(addprefix $(C_OBJ_D), $(C_SRC:.c=.o))
S_OBJ	= $(addprefix $(S_OBJ_D), $(S_SRC:.c=.o))
FLAGS	= -g -Wall -Werror -Wextra
LIBS	= -L libft/ -lft

INCS	= -I $(INC_D)

all: $(OBJ_D) $(C_OBJ_D) $(S_OBJ_D) $(C_NAME) $(S_NAME)

$(OBJ_D):
	@mkdir -p $@

$(C_OBJ_D):
	@mkdir -p $@

$(S_OBJ_D):
	@mkdir -p $@

$(C_NAME): $(OBJ) $(C_OBJ)
	@make -C $(LIBFT_D)
	gcc -o $@ $^ $(LIBS)

$(S_NAME): $(OBJ) $(S_OBJ)
	gcc -o $@ $^ $(LIBS)

$(OBJ_D)%.o: $(SRC_D)%.c
	gcc $(FLAGS) -o $@ -c $< $(INCS)

$(C_OBJ_D)%.o: $(C_SRC_D)%.c
	gcc $(FLAGS) -o $@ -c $< $(INCS)

$(S_OBJ_D)%.o: $(S_SRC_D)%.c
	gcc $(FLAGS) -o $@ -c $< $(INCS)

clean:
	@make -C $(LIBFT_D) clean
	rm -rf $(OBJ_D)
	rm -rf $(C_OBJ_D)
	rm -rf $(S_OBJ_D)

fclean: clean
	@make -C $(LIBFT_D) fclean
	rm -f $(C_NAME)
	rm -f $(S_NAME)

re: fclean all

.PHONY: clean fclean re all
