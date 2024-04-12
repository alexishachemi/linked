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

SRC		=	list_add.c 				\
			list_create.c			\
			list_destroy.c			\
			list_handle.c			\
			list_node_utils.c		\
			list_positional_utils.c	\
			list_remove.c			\
			list_size.c				\
			list_utils.c			\

SRC		:=	$(addprefix src/,$(SRC))

OBJ		=	$(SRC:%.c=$(TMPDIR)/%.o)

CFLAGS	+=	-W -Wall -Wextra -Iinclude

# Tests

TNAME	=	unit_tests

TSRC	=	list_add_tests.c		\
			list_create_tests.c		\
			list_destroy_tests.c	\
			list_handle_tests.c		\
			list_remove_tests.c		\
			list_size_tests.c		\
			list_utils_tests.c		\
			test_utils.c			\

TSRC	:=	$(addprefix tests/unit_tests/,$(TSRC))

TOBJ	=	$(TSRC:%.c=$(TMPDIR)/%.o)

MAIN	=	tests/main.c

MOBJ	=	$(MAIN:%.c=$(TMPDIR)/%.o) $(OBJ)

TFLAGS	=	-lcriterion -lgcov --coverage -Itests/include

VFLAGS	=	--track-origins=yes --leak-check=full --show-leak-kinds=all

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

val_tests: unit_tests
	valgrind $(VFLAGS) ./unit_tests

.PHONY: all clean fclean re tests_run main
