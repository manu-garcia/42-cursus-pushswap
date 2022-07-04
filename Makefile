# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 20:21:02 by manu              #+#    #+#              #
#    Updated: 2022/07/04 20:49:56 by manu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

SRC_DIR				=	src
INCLUDES_DIR		= 	includes

SOURCES				= 	$(SRC_DIR)/main.c $(SRC_DIR)/error.c $(SRC_DIR)/moves_push.c $(SRC_DIR)/stack_printing.c $(SRC_DIR)/moves_swap.c $(SRC_DIR)/moves_rotate.c $(SRC_DIR)/moves_reverse_rotate.c $(SRC_DIR)/number_validation.c $(SRC_DIR)/stack_node.c $(SRC_DIR)/stack_sorting.c $(SRC_DIR)/get_number_moves.c $(SRC_DIR)/stack_init.c $(SRC_DIR)/algorithm_1_a_to_sorted_b.c $(SRC_DIR)/algorithm_2_best_a_and_b_move.c $(SRC_DIR)/algorithm_sort_3.c $(SRC_DIR)/algorithm_sort_5.c $(SRC_DIR)/move.c
TEST_SOURCES		= 	$(SRC_DIR)/tests.c $(SRC_DIR)/error.c $(SRC_DIR)/moves_push.c $(SRC_DIR)/stack_printing.c $(SRC_DIR)/moves_swap.c $(SRC_DIR)/moves_rotate.c $(SRC_DIR)/moves_reverse_rotate.c $(SRC_DIR)/number_validation.c $(SRC_DIR)/stack_node.c $(SRC_DIR)/stack_sorting.c $(SRC_DIR)/get_number_moves.c $(SRC_DIR)/stack_init.c $(SRC_DIR)/algorithm_1_a_to_sorted_b.c $(SRC_DIR)/algorithm_2_best_a_and_b_move.c $(SRC_DIR)/algorithm_sort_3.c $(SRC_DIR)/algorithm_sort_5.c $(SRC_DIR)/move.c
OBJS				= 	$(SOURCES:.c=.o)
TESTS_OBJS			= 	$(TEST_SOURCES:.c=.o)

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

run_tests: $(TESTS_OBJS)
	@make -C $(LIB_FT_PRINTF)
	@cp $(LIB_FT_PRINTF)/libftprintf.a .
	@make bonus -C $(LIB_FT)
	@cp $(LIB_FT)/libft.a .
	@$(CC) $(CFLAGS) -I ${INCLUDES_DIR} $(TESTS_OBJS) libft.a libftprintf.a -o push_swap_tests
	@echo
	@echo Running tests ...
	@./push_swap_tests

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

test: all
	./push_swap "951209027 -674876716 1452742795 -1900570950 614436416"

.PHONY: all clean fclean re run_tests
