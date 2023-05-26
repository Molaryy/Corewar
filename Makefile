##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

TEST_NAME	=	unit_tests

TEST = tests

BASE_ASM	=	./asm

PARSING = ./asm/parsing

BODY = ./body

HEADER = ./header

COMPILER = ./asm/compiler

INIT = ./asm/init

DESTROY = ./asm/destroy

TRANSCRIPTION += ./asm/transcription

PARAMETER_BYTE += ./asm/transcription/parameters

DEBUG += ./asm/debug/

SRC_ASM	+= $(BASE_ASM)/main.c

SRC_ASM += $(PARSING)/detect_file_extesion.c
SRC_ASM += $(PARSING)/parse_reference_file.c

SRC_ASM += $(PARSING)/$(HEADER)/parse_header.c
SRC_ASM += $(PARSING)/$(HEADER)/utils_header.c

SRC_ASM += $(PARSING)/$(BODY)/get_body.c
SRC_ASM += $(PARSING)/$(BODY)/check_nb_arguments.c
SRC_ASM += $(PARSING)/$(BODY)/check_type_arguments.c
SRC_ASM += $(PARSING)/$(BODY)/add_label_to_link.c
SRC_ASM += $(PARSING)/$(BODY)/check_params.c
SRC_ASM += $(PARSING)/$(BODY)/create_champ.c
SRC_ASM += $(PARSING)/$(BODY)/check_index.c


SRC_ASM += $(COMPILER)/compiler.c
SRC_ASM += $(COMPILER)/create_cor.c
SRC_ASM += $(COMPILER)/write_into_cor.c

SRC_ASM += $(INIT)/init_asm.c

SRC_ASM += $(DESTROY)/free_header.c
SRC_ASM += $(DESTROY)/free_parser.c
SRC_ASM += $(DESTROY)/free_body.c

SRC_ASM += $(TRANSCRIPTION)/coding_byte.c
SRC_ASM += $(TRANSCRIPTION)/instruction_code.c
SRC_ASM += $(TRANSCRIPTION)/op.c
SRC_ASM += $(TRANSCRIPTION)/header.c

SRC_ASM += $(PARAMETER_BYTE)/create_bytes.c
SRC_ASM += $(PARAMETER_BYTE)/get_bytes.c
SRC_ASM += $(PARAMETER_BYTE)/param_in_byte.c
SRC_ASM += $(PARAMETER_BYTE)/indexes.c
SRC_ASM += $(PARAMETER_BYTE)/label_find.c

SRC_ASM += $(DEBUG)/print_champ.c

ROOT_COR = ./corewar

BASE_CORE = ./corewar/src

PARSE_CORE = ./$(BASE_CORE)/parser

HELPER_CORE = ./$(BASE_CORE)/helper

CHAMPION_CORE = ./$(BASE_CORE)/champion

SRC_CORE += $(BASE_CORE)/main.c
SRC_CORE += $(BASE_CORE)/op.c
SRC_CORE += $(PARSE_CORE)/parser.c
SRC_CORE += $(HELPER_CORE)/get.c
SRC_CORE += $(HELPER_CORE)/str.c
SRC_CORE += $(CHAMPION_CORE)/champion.c
SRC_CORE += $(CHAMPION_CORE)/stack.c
SRC_CORE += $(HELPER_CORE)/stop.c
SRC_CORE += $(HELPER_CORE)/debug.c
SRC_CORE += $(HELPER_CORE)/free.c

LIB += -L./lib/jb -llink -L./lib/nc -lnc

TESTS += $(TEST)/tests.c
TESTS += $(PARSING)/detect_file_extesion.c
TESTS += $(TRANSCRIPTION)/coding_byte.c
TESTS += $(TRANSCRIPTION)/op.c
TESTS += $(TRANSCRIPTION)instruction_code.c
TESTS += $(COMPILER)/create_cor.c

OBJ_A =	$(SRC_ASM:.c=.o)
OBJ_C =	$(SRC_CORE:.c=.o)

NAME_A    =       asm
NAME_C    =       corewar

DOT_O = *.o

CFLAGS  =       -W -Wall -Wextra -I includes/ -g

all:	$(OBJ_A) $(OBJ_C)
	$(MAKE) -C lib/jb --no-print-directory
	$(MAKE) -C lib/nc --no-print-directory
	gcc -o $(BASE_ASM)/$(NAME_A) $(OBJ_A) $(LIB) $(CFLAGS)
	gcc -o $(ROOT_COR)/$(NAME_C) $(OBJ_C) $(LIB) $(CFLAGS)

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
	rm -f $(NAME_C)/$(NAME_C)
	$(MAKE) -C lib/nc clean --no-print-directory
	$(MAKE) -C lib/jb clean --no-print-directory

fclean:	clean
	rm -f $(BASE_ASM)/$(NAME_A)
	rm -f corewar/$(NAME_C)
	$(MAKE) -C lib/nc fclean --no-print-directory
	$(MAKE) -C lib/jb fclean --no-print-directory

re: fclean all

unit_tests: fclean
	$(MAKE) -C lib/nc --no-print-directory
	$(MAKE) -C lib/jb --no-print-directory
	gcc $(TESTS) $(CFLAGS) $(LIB) -lcriterion -o $(TEST_NAME) \
	--coverage

tests_run: unit_tests
	./$(TEST_NAME)

.PHONY: all clean fclean re

.SILENT:
SILENT:
