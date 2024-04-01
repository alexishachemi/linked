##
## EPITECH PROJECT, 2024
## liblinked
## File description:
## Makefile
##

NAME	=	linked

LIB		=	lib$(NAME).a

CC		=	gcc

TMPDIR	=	tmp

# Sources

SRC		=	$(shell find src -type f -name '*.c')

OBJ		=	$(SRC:%.c=$(TMPDIR)/%.o)

CFLAGS	+=	-W -Wall -Wextra -Iinclude

# Tests

TNAME	=	unit_tests

TSRC	=	$(shell find tests/$(TNAME) -type f -name '*.c')

TOBJ	=	$(TSRC:%.c=$(TMPDIR)/%.o)

MAIN	=	tests/main.c

MOBJ	=	$(MAIN:%.c=$(TMPDIR)/%.o) $(OBJ)

TFLAGS	=	-lcriterion -lgcov --coverage -Itests/include

VFLAGS	=	--trace-children=yes --track-origins=yes \
			--leak-check=full --show-leak-kinds=all

# Rules

$(LIB):	$(OBJ)
	ar rc $(LIB) $(OBJ)

all:	$(LIB)

clean:
	rm -rf $(TMPDIR)
	rm -f $(shell find . -type f -name '*.gc*')

fclean:	clean
	rm -f $(LIB)
	rm -f $(NAME)
	rm -f $(TNAME)

re:	clean all

$(TNAME):	CFLAGS += $(TFLAGS)
$(TNAME):	$(TOBJ) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tests_run:	$(TNAME)
	./$(TNAME)

$(NAME):	$(MOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

main:	$(NAME)

$(TMPDIR)/%.o:	%.c
	@mkdir -p $(@D)
	gcc -o $@ -c $< $(CFLAGS) $(LDFLAGS)

.PHONY: all clean fclean re tests_run main
