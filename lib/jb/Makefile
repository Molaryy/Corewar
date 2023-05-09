##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LINKS	=	./links


JB	=	./jb_lib

FEAT	= ./features

PRINT	=	./print

SRC += $(LINKS)/add_link.c
SRC += $(LINKS)/create_link.c
SRC += $(LINKS)/free_links.c
SRC += $(LINKS)/link_len.c
SRC += $(LINKS)/delete_node.c
SRC += $(LINKS)/print_link.c


SRC += $(JB)/$(FEAT)/j_strcat.c
SRC += $(JB)/$(FEAT)/is_alphanumeric.c
SRC += $(JB)/$(FEAT)/array_to_str.c
SRC += $(JB)/$(FEAT)/cpy_char_separator.c
SRC += $(JB)/$(FEAT)/my_strlen.c

SRC += $(JB)/$(PRINT)/my_printf.c
SRC += $(JB)/$(PRINT)/my_put_nbr.c
SRC += $(JB)/$(PRINT)/my_putchar.c
SRC += $(JB)/$(PRINT)/my_putstr.c
SRC += $(JB)/$(PRINT)/print_tab.c

OBJ     =       $(SRC:.c=.o)

CFLAGS	=	-I ../../includes/ -Wall -Wextra

NAME    =	liblink.a

all:    $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
