# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 20:21:02 by manu              #+#    #+#              #
#    Updated: 2022/07/01 21:40:11 by manu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

SRC_DIR				=	src
INCLUDES_DIR		= 	includes

SOURCES				= 	$(SRC_DIR)/main.c $(SRC_DIR)/error.c $(SRC_DIR)/moves_push.c $(SRC_DIR)/stack_printing.c $(SRC_DIR)/moves_swap.c $(SRC_DIR)/moves_rotate.c $(SRC_DIR)/moves_reverse_rotate.c $(SRC_DIR)/number_validation.c $(SRC_DIR)/stack_node.c $(SRC_DIR)/stack_sorting.c $(SRC_DIR)/get_number_moves.c $(SRC_DIR)/stack_init.c $(SRC_DIR)/algorithm_1_a_to_sorted_b.c $(SRC_DIR)/algorithm_2_best_a_and_b_move.c
TEST_SOURCES		= 	$(SRC_DIR)/tests.c $(SRC_DIR)/error.c $(SRC_DIR)/moves_push.c $(SRC_DIR)/stack_printing.c $(SRC_DIR)/moves_swap.c $(SRC_DIR)/moves_rotate.c $(SRC_DIR)/moves_reverse_rotate.c $(SRC_DIR)/number_validation.c $(SRC_DIR)/stack_node.c $(SRC_DIR)/stack_sorting.c $(SRC_DIR)/get_number_moves.c $(SRC_DIR)/stack_init.c $(SRC_DIR)/algorithm_1_a_to_sorted_b.c $(SRC_DIR)/algorithm_2_best_a_and_b_move.c
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
	# ./push_swap "37 60 64 100 3 98 39 93 1 94"
	# ./push_swap "1105339934 -732309121 452138020 -2093977165 -1989575772 1910122299 2105917496 1098840654 568186522 1174680545"
	# ./push_swap "1105339934 -732309121 452138020 -2093977165 -1989575772 1910122299"
	# ./push_swap "1209817465 -136445730 2103470450 -1543008962 227448846 -450614835 -1367091297 -693476175 1033820398 -309569003 697384018 2087390594 -747441213 -1345845606 -71439358 -422420241 831633526 -1784469877 -1451705378 1379117119 -1979344071 -1973920501 -1181309565 441796803 418199966 1536813168 -2114391804 1320804053 -984989746 1808050590 121105093 777141868 -338814828 -712673340 587714296 -566616944 -772539627 211080468 -1913909669 1593030487 -165626525 -694319681 -861771451 -916317503 413034995 664096253 -519681838 -1258735718 1923192478 805171539 -1225053649 -444691011 1556231411 -2145513014 -645720414 -575900834 -997780433 -699870449 439924308 328103309 -1971740460 2051255577 -5829873 -1314213733 -1334834676 783036923 -1426517318 -1898640848 145525514 565338678 2127913155 803761187 408500532 -1917206974 -865112301 876980804 1963492689 212764872 1425379463 -34258409 1743977765 -821000901 1883685252 623953082 1497955509 1678857529 1819525878 1461018423 -433877677 766567829 1785249131 221109357 297660471 -1740830282 728363183 403957557 -1022883268 363618890 -40609457 802759183"
	./push_swap "-975753679 699187136 -949942331 1517106328 1834646532 -1178334267 1642079644 737373552 -1091854697 2143345153 238405531 1346923960 -1005395212 1821860424 1687018747 -1746431582 1965513882 -2121926205 806829241 934588549 -1829006254 -1940500956 -2053664902 1929960094 -1843729558 504853563 -1224471867 1349967840 782210584 1505963719 -846390768 -500234880 425391162 -388731630 972217786 -436099285 1386108271 -1283520883 492170924 -1132967677 -1769401561 -1975660792 -1416777693 56127961 -393572216 -1249738841 2018149502 134122228 -813551383 -1982922983 -2089348971 -1650976617 1855339039 1556530806 -1506408258 -1901083070 983938332 1463226340 -1970412199 -1289235874 1247938125 -1869805835 857016715 1946735323 228914534 -1027227800 434593363 1763181814 610358336 403392694 -471711575 1121272020 1358369916 -1886055055 -1985923932 -1441855125 -316102501 1627460447 583213942 243472416 -552887086 781104151 -2006279864 -687291721 -1671991707 1511482202 -185616693 198003255 1781562116 -214324228 980993768 438491833 -1030922156 289233255 1994922048 -1546721672 987811024 -1762198415 -1406733131 -354234468"

.PHONY: all clean fclean re run_tests
