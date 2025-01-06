EXEC = ghsu

CC = gcc
CFLAGS = -Wall -Wextra -pedantic 
LDFLAGS =

SRC = $(wildcard src/*.c) $(wildcard src/utils/*.c)

OBJ = $(SRC:src/%.c=obj/%.o)
OBJ_UTILS = $(SRC:src/utils/%.c=obj/utils/%.o)

all: $(EXEC)

obj/%.o: src/%.c
	@mkdir -p obj obj/utils
	@$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	@rm -rf $(EXEC) obj/
