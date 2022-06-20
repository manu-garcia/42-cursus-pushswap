# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 20:21:02 by manu              #+#    #+#              #
#    Updated: 2022/06/20 20:04:08 by manu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

SRC_DIR				=	src
INCLUDES_DIR		= 	includes

SOURCES				= 	$(SRC_DIR)/main.c $(SRC_DIR)/error.c $(SRC_DIR)/moves_push.c $(SRC_DIR)/print_stack.c $(SRC_DIR)/moves_swap.c $(SRC_DIR)/moves_rotate.c $(SRC_DIR)/moves_reverse_rotate.c $(SRC_DIR)/number_validation.c
OBJS				= 	$(SOURCES:.c=.o)

LIB_FT_PRINTF		=	ft_printf
LIB_FT				=	libft
CFLAGS 				= 	-Wall -Wextra -Werror
CC 					= 	gcc

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -I ${INCLUDES_DIR} -o $@ $^

$(NAME): $(OBJS)
	@make -C $(LIB_FT_PRINTF)
	@cp $(LIB_FT_PRINTF)/libftprintf.a .
	@make bonus -C $(LIB_FT)
	@cp $(LIB_FT)/libft.a .
	@$(CC) $(CFLAGS) -I ${INCLUDES_DIR} $(OBJS) libft.a libftprintf.a -o $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)
	rm ./libft.a
	rm ./libftprintf.a
	@make fclean -C $(LIB_FT)
	@make fclean -C $(LIB_FT_PRINTF)


fclean: clean
	rm -f $(NAME)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

.PHONY: all clean fclean re
