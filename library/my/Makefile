##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Task01
##

SRC	=	free_array.c	\
		is_number.c	\
		my_getnbr.c	\
		my_putnbr.c	\
		nb_to_str.c	\
		my_putstr.c	\
		str_find.c	\
		my_nblen.c	\
		my_revstr.c	\
		my_clean_str.c	\
		my_putchar.c	\
		my_strcat.c	\
		my_rand.c	\
		my_pow.c	\
		my_puterr.c	\
		my_strlen.c	\
		my_strcmp.c	\
		realloc_array.c	\
		infin_put.c	\
		str_to_word_array.c	\
		get_next_line.c	\

CFLAGS	+=	-W -Wall -Wextra -g

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

YELLOW		=	\033[0;103m
RED             =       \033[0;31m
GREEN           =       \033[0;32m
NC              =       \033[0m
GREY            =       \033[90m
BLUE            =       \033[0;94m
PURPLE          =       \033[0;95m
BG_COLOR        =       \033[46m####\033[m
IRED            =       \033[0;91m

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../
	@cp my.h ../../include/
	@echo -e '${NC}${BG_COLOR}Libs: $(LDFLAGS)${NC}'
	@echo -e '${BG_COLOR}Flags: $(CFLAGS)${NC}'
	@echo -e '${BLUE}Create${NC}: ${YELLOW}${GREY}./$(NAME)${NC}'

%.o:	%.c
	@-$(CC) -o $@ -c $< $(CFLAGS)\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'

clean:
	@find . -name "*~" -delete -o -name "#*#" -delete
	@rm -rf $(OBJ)
	@echo -e '${BLUE}Clean${NC} : OK'

fclean:
	@find . -name "*~" -delete -o -name "#*#" -delete
	@rm -rf $(OBJ)
	@rm -rf ./$(NAME)
	@rm -rf ../$(NAME)
	@echo -e '${BLUE}Fclean${NC}: ./$(NAME) removed'

re:	fclean	all

.PHONY:	all	$(NAME)	clean	fclean	re
