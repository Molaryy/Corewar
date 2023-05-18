##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

TEST_NAME	=	unit_tests

TEST = tests

BASE_ASM	=	./asm

BASE_CORE = ./corewar

PARSING = ./asm/parsing

BODY = ./body

HEADER = ./header

COMPILER = ./asm/compiler

INIT = ./asm/init

DESTROY = ./asm/destroy

SRC_ASM	+= $(BASE_ASM)/main.c

SRC_ASM += $(PARSING)/detect_file_extesion.c
SRC_ASM += $(PARSING)/parse_reference_file.c

SRC_ASM += $(PARSING)/$(HEADER)/parse_header.c
SRC_ASM += $(PARSING)/$(HEADER)/utils_header.c

SRC_ASM += $(PARSING)/$(BODY)/get_body.c
SRC_ASM += $(PARSING)/$(BODY)/check_nb_arguments.c
SRC_ASM += $(PARSING)/$(BODY)/check_type_arguments.c

SRC_ASM += $(COMPILER)/compiler.c

SRC_ASM += $(INIT)/init_asm.c

SRC_ASM += $(DESTROY)/free_header.c
SRC_ASM += $(DESTROY)/free_parser.c
SRC_ASM += $(DESTROY)/free_body.c

SRC_CORE += $(BASE_CORE)/main.c

LIB += -L./lib/jb -llink

TESTS += $(TEST)/tests.c
TESTS += $(PARSING)/detect_file_extesion.c

OBJ_A =	$(SRC_ASM:.c=.o)
OBJ_C =	$(SRC_CORE:.c=.o)

NAME_A    =       name_a
NAME_C    =       name_c

DOT_O = *.o

CFLAGS  =       -W -Wall -Wextra -I includes/

all:	$(OBJ_A) $(OBJ_C)
	$(MAKE) -C lib/jb --no-print-directory
	gcc -o $(NAME_A) $(OBJ_A) $(LIB) $(CFLAGS)
	mv $(NAME_A) $(BASE_ASM)
	mv $(BASE_ASM)/$(NAME_A) $(BASE_ASM)/$(BASE_ASM)
	gcc -o $(NAME_C) $(OBJ_C) $(LIB) $(CFLAGS)
	mv $(NAME_C) $(BASE_CORE)
	mv $(BASE_CORE)/$(NAME_C) $(BASE_CORE)/$(BASE_CORE)

clean:
	rm -f $(BASE_ASM)/$(BASE_ASM)
	rm -f *log
	rm -f *~
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(TEST_NAME)
	rm -f $(OBJ_A)
	rm -f $(OBJ_C)
	rm -f liblist.a
	rm -f $(BASE_ASM)/$(DOT_O)
	rm -f $(BASE_CORE)/$(DOT_O)
	rm -f $(BASE_ASM)/$(BASE_ASM)
	rm -f $(BASE_CORE)/$(BASE_ASM)
	$(MAKE) -C lib/jb clean --no-print-directory

fclean:	clean
	rm -f $(BASE_ASM)/$(BASE_ASM)
	rm -f $(BASE_CORE)/$(BASE_CORE)
	$(MAKE) -C lib/jb fclean --no-print-directory

re: fclean all

unit_tests: fclean
	$(MAKE) -C lib/jb --no-print-directory
	gcc $(TESTS) $(CFLAGS) $(LIB) -lcriterion -o $(TEST_NAME) \
	--coverage

tests_run: unit_tests
	./$(TEST_NAME)

.PHONY: all clean fclean re

.SILENT:
SILENT:
