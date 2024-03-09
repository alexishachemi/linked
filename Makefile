##
## EPITECH PROJECT, 2024
## liblinked
## File description:
## Makefile
##

NAME	=	linked

LIB	=	lib$(NAME).a

CC		=	gcc

CURRDIR	=	$(shell pwd)

OBJDIR	=	$(CURRDIR)/tmp

OBJECTS	=	$(OBJDIR)/*.o

# Sources

SRC		=	$(shell find $(CURRDIR)/src -type f -name '*.c')

OBJ		=	$(SRC:%.c=$(OBJDIR)/%.o)

CFLAGS	+=	-W -Wall -Wextra -I$(CURRDIR)/include

# Tests

TSRC	=	$(shell find $(CURRDIR)/tests/unit_tests -type f -name '*.c')

TOBJ	=	$(TSRC:%.c=$(OBJDIR)/%.o)

MAIN	=	tests/main.c

MOBJ	=	$(MAIN:%.c=$(OBJDIR)/%.o) $(OBJ)

TFLAGS	=	-lcriterion -lgcov --coverage

VFLAGS	=	--trace-children=yes --track-origins=yes \
			--leak-check=full --show-leak-kinds=all

# Rules

$(LIB):	$(OBJ)
	ar rc $(LIB) $(OBJECTS)

all:	$(LIB)

clean:
	rm -rf $(OBJDIR)
	rm -f $(shell find . -type f -name '*.gc*')

fclean:	clean
	rm -f $(LIB)
	rm -f $(NAME)

re:	clean all

unit_tests:	CFLAGS += $(TFLAGS)
unit_tests:	$(TOBJ) $(OBJ)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS)

tests_run:	unit_tests
	./unit_tests

$(NAME):	$(MOBJ)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS)

main:	$(NAME)

$(OBJDIR)/%.o:	%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $(OBJDIR)/$(@F) -c $< $(CFLAGS)

.PHONY: all clean fclean re tests_run main
