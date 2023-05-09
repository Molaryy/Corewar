##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

TEST_NAME	=	unit_tests

TEST = tests

BASE	=	./asm

SRC_ASM	+=	$(BASE)/main.c

LIB += -L./lib/jb -llink

TESTS	= $(TEST)/shell_tests.c

OBJ	=	$(SRC_ASM:.c=.o)

NAME    =       name

CFLAGS  =       -W -Wall -Wextra -I includes/

all:	$(OBJ)
	$(MAKE) -C lib/jb --no-print-directory
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
	mv $(NAME) $(BASE)
	mv $(BASE)/$(NAME) $(BASE)/$(BASE)

debug:	$(OBJ)
		$(MAKE) -C lib/jb --no-print-directory
		gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) -g

clean:
	rm -f $(BASE)/$(BASE)
	rm -f *log
	rm -f *~
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(TEST_NAME)
	rm -f $(OBJ)
	rm -f liblist.a
	rm -f $(SRC_FILES)/$(OBJ)
	$(MAKE) -C lib/jb clean --no-print-directory

fclean:	clean
	rm -f $(BASE)/$(NAME)
	$(MAKE) -C lib/jb fclean --no-print-directory

re: fclean all

unit_tests: re
	gcc $(TESTS) $(CFLAGS) -L . -lmy -llist -lcriterion -o $(TEST_NAME) \
	--coverage

tests_run: unit_tests
	./$(TEST_N)

.PHONY: all clean fclean re

.SILENT:
SILENT:
