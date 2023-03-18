CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
VALGRIND = valgrind --leak-check=full --show-reachable=yes --track-origins=yes

PROG = main
SRC = location.c main.c object.c setup.c
HDR = object.h location.h setup.h
OBJ = $(SRC:.c=.o)

$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean check memcheck
clean:
	$(RM) $(PROG) $(OBJ)
check: $(PROG)
	./$(PROG)
memcheck: $(PROG)
	$(VALGRIND) ./$(PROG)
