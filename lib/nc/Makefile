##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## This will be used to compile and clean files
##

SRC	=	concat_params.c		\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c		\
		my_isalpha.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_putstr_printf_inte.c	\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_show_word_array.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isaplpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_str_to_word_array.c	\
		my_strupcase.c		\
		my_swap.c		\
		my_strtok.c		\
		my_putchar_printf.c	\
		my_putstr_printf.c	\
		my_put_nbr_printf.c	\
		my_put_base_printf.c	\
		my_getnbr_printf.c	\
		my_log.c	\
		my_ll_add.c	\
		my_list_size.c	\
		my_put_ll.c	\
		my_strtok_printf.c	\
		add_padding_printf.c	\
		my_printf.c	\
		evaluate_flags.c	\
		evaluate_flags2.c	\
		my_put_float_ll.c	\
		my_put_nbr_printf2.c	\
		ll_manipulation.c	\
		update_specifier.c	\
		error_detection.c	\
		my_put_nbr_printf_ll.c	\
		my_put_science.c	\
		my_put_float2.c	\
		my_putchar_printf_c.c	\
		flag_g.c	\
		my_put_science2.c	\
		my_pointers_hexa.c	\
		my_put_base_printf2.c	\
		my_convert_hexa.c	\
		my_convert_octal.c	\
		my_put_nbr_printf_unsigned.c	\
		flag_g2.c	\
		update_specifier2.c	\
		my_handle_length_put_nbr_printf.c	\
		my_getnbr_index.c	\
		my_getnbr_index_u.c	\
		my_strtok_s.c	\
		my_strdup_s.c	\
		my_strdup_f.c	\
		my_strtok_a.c	\
		realloc_char.c	\
		my_strtok_quotes.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../../includes

NAME	=	libnc.a

all:	$(OBJ)
	@ $(AR) rc $(NAME) $(OBJ)

clean:
	@ rm -rf $(OBJ)

fclean:	clean
	@ rm -rf $(NAME)

re:	fclean all

COUNT = 0
MAX_FILES = $(words $(SRC))

%.o: %.c
	@ $(eval COUNT=$(shell echo $$(($(COUNT) + 1))))

##	mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@

ifneq ($(findstring -j, $(MAKEFLAGS)),)
	@echo "$c =====> $@"
else
	@ python3 bar.py --stepno=$(COUNT) --nsteps=$(MAX_FILES)
endif
