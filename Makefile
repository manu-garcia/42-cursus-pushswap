# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 20:21:02 by manu              #+#    #+#              #
#    Updated: 2022/07/09 18:55:11 by manugarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

SRC_DIR				=	src
INCLUDES_DIR		= 	includes

SOURCES				=	$(SRC_DIR)/error.c $(SRC_DIR)/moves_push.c $(SRC_DIR)/stack_printing.c $(SRC_DIR)/moves_swap.c $(SRC_DIR)/moves_rotate.c $(SRC_DIR)/moves_reverse_rotate.c $(SRC_DIR)/number_validation.c $(SRC_DIR)/stack_node.c $(SRC_DIR)/stack_sorting.c $(SRC_DIR)/get_number_moves.c $(SRC_DIR)/stack_init.c $(SRC_DIR)/algorithm_2_best_a_and_b_move.c $(SRC_DIR)/algorithm_sort_3.c $(SRC_DIR)/algorithm_sort_5.c $(SRC_DIR)/move.c $(SRC_DIR)/stack_free.c
MAIN_SOURCES		= 	$(SRC_DIR)/main.c $(SOURCES)
TEST_SOURCES		= 	$(SRC_DIR)/tests.c $(SOURCES)
CHECKER_SOURCES		= 	$(SRC_DIR)/checker.c $(SOURCES)
OBJS				= 	$(MAIN_SOURCES:.c=.o)
TESTS_OBJS			= 	$(TEST_SOURCES:.c=.o)
CHECKER_OBJS		= 	$(CHECKER_SOURCES:.c=.o)

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

checker: $(CHECKER_OBJS)
	@make -C $(LIB_FT_PRINTF)
	@cp $(LIB_FT_PRINTF)/libftprintf.a .
	@make bonus -C $(LIB_FT)
	@cp $(LIB_FT)/libft.a .
	@$(CC) $(CFLAGS) -I ${INCLUDES_DIR} $(CHECKER_OBJS) libft.a libftprintf.a -o checker

re: fclean all

clean:
	rm -f $(CHECKER_OBJS) $(TESTS_OBJS) $(OBJS)
	rm ./libft.a
	rm ./libftprintf.a
	@make fclean -C $(LIB_FT)
	@make fclean -C $(LIB_FT_PRINTF)

fclean: clean
	rm -f $(NAME)
	rm -f checker

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

test: all
	./push_swap "951209027 -674876716 1452742795 -1900570950 614436416"

valgrind:
	valgrind --leak-check=full --track-origins=yes ./push_swap "1465820556 430441041 -1624535205 1718081214 -735725204 1745521056 -29993210 -1607307052 994282090 -1161409553 25123643 172627925 -1440211281 -1128740521 1739435383 1351556812 -1711606927 -1918864149 -1553440839 852978286 -387891829 696765134 2042257883 -1871099817 573158462 1962158170 -1976459364 1900255265 -1056083876 647514757 470050411 -1962082083 -1427797587 1033327119 935023893 61142391 -1749551578 1450363442 1150273749 477090011 451004984 560628580 33755258 -1014772 348082641 -1641624833 -1533860964 -1927655780 -1356848336 1070893722 -1196301995 1788986161 942646646 219448269 1108996219 998105347 -2004669795 -167933093 1167907709 -1117961137 -1535054326 717992686 1116653576 -861006865 522429488 150413480 -1587837464 2144695918 -1620461186 -191046495 755096228 -1516931892 -940532572 -1440875192 -1102273842 -1189896562 -391762977 620075927 -295368906 -969488744 2126308343 86249555 -561540872 -1348701384 -635795643 -1993427322 956068562 -1874077267 -2022240580 -1916798712 -1382725533 129342683 1571968169 -1493723116 1591746204 -1027542148 668087848 360900690 2014650011 -1014922928"

.PHONY: all clean fclean re run_tests checker valgrind
