##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LINKS	=	./links


JB	=	src

STR = str

ARRAY = array

BOOL = bool

INT = int

FEAT	= features

PRINT	=	print

SRC += $(JB)/$(LINKS)/add_link.c
SRC += $(JB)/$(LINKS)/create_link.c
SRC += $(JB)/$(LINKS)/free_links.c
SRC += $(JB)/$(LINKS)/link_len.c
SRC += $(JB)/$(LINKS)/delete_node.c
SRC += $(JB)/$(LINKS)/print_link.c



SRC += $(JB)/$(FEAT)/$(ARRAY)/array_to_str.c
SRC += $(JB)/$(FEAT)/$(ARRAY)/free_str_2d.c
SRC += $(JB)/$(FEAT)/$(ARRAY)/str_to_array_separator.c
SRC += $(JB)/$(FEAT)/$(BOOL)/is_alphanumeric.c
SRC += $(JB)/$(FEAT)/$(BOOL)/str_contains_char.c
SRC += $(JB)/$(FEAT)/$(INT)/my_getnbr.c
SRC += $(JB)/$(FEAT)/$(INT)/my_strlen.c
SRC += $(JB)/$(FEAT)/$(INT)/count_tab.c
SRC += $(JB)/$(FEAT)/$(INT)/is_digit.c
SRC += $(JB)/$(FEAT)/$(STR)/j_strcat.c
SRC += $(JB)/$(FEAT)/$(STR)/cpy_char_separator.c
SRC += $(JB)/$(FEAT)/$(STR)/my_strcmp.c
SRC += $(JB)/$(FEAT)/$(STR)/my_trim.c
SRC += $(JB)/$(FEAT)/$(STR)/my_strdup.c
SRC += $(JB)/$(FEAT)/$(STR)/my_strcpy.c
SRC += $(JB)/$(FEAT)/$(STR)/q_strcpy.c



SRC += $(JB)/$(PRINT)/my_printf.c
SRC += $(JB)/$(PRINT)/my_put_nbr.c
SRC += $(JB)/$(PRINT)/my_putchar.c
SRC += $(JB)/$(PRINT)/my_putstr.c
SRC += $(JB)/$(PRINT)/print_tab.c
SRC += $(JB)/$(PRINT)/my_putnbr_base.c

OBJ     =       $(SRC:.c=.o)

CFLAGS	=	-I ../../includes/ -Wall -Wextra

NAME    =	liblink.a

all:    $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
